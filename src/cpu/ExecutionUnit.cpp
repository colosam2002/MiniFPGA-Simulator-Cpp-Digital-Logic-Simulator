#include "cpu/ExecutionUnit.hpp"

ExecutionUnit::ExecutionUnit(RegisterFile& regFile) : registerFile(regFile){}

void ExecutionUnit::execute(const Instruction& instruction) {

    switch (instruction.opcode) {

        case Opcode::LOAD:

            registerFile.writeRegister(instruction.destination, instruction.immediate);

            break;

        case Opcode::MOV:

            registerFile.writeRegister(instruction.destination,registerFile.readRegister(instruction.source1));

            break;

        case Opcode::ADD:

            registerFile.writeRegister(instruction.destination,
                registerFile.readRegister(instruction.source1)
                +
                registerFile.readRegister(instruction.source2)
            );

            break;
    }
}