#include <iostream>

using namespace std;

#define STATIC_POINTER 0

class DialogComponent{
#if STATIC_POINTER
    static DialogComponent *m_dialog;
#endif
    int m_width;
    int m_height;
    float m_opacity;
    bool m_isVisisble;

    // Constructor is private
    DialogComponent(): m_width(60), m_height(80), m_opacity(1.0), m_isVisisble(true) {}

public:
#if STATIC_POINTER
    static DialogComponent* getInstance(){
        if(m_dialog == nullptr)
            m_dialog = new DialogComponent;
        return m_dialog;
    }
#else
    static DialogComponent& getInstance(){
        static DialogComponent m_dialog;
        return m_dialog;
    }
#endif
    // Setters
    void setWidth(int width){ m_width = width; }
    void setHeight(int height){ m_height = height; }
    void setOpacity(float opacity){ m_opacity = opacity; }
    void setVisibility(bool isVisible) {m_isVisisble = isVisible; }

    //Getters
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }
    float getOpacity() { return m_opacity; }
    bool getVisibility() { return m_isVisisble; }

    void DisplaySettings(){
        cout<<"Width: "<<m_width<<"\n";
        cout<<"Height: "<<m_height<<"\n";
        cout<<"Opacity: "<<m_opacity<<"\n";
        cout<<"Visible: "<<m_isVisisble<<"\n";
    }
};