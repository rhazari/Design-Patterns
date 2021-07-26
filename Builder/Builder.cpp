#include "Builder.h"

void ClientDriver(std::unique_ptr<Director> director){
    auto builder = std::make_unique<ConceteBuilder>();
    director->SetBuilder(builder.get());

    std::cout<<"Basic Minimal Product\n";
    director->BuildMinimalProduct();
    auto ptr = builder->GetProduct();
    ptr->ListParts();

    std::cout<<"Full Feature Product\n";
    director->BuildFullFeatureProdcut();
    ptr = builder->GetProduct();
    ptr->ListParts();

    std::cout<<"Custom Product\n";
    builder->ProducePartA();
    builder->ProducePartC();

    ptr = builder->GetProduct();
    ptr->ListParts();
}

int main(){

    ClientDriver(std::make_unique<Director>());
    
}