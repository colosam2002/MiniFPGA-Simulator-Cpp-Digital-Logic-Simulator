#include "Circuit.hpp"

#include <iostream>

Signal& Circuit::createSignal(
    const std::string& name,
    bool initialValue
) {
    signals.push_back(
        std::make_unique<Signal>(name, initialValue)
    );

    return *signals.back();
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