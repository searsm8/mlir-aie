include ../../makefile-common

.PHONY: all clean

# TODO - Change this to env variable?
ifeq ($(MLIR_AIE_SYSROOT),)
MLIR_AIE_SYSROOT = /group/xrlabs/platforms/vck190-pynq-v2.7/sysroot
endif
AIE_INSTALL = $(dir $(shell which aie-opt))/..

all: tutorial-7.exe
	@mkdir -p elf
	@mv *.elf* ./elf
	@cp ./elf/*.elf ./elf/*.elf.map .

# Command line mlir-aie compile script "aiecc.py"
# Sysroot and host target used to cross compile  host executable
# Local runtime_lib needed for testbench functions
tutorial-7.exe: test.cpp aie.mlir
	aiecc.py -j4 $(AIECC_FLAGS) $(word 2,$^) $(AIECC_HOST_FLAGS) ./$< -o $@

clean:
	rm -rf acdc_project sim aiesimulator_output *elf core* *log *vcd *exe pl_sample_counts .AIE_SIM_CMD_LINE_OPTIONS
