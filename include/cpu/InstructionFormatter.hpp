#ifndef INSTRUCTION_FORMATTER_HPP
#define INSTRUCTION_FORMATTER_HPP

#include <string>
#include <sstream>

#include "cpu/Instruction.hpp"

class InstructionFormatter {
    public:
        static std::string format(
            const Instruction& instruction
        );
};

#endif