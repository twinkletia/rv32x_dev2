TOP=rv32x_simulation
NSL2VL=nsl2vl
NFLAGS=-O2 -neg_res -I../core -I../integration -I../integration/mmcspi/src -DSIM
#SIMFLAGS=-verisim2 -target $(TOP)
INCOPT=-I../core
NSRC := $(wildcard ../core/*.nsl) $(wildcard ../integration/*.nsl) $(wildcard ../integration/mmcspi/src/*.nsl) $(wildcard ../simulation/*.nsl)
SRC := $(notdir $(NSRC)) 
# VFILES := $(addprefix out/, $(SRC:.nsl=.v))
VFILES := $(addprefix out/, $(SRC:.nsl=.v)) 
RISCV_PREFIX=riscv32-unknown-elf-
AS=$(RISCV_PREFIX)as
LD=$(RISCV_PREFIX)ld
OBJCOPY=$(RISCV_PREFIX)objcopy
RISCV_INSTALL_DIR=/opt/riscv/x86_64-pc-linux-gnu/riscv32-elflittle
LIBSFRAME_DIR=/opt/riscv/lib
SIMOPT=

.PHONY: clean all obj_dir $(TOP)
.SUFFIXES: .nsl .v

all: $(TOP)
lint: $(VFILES)
	verilator --lint-only -Wall -Wno-UNUSED -Wno-UNDRIVEN --Wno-DECLFILENAME --Wno-VARHIDDEN rv32x_simulation -Iout/
	
run_riscv_tests: $(TOP)_test bootrom.hex
	make -C ../software/riscv-tests/isa XLEN=32
	./run_riscv_tests.py log
check: run_riscv_tests
out/%.v: ../integration/%.nsl 
	if [ ! -d out ]; then \
		mkdir out; \
	fi
	$(NSL2VL) $(NFLAGS) $< -o $@
out/%.v: ../integration/mmcspi/src/%.nsl 
	if [ ! -d out ]; then \
		mkdir out; \
	fi
	$(NSL2VL) $(NFLAGS) $< -o $@
out/%.v: ../core/%.nsl 
	if [ ! -d out ]; then \
		mkdir out; \
	fi
	$(NSL2VL) $(NFLAGS) $< -o $@
out/$(TOP).v: $(TOP).nsl 
	if [ ! -d out ]; then \
		mkdir out; \
	fi
	$(NSL2VL) $< $(NFLAGS) $(SIMFLAGS) -o $@
obj_dir: $(TOP).cpp $(VFILES) 
	make out/$(TOP).v SIMFLAGS=
	make -C elfloader libelfloader.a
	verilator --cc -Wno-lint -Wno-UNOPTFLAT --trace --trace-underscore out/*.v --top-module $(TOP) --exe $(TOP).cpp -O3 --autoflush -LDFLAGS "-L../elfloader -L$(LIBSFRAME_DIR) -L$(RISCV_INSTALL_DIR)/lib -lelfloader -lopcodes -lbfd -lsframe -liberty -lz -ldl" -CFLAGS "-I$(RISCV_INSTALL_DIR)/include -O2 -static -ggdb $(SIMOPT)"

$(TOP): $(TOP).cpp obj_dir $(VFILES) bootrom.hex
	cd obj_dir && make -f V$(TOP).mk V$(TOP)
	cp obj_dir/V$(TOP) $(TOP)
$(TOP)_test: 
	make $(TOP) NFLAGS=-O2\ -neg_res\ -I../core\ -I../integration\ -I../integration/mmcspi/src\ -DSIM SIMOPT=-DHTIF -B
	
bootrom.hex: 
	make -C bootrom -B
	cp bootrom/bootrom.hex ./
clean:
	@rm -rf out 
	@rm -rf $(TOP).v 
	@rm -rf obj_dir $(TOP) $(TOP).vcd
	@rm -rf failed
	@rm -rf bootrom.hex
	@rm -rf logs
	make clean -C elfloader 
	make clean -C bootrom
