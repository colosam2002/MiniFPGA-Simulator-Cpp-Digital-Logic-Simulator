#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>

class Component {
private:
    std::string name;

public:
    Component(const std::string& componentName);

    virtual ~Component() = default;

    std::string getName() const;

    virtual void evaluate() = 0;
};

#endif