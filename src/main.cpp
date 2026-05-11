#include <iostream>
#include <memory>

#include "Circuit.hpp"
#include "gates/AndGate.hpp"
#include "gates/XorGate.hpp"

void runHalfAdderCase(
    Signal& a,
    Signal& b,
    Signal& sum,
    Signal& carry,
    Circuit& circuit,
    bool aValue,
    bool bValue
) {
    a.setValue(aValue);
    b.setValue(bValue);

    circuit.evaluate();

    std::cout << a.getValue()
              << " "
              << b.getValue()
              << " |  "
              << sum.getValue()
              << "     "
              << carry.getValue()
              << std::endl;
}

void printHalfAdderHeader() {
    std::cout << "Half Adder Truth Table" << std::endl;
    std::cout << "A B | SUM CARRY" << std::endl;
    std::cout << "--------------" << std::endl;
}

int main() {
    Circuit circuit;

    Signal& a = circuit.createSignal("A");
    Signal& b = circuit.createSignal("B");
    Signal& sum = circuit.createSignal("SUM");
    Signal& carry = circuit.createSignal("CARRY");

    circuit.addComponent(
        std::make_unique<XorGate>("XOR_SUM", a, b, sum)
    );

    circuit.addComponent(
        std::make_unique<AndGate>("AND_CARRY", a, b, carry)
    );

    printHalfAdderHeader();

    runHalfAdderCase(a, b, sum, carry, circuit, false, false);
    runHalfAdderCase(a, b, sum, carry, circuit, false, true);
    runHalfAdderCase(a, b, sum, carry, circuit, true, false);
    runHalfAdderCase(a, b, sum, carry, circuit, true, true);

    return 0;
}