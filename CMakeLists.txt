cmake_minimum_required(VERSION 3.16)

project(MiniFPGASim VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(minifpga
    src/main.cpp
    src/Signal.cpp
    src/Component.cpp
    src/Circuit.cpp
    src/gates/AndGate.cpp
    src/gates/OrGate.cpp
    src/gates/XorGate.cpp
    src/gates/NotGate.cpp
    src/subcircuits/HalfAdder.cpp
    src/subcircuits/FullAdder.cpp
    src/factory/GateFactory.cpp
    src/parser/CircuitParser.cpp
    src/core/Bus.cpp
    src/subcircuits/MultiBitAdder.cpp
    src/subcircuits/BasicALU.cpp
    src/subcircuits/Mux2to1.cpp
    src/core/Clock.cpp
    src/sequential/DFlipFlop.cpp
    src/sequential/Register.cpp
    src/sequential/BinaryCounter.cpp
    src/sequential/SequentialComponent.cpp
    src/core/SimulationEngine.cpp
    src/memory/RAM.cpp
    src/memory/RegisterFile.cpp
    src/memory/MemoryInterface.cpp
    src/cpu/Instruction.cpp
    src/cpu/ExecutionUnit.cpp
    src/cpu/TinyCPU.cpp
    src/cpu/CPUFlags.cpp
    src/cpu/ExecutionResult.cpp
)

target_include_directories(minifpga PRIVATE
    include
)