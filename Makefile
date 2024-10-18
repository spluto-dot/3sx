# Binaries

VERSION ?= anniversary

ifeq ($(VERSION), standalone)
MAIN := SLPM_656.21
else ifeq ($(VERSION), anniversary)
MAIN := THIRD_U.BIN
endif

# Export so that Python could see those
export VERSION
export MAIN

# Directories

BIN_DIR := bin
BUILD_DIR := build/$(VERSION)
SRC_DIR := src/$(VERSION)
ASM_DIR := asm/$(VERSION)
INCLUDE_DIR := include
ASSETS_DIR := assets/$(VERSION)
CONFIG_DIR := config/$(VERSION)
TOOLS_DIR := tools

# Tools

WIBO := $(BIN_DIR)/wibo
MWCCPS2 := $(BIN_DIR)/mwccps2.exe
# MWASPS2 := $(WIBO) $(BIN_DIR)/asm_r5900_elf.exe -gnu
MWLDPS2 := MWCIncludes=$(BIN_DIR) $(WIBO) $(BIN_DIR)/mwldps2.exe

CCPS2 := MWCIncludes=$(BIN_DIR) $(WIBO) $(MWCCPS2)

CC := $(CCPS2)
AS := mipsel-linux-gnu-as
LD := $(MWLDPS2)

PYTHON := python3
SPLICE_ELF := $(PYTHON) $(TOOLS_DIR)/splice_elf.py
COMPARE_BYTES := $(PYTHON) $(TOOLS_DIR)/compare_bytes.py
PATCH_ALIGNMENT := $(PYTHON) $(TOOLS_DIR)/patch_alignment.py
GENERATE_LCF := $(PYTHON) $(TOOLS_DIR)/lcf/generate_lcf.py

# Flags

MWCCPS2_INCLUDES := -I$(INCLUDE_DIR)
MWCCPS2_FLAGS_BASE := -gccinc $(MWCCPS2_INCLUDES) -O0,p -c -lang c -str readonly
MWCCPS2_FLAGS_DEFAULT := $(MWCCPS2_FLAGS_BASE) -sdatathreshold 128
MWCCPS2_FLAGS_SDT2 := $(MWCCPS2_FLAGS_BASE) -sdatathreshold 2
MWCCPS2_FLAGS_SDT128 := $(MWCCPS2_FLAGS_BASE) -sdatathreshold 128

AS_FLAGS += -EL -I $(INCLUDE_DIR) -G 128 -march=r5900 -mabi=eabi -no-pad-sections
LD_FLAGS := -main func_00100008 -map

# Files

MAIN_TARGET := $(BUILD_DIR)/$(MAIN)

MAIN_S_FILES := $(shell find $(ASM_DIR) -name '*.s')
MAIN_C_FILES := $(shell find $(SRC_DIR) -name '*.c')
MAIN_O_FILES := $(patsubst %.s,%.s.o,$(MAIN_S_FILES))
MAIN_O_FILES += $(patsubst %.c,%.c.o,$(MAIN_C_FILES))
MAIN_O_FILES := $(addprefix $(BUILD_DIR)/,$(MAIN_O_FILES))

SDT2_C_FILES := sfiii/2207F0.c
SDT2_C_FILES := $(addprefix $(SRC_DIR)/,$(SDT2_C_FILES))

SDT128_C_FILES := sfiii/pad/384790.c sfiii/pad/386000.c
SDT128_C_FILES := $(addprefix $(SRC_DIR)/,$(SDT128_C_FILES))

LINKER_SCRIPT := $(BUILD_DIR)/$(MAIN).lcf

COMPILER_TAR := mwcps2-3.0b52-030722.tar.gz

# Rules

build: $(MAIN_TARGET)

split:
	$(GENERATE_LCF) $(LINKER_SCRIPT)

clean: ##@ clean extracted files, assets, and build artifacts
	git clean -fdx $(ASSETS_DIR)/
	git clean -fdx $(ASM_DIR)/
	git clean -fdx $(BUILD_DIR)/
	git clean -fdx .splache

setup_tools: $(WIBO) $(MWCCPS2)

$(MAIN_TARGET): $(MAIN_O_FILES) $(LINKER_SCRIPT)
	$(LD) $(LD_FLAGS) -o $@ \
		$(LINKER_SCRIPT) \
		$(shell find $(BUILD_DIR) -name '*.o')
	# $(SPLICE_ELF)
	$(COMPARE_BYTES) $(MAIN) $(MAIN_TARGET) 0x80 0x478A00

$(BUILD_DIR)/%.s.o: %.s
	mkdir -p $(dir $@)
	$(AS) $(AS_FLAGS) -o $@ $<
	$(PATCH_ALIGNMENT) $@

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(if $(findstring $<,$(SDT2_C_FILES)),$(MWCCPS2_FLAGS_SDT2),$(if $(findstring $<,$(SDT128_C_FILES)),$(MWCCPS2_FLAGS_SDT128),$(MWCCPS2_FLAGS_DEFAULT))) -o $@ $<
	$(PATCH_ALIGNMENT) $@

$(WIBO):
	wget -O $@ https://github.com/decompals/wibo/releases/download/0.6.13/wibo
	chmod +x $(WIBO)

$(MWCCPS2):
	wget https://github.com/decompme/compilers/releases/download/compilers/$(COMPILER_TAR)
	cd $(BIN_DIR) && tar -x -f ../$(COMPILER_TAR)
	rm $(COMPILER_TAR)
