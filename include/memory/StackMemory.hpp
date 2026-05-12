#ifndef STACK_MEMORY_HPP
#define STACK_MEMORY_HPP

#include <vector>

class StackMemory {
    private:
        std::vector<unsigned int> stack;

        unsigned int stackPointer;

        unsigned int maxSize;

    public:
        StackMemory(unsigned int size);

        void push(unsigned int value);

        unsigned int pop();

        bool isEmpty() const;

        bool isFull() const;

        void printStack() const;

        unsigned int getStackPointer() const;
};

#endif