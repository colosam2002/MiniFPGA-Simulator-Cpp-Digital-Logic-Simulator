#include "core/Clock.hpp"

Clock::Clock() : currentState(false), previousState(false), tickCount(0){}

void Clock::tick() {

    previousState = currentState;

    currentState = !currentState;

    ++tickCount;
}

bool Clock::getState() const {

    return currentState;
}

bool Clock::isRisingEdge() const {

    return (!previousState && currentState);
}

bool Clock::isFallingEdge() const {

    return (previousState && !currentState);
}

unsigned long Clock::getTickCount() const {

    return tickCount;
}