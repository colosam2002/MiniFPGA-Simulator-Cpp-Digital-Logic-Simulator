#ifndef FULL_ADDER_HPP
#define FULL_ADDER_HPP

#include "Circuit.hpp"
#include "Signal.hpp"

class FullAdder {
public:
    FullAdder(
        Circuit& circuit,
        const std::string& name,
        Signal& a,
        Signal& b,
        Signal& carryIn,
        Signal& sum,
        Signal& carryOut
    );
};

#endif