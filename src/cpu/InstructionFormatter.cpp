#include "cpu/InstructionFormatter.hpp"

std::string InstructionFormatter::format(
    const Instruction& instruction
) {

    switch (instruction.opcode) {

        case Opcode::LOAD:

            return
                "LOAD R"
                +
                std::to_string(
                    instruction.destination
                )
                +
                " "
                +
                std::to_string(
                    instruction.immediate
                );

        case Opcode::MOV:

            return
                "MOV R"
                +
                std::to_string(
                    instruction.destination
                )
                +
                " R"
                +
                std::to_string(
                    instruction.source1
                );

        case Opcode::ADD:

            return
                "ADD R"
                +
                std::to_string(
                    instruction.destination
                )
                +
                " R"
                +
                std::to_string(
                    instruction.source1
                )
                +
                " R"
                +
                std::to_string(
                    instruction.source2
                );

        case Opcode::SUB:

            return
                "SUB R"
                +
                std::to_string(
                    instruction.destination
                )
                +
                " R"
                +
                std::to_string(
                    instruction.source1
                )
                +
                " R"
                +
                std::to_string(
                    instruction.source2
                );

        case Opcode::PUSH:

            return
                "PUSH R"
                +
                std::to_string(
                    instruction.source1
                );

        case Opcode::POP:

            return
                "POP R"
                +
                std::to_string(
                    instruction.destination
                );

        case Opcode::CALL:

            return
                "CALL "
                +
                std::to_string(
                    instruction.immediate
                );

        case Opcode::RET:

            return "RET";

        case Opcode::JMP:

            return
                "JMP "
                +
                std::to_string(
                    instruction.immediate
                );

        default:

            return "UNKNOWN";
    }
}