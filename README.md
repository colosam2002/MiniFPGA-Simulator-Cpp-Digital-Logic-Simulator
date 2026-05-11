# MiniFPGA Simulator

MiniFPGA Simulator is an educational C++ digital logic simulator inspired by FPGA-style circuits.

The project aims to simulate digital logic components from basic gates to more advanced sequential systems and eventually a small RISC-V inspired execution core. 

## Current Features

- Signal abstraction
- Component abstraction
- Logic gates: AND, OR, XOR, NOT
- Circuit container
- Dynamic gate creation with a factory
- JSON-based circuit descriptions
- CLI execution from circuit files
- Half-adder example
- Full-adder example

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
