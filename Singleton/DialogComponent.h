#include <iostream>

#define STATIC_POINTER 0

class DialogComponent{
#if STATIC_POINTER
    static DialogComponent *m_dialog;
#endif
    int _width;
    int _height;
    float _opacity;
    bool _isVisisble;

    // Constructor is private
    DialogComponent(): _width(60), _height(80), _opacity(1.0), _isVisisble(true) {}

public:
#if STATIC_POINTER
    static DialogComponent* getInstance(){
        if(_dialog == nullptr)
            _dialog = new DialogComponent;
        return _dialog;
    }
#else
    static DialogComponent& getInstance(){
        static DialogComponent _dialog;
        return _dialog;
    }
#endif
    // Setters
    void setWidth(int width){ _width = width; }
    void setHeight(int height){ _height = height; }
    void setOpacity(float opacity){ _opacity = opacity; }
    void setVisibility(bool isVisible) {_isVisisble = isVisible; }

    //Getters
    int getWidth() { return _width; }
    int getHeight() { return _height; }
    float getOpacity() { return _opacity; }
    bool getVisibility() { return _isVisisble; }

    void DisplaySettings(){
        std::cout<<"Width: "<<_width<<"\n";
        std::cout<<"Height: "<<_height<<"\n";
        std::cout<<"Opacity: "<<_opacity<<"\n";
        std::cout<<"Visible: "<<_isVisisble<<"\n";
    }
};