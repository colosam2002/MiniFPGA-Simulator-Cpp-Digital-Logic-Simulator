#include <iostream>

#include "core/Bus.hpp"
#include "core/SimulationEngine.hpp"

#include "sequential/BinaryCounter.hpp"

int main() {

    SimulationEngine engine;

    Bus counterBus("COUNTER", 4);

    BinaryCounter counter(
        counterBus,
        engine.getClock()
    );

    engine.registerComponent(counter);

    std::cout
        << "Sequential simulation started"
        << std::endl;

    std::cout << std::endl;

    for (int cycle = 0; cycle < 20; ++cycle) {

        engine.tick();

        std::cout
            << "Cycle "
            << engine.getTickCount();

        std::cout
            << " | CLK="
            << engine.getClock().getState();

        if (
            engine.getClock().isRisingEdge()
        ) {

            std::cout
                << " | Rising Edge";
        }

        if (
            engine.getClock().isFallingEdge()
        ) {

            std::cout
                << " | Falling Edge";
        }

        std::cout
            << std::endl;

        counterBus.print();

        std::cout
            << std::endl;
    }

    return 0;
}