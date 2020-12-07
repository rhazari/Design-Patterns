#include "DoorFactory.h"

int main() {

    std::unique_ptr<DoorFactory> factory;
    {
        factory = std::make_unique<WoodenDoorFactory>();
        auto door = factory->getDoor();
        auto expert = factory->getExpert();

        door->getDescription();
        expert->getDescription();
    }

    {
        factory = std::make_unique<MetalDoorFactory>();
        auto door = factory->getDoor();
        auto expert = factory->getExpert();

        door->getDescription();
        expert->getDescription();
    }
}