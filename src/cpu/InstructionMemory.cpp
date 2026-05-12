#include "cpu/InstructionMemory.hpp"
#include "cpu/InstructionFormatter.hpp"

#include <iostream>

InstructionMemory::InstructionMemory() {}

void InstructionMemory::loadProgram(const std::vector<Instruction>& program) {

    instructions = program;
}

Instruction InstructionMemory::fetch(unsigned int address) const {

    if (address >= instructions.size()) {

        std::cout
            << "Invalid instruction address: "
            << address
            << std::endl;

        return {
            Opcode::RET,
            0,
            0,
            0,
            0
        };
    }

    return instructions[address];
}

unsigned int
InstructionMemory::getProgramSize() const {

    return instructions.size();
}

void InstructionMemory::printProgram() const {

    std::cout
        << "===== PROGRAM MEMORY ====="
        << std::endl;

    for (unsigned int i = 0; i < instructions.size(); ++i) {

        std::cout
            << "[" << i << "] "
            << InstructionFormatter::format(
                instructions[i]
            )
            << std::endl;
    }
}