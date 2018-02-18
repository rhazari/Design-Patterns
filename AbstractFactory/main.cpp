#include "Client.h"

using namespace std;

#define SIMPLE 1
#define COMPLEX 0

int Shape:: _total = 0;

int main(){
    Factory *factory;
#if SIMPLE
    factory = new SimpleShapeFactory;
#elif COMPLEX
    factory =  new ComplexShapeFactory;
#endif
    Client *c = new Client(factory);
    c->draw();
    return 0;
}