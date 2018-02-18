#include "Factory.h"

class Client{
    Factory *m_factory;
public:
    Client(Factory *f){
        m_factory = f;
    }

    void draw() {
        Shape *shape[] = {
            m_factory->createStraightInstance(),
            m_factory->createCurvedInstance()
        };

        shape[0]->draw();
        shape[1]->draw();
    }
};

