#pragma once

#include <iostream>
#include <string>

class IObserver{
public:
    virtual ~IObserver() {}

    virtual void Update(const std::string& message) = 0;

    virtual int getId() const = 0;
};