#pragma once

#include "Observer.h"

#include <iostream>

class Client: public Observer{
    int id_;
public:
    Client(int id): id_(id){}

    virtual void update(float temp, float humidity, float pressure) override{
        std::cout<<"Client: "<<id_<<" \nData: "
        <<"Temperature: "<<temp<<" Humidity: "<<humidity<<" Pressure: "<<pressure<<"\n";
    }
};
