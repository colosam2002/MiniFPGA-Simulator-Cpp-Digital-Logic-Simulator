#ifndef EXECUTION_UNIT_HPP
#define EXECUTION_UNIT_HPP

#include "cpu/Instruction.hpp"

#include "memory/RegisterFile.hpp"

class ExecutionUnit {
    private:
        RegisterFile& registerFile;

    public:
        ExecutionUnit(RegisterFile& regFile);

        void execute(const Instruction& instruction);
};

#endif