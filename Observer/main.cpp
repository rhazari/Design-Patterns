#include "WeatherData.h"
#include "Client.h"

#include <iostream>
#include <memory>

int main(){

    WeatherData weatherStation;
    auto c1 = std::make_unique<Client>(1);
    auto c2 = std::make_unique<Client>(2);
    auto c3 = std::make_unique<Client>(3);

    weatherStation.registerObserver(c1.get());
    weatherStation.registerObserver(c2.get());
    weatherStation.registerObserver(c3.get());

    weatherStation.setState(25, 40, 10);

    weatherStation.removeObserver(c2.get());

    weatherStation.setState(35, 50, 5);

}