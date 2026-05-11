#ifndef GATE_FACTORY_HPP
#define GATE_FACTORY_HPP

#include <memory>
#include <string>

#include "Component.hpp"
#include "Signal.hpp"
#include "factory/ComponentType.hpp"

class GateFactory {
public:
    static std::unique_ptr<Component> createBinaryGate(
        ComponentType type,
        const std::string& name,
        Signal& inputA,
        Signal& inputB,
        Signal& output
    );

    static std::unique_ptr<Component> createUnaryGate(
        ComponentType type,
        const std::string& name,
        Signal& input,
        Signal& output
    );
};

#endif