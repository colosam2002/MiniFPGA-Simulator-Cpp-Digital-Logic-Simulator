#include "cpu/ProgramLoader.hpp"

#include <fstream>
#include <iostream>

#include "cpu/InstructionDecoder.hpp"

std::vector<Instruction>
ProgramLoader::loadProgram(const std::string& filename) {

    std::ifstream file(filename);

    std::vector<Instruction> program;

        if (!file.is_open()) {

        std::cout
            << "Failed to open file: "
            << filename
            << std::endl;

        return program;
    }

    std::string line;

    while (std::getline(file, line)) {

        if (line.empty() || line.find_first_not_of(' ') == std::string::npos) {
            continue;
        }
        if (line[0] == ';') {
            continue;
        }
        std::cout
            << "Loading: "
            << line
            << std::endl;

        program.push_back(
            InstructionDecoder::decode(line)
        );
    }

    file.close();

    std::cout
        << std::endl;

    std::cout
        << "Program loaded successfully"
        << std::endl;

    std::cout
        << "Instruction count: "
        << program.size()
        << std::endl;

    std::cout
        << std::endl;

    return program;
}