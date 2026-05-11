#include "gates/AndGate.hpp"

AndGate::AndGate(
    const std::string& name,
    Signal& a,
    Signal& b,
    Signal& out
)
    : Component(name), inputA(a), inputB(b), output(out) {}

void AndGate::evaluate() {
    output.setValue(inputA.getValue() && inputB.getValue());
}