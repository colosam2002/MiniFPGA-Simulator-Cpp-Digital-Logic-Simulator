#ifndef REGISTER_FILE_HPP
#define REGISTER_FILE_HPP

#include <vector>

#include "core/Bus.hpp"

class RegisterFile {
    private:
        std::vector<unsigned int> registers;

        unsigned int registerCount;

        unsigned int registerWidth;

    public:
        RegisterFile(unsigned int count, unsigned int width);

        void writeRegister(unsigned int index, unsigned int value);

        unsigned int readRegister(unsigned int index) const;

        void loadRegisterToBus(unsigned int index, Bus& outputBus) const;

        void storeBusToRegister(unsigned int index, const Bus& inputBus);

        void printRegisters() const;

        unsigned int getRegisterCount() const;
};

#endif