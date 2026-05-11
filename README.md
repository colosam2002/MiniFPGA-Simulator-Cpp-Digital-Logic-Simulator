# MiniFPGA Simulator

MiniFPGA Simulator is an educational C++ digital logic simulator inspired by FPGA-style circuits.

The project aims to simulate digital logic components from basic gates to more advanced sequential systems and eventually a small RISC-V inspired execution core. 

## Current Features

- Logic gates
  - AND
  - OR
  - XOR
  - NOT

- Circuit abstraction

- Dynamic gate creation

- JSON-based circuit descriptions

- Multi-bit buses

- Binary and hexadecimal visualization

- Ripple-carry multi-bit adder

- Basic ALU operations
  - ADD
  - AND
  - OR
  - XOR

- Multiplexer support

- CLI-based simulation

## JSON Circuit Format

Circuits can be described using JSON files.

Example:

```json
{
  "signals": [
    { "name": "A", "initial": true },
    { "name": "B", "initial": false },
    { "name": "OUT", "initial": false }
  ],

  "components": [
    {
      "type": "XOR",
      "name": "XOR_1",
      "inputs": ["A", "B"],
      "output": "OUT"
    }
  ]
}
```

## Supported gate types

- AND
- OR
- NOT
- XOR

### Binary gates use 

"inputs" : ["A", "B"]

### Unary gates use

"input": "A"

## Usage

Build the project:

```bash
mkdir build
cd build
cmake ..
make
```

## Architecture

The simulator currently follows a layered architecture:

```text
JSON description
        ↓
CircuitParser
        ↓
GateFactory
        ↓
Circuit / Bus system
        ↓
Logic simulation

Higher level components are build heirarchically

Logic Gates
    ↓
Half Adders
    ↓
Full Adders
    ↓
Multi-bit Adders
    ↓
ALU structures
```

### Run a circuit

./build/minifpga examples/xor_gate.json

### Available examples

- ./build/minifpga examples/and_gate.json
- ./build/minifpga examples/xor_gate.json
- ./build/minifpga examples/not_gate.json
- ./build/minifpga examples/half_adder.json
- ./build/minifpga examples/full_adder.json

## Project Goals

The long-term goal of MiniFPGA Simulator is to evolve from a simple digital logic simulator into a small educational hardware simulation platform.

Planned features include:

- More combinational circuits
  - multiplexers
  - decoders
  - arithmetic units

- Sequential logic support
  - clock signals
  - flip-flops
  - registers
  - counters

- Memory simulation
  - RAM blocks
  - instruction memory
  - data memory

- Waveform generation
  - VCD export support
  - GTKWave compatibility

- Improved circuit description system
  - hierarchical subcircuits
  - reusable modules
  - cleaner HDL-like JSON format

- Small RISC-V-inspired execution core
  - arithmetic instructions
  - registers
  - instruction decoding
  - simple execution pipeline

- Educational focus
  - easy-to-read architecture
  - visualization-friendly simulation
  - beginner-friendly digital logic examples

## Educational Goals

This project is designed as an educational exploration of:

- digital logic
- computer architecture
- hardware simulation
- C++ systems programming
- low-level computation
- CPU design fundamentals

The long-term goal is to evolve the simulator toward a small RISC-V-inspired educational architecture.
