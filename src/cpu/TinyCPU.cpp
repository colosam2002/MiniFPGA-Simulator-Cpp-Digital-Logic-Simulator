#include "cpu/TinyCPU.hpp"

#include <iostream>

TinyCPU::TinyCPU() : registerFile(8, 8), stackMemory(16), flags(), executionUnit(registerFile, flags, stackMemory), instructionMemory(), programCounter(0) {}

void TinyCPU::loadProgram(const std::vector<Instruction>& instructions) {
    instructionMemory.loadProgram(instructions);
    programCounter = 0;

    instructionMemory.printProgram();
}

void TinyCPU::step() {

    if (programCounter >= instructionMemory.getProgramSize()) {
        std::cout << "Program finished" << std::endl;
        return;
    }

    Instruction instruction = instructionMemory.fetch(programCounter);

    std::cout << "--------------------------------" << std::endl;

    std::cout
        << "Program Counter = "
        << programCounter
        << std::endl;

    std::cout
        << "Executing: "
        << opcodeToString(instruction.opcode)
        << std::endl;

    std::cout
        << "--------------------------------"
        << std::endl;

    ExecutionResult result = executionUnit.execute(instruction, programCounter);

    registerFile.printRegisters();

    std::cout << std::endl;

    flags.printFlags();

    std::cout << std::endl;

    stackMemory.printStack();

    std::cout << std::endl;

    std::cout
        << "SP = "
        << stackMemory.getStackPointer()
        << std::endl;

    std::cout << std::endl;

    if (result.jumpRequested) {
        std::cout
        << "Jumping to instruction "
        << result.jumpAddress
        << std::endl;
        programCounter = result.jumpAddress;
    }
    else {
        ++programCounter;
    }
}

void TinyCPU::run() {

    while (programCounter < instructionMemory.getProgramSize()) {
        step();
    }
}

void TinyCPU::printState() const {

    std::cout
        << std::endl;

    std::cout
        << "================================"
        << std::endl;

    std::cout
        << "FINAL CPU + STACK STATE"
        << std::endl;

    std::cout
        << "================================"
        << std::endl;

    std::cout
        << "Program Counter = "
        << programCounter
        << std::endl;

    std::cout
        << "Program Size = "
        << instructionMemory.getProgramSize()
        << std::endl;

    std::cout
        << std::endl;

    registerFile.printRegisters();

    std::cout
        << std::endl;

    flags.printFlags();

    std::cout << std::endl;

    stackMemory.printStack();

    std::cout << std::endl;

    std::cout
        << "SP = "
        << stackMemory.getStackPointer()
        << std::endl;
    std::cout
        << std::endl;
}