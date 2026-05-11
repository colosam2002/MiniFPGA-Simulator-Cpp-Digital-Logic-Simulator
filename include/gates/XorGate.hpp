#ifndef XOR_GATE_HPP
#define XOR_GATE_HPP

#include "Component.hpp"
#include "Signal.hpp"

class XorGate : public Component {
private:
    Signal& inputA;
    Signal& inputB;
    Signal& output;

public:
    XorGate(
        const std::string& name,
        Signal& a,
        Signal& b,
        Signal& out
    );

    void evaluate() override;
};

#endif