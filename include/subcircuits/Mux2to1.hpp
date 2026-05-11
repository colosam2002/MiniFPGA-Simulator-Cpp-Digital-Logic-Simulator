#ifndef MUX2TO1_HPP
#define MUX2TO1_HPP

#include "core/Bus.hpp"

class Mux2to1 {
private:
    Bus& inputA;
    Bus& inputB;

    Bus& outputBus;

public:
    Mux2to1(
        Bus& a,
        Bus& b,
        Bus& output
    );

    void select(bool selector);
};

#endif