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

    std::cout
        << "Stack + Function Execution Demo"
        << std::endl;

    std::cout << std::endl;
}

int main() {

    printBanner();

    TinyCPU cpu;

    std::vector<Instruction> program = {

        // =========================
        // MAIN PROGRAM
        // =========================

        // LOAD R1, 20

        {
            Opcode::LOAD,
            1,
            0,
            0,
            20
        },

        // LOAD R2, 22

        {
            Opcode::LOAD,
            2,
            0,
            0,
            22
        },

        // CALL FUNCTION

        {
            Opcode::CALL,
            0,
            0,
            0,
            6
        },

        // LOAD R5, 99

        {
            Opcode::LOAD,
            5,
            0,
            0,
            99
        },

        // END PROGRAM

        {
            Opcode::JMP,
            0,
            0,
            0,
            11
        },

        // UNUSED

        {
            Opcode::LOAD,
            0,
            0,
            0,
            0
        },

        // =========================
        // FUNCTION
        // =========================

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
        },

        // PUSH R4

        {
            Opcode::PUSH,
            0,
            4,
            0,
            0
        },

        // POP R6

        {
            Opcode::POP,
            6,
            0,
            0,
            0
        },

        // RET

        {
            Opcode::RET,
            0,
            0,
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