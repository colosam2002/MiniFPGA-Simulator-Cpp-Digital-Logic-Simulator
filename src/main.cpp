#include <iostream>
#include <vector>

#include "cpu/TinyCPU.hpp"

void printBanner() {

    std::cout
        << "MiniFPGA TinyCPU"
        << std::endl;

    std::cout
        << "================="
        << std::endl;

    std::cout << std::endl;
}

int main() {

    printBanner();

    TinyCPU cpu;

    std::vector<Instruction> program = {

        // LOAD R1, 3

        {
            Opcode::LOAD,
            1,
            0,
            0,
            3
        },

        // LOAD R2, 1

        {
            Opcode::LOAD,
            2,
            0,
            0,
            1
        },

        // LOOP START

        // SUB R1, R1, R2

        {
            Opcode::SUB,
            1,
            1,
            2,
            0
        },

        // CMP R1, R0

        {
            Opcode::CMP,
            0,
            1,
            0,
            0
        },

        // JNE 2

        {
            Opcode::JNE,
            0,
            0,
            0,
            2
        },

        // LOAD R3, 42

        {
            Opcode::LOAD,
            3,
            0,
            0,
            42
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