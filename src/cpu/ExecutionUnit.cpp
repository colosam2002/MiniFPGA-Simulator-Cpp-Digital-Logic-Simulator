#include <iostream>

#include "cpu/ExecutionUnit.hpp"

ExecutionUnit::ExecutionUnit(RegisterFile& regFile, CPUFlags& cpuFlags, StackMemory& stack) : registerFile(regFile), flags(cpuFlags), stackMemory(stack){}

ExecutionResult ExecutionUnit::execute(const Instruction& instruction, unsigned int currentPC) {

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

        case Opcode::PUSH: {

            unsigned int value = registerFile.readRegister(instruction.source1);

            stackMemory.push(value);

            std::cout
                << "Pushing value "
                << value
                << " onto stack"
                << std::endl;

            break;
        }

        case Opcode::POP: {

            unsigned int value = stackMemory.pop();

            registerFile.writeRegister(instruction.destination, value);

            std::cout
                << "Popping value "
                << value
                << " from stack"
                << std::endl;

            break;
        }

        case Opcode::CALL: {

            unsigned int returnAddress = currentPC + 1;

            stackMemory.push(returnAddress);

            result.jumpRequested = true;

            result.jumpAddress = instruction.immediate;

            std::cout
                << "Call depth increased"
                << std::endl;

            std::cout
                << "Saving return address: "
                << returnAddress
                << std::endl;

            std::cout
                << "Calling function at instruction "
                << instruction.immediate
                << std::endl;

            break;
        }

        case Opcode::RET: {

            unsigned int returnAddress = stackMemory.pop();

            std::cout
                << "Call depth decreased"
                << std::endl;

            std::cout
                << "Returning to instruction "
                << returnAddress
                << std::endl;
            
            std::cout
                << "Resuming execution"
                << std::endl;

            result.jumpRequested = true;

            result.jumpAddress = returnAddress;

            break;
        }

       
    }

    return result;
}