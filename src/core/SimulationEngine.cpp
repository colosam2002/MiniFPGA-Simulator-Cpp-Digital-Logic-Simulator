#include "core/SimulationEngine.hpp"

Clock& SimulationEngine::getClock() {
    return clock;
}

void SimulationEngine::registerComponent(SequentialComponent& component) {
    components.push_back(&component);
}

void SimulationEngine::tick() {

    clock.tick();

    for (auto* component : components) {
        component->update();
    }
}

unsigned long SimulationEngine::getTickCount() const {
    return clock.getTickCount();
}