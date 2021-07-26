#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Product{
    std::vector<std::string> parts_;
public:
    void ListParts() const{
        std::cout<<"Product Parts: ";
        for(size_t k = 0; k < parts_.size(); ++k){
            if(k == parts_.size()-1){
                std::cout<<parts_[k];
            }
            else{
                std::cout<<parts_[k]<<", ";
            }
        }
        std::cout<<"\n";
    }

    void AddPart(const std::string& part) {
        parts_.push_back(part);
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
    std::unique_ptr<Product> product_;
public:

    ConceteBuilder(){
        Reset();
    }

    void Reset(){
        product_ = std::make_unique<Product>();
    }

    void ProducePartA() const override{
        product_->AddPart("PartA");
    }

    void ProducePartB() const override{
        product_->AddPart("PartB");
    }

    void ProducePartC() const override{
        product_->AddPart("PartC");
    }

    std::unique_ptr<Product> GetProduct() {
        auto ptr = std::move(product_);
        Reset();
        return ptr;
    }
};

class Director{
    Builder* builder_;
public:
    void SetBuilder(Builder* bd){
        builder_ = bd;
    }

    // The Director can construct several variations
    void BuildMinimalProduct(){
        builder_->ProducePartA();
    }

    void BuildFullFeatureProdcut(){
        builder_->ProducePartA();
        builder_->ProducePartB();
        builder_->ProducePartC();
    }
};
