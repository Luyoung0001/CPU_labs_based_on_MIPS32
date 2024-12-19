#include "VCPU.h"
#include "VCPU___024root.h"
#include "verilated_vcd_c.h"  // add

#include <iostream>
vluint64_t main_time = 0;                  // initial 仿真时间
VerilatedVcdC* tfp = new VerilatedVcdC();  //导出vcd波形需要加此语
VCPU* top = NULL;

void step() {
    top->clk = 0;
    top->eval();

    tfp->dump(main_time);  // 记录波形数据
    main_time++;           // 时间递增

    top->clk = 1;
    top->eval();

    tfp->dump(main_time);
    main_time++;
}
void reset(int n) {
    top->rst = 1;
    while (n--) {
        step();
    }
    top->rst = 0;
}

void cpu_exec(uint64_t n) {
    while (n--) {
        step();
    }
}

int main() {
    top = new VCPU;
    Verilated::traceEverOn(true);  //导出vcd波形需要加此语句
    top->trace(tfp, 99);
    tfp->open("wave.vcd");

    reset(1);

    cpu_exec(10000);
    top->final();
    tfp->close();

    return 0;
}