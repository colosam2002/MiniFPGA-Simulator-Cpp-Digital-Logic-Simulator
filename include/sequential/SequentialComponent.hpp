#ifndef SEQUENTIAL_COMPONENT_HPP
#define SEQUENTIAL_COMPONENT_HPP

class SequentialComponent {
    public:
        virtual ~SequentialComponent() = default;

        virtual void update() = 0;
};

#endif