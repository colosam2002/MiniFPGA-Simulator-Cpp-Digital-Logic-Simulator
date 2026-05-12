#ifndef EXECUTION_UNIT_HPP
#define EXECUTION_UNIT_HPP

#include "cpu/Instruction.hpp"
#include "cpu/CPUFlags.hpp"
#include "cpu/ExecutionResult.hpp"

#include "memory/RegisterFile.hpp"
#include "memory/StackMemory.hpp"

class ExecutionUnit {
    private:
        RegisterFile& registerFile;

        CPUFlags& flags;

        StackMemory& stackMemory;

    public:
        ExecutionUnit(RegisterFile& regFile, CPUFlags& cpuFlags, StackMemory& stack);

        ExecutionResult execute(const Instruction& instruction, unsigned int currentPC);
};

#endif