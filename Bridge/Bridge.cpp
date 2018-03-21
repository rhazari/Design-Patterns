#include <iostream>
#include <memory>
#include <string>


class Implementation{
public:
    virtual void platform() = 0;
};

// Different platform implementations
class Windows: public Implementation{
public:
    void platform() override{
        std::cout<<"Windows Platform"<<"\n";
    }
};

class Linux: public Implementation{
public:
    void platform() override{
        std::cout<<"Linux Platform"<<"\n";
    }
};

class Mac: public Implementation{
public:
    void platform() override{
        std::cout<<"Mac Platform"<<"\n";
    }
};

class Abstraction{
public:
    virtual void threadScheduler() = 0;
}; 

class Bridge: public Abstraction{
public:
    Bridge(Implementation *impl){
        m_ptr = impl;
    }

protected:
    Implementation *m_ptr;
};

class UseCase1: public Bridge{
public:
    UseCase1(Implementation *impl)
    :Bridge(impl){}

    void threadScheduler() override{
        std::cout<<"Preemptive Scheduler"<<"\n";
        m_ptr->platform();
    }
};

class UseCase2: public Bridge{
public:
    UseCase2(Implementation *impl)
    :Bridge(impl){}

    void threadScheduler() override{
        std::cout<<"Time Sliced Scheduler"<<"\n";
        m_ptr->platform();
    }
};

int main(){
    Implementation *osWindows = new Windows;
    Implementation *osLinux = new Linux;
    Implementation *osMac = new Mac;

    Abstraction *ptr = new UseCase1(osWindows);
    ptr->threadScheduler();
    delete ptr;

    ptr =  new UseCase2(osLinux);
    ptr->threadScheduler();
    delete ptr;

    ptr = new UseCase1(osMac);
    ptr->threadScheduler();
    delete ptr;

    delete osWindows;
    delete osLinux;
    delete osMac;

    return 0;
}