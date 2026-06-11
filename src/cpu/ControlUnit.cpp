#include "cpu/ControlUnit.hpp"

ControlSignals ControlUnit::decode(
    const Instruction& instruction
) const {

    ControlSignals signals {

        false,
        false,
        false,
        false,
        ALUOperation::NONE
    };

    switch (instruction.opcode) {

        case Opcode::LOAD:

            signals.writesRegister = true;
            signals.usesImmediate = true;

            break;

        case Opcode::MOV:

            signals.writesRegister = true;

            signals.aluOperation =
                ALUOperation::MOV;

            break;

        case Opcode::ADD:

            signals.usesALU = true;

            signals.usesTwoOperands = true;

            signals.writesRegister = true;

            signals.aluOperation =
                ALUOperation::ADD;

            break;

        case Opcode::SUB:

            signals.usesALU = true;

            signals.usesTwoOperands = true;

            signals.writesRegister = true;

            signals.aluOperation =
                ALUOperation::SUB;

            break;


        default:

            break;
    }

    return signals;
}