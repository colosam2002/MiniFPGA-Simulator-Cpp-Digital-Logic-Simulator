#ifndef ALU_OPERATION_HPP
#define ALU_OPERATION_HPP

enum class ALUOperation {

    NONE,

    ADD,

    SUB,

    MOV
};

const char* aluOperationToString(
    ALUOperation operation
);

#endif