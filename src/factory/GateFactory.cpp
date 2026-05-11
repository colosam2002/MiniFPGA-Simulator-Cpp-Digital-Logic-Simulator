#include "factory/GateFactory.hpp"

#include <memory>
#include <stdexcept>

#include "gates/AndGate.hpp"
#include "gates/NotGate.hpp"
#include "gates/OrGate.hpp"
#include "gates/XorGate.hpp"

std::unique_ptr<Component>
GateFactory::createBinaryGate(
    ComponentType type,
    const std::string& name,
    Signal& inputA,
    Signal& inputB,
    Signal& output
) {
    switch (type) {
        case ComponentType::AND:
            return std::make_unique<AndGate>(
                name,
                inputA,
                inputB,
                output
            );

        case ComponentType::OR:
            return std::make_unique<OrGate>(
                name,
                inputA,
                inputB,
                output
            );

        case ComponentType::XOR:
            return std::make_unique<XorGate>(
                name,
                inputA,
                inputB,
                output
            );

        default:
            throw std::runtime_error(
                "Invalid binary gate type"
            );
    }
}

std::unique_ptr<Component>
GateFactory::createUnaryGate(
    ComponentType type,
    const std::string& name,
    Signal& input,
    Signal& output
) {
    switch (type) {
        case ComponentType::NOT:
            return std::make_unique<NotGate>(
                name,
                input,
                output
            );

        default:
            throw std::runtime_error(
                "Invalid unary gate type"
            );
    }
}