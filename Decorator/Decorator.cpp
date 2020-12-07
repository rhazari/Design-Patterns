#include "Coffee.h"

int main(){
    Coffee* c1 = new SimpleCoffee();
    std::cout<<c1->getDescription()<<": ";
    std::cout<<c1->getCost()<<"\n";

    Coffee* c2 = new MilkCoffee(c1);
    std::cout<<c2->getDescription()<<": ";
    std::cout<<c2->getCost()<<"\n";

    Coffee* c3 = new WhipCoffee(c2);
    std::cout<<c3->getDescription()<<": ";
    std::cout<<c3->getCost()<<"\n";

    Coffee* c4 = new VanillaCoffee(c3);
    std::cout<<c4->getDescription()<<": ";
    std::cout<<c4->getCost()<<"\n";

    delete c4;
    delete c3;
    delete c2;
    delete c1;

}