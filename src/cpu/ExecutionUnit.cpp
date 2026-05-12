#include "cpu/ExecutionUnit.hpp"

ExecutionUnit::ExecutionUnit(RegisterFile& regFile, CPUFlags& cpuFlags) : registerFile(regFile), flags(cpuFlags){}

ExecutionResult ExecutionUnit::execute(const Instruction& instruction) {

    ExecutionResult result {
        false,
        0
    };

    switch (instruction.opcode) {

        case Opcode::LOAD:

            registerFile.writeRegister(instruction.destination, instruction.immediate);

            break;

        case Opcode::MOV:

            registerFile.writeRegister(instruction.destination,registerFile.readRegister(instruction.source1));

            break;

        case Opcode::ADD: {

            unsigned int result_add =

                registerFile.readRegister(instruction.source1)
                +
                registerFile.readRegister(instruction.source2);

            registerFile.writeRegister(instruction.destination, result_add);

            flags.updateZeroFlag(result_add);

            break;
        }

        case Opcode::SUB: {

            unsigned int resultSub =
                registerFile.readRegister(instruction.source1)
                -
                registerFile.readRegister(instruction.source2);

            registerFile.writeRegister(instruction.destination, resultSub);

            flags.updateZeroFlag(resultSub);

            break;
        }

        case Opcode::CMP: {

            unsigned int value1 = registerFile.readRegister(instruction.source1);

            unsigned int value2 = registerFile.readRegister(instruction.source2);

            unsigned int result_cmp = value1 - value2;

            flags.updateZeroFlag(result_cmp);

            break;
        }

        case Opcode::JMP: {

            result.jumpRequested = true;

            result.jumpAddress = instruction.immediate;

            break;
        }

        case Opcode::JE: {

            if (flags.getZeroFlag()) {

                result.jumpRequested = true;

                result.jumpAddress = instruction.immediate;
            }

            break;
        }

        case Opcode::JNE: {

            if (!flags.getZeroFlag()) {

                result.jumpRequested = true;

                result.jumpAddress = instruction.immediate;
            }

            break;
        }

       
    }

    return result;
}