#ifndef COMPONENT_TYPE_HPP
#define COMPONENT_TYPE_HPP

#include <stdexcept>
#include <string>

enum class ComponentType {
    AND,
    OR,
    XOR,
    NOT
};

inline ComponentType componentTypeFromString(
    const std::string& type
) {
    if (type == "AND") {
        return ComponentType::AND;
    }

    if (type == "OR") {
        return ComponentType::OR;
    }

    if (type == "XOR") {
        return ComponentType::XOR;
    }

    if (type == "NOT") {
        return ComponentType::NOT;
    }

    throw std::runtime_error(
        "Unknown component type: " + type
    );
}

#endif