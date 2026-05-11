#include "gates/NotGate.hpp"

NotGate::NotGate(
    const std::string& name,
    Signal& in,
    Signal& out
)
    : Component(name), input(in), output(out) {}

void NotGate::evaluate() {
    output.setValue(!input.getValue());
}