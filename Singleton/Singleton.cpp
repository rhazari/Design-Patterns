#include "DialogComponent.h"

using namespace std;

#if STATIC_POINTER
    DialogComponent* DialogComponent::m_dialog = nullptr;
#endif

int main(){

#if STATIC_POINTER
    std::cout<<"*** STATIC POINTER ***"<<"\n";
    DialogComponent* dialog = DialogComponent::getInstance();
    dialog->DisplaySettings();

    // Change of Settings
    std::cout<<"\n";
    dialog->setHeight(100);
    dialog->setWidth(150);
    dialog->setOpacity(0.5);

    dialog->DisplaySettings();

#else
    std::cout<<"*** LOCAL STATIC ***"<<"\n";
    DialogComponent dialog = DialogComponent::getInstance();
    dialog.DisplaySettings();

    // Change of Settings
    std::cout<<"\n";
    dialog.setHeight(100);
    dialog.setWidth(150);
    dialog.setOpacity(0.5);

    dialog.DisplaySettings();

#endif
}