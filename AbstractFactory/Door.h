#pragma once
#include <iostream>
#include <string>

class Door {
public:
    virtual ~Door() {}
    virtual void getDescription() = 0;
};

class WooderDoor: public Door {
public:
    ~WooderDoor() {}

    void getDescription() {
        std::cout<<"This is a wooden door!\n";
    }
};

class MetalDoor: public Door {
public:
    ~MetalDoor() {}
    
    void getDescription() {
        std::cout<<"This is a metal door!\n";
    }
};

