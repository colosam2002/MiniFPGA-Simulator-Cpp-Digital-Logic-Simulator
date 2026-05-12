#ifndef PROGRAM_LOADER_HPP
#define PROGRAM_LOADER_HPP

#include <string>
#include <vector>

#include "cpu/Instruction.hpp"

class ProgramLoader {
    public:
        static std::vector<Instruction> loadProgram(
            const std::string& filename
        );
};

#endif