#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

enum class Opcode {LOAD, MOV, ADD, SUB, CMP, JMP, JE, JNE, PUSH, POP, CALL, RET};

struct Instruction {
    Opcode opcode;

    unsigned int destination;

    unsigned int source1;

    unsigned int source2;

    unsigned int immediate;
};

const char* opcodeToString(
    Opcode opcode
);

#endif