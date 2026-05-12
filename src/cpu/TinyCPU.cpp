#include "cpu/TinyCPU.hpp"

#include <iostream>

TinyCPU::TinyCPU() : registerFile(8, 8), executionUnit(registerFile), programCounter(0) {}

void TinyCPU::loadProgram(const std::vector<Instruction>& instructions) {
    program = instructions;
    programCounter = 0;
}

void TinyCPU::step() {

    if (programCounter >= program.size()) {
        std::cout << "Program finished" << std::endl;
        return;
    }

    const Instruction& instruction = program[programCounter];

    std::cout << "Executing instruction " << programCounter << std::endl;

    executionUnit.execute(instruction);

    ++programCounter;
}

void TinyCPU::run() {

    while (programCounter < program.size()) {
        step();
    }
}

void TinyCPU::printState() const {

    std::cout << std::endl;

    std::cout << "CPU State" << std::endl;

    std::cout << "Program Counter = " << programCounter << std::endl;

    std::cout << std::endl;

    registerFile.printRegisters();

    std::cout << std::endl;
}