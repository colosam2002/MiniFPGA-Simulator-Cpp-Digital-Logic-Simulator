#include <iostream>
#include "cpu/Datapath.hpp"

Datapath::Datapath()
    :
      operandA(0),
      operandB(0),
      executionResult(0),
      alu()
{
}

unsigned int Datapath::getOperandA() const {
    return operandA;
}

unsigned int Datapath::getOperandB() const {
    return operandB;
}

unsigned int Datapath::getExecutionResult() const {
    return executionResult;
}

void Datapath::setOperandA(
    unsigned int value
) {
    operandA = value;
}

void Datapath::setOperandB(
    unsigned int value
) {
    operandB = value;
}

void Datapath::setExecutionResult(
    unsigned int value
) {
    executionResult = value;
}

void Datapath::reset() {

    operandA = 0;

    operandB = 0;

    executionResult = 0;
}

void Datapath::executeOperation(
    ALUOperation operation
) {

    switch (operation) {

        case ALUOperation::ADD:

            executionResult =

                alu.add(
                    operandA,
                    operandB
                );

            break;

        case ALUOperation::SUB:

            executionResult =

                alu.sub(
                    operandA,
                    operandB
                );

            break;

        case ALUOperation::MOV:

            executionResult =

                alu.mov(
                    operandA
                );

            break;

        default:

            break;
    }
}

void Datapath::printState() const {

        std::cout
            << "Operand A: "
            << operandA
            << std::endl;

        std::cout
            << "Operand B: "
            << operandB
            << std::endl;

        std::cout
            << "Execution Result: "
            << executionResult
            << std::endl;
    }