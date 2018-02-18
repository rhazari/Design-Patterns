#include "Client.h"

using namespace std;

#define COMPLEX 1

int Shape:: _total = 0;

int main(){
    Factory *factory;
#ifdef SIMPLE
    factory = new SimpleShapeFactory;
#elif COMPLEX
    factory =  new ComplexShapeFactory;
#endif
    Client *c = new Client(factory);
    c->draw();
    return 0;
}