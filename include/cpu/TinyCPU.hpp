#ifndef TINY_CPU_HPP
#define TINY_CPU_HPP

#include <vector>

#include "cpu/ExecutionUnit.hpp"
#include "cpu/CPUFlags.hpp"

#include "memory/RegisterFile.hpp"
#include "memory/StackMemory.hpp"

class TinyCPU {
    private:
        RegisterFile registerFile;

        ExecutionUnit executionUnit;

        std::vector<Instruction> program;

        unsigned int programCounter;

        CPUFlags flags;

        StackMemory stackMemory;

    public:
        TinyCPU();

        void loadProgram(const std::vector<Instruction>& instructions);

        void step();

        void run();

        void printState() const;
};

#endif