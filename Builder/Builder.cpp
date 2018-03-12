#include "Builder.h"

int main(){
    
    Director dir;

    dir.set(new ConcreteBuilderX);
    dir.createProduct();
    Product *p1 = dir.getProduct();
    p1->display();


    dir.set(new ConcreteBuilderY);
    dir.createProduct();
    Product *p2 = dir.getProduct();
    p2->display();

    dir.set(new ConcreteBuilderZ);
    dir.createProduct();
    Product *p3 = dir.getProduct();
    p3->display();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}