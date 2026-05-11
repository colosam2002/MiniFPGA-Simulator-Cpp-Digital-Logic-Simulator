#include <iostream>

#include "parser/CircuitParser.hpp"
#include "subcircuits/BasicALU.hpp"

void runOperation(
    BasicALU& alu,
    ALUOperation operation,
    const std::string& operationName,
    Bus& resultBus
) {

    alu.execute(operation);

    std::cout
        << operationName
        << ":" << std::endl;

    resultBus.print();

    std::cout << std::endl;
}

int main(int argc, char* argv[]) {

    if (argc < 2) {

        std::cout
            << "Usage: ./minifpga <file.json>"
            << std::endl;

        return 1;
    }

    try {

        Circuit circuit =
            CircuitParser::parseFromFile(
                argv[1]
            );

        Bus& busA =
            circuit.getBus("BUS_A");

        Bus& busB =
            circuit.getBus("BUS_B");

        Bus& resultBus =
            circuit.getBus("RESULT");

        std::cout
            << "Inputs:"
            << std::endl;

        busA.print();
        busB.print();

        std::cout << std::endl;

        BasicALU alu(
            busA,
            busB,
            resultBus
        );

        runOperation(
            alu,
            ALUOperation::ADD,
            "ADD",
            resultBus
        );

        runOperation(
            alu,
            ALUOperation::AND,
            "AND",
            resultBus
        );

        runOperation(
            alu,
            ALUOperation::OR,
            "OR",
            resultBus
        );

        runOperation(
            alu,
            ALUOperation::XOR,
            "XOR",
            resultBus
        );
    }

    catch (const std::exception& error) {

        std::cerr
            << "Error: "
            << error.what()
            << std::endl;

        return 1;
    }

    return 0;
}