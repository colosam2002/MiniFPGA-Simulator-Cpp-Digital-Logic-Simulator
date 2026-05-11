#ifndef SIMULATION_ENGINE_HPP
#define SIMULATION_ENGINE_HPP

#include <memory>
#include <vector>

#include "core/Clock.hpp"

#include "sequential/SequentialComponent.hpp"

class SimulationEngine {
    private:
        Clock clock;

        std::vector<SequentialComponent*> components;

    public:
        Clock& getClock();

        void registerComponent(SequentialComponent& component);

        void tick();

        unsigned long getTickCount() const;
};

#endif