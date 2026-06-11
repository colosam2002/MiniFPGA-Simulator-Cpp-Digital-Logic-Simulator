#ifndef IALU_HPP
#define IALU_HPP

class IALU {

public:

    virtual ~IALU() = default;

    virtual unsigned int add(
        unsigned int a,
        unsigned int b
    ) = 0;

    virtual unsigned int sub(
        unsigned int a,
        unsigned int b
    ) = 0;

    virtual unsigned int mov(
        unsigned int value
    ) = 0;
};

#endif