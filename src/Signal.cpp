#include "Signal.hpp"

Signal::Signal(const std::string& signalName, bool initialValue)
    : name(signalName), value(initialValue) {}

std::string Signal::getName() const {
    return name;
}

bool Signal::getValue() const {
    return value;
}

void Signal::setValue(bool newValue) {
    value = newValue;
}