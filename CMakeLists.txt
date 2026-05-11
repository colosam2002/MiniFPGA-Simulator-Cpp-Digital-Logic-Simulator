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
)

target_include_directories(minifpga PRIVATE
    include
)