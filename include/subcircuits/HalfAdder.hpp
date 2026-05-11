#ifndef HALF_ADDER_HPP
#define HALF_ADDER_HPP

#include "Circuit.hpp"
#include "Signal.hpp"

class HalfAdder {
public:
    HalfAdder(
        Circuit& circuit,
        const std::string& name,
        Signal& a,
        Signal& b,
        Signal& sum,
        Signal& carry
    );
};

#endif