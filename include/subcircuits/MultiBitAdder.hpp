#ifndef MULTI_BIT_ADDER_HPP
#define MULTI_BIT_ADDER_HPP

#include <vector>

#include "Circuit.hpp"
#include "core/Bus.hpp"

class MultiBitAdder {
public:
    MultiBitAdder(
        Circuit& circuit,
        const std::string& name,
        Bus& inputA,
        Bus& inputB,
        Bus& sumBus,
        Signal& carryOut
    );
};

#endif