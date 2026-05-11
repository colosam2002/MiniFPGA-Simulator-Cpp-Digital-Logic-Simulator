#include "sequential/Register.hpp"

#include <stdexcept>

Register::Register(Bus& input, Bus& output, Clock& clk, Signal& load) : inputBus(input), outputBus(output), clock(clk), loadSignal(load) {
   
    if (inputBus.getWidth() != outputBus.getWidth()) {
        throw std::runtime_error("Register bus widths must match");
    }

    const int width = inputBus.getWidth();

    for (int i = 0; i < width; ++i) {
        flipFlops.push_back(std::make_unique<DFlipFlop>(inputBus.getSignal(i), outputBus.getSignal(i), clock));
    }
}

void Register::update() {

    if (!loadSignal.getValue()) {
        return;
    }

    for (auto& flipFlop : flipFlops) {
        flipFlop->update();
    }
}