#include "Lion.h"
#include "Dog.h"
#include <memory>

class DogAdapter: public Lion {
    std::unique_ptr<Dog> _dog;
public:
    DogAdapter() {
        _dog = std::make_unique<WildDog>();
    }

    void roar() {
        _dog->bark();
    }
};

int main() {
    std::unique_ptr<Lion> lion; 
    {
        lion = std::make_unique<AfricanLion>();
        lion->roar();
    }
    {
        lion = std::make_unique<DogAdapter>();
        lion->roar();
    }
}