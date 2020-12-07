#pragma once
#include <iostream>
#include <string>
#include <memory>

class Product{
private:
    std::string _partA;
    std::string _partB;
    std::string _partC;

public:

    void makePartA(std::string partA){
        _partA = partA;
    }

    void makePartB(std::string partB){
        _partB = partB;
    }

    void makePartC(std::string partC){
        _partC = partC;
    }

    std::string get(){
        return (_partA + " " + _partB + " " + _partC);
    }
};

class Builder{
protected:
    Product _product;

public:
    virtual ~Builder(){}
    virtual void buildPartsA() = 0;
    virtual void buildPartsB() = 0;
    virtual void buildPartsC() = 0;

    Product get(){
        return _product;
    }
};

class ConcreteBuilderX : public Builder{
public:
    ~ConcreteBuilderX () {
        std::cout<<"Destructor: ConcreteBuilderX\n";
    }

    void buildPartsA(){
        _product.makePartA("X-A");
    }
    
    void buildPartsB(){
        _product.makePartB("X-B");
    }

    void buildPartsC(){
        _product.makePartC("X-C");
    }
};

class ConcreteBuilderY : public Builder{
public:
    ~ConcreteBuilderY () {
        std::cout<<"Destructor: ConcreteBuilderY\n";
    }

    void buildPartsA(){
        _product.makePartA("Y-A");
    }
    
    void buildPartsB(){
        _product.makePartB("Y-B");
    }

    void buildPartsC(){
        _product.makePartC("Y-C");
    }
};

class ConcreteBuilderZ : public Builder{
public:
    ~ConcreteBuilderZ () {
        std::cout<<"Destructor: ConcreteBuilderZ\n";
    }

    void buildPartsA(){
        _product.makePartA("Z-A");
    }

    void buildPartsB(){
        _product.makePartB("Z-B");
    }

    void buildPartsC(){
        _product.makePartC("Z-C");
    }
};

class Director{
private:
    std::unique_ptr<Builder> _builder;

public:
    Director(): _builder(nullptr){}
    
    void set(std::unique_ptr<Builder> builder) {
        _builder = std::move(builder);
      }

    void createProduct(){
        _builder->buildPartsA();
        _builder->buildPartsB();
        _builder->buildPartsC();
    }

    Product getProduct(){
        return _builder->get();
    }
};