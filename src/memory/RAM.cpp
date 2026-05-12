#include "memory/RAM.hpp"

#include <iostream>
#include <stdexcept>

RAM::RAM(Bus& address, Bus& data, Signal& writeEn, Signal& readEn, unsigned int size) : addressBus(address), dataBus(data), writeEnable(writeEn), readEnable(readEn), memory(size, 0), memorySize(size) {}

void RAM::write() {

    if(!writeEnable.getValue()){
        return;
    }

    unsigned int address = addressBus.toInteger();

    if (address >= memorySize) {
        throw std::runtime_error(
            "RAM write address out of range"
        );
    }

    memory[address] = dataBus.toInteger();
}

void RAM::read() {

    if (!readEnable.getValue()) {
        return;
    }

    unsigned int address = addressBus.toInteger();

    if (address >= memorySize) {
        throw std::runtime_error(
            "RAM read address out of range"
        );
    }

    dataBus.setValueFromInteger(memory[address]);
}

void RAM::printMemory() const {

    std::cout << "RAM contents:" << std::endl;

    for (unsigned int i = 0; i < memorySize; ++i) {
        std::cout << "[" << i << "] = " << memory[i] << std::endl;
    }
}

unsigned int RAM::getMemorySize() const {
    return memorySize;
}