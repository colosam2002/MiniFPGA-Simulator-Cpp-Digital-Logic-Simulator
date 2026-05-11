#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <memory>
#include <vector>

#include "core/Bus.hpp"
#include "core/Clock.hpp"
#include "sequential/DFlipFlop.hpp"
#include "sequential/SequentialComponent.hpp"

class Register : public SequentialComponent {
    private:
        Bus& inputBus;

        Bus& outputBus;

        Clock& clock;

        std::vector<std::unique_ptr<DFlipFlop>> flipFlops;

        Signal& loadSignal;

    public:
        Register(Bus& input, Bus& output, Clock& clk, Signal& load);

        void update();
};

#endif