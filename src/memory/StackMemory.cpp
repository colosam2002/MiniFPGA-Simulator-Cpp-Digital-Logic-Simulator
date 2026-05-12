#include "memory/StackMemory.hpp"

#include <iostream>

StackMemory::StackMemory(unsigned int size) : stackPointer(0), maxSize(size) {}

void StackMemory::push(unsigned int value) {

    if (isFull()) {

        std::cout << "Stack overflow" << std::endl;

        return;
    }

    stack.push_back(value);

    ++stackPointer;
}

unsigned int StackMemory::pop() {

    if (isEmpty()) {

        std::cout << "Stack underflow" << std::endl;

        return 0;
    }

    unsigned int value = stack.back();

    stack.pop_back();

    --stackPointer;

    return value;
}

bool StackMemory::isEmpty() const {
    return stack.empty();
}

bool StackMemory::isFull() const {
    return stackPointer >= maxSize;
}

void StackMemory::printStack() const {

    std::cout << "========== STACK ==========" << std::endl;

    for (int i = stack.size() - 1; i >= 0; --i) {

        if (i == stack.size() - 1) {

            std::cout
                << "[TOP] ";
        }
        else {

            std::cout
                << "      ";
        }

        std::cout
            << "[" << i << "] = "
            << stack[i]
            << std::endl;
    }

    if (stack.empty()) {

        std::cout
            << "(empty)"
            << std::endl;
    }
}

unsigned int StackMemory::getStackPointer() const {

    return stackPointer;
}