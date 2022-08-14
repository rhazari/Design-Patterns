#pragma once

#include "IObserver.h"

class ISubject{
    public:
        virtual ~ISubject(){}

        virtual void AttachObserver(IObserver* observer) = 0;

        virtual void DetachObserver(IObserver* observer) = 0;

        virtual void  NotifyObservers() = 0;

};