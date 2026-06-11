#ifndef DATAPATH_HPP
#define DATAPATH_HPP

#include "cpu/SimpleALU.hpp"
#include "cpu/ALUOperation.hpp"

class Datapath {

private:

    unsigned int operandA;

    unsigned int operandB;

    unsigned int executionResult;

    SimpleALU alu;

public:

    Datapath();

    unsigned int getOperandA() const;

    unsigned int getOperandB() const;

    unsigned int getExecutionResult() const;

    void setOperandA(
        unsigned int value
    );

    void setOperandB(
        unsigned int value
    );

    void setExecutionResult(
        unsigned int value
    );

    void reset();

    void executeOperation(
        ALUOperation operation
    );

    void printState() const;
};

#endif