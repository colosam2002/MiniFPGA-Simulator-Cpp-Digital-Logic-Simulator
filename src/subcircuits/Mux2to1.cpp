#include "subcircuits/Mux2to1.hpp"

#include <stdexcept>

Mux2to1::Mux2to1(
    Bus& a,
    Bus& b,
    Bus& output
)
    : inputA(a),
      inputB(b),
      outputBus(output)
{
    if (
        inputA.getWidth() != inputB.getWidth() ||
        inputA.getWidth() != outputBus.getWidth()
    ) {
        throw std::runtime_error(
            "MUX bus widths must match"
        );
    }
}

void Mux2to1::select(bool selector) {

    unsigned int selectedValue =
        selector
        ? inputB.toInteger()
        : inputA.toInteger();

    outputBus.setValueFromInteger(
        selectedValue
    );
}