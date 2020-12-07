#include "HiringManager.h"

int main(){

    std::unique_ptr<HiringManager> manager;
    {
        manager = std::make_unique<DeveloperManager>();

        auto pr = manager->createInterviewer();
        std::cout<<pr->getName()<<"\n";
        std::cout<<pr->askQuestion()<<"\n";
    }
    
    {
        manager = std::make_unique<CommunityManager>();
        auto pr = manager->createInterviewer();
        std::cout<<pr->getName()<<"\n";
        std::cout<<pr->askQuestion()<<"\n";
    }
}