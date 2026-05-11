#include "Component.hpp"

Component::Component(const std::string& componentName)
    : name(componentName) {}

std::string Component::getName() const {
    return name;
}