#include "DoorFactory.h"

int main() {

    DoorFactory* factory;
    {
        factory = new WoodenDoorFactory();
        auto door = factory->getDoor();
        auto expert = factory->getExpert();

        door->getDescription();
        expert->getDescription();
        factory->removeDoor(door);
        factory->removeExpert(expert);

        delete factory;
    }

    {
        factory = new MetalDoorFactory();
        auto door = factory->getDoor();
        auto expert = factory->getExpert();

        door->getDescription();
        expert->getDescription();
        factory->removeDoor(door);
        factory->removeExpert(expert);

        delete factory;
    }
}