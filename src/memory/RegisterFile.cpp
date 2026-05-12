#include "memory/RegisterFile.hpp"

#include <iostream>
#include <stdexcept>

RegisterFile::RegisterFile(unsigned int count, unsigned int width) : registers(count, 0), registerCount(count), registerWidth(width) {}

void RegisterFile::writeRegister(unsigned int index, unsigned int value) {

    if (index >= registerCount) {

        throw std::runtime_error(
            "Register index out of range"
        );
    }

    unsigned int maxValue = (1 << registerWidth);

    registers[index] = value % maxValue;
}

unsigned int RegisterFile::readRegister(unsigned int index) const {

    if (index >= registerCount) {

        throw std::runtime_error(
            "Register index out of range"
        );
    }

    return registers[index];
}

void RegisterFile::loadRegisterToBus(unsigned int index, Bus& outputBus) const {

    outputBus.setValueFromInteger(readRegister(index));
}

void RegisterFile::storeBusToRegister(unsigned int index, const Bus& inputBus) {
    writeRegister(index, inputBus.toInteger());
}

void RegisterFile::printRegisters() const {

    std::cout << "Register File:" << std::endl;

    for (unsigned int i = 0; i < registerCount; ++i) {
        std::cout << "R" << i << " = " << registers[i] << std::endl;
    }
}

unsigned int RegisterFile::getRegisterCount() const {
    return registerCount;
}