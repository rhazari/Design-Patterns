#pragma once

#include "Observer.h"

// Interface for Notifier
class Notifier{
public:
    virtual void registerObserver(Observer*) = 0;

    virtual void removeObserver(Observer*) = 0;

    virtual void notifyObservers() = 0;
};
