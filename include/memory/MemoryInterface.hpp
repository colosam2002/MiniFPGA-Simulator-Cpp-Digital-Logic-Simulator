#ifndef MEMORY_INTERFACE_HPP
#define MEMORY_INTERFACE_HPP

#include "Signal.hpp"

#include "core/Bus.hpp"

#include "memory/RAM.hpp"

class MemoryInterface {
    private:
        Bus addressBus;

        Bus dataBus;

        Signal writeEnable;

        Signal readEnable;

        RAM ram;

    public:
        MemoryInterface(unsigned int addressWidth, unsigned int dataWidth, unsigned int memorySize);

        void writeMemory(unsigned int address, unsigned int value);

        unsigned int readMemory(unsigned int address);

        void printMemory() const;

        Bus& getAddressBus();

        Bus& getDataBus();
};

#endif