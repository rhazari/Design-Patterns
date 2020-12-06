#pragma once
#include <iostream>
#include <string>

class Theme{
public:
    virtual ~Theme(){}

    virtual std::string getColor() = 0;
};

class DarkTheme: public Theme{
public:
    ~DarkTheme() {}

    std::string getColor() {
        return "Dark Black\n";
    }
};

class LightTheme: public Theme{
public:
    ~LightTheme() {}

    std::string getColor() {
        return "Off White\n";
    }
};

class AquaTheme: public Theme{
public:
    ~AquaTheme() {}

    std::string getColor() {
        return "Light Blue\n";
    }
};

