#ifndef SIMPLE_ALU_HPP
#define SIMPLE_ALU_HPP

#include "cpu/IALU.hpp"

class SimpleALU : public IALU {

public:

    unsigned int add(
        unsigned int a,
        unsigned int b
    ) override;

    unsigned int sub(
        unsigned int a,
        unsigned int b
    ) override;

    unsigned int mov(
        unsigned int value
    ) override;
};

#endif