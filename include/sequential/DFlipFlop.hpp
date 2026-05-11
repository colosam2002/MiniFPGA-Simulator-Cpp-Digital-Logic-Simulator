#ifndef D_FLIP_FLOP_HPP
#define D_FLIP_FLOP_HPP

#include "Signal.hpp"
#include "core/Clock.hpp"
#include "sequential/SequentialComponent.hpp"

class DFlipFlop : public SequentialComponent {
    private:
        Signal& inputD;

        Signal& outputQ;

        Clock& clock;

        bool storedState;

    public:
        DFlipFlop(Signal& d, Signal& q, Clock& clk);

        void update();

        bool getStoredState() const;
};

#endif