#pragma once
#include "FittingExpert.h"

class DoorFactory{
public:
    virtual ~DoorFactory() {}
    virtual Door* getDoor() = 0;
    virtual FittingExpert* getExpert() = 0;

    void removeDoor(Door* door){
        delete door;
    }

    void removeExpert(FittingExpert* expert){
        delete expert;
    }

};

class WoodenDoorFactory: public DoorFactory{
public:
    ~WoodenDoorFactory() {}

    Door* getDoor() {
        return new WooderDoor();
    }

    FittingExpert* getExpert() {
        return new Carpernter();
    }
};

class MetalDoorFactory: public DoorFactory{
public:
    ~MetalDoorFactory() {}

    Door* getDoor() {
        return new MetalDoor();
    }

    FittingExpert* getExpert() {
        return new Welder();
    }
};