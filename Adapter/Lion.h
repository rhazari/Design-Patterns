#pragma once
#include <iostream>
#include <string>

class Lion{
public:
    virtual ~Lion() {}

    virtual void roar() = 0;
};

class AfricanLion: public Lion{
public:
    ~AfricanLion() {}

    void roar() {
        std::cout<<"This is an African Lion\n";
    }
};

class AsianLion: public Lion{
public:
    ~AsianLion() {}

    void roar() {
        std::cout<<"This is an Asian Lion\n";
    }
};