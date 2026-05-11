#include "core/Bus.hpp"

#include <iostream>
#include <stdexcept>
#include <bitset>
#include <sstream>

Bus::Bus(
    const std::string& busName,
    int width
)
    : name(busName)
{
    if (width <= 0) {
        throw std::runtime_error(
            "Bus width must be positive"
        );
    }

    for (int i = 0; i < width; ++i) {

        signals.emplace_back(
            busName + "_" + std::to_string(i),
            false
        );
    }
}

std::string Bus::getName() const {
    return name;
}

int Bus::getWidth() const {
    return signals.size();
}

Signal& Bus::getSignal(int index) {

    if (index < 0 || index >= getWidth()) {
        throw std::runtime_error(
            "Bus index out of range"
        );
    }

    return signals[index];
}

const Signal& Bus::getSignal(int index) const {

    if (index < 0 || index >= getWidth()) {
        throw std::runtime_error(
            "Bus index out of range"
        );
    }

    return signals[index];
}

void Bus::setValueFromInteger(
    unsigned int value
) {
    for (int i = 0; i < getWidth(); ++i) {

        bool bit =
            (value >> i) & 1;

        signals[i].setValue(bit);
    }
}

unsigned int Bus::toInteger() const {

    unsigned int result = 0;

    for (int i = 0; i < getWidth(); ++i) {

        if (signals[i].getValue()) {

            result |= (1 << i);
        }
    }

    return result;
}

void Bus::print() const {

    std::cout
        << name
        << " = "
        << toBinaryString()
        << " ("
        << toInteger()
        << ", "
        << toHexString()
        << ")"
        << std::endl;
}

std::string Bus::toBinaryString() const {

    std::string result;

    for (int i = getWidth() - 1; i >= 0; --i) {

        result +=
            signals[i].getValue()
            ? '1'
            : '0';
    }

    return result;
}

std::string Bus::toHexString() const {

    std::stringstream stream;

    stream
        << "0x"
        << std::hex
        << std::uppercase
        << toInteger();

    return stream.str();
}

void Bus::setValueFromBinaryString(
    const std::string& binaryString
) {

    if (
        binaryString.length()
        != static_cast<size_t>(getWidth())
    ) {
        throw std::runtime_error(
            "Binary string width mismatch"
        );
    }

    for (int i = 0; i < getWidth(); ++i) {

        char bit =
            binaryString[
                binaryString.length() - 1 - i
            ];

        if (bit == '1') {
            signals[i].setValue(true);
        }

        else if (bit == '0') {
            signals[i].setValue(false);
        }

        else {
            throw std::runtime_error(
                "Invalid binary character"
            );
        }
    }
}