#ifndef stuff
#define stuff

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

class Bttn{
    public:
        Bttn();
        Bttn(int, int, int, int, string);
        ~Bttn();

        int getWidth();
        int getHeight();
        int getXpos();
        int getYpos();
        string getValue();

        void setWidth(int);
        void setHeight(int);
        void setPosAndValue(int, int, string);
        void setXpos(int);
        void setYpos(int);
        void setValue(string);
    private:
        //position and size of the button
        int width;
        int height;
        int xpos;
        int ypos;
        //value of the button
        string value;
};

#endif
