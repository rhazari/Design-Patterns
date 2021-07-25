#pragma once

// Interface for Observer
class Observer{
public:
    virtual void update(float temp, float humity, float pressure) = 0;
};

