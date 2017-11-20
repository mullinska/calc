#ifndef guard
#define guard

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Bttn.h"

class Win {
    public:
        Win();
        ~Win();

        string rev(string);
        int run();
        void loadButtons();
        void callButton();
        //Update window
        void draw(sf::RenderWindow);

        //getters&setters
        int getHeight();
        int getWidth();
        bool getFullscreen();

        void setHeight(int height);
        void setWidth(int width);
    private:
        //window properties
        int height;
        int width;

        //mouse
        int mousex;
        int mousey;
        bool mousepressed;
        bool buttonlock;

        //Here's an array of button objects with an arbitrary number inside
        Bttn buttons[30];
        sf::RenderWindow window;
        sf::Font font;
        sf::Text text;
        sf::Text result;
};

#endif
