#include "gates/OrGate.hpp"

OrGate::OrGate(
    const std::string& name,
    Signal& a,
    Signal& b,
    Signal& out
)
    : Component(name), inputA(a), inputB(b), output(out) {}

void OrGate::evaluate() {
    output.setValue(inputA.getValue() || inputB.getValue());
}