#include "WebPage.h"

int main() {
    std::unique_ptr<WebPage> page;
    {
        page = std::make_unique<AboutPage>(std::make_unique<DarkTheme>());
        page->getContent();
    }

    {
        page = std::make_unique<HomePage>(std::make_unique<LightTheme>());
        page->getContent();
    }

    {
        page = std::make_unique<CareerPage>(std::make_unique<AquaTheme>());
        page->getContent();
    }
}