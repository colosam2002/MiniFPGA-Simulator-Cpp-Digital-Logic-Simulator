#include <iostream>
#include <string>

#include "parser/CircuitParser.hpp"

void printUsage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "  ./minifpga <circuit.json>" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }

    const std::string filepath = argv[1];

    try {
        Circuit circuit =
            CircuitParser::parseFromFile(filepath);

        std::cout << "Loaded circuit: "
                  << filepath
                  << std::endl;

        std::cout << "\nInitial signals:" << std::endl;
        circuit.printSignals();

        circuit.evaluate();

        std::cout << "\nAfter evaluation:" << std::endl;
        circuit.printSignals();
    }
    catch (const std::exception& error) {
        std::cerr << "Error: "
                  << error.what()
                  << std::endl;

        return 1;
    }

    return 0;
}