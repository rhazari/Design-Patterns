#pragma once

#include "Observer.h"

#include <iostream>

class Client: public Observer{
    int _id;
public:
    Client(int id): _id(id){}

    virtual void update(float temp, float humidity, float pressure) override{
        std::cout<<"Client: "<<_id<<" \nData: "
        <<"Temperature: "<<temp<<" Humidity: "<<humidity<<" Pressure: "<<pressure<<"\n";
    }
};
