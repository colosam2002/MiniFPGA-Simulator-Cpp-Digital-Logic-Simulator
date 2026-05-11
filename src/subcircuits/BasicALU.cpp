#include "subcircuits/BasicALU.hpp"

#include <stdexcept>

BasicALU::BasicALU(
    Bus& a,
    Bus& b,
    Bus& result
)
    : inputA(a),
      inputB(b),
      resultBus(result)
{
    if (
        inputA.getWidth() != inputB.getWidth() ||
        inputA.getWidth() != resultBus.getWidth()
    ) {
        throw std::runtime_error(
            "ALU bus widths must match"
        );
    }
}

void BasicALU::execute(
    ALUOperation operation
) {

    unsigned int a =
        inputA.toInteger();

    unsigned int b =
        inputB.toInteger();

    unsigned int result = 0;

    switch (operation) {

        case ALUOperation::ADD:
            result = a + b;
            break;

        case ALUOperation::AND:
            result = a & b;
            break;

        case ALUOperation::OR:
            result = a | b;
            break;

        case ALUOperation::XOR:
            result = a ^ b;
            break;

        default:
            throw std::runtime_error(
                "Unknown ALU operation"
            );
    }

    resultBus.setValueFromInteger(result);
}