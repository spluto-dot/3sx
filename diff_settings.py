def apply(config, args):
    config["baseimg"] = "SLPM_656.21"
    config["myimg"] = "build/SLPM_656.21"
    config["mapfile"] = "build/SLPM_656.21.map"
    config["source_directories"] = ["src"]
    # config["show_line_numbers_default"] = True
    config["arch"] = "mipsee"
    config["map_format"] = "gnu" # gnu, mw, ms
    # config["build_dir"] = "build/" # only needed for mw and ms map format
    config["expected_dir"] = "" # needed for -o
    # config["makeflags"] = []
    config["objdump_executable"] = "mipsel-linux-gnu-objdump"
