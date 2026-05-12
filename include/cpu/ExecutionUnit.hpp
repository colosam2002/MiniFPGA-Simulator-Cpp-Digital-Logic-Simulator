#ifndef EXECUTION_UNIT_HPP
#define EXECUTION_UNIT_HPP

#include "cpu/Instruction.hpp"
#include "cpu/CPUFlags.hpp"
#include "cpu/ExecutionResult.hpp"

#include "memory/RegisterFile.hpp"

class ExecutionUnit {
    private:
        RegisterFile& registerFile;

        CPUFlags& flags;

    public:
        ExecutionUnit(RegisterFile& regFile, CPUFlags& cpuFlags);

        ExecutionResult execute(const Instruction& instruction);
};

#endif