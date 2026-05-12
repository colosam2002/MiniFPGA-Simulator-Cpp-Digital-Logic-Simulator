# MiniFPGA TinyCPU Emulator

A C++ educational CPU and digital logic simulator inspired by FPGA systems, computer architecture and low-level execution models.

The project evolved from basic logic gates into a small educational CPU emulator supporting:

- branching
- stack execution
- CALL / RET
- instruction memory
- assembly-like syntax
- external program loading

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

```text
Assembly Program
        ↓
Program Loader
        ↓
Instruction Decoder
        ↓
Instruction Memory
        ↓
TinyCPU Execution
        ↓
Registers / Stack / Flags
```

## TinyCPU Features

### Arithmetic Instructions
- LOAD
- MOV
- ADD
- SUB

### Branching Instructions
- CMP
- JMP
- JE
- JNE

### Stack Instructions
- PUSH
- POP

### Function Execution
- CALL
- RET

## Emulator Features

- instruction memory
- execution tracing
- assembly-like syntax
- external program loading
- instruction decoding
- stack-aware execution
- function execution model
- program counter tracing

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

## Running Assembly Programs

Assembly programs are stored in:

```text
examples/*.asm
```

The emulator loads programs through the `ProgramLoader` system and executes them through the TinyCPU execution pipeline.

## Learning Goals

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