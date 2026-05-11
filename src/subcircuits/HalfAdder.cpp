#include "subcircuits/HalfAdder.hpp"

#include <memory>

#include "gates/AndGate.hpp"
#include "gates/XorGate.hpp"

HalfAdder::HalfAdder(
    Circuit& circuit,
    const std::string& name,
    Signal& a,
    Signal& b,
    Signal& sum,
    Signal& carry
) {
    circuit.addComponent(
        std::make_unique<XorGate>(
            name + "_XOR",
            a,
            b,
            sum
        )
    );

    circuit.addComponent(
        std::make_unique<AndGate>(
            name + "_AND",
            a,
            b,
            carry
        )
    );
}