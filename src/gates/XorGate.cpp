#include "gates/XorGate.hpp"

XorGate::XorGate(
    const std::string& name,
    Signal& a,
    Signal& b,
    Signal& out
)
    : Component(name), inputA(a), inputB(b), output(out) {}

void XorGate::evaluate() {
    output.setValue(inputA.getValue() != inputB.getValue());
}