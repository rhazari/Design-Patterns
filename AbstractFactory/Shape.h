#include <iostream>

using namespace std;

class Shape{
public:
    Shape(){
        _id = _total++;
    }

    virtual void draw() = 0;
protected:
    int _id;
    static int _total;
};

class Circle : public Shape{
public:
    void draw() override {
        cout<<"Circle Instance "<<_id<<"\n";
    }
};

class Sqaure : public Shape{
public:
    void draw() override {
        cout<<"Square Instance "<<_id<<"\n";
    }
};

class Ellipse : public Shape {
public:
    void draw() override {
        cout<<"Ellipse Instance "<<_id<<"\n";
    }
};

class Rectangle : public Shape{
public:
    void draw() override {
        cout<<"Rectangle Instance "<<_id<<"\n";
    }
};

