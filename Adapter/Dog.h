#pragma once
#include <iostream>
#include <string>

class Dog {
public:
    virtual ~Dog() {}

    virtual void bark() = 0;
};

class WilDog: public Dog {
public:
    ~WilDog() {}

    void bark() {
        std::cout<<"This is a WildDog\n";
    }
};