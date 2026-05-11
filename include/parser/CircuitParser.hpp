#ifndef CIRCUIT_PARSER_HPP
#define CIRCUIT_PARSER_HPP

#include <string>

#include "Circuit.hpp"

class CircuitParser {
public:
    static Circuit parseFromFile(
        const std::string& filepath
    );
};

#endif