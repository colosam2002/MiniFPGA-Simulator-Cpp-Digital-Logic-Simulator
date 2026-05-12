#ifndef INSTRUCTION_MEMORY_HPP
#define INSTRUCTION_MEMORY_HPP

#include <vector>

#include "cpu/Instruction.hpp"

class InstructionMemory {
    private:
        std::vector<Instruction> instructions;

    public:
        InstructionMemory();

        void loadProgram(
            const std::vector<Instruction>& program
        );

        Instruction fetch(
            unsigned int address
        ) const;

        unsigned int getProgramSize() const;

        void printProgram() const;
    };

#endif