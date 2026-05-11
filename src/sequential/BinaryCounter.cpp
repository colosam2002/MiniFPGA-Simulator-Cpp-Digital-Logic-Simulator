#include "sequential/BinaryCounter.hpp"

BinaryCounter::BinaryCounter(Bus& output, Clock& clk) : outputBus(output), clock(clk), counterValue(0) {
    outputBus.setValueFromInteger(0);
}

void BinaryCounter::update() {

    if (clock.isRisingEdge()) {

        ++counterValue;

        unsigned int maxValue = (1 << outputBus.getWidth());

        counterValue %= maxValue;

        outputBus.setValueFromInteger(counterValue);
    }
}

unsigned int BinaryCounter::getValue() const {
    return counterValue;
}