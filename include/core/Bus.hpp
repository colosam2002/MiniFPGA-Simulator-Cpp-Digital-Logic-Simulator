#ifndef BUS_HPP
#define BUS_HPP

#include <string>
#include <vector>

#include "Signal.hpp"

class Bus {
private:
    std::string name;

    std::vector<Signal> signals;

public:
    Bus(
        const std::string& busName,
        int width
    );

    std::string getName() const;

    int getWidth() const;

    Signal& getSignal(int index);

    const Signal& getSignal(int index) const;

    void setValueFromInteger(unsigned int value);

    unsigned int toInteger() const;

    void print() const;

    std::string toBinaryString() const;

    std::string toHexString() const;

    void setValueFromBinaryString(
        const std::string& binaryString
    );
};

#endif