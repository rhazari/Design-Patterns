#include "WebPage.h"

int main() {
    WebPage* page;
    {
        page = new AboutPage(new DarkTheme());
        page->getContent();
        delete page;
    }

    {
        page = new HomePage(new LightTheme());
        page->getContent();
        delete page;
    }

    {
        page = new CareerPage(new AquaTheme());
        page->getContent();
        delete page;
    }
}