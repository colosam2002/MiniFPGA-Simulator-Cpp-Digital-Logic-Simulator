#ifndef RAM_HPP
#define RAM_HPP

#include <vector>

#include "core/Bus.hpp"
#include "Signal.hpp"

class RAM {
    private:
        Bus& addressBus;

        Bus& dataBus;

        std::vector<unsigned int> memory;

        unsigned int memorySize;

        Signal& writeEnable;

        Signal& readEnable;

    public:
        RAM(Bus& address, Bus& data, Signal& writeEn, Signal& readEn, unsigned int size);

        void write();

        void read();

        void printMemory() const;

        unsigned int getMemorySize() const;
};

#endif