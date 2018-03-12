#include <iostream>

class Product{
private:
    std::string m_partA;
    std::string m_partB;
    std::string m_productName;

public:
    Product(std::string productName):
        m_productName(productName){}

    void makePartA(std::string partA){
        m_partA = partA;
    }

    void makePartB(std::string partB){
        m_partB = partB;
    }

    std::string getPartA(){
        return m_partA;
    }


    std::string getPartB(){
        return m_partB;
    }

    void display(){
        std::cout<<"Product: "<<m_productName<<"\n";
        std::cout<<"PartA :"<<m_partA<<"\n";
        std::cout<<"PartB :"<<m_partB<<"\n";
    }
};

class AbstractBuilder{
protected:
    Product *m_product;

public:
    virtual ~AbstractBuilder(){}

    virtual void setProduct() = 0;
    virtual void buildPartsA() = 0;
    virtual void buildPartsB() = 0;

    Product* get(){
        return m_product;
    }
};

class ConcreteBuilderX : public AbstractBuilder{
public:
    void setProduct() {
        m_product = new Product("Product-X");
    }

    void buildPartsA(){
        m_product->makePartA("X-A");
    }
    
    void buildPartsB(){
        m_product->makePartB("X-B");
    }
};

class ConcreteBuilderY : public AbstractBuilder{
public:
    void setProduct() {
        m_product = new Product("Product-Y");
    }

    void buildPartsA(){
        m_product->makePartA("Y-A");
    }
    
    void buildPartsB(){
        m_product->makePartB("Y-B");
    }
};

class ConcreteBuilderZ : public AbstractBuilder{
public:
    void setProduct() {
        m_product = new Product("Product-Z");
    }

    void buildPartsA(){
        m_product->makePartA("Z-A");
    }

    void buildPartsB(){
        m_product->makePartB("Z-B");
    }
};

class Director{
private:
    AbstractBuilder* m_builder;

public:
    Director():
        m_builder(nullptr){}

    ~Director() {
        if (m_builder) {
            delete m_builder;
        }
    }

    void set(AbstractBuilder *b) {
        if (m_builder) {
            delete m_builder;
        }
        m_builder = b;
      }

    void createProduct(){
        m_builder->setProduct();
        m_builder->buildPartsA();
        m_builder->buildPartsB();
    }

    Product* getProduct(){
        return m_builder->get();
    }
};