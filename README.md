# MiniFPGA TinyCPU Emulator

A C++ educational CPU and digital logic simulator inspired by FPGA systems, computer architecture and low-level execution models.

## Current Capabilities

The emulator currently supports:

- digital logic simulation
- RAM and register-based execution
- stack-based execution flow
- CALL / RET subroutines
- branching and loops
- instruction memory
- assembly-like syntax
- external assembly program loading
- instruction decoding and execution tracing

## Architecture Overview

Execution pipeline:

1. Assembly Program
2. Program Loader
3. Instruction Decoder
4. Instruction Memory
5. TinyCPU Execution
6. Registers / Stack / Flags

## CPU Architecture

                 +-------------+
                 | ControlUnit |
                 +-------------+
                        |
                        v

+-------------------------------+
|            TinyCPU            |
+-------------------------------+
|                               |
|  +---------+    +----------+  |
|  |Datapath |--->|   ALU    |  |
|  +---------+    +----------+  |
|                               |
|  +------------+              |
|  |RegisterFile|              |
|  +------------+              |
|                               |
|  +------------+              |
|  |StackMemory |              |
|  +------------+              |
|                               |
|  +----------------+          |
|  |InstructionMemory|         |
|  +----------------+          |
+-------------------------------+


## TinyCPU Features

| Category                | Instructions              |
|------------------------|--------------------------|
| Arithmetic Instructions | LOAD, MOV, ADD, SUB     |
| Branching Instructions  | CMP, JMP, JE, JNE       |
| Stack Instructions      | PUSH, POP               |
| Function Execution      | CALL, RET               |

## Example Assembly Program

```asm
LOAD R1 5
LOAD R2 1

CALL 5

LOAD R5 99

JMP 13

LOAD R0 0

SUB R1 R1 R2

CMP R1 R0

JNE 6

LOAD R3 42

PUSH R3
POP R4

RET
```

## Build Instructions

```bash
mkdir build
cd build

cmake ..
make

./minifpga
```

## Command Line Usage

Run logic circuit simulations:

```bash
./build/minifpga examples/and_gate.json
```

Run TinyCPU assembly programs:

```bash
./build/minifpga examples/loop_function.asm
```

Assembly programs are stored in:

```text
examples/*.asm
examples/*.json
```

The emulator loads programs through the `ProgramLoader` system and executes them through the TinyCPU execution pipeline.

## Project Goals

This project was built by Colomán Samprón to deeply understand:

- low-level systems programming in C++
- CPU execution flow
- stack-based execution
- instruction decoding
- assembly semantics
- memory organization
- emulator architecture
- digital logic simulation
- computer architecture fundamentals

## Future Improvements

Possible future extensions include:

- RISC-V inspired ISA
- pipeline simulation
- hazard detection
- memory-mapped execution
- instruction encoding
- assembler improvements
- recursive function support
- simple cache simulation
