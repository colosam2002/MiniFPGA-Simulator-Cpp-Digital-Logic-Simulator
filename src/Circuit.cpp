#include "Circuit.hpp"

#include <iostream>
#include <stdexcept>
#include "core/Bus.hpp"

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

Bus& Circuit::createBus(
    const std::string& name,
    int width
) {

    buses.push_back(
        std::make_unique<Bus>(
            name,
            width
        )
    );

    Bus* busPtr = buses.back().get();

    busMap[name] = busPtr;

    return *busPtr;
}

Bus& Circuit::getBus(
    const std::string& name
) {

    auto it = busMap.find(name);

    if (it == busMap.end()) {

        throw std::runtime_error(
            "Bus not found: " + name
        );
    }

    return *(it->second);
}

void Circuit::printBuses() const {

    for (const auto& bus : buses) {

        bus->print();
    }
}