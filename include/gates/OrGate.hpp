#ifndef OR_GATE_HPP
#define OR_GATE_HPP

#include "Component.hpp"
#include "Signal.hpp"

class OrGate : public Component {
private:
    Signal& inputA;
    Signal& inputB;
    Signal& output;

public:
    OrGate(
        const std::string& name,
        Signal& a,
        Signal& b,
        Signal& out
    );

    void evaluate() override;
};

#endif