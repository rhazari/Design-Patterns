#pragma once
#include "Door.h"

class FittingExpert{
public:
    virtual ~FittingExpert() {}
    virtual void getDescription() =  0;
};

class Carpernter: public FittingExpert {
public:
    ~Carpernter() {}

    void getDescription() {
        std::cout<<"This is a carpenter\n";
    }
};

class Welder: public FittingExpert {
public:
    ~Welder() {}

    void getDescription() {
        std::cout<<"This is a welder\n";
    }
};

