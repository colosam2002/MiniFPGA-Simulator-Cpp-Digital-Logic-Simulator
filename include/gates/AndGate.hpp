#ifndef AND_GATE_HPP
#define AND_GATE_HPP

#include "Component.hpp"
#include "Signal.hpp"

class AndGate : public Component {
private:
    Signal& inputA;
    Signal& inputB;
    Signal& output;

public:
    AndGate(
        const std::string& name,
        Signal& a,
        Signal& b,
        Signal& out
    );

    void evaluate() override;
};

#endif