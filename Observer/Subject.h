#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "ISubject.h"

class Subject: public ISubject {
        std::vector<IObserver*> _observers;
        std::string _message;
public:
    virtual ~Subject(){
        std::cout<<"Calling Destructor on Subject\n";
    }

    void AttachObserver(IObserver *observer) override{
        std::cout<<"Attaching Obsever to the list: "<<observer->getId()<<"\n";
        _observers.push_back(observer);
    }

    void DetachObserver(IObserver* observer) override {
        auto iter = std::find(_observers.begin(), _observers.end(), observer);
        if (iter != _observers.end()){
            _observers.erase(iter);
        }
    }

    void printTotalObservers() {
        std::cout<<"Total Observers: "<<_observers.size()<<"\n";
    }

    void NotifyObservers() override {
        printTotalObservers();
        for(auto* observer: _observers){
            observer->Update(_message);
        }
    }

    void CreateMessage(const std::string& message){
        _message = message;
        NotifyObservers();
    }
};