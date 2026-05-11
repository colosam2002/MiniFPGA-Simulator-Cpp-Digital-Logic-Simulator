#ifndef BASIC_ALU_HPP
#define BASIC_ALU_HPP

#include "Circuit.hpp"
#include "core/Bus.hpp"

enum class ALUOperation {
    ADD = 0,
    AND = 1,
    OR  = 2,
    XOR = 3
};

class BasicALU {
private:
    Bus& inputA;
    Bus& inputB;
    Bus& resultBus;

public:
    BasicALU(
        Bus& a,
        Bus& b,
        Bus& result
    );

    void execute(ALUOperation operation);
};

#endif