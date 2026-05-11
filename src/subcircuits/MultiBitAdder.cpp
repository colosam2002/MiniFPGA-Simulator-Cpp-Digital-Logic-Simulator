#include "subcircuits/MultiBitAdder.hpp"

#include <memory>
#include <stdexcept>
#include <vector>

#include "subcircuits/FullAdder.hpp"

MultiBitAdder::MultiBitAdder(
    Circuit& circuit,
    const std::string& name,
    Bus& inputA,
    Bus& inputB,
    Bus& sumBus,
    Signal& carryOut
) {

    if (
        inputA.getWidth() != inputB.getWidth() ||
        inputA.getWidth() != sumBus.getWidth()
    ) {
        throw std::runtime_error(
            "Bus widths must match"
        );
    }

    const int width = inputA.getWidth();

    std::vector<Signal*> carrySignals;

    // Initial carry = 0

    Signal& initialCarry =
        circuit.createSignal(
            name + "_CARRY_0",
            false
        );

    carrySignals.push_back(&initialCarry);

    // Intermediate carries

    for (int i = 1; i < width; ++i) {

        Signal& carry =
            circuit.createSignal(
                name + "_CARRY_" + std::to_string(i),
                false
            );

        carrySignals.push_back(&carry);
    }

    // Create Full Adders

    for (int i = 0; i < width; ++i) {

        Signal& currentCarryIn =
            *carrySignals[i];

        Signal& currentCarryOut =
            (i == width - 1)
            ? carryOut
            : *carrySignals[i + 1];

        FullAdder fullAdder(
            circuit,
            name + "_FA_" + std::to_string(i),

            inputA.getSignal(i),
            inputB.getSignal(i),

            currentCarryIn,

            sumBus.getSignal(i),

            currentCarryOut
        );
    }
}