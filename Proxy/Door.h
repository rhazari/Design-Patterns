#pragma once
#include <iostream>
#include <string>
#include <memory>

class Door{
public:
    virtual ~Door(){}

    virtual void open() = 0;
    virtual void close() = 0;
};

class LabDoor: public Door{
public:
    ~LabDoor() {}

    void open() {
        std::cout<<"Opening Lab Door\n";
    }

    void close() {
        std::cout<<"Closing Lab Door\n";
    }
};

class SecureDoor {
    std::unique_ptr<LabDoor> _door;
    std::string _password = "secret";

    bool authenticate(std::string password) {
        return password == _password;
    }

public:
    SecureDoor(){
        _door = std::make_unique<LabDoor>();
    }

    ~SecureDoor() {
    }

    void open(std::string password){
        if(authenticate(password)){
            _door->open();
        }
        else{
            std::cout<<"Wrong password\n";
        }
    }

    void close(){
        _door->close();
    }
};

