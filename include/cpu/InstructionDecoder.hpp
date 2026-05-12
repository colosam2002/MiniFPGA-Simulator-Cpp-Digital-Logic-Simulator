#ifndef INSTRUCTION_DECODER_HPP
#define INSTRUCTION_DECODER_HPP

#include <string>

#include "cpu/Instruction.hpp"

class InstructionDecoder {
    public:
        static Instruction decode(
            const std::string& line
        );
};

#endif