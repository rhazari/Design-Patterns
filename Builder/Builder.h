#pragma once
#include <iostream>
#include <string>

class Product{
private:
    std::string _partA;
    std::string _partB;
    std::string _productName;

public:
    Product(std::string productName):
        _productName(productName){}

    void makePartA(std::string partA){
        _partA = partA;
    }

    void makePartB(std::string partB){
        _partB = partB;
    }

    std::string getPartA(){
        return _partA;
    }


    std::string getPartB(){
        return _partB;
    }

    void display(){
        std::cout<<"Product: "<<_productName<<"\n";
        std::cout<<"PartA :"<<_partA<<"\n";
        std::cout<<"PartB :"<<_partB<<"\n";
    }
};

class AbstractBuilder{
protected:
    Product *_product;

public:
    virtual ~AbstractBuilder(){}

    virtual void setProduct() = 0;
    virtual void buildPartsA() = 0;
    virtual void buildPartsB() = 0;

    Product* get(){
        return _product;
    }
};

class ConcreteBuilderX : public AbstractBuilder{
public:
    ~ConcreteBuilderX () {
        std::cout<<"Destructor: ConcreteBuilderX\n";
    }

    void setProduct() {
        _product = new Product("Product-X");
    }

    void buildPartsA(){
        _product->makePartA("X-A");
    }
    
    void buildPartsB(){
        _product->makePartB("X-B");
    }
};

class ConcreteBuilderY : public AbstractBuilder{
public:
    ~ConcreteBuilderY () {
        std::cout<<"Destructor: ConcreteBuilderY\n";
    }

    void setProduct() {
        _product = new Product("Product-Y");
    }

    void buildPartsA(){
        _product->makePartA("Y-A");
    }
    
    void buildPartsB(){
        _product->makePartB("Y-B");
    }
};

class ConcreteBuilderZ : public AbstractBuilder{
public:
    ~ConcreteBuilderZ () {
        std::cout<<"Destructor: ConcreteBuilderZ\n";
    }

    void setProduct() {
        _product = new Product("Product-Z");
    }

    void buildPartsA(){
        _product->makePartA("Z-A");
    }

    void buildPartsB(){
        _product->makePartB("Z-B");
    }
};

class Director{
private:
    AbstractBuilder* _builder;

public:
    Director():
        _builder(nullptr){}

    ~Director() {
        if (_builder) {
            delete _builder;
        }
    }

    void set(AbstractBuilder *b) {
        if (_builder) {
            delete _builder;
        }
        _builder = b;
      }

    void createProduct(){
        _builder->setProduct();
        _builder->buildPartsA();
        _builder->buildPartsB();
    }

    Product* getProduct(){
        return _builder->get();
    }
};