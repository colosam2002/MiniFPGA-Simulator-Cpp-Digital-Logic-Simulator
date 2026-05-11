#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "Component.hpp"
#include "Signal.hpp"
#include "core/Bus.hpp"

class Circuit {
private:
    std::vector<std::unique_ptr<Signal>> signals;
    std::vector<std::unique_ptr<Component>> components;
    std::unordered_map<std::string, Signal*> signalMap;

    std::vector<std::unique_ptr<Bus>> buses;
    std::unordered_map<std::string, Bus*> busMap;

public:
    Signal& createSignal(
        const std::string& name,
        bool initialValue = false
    );

    void addComponent(std::unique_ptr<Component> component);

    Signal& getSignal(const std::string& name);

    void evaluate();

    void printSignals() const;

    Bus& createBus(
        const std::string& name,
        int width
    );

    Bus& getBus(
        const std::string& name
    );

    void printBuses() const;
};

#endif