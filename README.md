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

## Sequential Logic Features

- Clock system
- Rising edge detection
- Falling edge detection
- D Flip-Flops
- Multi-bit registers
- Load / enable signals
- Binary counters
- Simulation engine
- Tick-based simulation
- Stateful sequential components

## CPU Architecture Features

- Register file
- Instruction execution
- Program counter
- Execution unit
- Instruction sequencing
- Tiny CPU abstraction
- Basic instruction set
- LOAD / MOV / ADD instructions
- Fetch-decode-execute concepts

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

## Sequential Simulation Architecture

The simulator now supports sequential digital logic.

Core concepts include:

- global clock synchronization
- edge-triggered updates
- persistent component state
- centralized simulation scheduling

Simulation flow:

```text
SimulationEngine
        ↓
Clock tick
        ↓
Sequential component updates
        ↓
State propagation

Sequential hierarchy:

Clock
   ↓
D Flip-Flops
   ↓
Registers
   ↓
Counters
```

## TinyCPU Architecture

The simulator now includes a minimal CPU-style execution system.

Core concepts implemented:

- program execution
- instruction sequencing
- register-based computation
- execution units
- instruction decoding
- program counter flow

Execution cycle:

```text
FETCH
  ↓
DECODE
  ↓
EXECUTE
  ↓
UPDATE STATE
```

### CPU hierarchy
```text
TinyCPU
   ├── Program Counter
   ├── Execution Unit
   ├── Register File
   └── Instruction Program
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

- RAM simulation
- instruction execution
- register files
- instruction decoding
- small RISC-V-inspired core
- waveform generation
- pipeline experimentation

## Educational Goals

This project is designed as an educational exploration of:

- digital logic
- computer architecture
- hardware simulation
- C++ systems programming
- low-level computation
- CPU design fundamentals

The long-term goal is to evolve the simulator toward a small RISC-V-inspired educational architecture.

## Concepts Explored

This project explores concepts from:

- digital logic
- sequential systems
- computer architecture
- CPU design
- memory systems
- instruction execution
- hardware simulation
- low-level systems programming

## Future goals include:

- memory-mapped execution
- instruction memory
- simple assembler
- RISC-V-inspired instructions
- branching and jumps
- stack concepts
- pipeline experimentation
- waveform tracing
