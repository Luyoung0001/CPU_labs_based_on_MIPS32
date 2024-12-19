# CPU_labs_based_on_MIPS32

## 说明
RTL with Verilog. Simulation with verilator.

本实验用 Verilog 描述，然后用 verilator 将 Verilog 仿真成 C++ 代码，然后顺便在仿真环境中进行验证 CPU

## 框架

CPU 模块就是 Top 模块；子模块有：IFU、IDU、EXU，实验比较简单，因此分为 3 个模块

