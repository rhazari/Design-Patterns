#include "Lion.h"
#include "Dog.h"

class DogAdapter: public Lion {
    Dog* _dog;
public:
    DogAdapter() {
        _dog = new WilDog();
    }

    ~DogAdapter() {
        delete _dog;
    }

    void roar() {
        _dog->bark();
    }
};

int main() {
    Lion* lion; 
    {
        lion = new AfricanLion();
        lion->roar();
        delete lion;
    }
    {
        lion = new DogAdapter();
        lion->roar();
        delete lion;
    }
}