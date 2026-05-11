# MiniFPGA Simulator

MiniFPGA Simulator is an educational C++ digital logic simulator inspired by FPGA-style circuits.

The project aims to simulate digital logic components from basic gates to more advanced sequential systems and eventually a small RISC-V inspired execution core. 

## Current Features

- Signal abstraction
- Component abstraction
- Logic gates:
    - AND
    - OR
    - NOT
    - XOR
- Circuit abstraction
- Half-adder simulation

## Build

```bash
mkdir build
cd build
cmake ..
make
./minifpga
```

## Example

Current demo:

```text
Half adder Truth Table
A B | SUM CARRY

0 0    0    0
0 1    1    0
1 0    1    0
1 1    0    1
```

## Project goals

Future goals include:

- Full adder
- Sequential circuits
- Registers
- Memory simulation
- VCD waveform generation
- Small RISC-V inspired CPU core