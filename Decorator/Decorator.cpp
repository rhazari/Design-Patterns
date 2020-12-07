#include "Coffee.h"

int main(){
    std::unique_ptr<Coffee> c1 = std::make_unique<SimpleCoffee>();
    std::cout<<c1->getDescription()<<": ";
    std::cout<<c1->getCost()<<"\n";

    std::unique_ptr<Coffee> c2 = std::make_unique<MilkCoffee>(std::move(c1));
    std::cout<<c2->getDescription()<<": ";
    std::cout<<c2->getCost()<<"\n";

    std::unique_ptr<Coffee> c3 = std::make_unique<WhipCoffee>(std::move(c2));
    std::cout<<c3->getDescription()<<": ";
    std::cout<<c3->getCost()<<"\n";

    std::unique_ptr<Coffee> c4 = std::make_unique<VanillaCoffee>(std::move(c3));
    std::cout<<c4->getDescription()<<": ";
    std::cout<<c4->getCost()<<"\n";
}