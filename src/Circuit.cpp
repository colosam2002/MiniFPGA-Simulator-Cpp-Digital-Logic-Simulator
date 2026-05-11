#include "Circuit.hpp"

#include <iostream>
#include <stdexcept>

Signal& Circuit::createSignal(
    const std::string& name,
    bool initialValue
) {
    signals.push_back(
        std::make_unique<Signal>(name, initialValue)
    );

    Signal* signalPtr = signals.back().get();

    signalMap[name] = signalPtr;

    return *signalPtr;
}

void Circuit::addComponent(std::unique_ptr<Component> component) {
    components.push_back(std::move(component));
}

void Circuit::evaluate() {
    for (const auto& component : components) {
        component->evaluate();
    }
}

void Circuit::printSignals() const {
    for (const auto& signal : signals) {
        std::cout << signal->getName()
                  << " = "
                  << signal->getValue()
                  << std::endl;
    }
}

Signal& Circuit::getSignal(
    const std::string& name
) {
    auto it = signalMap.find(name);

    if (it == signalMap.end()) {
        throw std::runtime_error(
            "Signal not found: " + name
        );
    }

    return *(it->second);
}