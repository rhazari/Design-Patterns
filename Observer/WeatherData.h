#pragma once

#include "Notifier.h"
#include "Observer.h"

#include <vector>
#include <algorithm>
#include <iostream>

class WeatherData: public Notifier{
    std::vector<Observer*> observers_;
    float temp_ = 0.0f;
    float humidity_ = 0.0f;
    float pressure_ = 0.0f;

public:
    void registerObserver(Observer*) override;

    void removeObserver(Observer*) override;

    void notifyObservers() override;

    void setState(float temp, float humidity, float pressure);
};

void WeatherData::registerObserver(Observer *ob) {
    observers_.push_back(ob);
}

void WeatherData::removeObserver(Observer* ob) {
    // find the observer
    auto iterator = std::find(observers_.begin(), observers_.end(), ob);

    if (iterator != observers_.end()) { // observer found
        observers_.erase(iterator); // remove the observer
    }
}

void WeatherData::notifyObservers() {
    for (auto* ob : observers_) { // notify all observers
        ob->update(temp_, humidity_, pressure_);
    }
}

void WeatherData::setState(float temp, float humidity, float pressure) {
    temp_ = temp;
    humidity_ = humidity;
    pressure_ = pressure;
    notifyObservers();
}