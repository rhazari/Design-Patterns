#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Product{
    std::vector<std::string> _parts;
public:
    void ListParts() const{
        std::cout<<"Product Parts: ";
        for(size_t k = 0; k < _parts.size(); ++k){
            if(k == _parts.size()-1){
                std::cout<<_parts[k];
            }
            else{
                std::cout<<_parts[k]<<", ";
            }
        }
        std::cout<<"\n";
    }

    void AddPart(const std::string& part) {
        _parts.push_back(part);
    }
};

class Builder{
public:
    virtual ~Builder(){}

    virtual void ProducePartA() const = 0;
    virtual void ProducePartB() const = 0;
    virtual void ProducePartC() const = 0;
};

class ConceteBuilder: public Builder {
    std::unique_ptr<Product> _product;
public:

    ConceteBuilder(){
        Reset();
    }

    void Reset(){
        _product = std::make_unique<Product>();
    }

    void ProducePartA() const override{
        _product->AddPart("PartA");
    }

    void ProducePartB() const override{
        _product->AddPart("PartB");
    }

    void ProducePartC() const override{
        _product->AddPart("PartC");
    }

    std::unique_ptr<Product> GetProduct() {
        auto ptr = std::move(_product);
        Reset();
        return ptr;
    }
};

class Director{
    Builder* _builder;
public:
    void SetBuilder(Builder* bd){
        _builder = bd;
    }

    // The Director can construct several variations
    void BuildMinimalProduct(){
        _builder->ProducePartA();
    }

    void BuildFullFeatureProdcut(){
        _builder->ProducePartA();
        _builder->ProducePartB();
        _builder->ProducePartC();
    }
};
