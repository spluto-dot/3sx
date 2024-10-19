import sys
from dataclasses import dataclass
from pathlib import Path
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

@dataclass
class Run:
    entries: list[LinkerEntry]
    is_game: bool
    section: str

def split_into_runs(entries: list[LinkerEntry]) -> list[Run]:
    runs: list[Run] = list()
    runs.append(Run(list(), False, ".text"))

    for entry in entries:
        if entry.section_link_type == "pad":
            continue

        entry_is_game = "sf33rd" in str(entry.object_path)
        # print(entry_is_game, entry.object_path, entry.section_link_type)

        if entry.section_link_type != runs[-1].section or entry_is_game != runs[-1].is_game:
            runs.append(Run(list(), entry_is_game, entry.section_link_type))

        runs[-1].entries.append(entry)

    return runs

def strip_path(path: Path) -> str:
    return path.name

class LCFWriter:
    def __init__(self, config_path: Path):
        self.config_path = config_path
        self.file = None
        self.last_line_blank = False

    def __enter__(self) -> 'LCFWriter':
        self.file = open(self.config_path, "w")

        with open("tools/lcf/lcf_header.txt") as header:
            self.file.write(header.read())

        return self

    def __exit__(self, *args):
        with open("tools/lcf/lcf_footer.txt") as footer:
            self.file.write(footer.read())

        self.file.close()

    def write_line(self, line: str):
        self.file.write(f"\t\t{line}\n")
        self.last_line_blank = False

    def blank(self):
        self.file.write("\n")
        self.last_line_blank = True

    def separator(self):
        self.write_line("# " + "=" * 75)

    def begin_section(self, title: str):
        if not self.last_line_blank:
            self.blank()

        self.separator()
        self.write_line(f"# {title}")
        self.separator()
        self.blank()

    def align(self, alignment: int):
        self.write_line(f". = ALIGN(0x{alignment:X});")

    def align_all(self, alignment: int):
        self.write_line(f"ALIGNALL(0x{alignment:X});")

    def add_entry(self, entry: LinkerEntry, section: str):
        self.write_line(f"{strip_path(entry.object_path)} ({section})")

    def add_entries(self, entries: list[LinkerEntry], section: str):
        for entry in entries:
            self.add_entry(entry, section)

    def add_runs(self, runs: list[Run], section: str):
        for run in runs:
            self.add_entries(run.entries, section)

def main():
    config_path = Path(sys.argv[1])
    split.main(["config/anniversary/sfiii.anniversary.yaml"], modes="all", verbose=False)
    runs = split_into_runs(split.linker_writer.entries)

    with LCFWriter(config_path) as lcf:
        lcf.write_line("_gp = 0x57A3F0;")

        # text

        lcf.begin_section("text sections")
        lcf.align(0x80)

        text_runs = [x for x in runs if x.section == ".text"]
        first_entry = text_runs[0].entries[0]

        # crt0 special case

        if "crt0" in str(first_entry.object_path):
            lcf.add_entry(first_entry, ".text")
            lcf.align(0x10)
            del runs[0].entries[0]

        for run in text_runs:
            is_lib_vib = "libvib" in str(run.entries[0].object_path)
            alignment = 0x4

            if run.is_game:
                alignment = 0x10
            elif is_lib_vib:
                alignment = 0x8

            lcf.align_all(alignment)
            lcf.add_entries(run.entries, ".text")

        lcf.blank()

        for _ in range(2):
            lcf.write_line("WRITEW 0x0; # text section patch for EE pipeline")

        # data/rodata

        lcf.begin_section("data sections")

        data_groups = [
            (".data", [x for x in runs if x.section == ".data"]),
            (".rodata", [x for x in runs if x.section == ".rodata"])
        ]

        for section, section_runs in data_groups:
            lcf.begin_section(section)
            lcf.align(0x80)
            lcf.align_all(0x8)

            for run in section_runs:
                lcf.add_entries(run.entries, section)

        # small data

        lcf.begin_section("small data sections")

        sdata_runs = [x for x in runs if x.section == ".sdata"]
        lcf.align(0x80)
        # lcf.align_all(0x10)
        # lcf.add_runs(sdata_runs, ".sdata")

        alignment = 0x8

        for run in sdata_runs:
            for entry in run.entries:
                if "Continue" in str(entry.object_path):
                    alignment = 0x10

                lcf.align(alignment)
                lcf.add_entry(entry, ".sdata")

        lcf.blank()

        sbss_runs = [x for x in runs if x.section == ".sbss"]
        lcf.align(0x80)
        lcf.align_all(0x4)
        lcf.add_runs(sbss_runs, ".sbss")

        # bss

        lcf.begin_section("bss sections")

        bss_runs = [x for x in runs if x.section == ".bss"]

        # lcf.align(0x80)
        lcf.align_all(0x8)
        lcf.add_runs(bss_runs, ".bss")

        lcf.blank()

        # finalize

        lcf.align(0x80)

if __name__ == "__main__":
    main()
