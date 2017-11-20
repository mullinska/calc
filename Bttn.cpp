#ifndef stuff2
#define stuff2
#include <string>
#include "Bttn.h"

//constructors
Bttn::Bttn() {

}
Bttn::Bttn(int x, int y, int hght, int wdth, string s) {
    xpos = x;
    ypos = y;
    height = hght;
    width = wdth;
    value = s;
}
Bttn::~Bttn() {

}

//functions


//getters/setters
int Bttn::getWidth() {
    return width;
}
int Bttn::getHeight() {
    return height;
}
int Bttn::getXpos() {
    return xpos;
}
int Bttn::getYpos() {
    return ypos;
}
string Bttn::getValue() {
    return value;
}
void Bttn::setWidth(int w) {
    width = w;
}
void Bttn::setHeight(int h) {
    height = h;
}
void Bttn::setXpos(int x) {
    xpos = x;
}
void Bttn::setYpos(int y) {
    ypos = y;
}
void Bttn::setValue(string s) {
    value = s;
}
void Bttn::setPosAndValue(int x, int y, string s) {
    xpos = x;
    ypos = y;
    value = s;
}

#endif
