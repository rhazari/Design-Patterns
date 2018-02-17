#include <iostream>
#include <string>

using namespace std;

class Vehicle{
protected:
    string m_make;
    string m_name;
    int m_price;

public:
    virtual void assemble() = 0;
    virtual void applyChecks() = 0;
    virtual void applyLabel() = 0;
    virtual void deliver() = 0;
    virtual void display() = 0;
};

// Make all consctructors in the derived class trivate or trotected
class Car: public Vehicle{
public:
    void assemble() override { cout<<"Car Assembled"<<"\n"; }
    void applyChecks() override { cout <<"Car Checks Applied"<<"\n"; }
    void applyLabel() override { 
        m_make = "Toyota";
        m_name = "Prius";
        m_price = 17000;
        cout<<"Car is labeled"<<"\n" ;
    }
    void deliver() override {std::cout <<"Car delivered"<<"\n";}
    void display() override
    {
        cout<<"Car make: "<<m_make <<"\n";
        cout<<"Car name: "<<m_name <<"\n";
        cout<<"Car price: "<<m_price <<"\n";
    }
};

class Truck: public Vehicle{
public:
    void assemble() override { cout<<"Truck Assembled"<<"\n"; }
    void applyChecks() override { cout <<"Truck Checks Applied"<<"\n"; }
    void applyLabel() override { 
        m_make = "Ford";
        m_name = "F50";
        m_price = 20000;
        cout<<"Truck is labeled"<<"\n" ;
    }
    void deliver() override {std::cout <<"Truck delivered"<<"\n";}
    void display() override
    {
        cout<<"Truck make: "<<m_make <<"\n";
        cout<<"Truck name: "<<m_name <<"\n";
        cout<<"Truck price: "<<m_price <<"\n";
    }
};

