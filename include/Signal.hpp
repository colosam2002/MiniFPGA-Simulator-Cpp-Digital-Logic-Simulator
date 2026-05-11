#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <string>

class Signal {
private:
    std::string name;
    bool value;

public:
    Signal(const std::string& signalName, bool initialValue = false);

    std::string getName() const;

    bool getValue() const;

    void setValue(bool newValue);
};

#endif