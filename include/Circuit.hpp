#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#include <memory>
#include <string>
#include <vector>

#include "Component.hpp"
#include "Signal.hpp"

class Circuit {
private:
    std::vector<std::unique_ptr<Signal>> signals;
    std::vector<std::unique_ptr<Component>> components;

public:
    Signal& createSignal(
        const std::string& name,
        bool initialValue = false
    );

    void addComponent(std::unique_ptr<Component> component);

    void evaluate();

    void printSignals() const;
};

#endif