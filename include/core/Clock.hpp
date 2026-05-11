#ifndef CLOCK_HPP
#define CLOCK_HPP

class Clock {
private:
    bool currentState;

    bool previousState;

    unsigned long tickCount;

public:
    Clock();

    void tick();

    bool getState() const;

    bool isRisingEdge() const;

    bool isFallingEdge() const;

    unsigned long getTickCount() const;
};

#endif