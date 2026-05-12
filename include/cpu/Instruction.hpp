#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

enum class Opcode {LOAD, MOV, ADD};

struct Instruction {
    Opcode opcode;

    unsigned int destination;

    unsigned int source1;

    unsigned int source2;

    unsigned int immediate;
};

#endif