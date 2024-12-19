#vsrc
LAB_PATH = /home/luyoung/CPU_labs_based_on_MIPS32
VSRC = $(LAB_PATH)/CPU/*.v

#main.cpp
CPPSRC = $(LAB_PATH)/main.cpp

VERI_FLAGS = --cc $(VSRC) --exe $(CPPSRC)  --trace --top CPU

# tools
VERILATOR = verilator

simu:
	$(VERILATOR) $(VERI_FLAGS)

build: simu
	bear -- make -C obj_dir -f VCPU.mk
run: build
	./obj_dir/VCPU

clean:
	rm -rf ./obj_dir
