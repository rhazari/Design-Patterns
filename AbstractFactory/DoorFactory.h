#pragma once
#include "FittingExpert.h"
#include <memory>

class DoorFactory{
public:
    virtual ~DoorFactory() {}
    virtual std::unique_ptr<Door> getDoor() = 0;
    virtual std::unique_ptr<FittingExpert> getExpert() = 0;
};

class WoodenDoorFactory: public DoorFactory{
public:
    ~WoodenDoorFactory() {
        std::cout<<"~WoodenDoorFactory()\n";
    }

    std::unique_ptr<Door> getDoor() {
        return std::make_unique<WooderDoor>();
    }

    std::unique_ptr<FittingExpert> getExpert() {
        return std::make_unique<Carpernter>();
    }
};

class MetalDoorFactory: public DoorFactory{
public:
    ~MetalDoorFactory() {
        std::cout<<"~MetalDoorFactory()\n";
    }

    std::unique_ptr<Door> getDoor() {
        return std::make_unique<MetalDoor>();
    }

    std::unique_ptr<FittingExpert> getExpert() {
        return std::make_unique<Welder>();
    }
};