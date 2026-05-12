#include "memory/MemoryInterface.hpp"

MemoryInterface::MemoryInterface(unsigned int addressWidth, unsigned int dataWidth, unsigned int memorySize)
    : addressBus("ADDRESS", addressWidth),
      dataBus("DATA", dataWidth),
      writeEnable("WRITE_ENABLE"),
      readEnable("READ_ENABLE"),
      ram(addressBus, dataBus, writeEnable, readEnable, memorySize){}

void MemoryInterface::writeMemory(unsigned int address, unsigned int value) {

    addressBus.setValueFromInteger(address);

    dataBus.setValueFromInteger(value);

    writeEnable.setValue(true);

    ram.write();

    writeEnable.setValue(false);
}

unsigned int MemoryInterface::readMemory(unsigned int address) {

    addressBus.setValueFromInteger(address);

    readEnable.setValue(true);

    ram.read();

    readEnable.setValue(false);

    return dataBus.toInteger();
}

void MemoryInterface::printMemory() const {
    ram.printMemory();
}

Bus& MemoryInterface::getAddressBus() {
    return addressBus;
}

Bus& MemoryInterface::getDataBus() {
    return dataBus;
}