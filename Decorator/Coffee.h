#pragma once
#include <iostream>
#include <string>

class Coffee{
public:
    virtual ~Coffee() {}

    virtual double getCost() = 0;
    virtual std::string getDescription() = 0;
};

class SimpleCoffee: public Coffee{
public:
    ~SimpleCoffee() {}

    double getCost() {
        return 10.0;
    }

    std::string getDescription() {
        return "Simple Coffee";
    }
};

class CoffeeDecorator: public Coffee {
protected:
    Coffee* _coffee;
public:
    ~CoffeeDecorator() {}

    CoffeeDecorator(Coffee* coffee): _coffee(coffee) {}

    virtual double getCost() = 0;
    virtual std::string getDescription() = 0;

};

class MilkCoffee: public CoffeeDecorator{
public:
    MilkCoffee(Coffee* coffee): CoffeeDecorator(coffee){}

    double getCost() {
        return _coffee->getCost() + 2.0;
    }

    std::string getDescription() {
        return _coffee->getDescription() + ", milk";
    }
};

class WhipCoffee: public CoffeeDecorator{
public:
    WhipCoffee(Coffee* coffee): CoffeeDecorator(coffee){}

    double getCost() {
        return _coffee->getCost() + 4.0;
    }

    std::string getDescription() {
        return _coffee->getDescription() + ", whip";
    }
};

class VanillaCoffee: public CoffeeDecorator{
public:
    VanillaCoffee(Coffee* coffee): CoffeeDecorator(coffee){}

    double getCost() {
        return _coffee->getCost() + 2.0;
    }

    std::string getDescription() {
        return _coffee->getDescription() + ", vanilla";
    }
};


