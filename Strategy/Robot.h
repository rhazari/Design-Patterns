#pragma once

#include <iostream>
#include <memory>

// Common interface to all supported algorithms
class IStrategy {
public:
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
        m_name(name){}

    void setStrategy(std::unique_ptr<IStrategy> s){
        m_strategy = std::move(s);
    }

    void executeCommand(){
        m_strategy->moveCommand();
    }

private:
    std::unique_ptr<IStrategy> m_strategy;
    std::string m_name;
};