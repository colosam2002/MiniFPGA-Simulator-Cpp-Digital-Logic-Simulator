#include <iostream>
#include <string>

#include "parser/CircuitParser.hpp"

#include "cpu/ProgramLoader.hpp"
#include "cpu/TinyCPU.hpp"

bool endsWith(const std::string& text, const std::string& suffix) {
    if (suffix.size() > text.size()) {
        return false;
    }

    return text.compare(
        text.size() - suffix.size(),
        suffix.size(),
        suffix
    ) == 0;
}

void printUsage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "  ./minifpga <file.json>" << std::endl;
    std::cout << "  ./minifpga <file.asm>" << std::endl;
}

void runJsonCircuit(const std::string& filepath) {
    Circuit circuit =
        CircuitParser::parseFromFile(filepath);

    std::cout
        << "Loaded logic circuit: "
        << filepath
        << std::endl;

    std::cout << std::endl;

    std::cout << "Initial signals:" << std::endl;
    circuit.printSignals();

    std::cout << std::endl;

    std::cout << "Initial buses:" << std::endl;
    circuit.printBuses();

    circuit.evaluate();

    std::cout << std::endl;

    std::cout << "After evaluation:" << std::endl;
    circuit.printSignals();

    std::cout << std::endl;

    circuit.printBuses();
}

void runAssemblyProgram(const std::string& filepath) {
    std::cout
        << "Loaded assembly program: "
        << filepath
        << std::endl;

    std::cout << std::endl;

    TinyCPU cpu;

    std::vector<Instruction> program = ProgramLoader::loadProgram(filepath);

    cpu.loadProgram(program);

    std::cout << std::endl;
    std::cout << "Starting TinyCPU execution..." << std::endl;
    std::cout << std::endl;

    cpu.run();

    cpu.printState();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }

    const std::string filepath = argv[1];

    try {
        if (endsWith(filepath, ".json")) {
            runJsonCircuit(filepath);
        }
        else if (endsWith(filepath, ".asm")) {
            runAssemblyProgram(filepath);
        }
        else {
            std::cerr
                << "Unsupported file type: "
                << filepath
                << std::endl;

            printUsage();

            return 1;
        }
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