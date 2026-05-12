#include "cpu/Instruction.hpp"

const char* opcodeToString(Opcode opcode) {

    switch (opcode) {

        case Opcode::LOAD:
            return "LOAD";

        case Opcode::MOV:
            return "MOV";

        case Opcode::ADD:
            return "ADD";

        case Opcode::SUB:
            return "SUB";

        case Opcode::CMP:
            return "CMP";

        case Opcode::JMP:
            return "JMP";

        case Opcode::JE:
            return "JE";

        case Opcode::JNE:
            return "JNE";

        case Opcode::PUSH:
            return "PUSH";

        case Opcode::POP:
            return "POP";

        case Opcode::CALL:
            return "CALL";

        case Opcode::RET:
            return "RET";

        default:
            return "UNKNOWN";
    }
}