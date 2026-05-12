#include "cpu/CPUFlags.hpp"

#include <iostream>

CPUFlags::CPUFlags() : zeroFlag(false) {}

void CPUFlags::updateZeroFlag(unsigned int value) {
    zeroFlag = (value == 0);
}

bool CPUFlags::getZeroFlag() const {
    return zeroFlag;
}

void CPUFlags::printFlags() const {
    std::cout << "CPU Flags:" << std::endl;

    std::cout << "ZERO = " << zeroFlag << std::endl;
}