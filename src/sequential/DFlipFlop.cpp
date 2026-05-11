#include "sequential/DFlipFlop.hpp"

DFlipFlop::DFlipFlop(Signal& d, Signal& q, Clock& clk) : inputD(d), outputQ(q), clock(clk), storedState(false) {
    outputQ.setValue(false);
}

void DFlipFlop::update() {

    if (clock.isRisingEdge()) {

        storedState = inputD.getValue();

        outputQ.setValue(storedState);
    }
}

bool DFlipFlop::getStoredState() const {
    return storedState;
}