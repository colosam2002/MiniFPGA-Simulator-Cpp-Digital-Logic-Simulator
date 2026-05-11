#include "subcircuits/FullAdder.hpp"

#include <memory>

#include "gates/AndGate.hpp"
#include "gates/OrGate.hpp"
#include "subcircuits/HalfAdder.hpp"

FullAdder::FullAdder(
    Circuit& circuit,
    const std::string& name,
    Signal& a,
    Signal& b,
    Signal& carryIn,
    Signal& sum,
    Signal& carryOut
) {
    Signal& partialSum =
        circuit.createSignal(name + "_PARTIAL_SUM");

    Signal& carry1 =
        circuit.createSignal(name + "_CARRY1");

    Signal& carry2 =
        circuit.createSignal(name + "_CARRY2");

    HalfAdder halfAdder1(
        circuit,
        name + "_HA1",
        a,
        b,
        partialSum,
        carry1
    );

    HalfAdder halfAdder2(
        circuit,
        name + "_HA2",
        partialSum,
        carryIn,
        sum,
        carry2
    );

    circuit.addComponent(
        std::make_unique<OrGate>(
            name + "_OR",
            carry1,
            carry2,
            carryOut
        )
    );
}