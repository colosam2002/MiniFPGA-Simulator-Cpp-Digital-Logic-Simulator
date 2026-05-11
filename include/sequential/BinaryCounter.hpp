#ifndef BINARY_COUNTER_HPP
#define BINARY_COUNTER_HPP

#include "core/Bus.hpp"
#include "core/Clock.hpp"
#include "sequential/SequentialComponent.hpp"

class BinaryCounter : public SequentialComponent {
    private:
        Bus& outputBus;

        Clock& clock;

        unsigned int counterValue;

    public:
        BinaryCounter(Bus& output, Clock& clk);

        void update();

        unsigned int getValue() const;
};

#endif