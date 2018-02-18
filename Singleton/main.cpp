#include "DialogComponent.h"

using namespace std;

DialogComponent* DialogComponent::m_dialog = nullptr;
int main(){
    DialogComponent* dialog = DialogComponent::getInstance();
    dialog->DisplaySettings();

    // Change of Settings
    cout<<"\n";
    dialog->setHeight(100);
    dialog->setWidth(150);
    dialog->setOpacity(0.5);

    dialog->DisplaySettings();
    return 0;
}