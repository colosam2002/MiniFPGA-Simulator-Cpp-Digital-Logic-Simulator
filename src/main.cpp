#include <iostream>
#include <vector>

#include "cpu/TinyCPU.hpp"

void printProgramInfo() {

    std::cout
        << "MiniFPGA TinyCPU Demo"
        << std::endl;

    std::cout
        << "====================="
        << std::endl;

    std::cout << std::endl;
}

int main() {

    printProgramInfo();

    TinyCPU cpu;

    std::vector<Instruction> program = {

        // LOAD R1, 15

        {
            Opcode::LOAD,
            1,
            0,
            0,
            15
        },

        // LOAD R2, 27

        {
            Opcode::LOAD,
            2,
            0,
            0,
            27
        },

        // ADD R3, R1, R2

        {
            Opcode::ADD,
            3,
            1,
            2,
            0
        },

        // MOV R4, R3

        {
            Opcode::MOV,
            4,
            3,
            0,
            0
        }
    };

    std::cout
        << "Loading program..."
        << std::endl;

    std::cout << std::endl;

    cpu.loadProgram(program);

    std::cout
        << "Starting execution..."
        << std::endl;

    std::cout << std::endl;

    cpu.run();

    cpu.printState();

    return 0;
}