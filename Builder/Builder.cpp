#include "Builder.h"

int main(){
    
    Director dir;

    dir.set(std::make_unique<ConcreteBuilderX>());
    dir.createProduct();
    Product p1 = dir.getProduct();
    std::cout<<p1.get()<<"\n";


    dir.set(std::make_unique<ConcreteBuilderY>());
    dir.createProduct();
    Product p2 = dir.getProduct();
    std::cout<<p2.get()<<"\n";

    dir.set(std::make_unique<ConcreteBuilderZ>());
    dir.createProduct();
    Product p3 = dir.getProduct();
    std::cout<<p3.get()<<"\n";
}