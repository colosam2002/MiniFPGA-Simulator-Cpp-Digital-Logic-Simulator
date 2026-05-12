#include "cpu/InstructionDecoder.hpp"

#include <iostream>
#include <sstream>
#include <vector>

unsigned int parseRegister(const std::string& token) {

    return std::stoi(
        token.substr(1)
    );
}

Instruction InstructionDecoder::decode(const std::string& line) {

    std::stringstream stream(line);

    std::vector<std::string> tokens;

    std::string token;

    while (stream >> token) {

        tokens.push_back(token);
    }

        if (tokens[0] == "LOAD") {

            return {
                Opcode::LOAD,
                parseRegister(tokens[1]),
                0,
                0,
                static_cast<unsigned int>(
                    std::stoi(tokens[2])
                )
            };
        }

        if (tokens[0] == "ADD") {
            return {
                Opcode::ADD,
                parseRegister(tokens[1]),
                parseRegister(tokens[2]),
                parseRegister(tokens[3]),
                0
            };
        }

        if (tokens[0] == "MOV") {

            return {
                Opcode::MOV,
                parseRegister(tokens[1]),
                parseRegister(tokens[2]),
                0,
                0
            };
        }

        if (tokens[0] == "SUB") {

            return {
                Opcode::SUB,
                parseRegister(tokens[1]),
                parseRegister(tokens[2]),
                parseRegister(tokens[3]),
                0
            };
        }

        if (tokens[0] == "PUSH") {

            return {
                Opcode::PUSH,
                0,
                parseRegister(tokens[1]),
                0,
                0
            };
        }

        if (tokens[0] == "POP") {

            return {
                Opcode::POP,
                parseRegister(tokens[1]),
                0,
                0,
                0
            };
        }

        if (tokens[0] == "CALL") {

            return {
                Opcode::CALL,
                0,
                0,
                0,
                static_cast<unsigned int>(
                    std::stoi(tokens[1])
                )
            };
        }

        if (tokens[0] == "RET") {

            return {
                Opcode::RET,
                0,
                0,
                0,
                0
            };
        }

        if (tokens[0] == "JMP") {

            return {
                Opcode::JMP,
                0,
                0,
                0,
                static_cast<unsigned int>(
                    std::stoi(tokens[1])
                )
            };
        }

        if (tokens[0] == "JE") {
            return {
                Opcode::JE,
                0,
                0,
                0,
                static_cast<unsigned int>(std::stoi(tokens[1]))
            };
        }

        if (tokens[0] == "JNE") {
            return {
                Opcode::JNE,
                0,
                0,
                0,
                static_cast<unsigned int>(std::stoi(tokens[1]))
            };
        }

        if (tokens[0] == "CMP") {
            return {
                Opcode::CMP,
                0,
                parseRegister(tokens[1]),
                parseRegister(tokens[2]),
                0
            };
        }

        std::cout
            << "Unknown instruction: "
            << line
            << std::endl;

        return {
            Opcode::RET,
            0,
            0,
            0,
            0
        };
}
