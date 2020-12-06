#pragma once
#include "Theme.h"

class WebPage{
public:
    virtual ~WebPage() {}

    virtual void getContent() = 0;

};

class AboutPage: public WebPage{
    Theme* _theme;
public:
    ~AboutPage() {
        delete _theme;
    }

    AboutPage(Theme* theme): _theme(theme){}

    void getContent() {
        std::cout<<"About page in "<<_theme->getColor()<<"\n";
    }
};

class CareerPage: public WebPage{
    Theme* _theme;
public:
    ~CareerPage() {
        delete _theme;
    }

    CareerPage(Theme* theme): _theme(theme){}

    void getContent() {
        std::cout<<"Career page in "<<_theme->getColor()<<"\n";
    }
};

class HomePage: public WebPage{
    Theme* _theme;
public:
    ~HomePage() {
        delete _theme;
    }

    HomePage(Theme* theme): _theme(theme){}

    void getContent() {
        std::cout<<"Home page in "<<_theme->getColor()<<"\n";
    }
};