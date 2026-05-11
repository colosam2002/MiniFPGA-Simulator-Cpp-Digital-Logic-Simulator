#ifndef NOT_GATE_HPP
#define NOT_GATE_HPP

#include "Component.hpp"
#include "Signal.hpp"

class NotGate : public Component {
private:
    Signal& input;
    Signal& output;

public:
    NotGate(
        const std::string& name,
        Signal& in,
        Signal& out
    );

    void evaluate() override;
};

#endif