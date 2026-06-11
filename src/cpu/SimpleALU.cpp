#include "cpu/SimpleALU.hpp"

unsigned int SimpleALU::add(
    unsigned int a,
    unsigned int b
) {
    return a + b;
}

unsigned int SimpleALU::sub(
    unsigned int a,
    unsigned int b
) {
    return a - b;
}

unsigned int SimpleALU::mov(
    unsigned int value
) {
    return value;
}