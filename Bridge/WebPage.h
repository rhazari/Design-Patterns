#pragma once
#include "Theme.h"
#include <memory>

class WebPage{
protected:
    std::unique_ptr<Theme> _theme;
public:
    virtual ~WebPage() {}

    WebPage(std::unique_ptr<Theme> theme): _theme(std::move(theme)){}

    virtual void getContent() = 0;

};

class AboutPage: public WebPage{
public:
    AboutPage(std::unique_ptr<Theme> theme): WebPage(std::move(theme)) {}

    void getContent() {
        std::cout<<"About page in "<<_theme->getColor()<<"\n";
    }
};

class CareerPage: public WebPage{
public:
    CareerPage(std::unique_ptr<Theme> theme): WebPage(std::move(theme)){}

    void getContent() {
        std::cout<<"Career page in "<<_theme->getColor()<<"\n";
    }
};

class HomePage: public WebPage{
public:
    HomePage(std::unique_ptr<Theme> theme): WebPage(std::move(theme)){}

    void getContent() {
        std::cout<<"Home page in "<<_theme->getColor()<<"\n";
    }
};