#include "Shape.h"

class Factory{
public:
    virtual Shape* createCurvedInstance() = 0;
    virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory: public Factory {
public:
    Shape* createStraightInstance() override {
        return new Sqaure;
    }

    Shape* createCurvedInstance() override {
        return new Circle;
    }
};

class ComplexShapeFactory: public Factory {
public:
    Shape* createStraightInstance() override {
        return new Rectangle;
    }

    Shape* createCurvedInstance() override {
        return new Ellipse;
    }
};