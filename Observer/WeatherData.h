#pragma once

#include "Notifier.h"
#include "Observer.h"

#include <vector>
#include <algorithm>
#include <iostream>

class WeatherData: public Notifier{
    std::vector<Observer*> _observers;
    float _temp = 0.0f;
    float _humidity = 0.0f;
    float _pressure = 0.0f;

public:
    void registerObserver(Observer*) override;

    void removeObserver(Observer*) override;

    void notifyObservers() override;

    void setState(float temp, float humidity, float pressure);
};

void WeatherData::registerObserver(Observer *ob) {
    _observers.push_back(ob);
}

void WeatherData::removeObserver(Observer* ob) {
    // find the observer
    auto iterator = std::find(_observers.begin(), _observers.end(), ob);

    if (iterator != _observers.end()) { // observer found
        _observers.erase(iterator); // remove the observer
    }
}

void WeatherData::notifyObservers() {
    for (auto* ob : _observers) { // notify all observers
        ob->update(_temp, _humidity, _pressure);
    }
}

void WeatherData::setState(float temp, float humidity, float pressure) {
    _temp = temp;
    _humidity = humidity;
    _pressure = pressure;
    notifyObservers();
}