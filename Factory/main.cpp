#include "HiringManager.h"
#include <memory>

int main(){

    HiringManager* manager;
    {
        manager = new DeveloperManager();

        auto pr = manager->createInterviewer();
        std::cout<<pr->getName()<<"\n";
        std::cout<<pr->askQuestion()<<"\n";
        manager->removeInterviewer(pr);
        delete manager;
    }
    
    {
        manager = new CommunityManager();

        auto pr = manager->createInterviewer();
        std::cout<<pr->getName()<<"\n";
        std::cout<<pr->askQuestion()<<"\n";
        manager->removeInterviewer(pr);
        delete manager;
    }
}