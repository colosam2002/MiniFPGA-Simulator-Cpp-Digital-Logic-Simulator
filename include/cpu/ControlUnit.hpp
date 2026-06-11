#ifndef CONTROL_UNIT_HPP
#define CONTROL_UNIT_HPP

#include "cpu/Instruction.hpp"
#include "cpu/ALUOperation.hpp"

struct ControlSignals {

    bool usesALU;

    bool usesTwoOperands;

    bool writesRegister;

    bool usesImmediate;

    ALUOperation aluOperation;

};

class ControlUnit {

public:

    ControlSignals decode(
        const Instruction& instruction
    ) const;
};

#endif