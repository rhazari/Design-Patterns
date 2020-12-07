#pragma once
#include <iostream>
#include <memory>

// Common interface to all supported algorithms
class IStrategy {
public:
    virtual ~IStrategy() {}
    virtual void moveCommand() = 0;
};

class AggressiveStrategy: public IStrategy{
public:
    void moveCommand(){
        std::cout<<"Aggressive Strategy: attack any robot when found"<<"\n";
    }
};

class NeutralStrategy: public IStrategy{
public:
    void moveCommand(){
        std::cout<<"Neutral Strategy: attack only when attacked, else ignore"<<"\n";
    }
};

class DefensiveStrategy: public IStrategy{
public:
    void moveCommand(){
        std::cout<<"Defensive Strategy: avoid confrontation at all cost, run when possible"<<"\n";
    }
};

// Context Class
class Robot{
public:
    Robot(std::string name):
        _name(name){}

    void setStrategy(std::unique_ptr<IStrategy> s){
        _strategy = std::move(s);
    }

    void executeCommand(){
        _strategy->moveCommand();
    }

private:
    std::unique_ptr<IStrategy> _strategy;
    std::string _name;
};