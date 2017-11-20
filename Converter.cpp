#ifndef guard3
#define guard3
#include <string>
#include <math.h>
#include "Converter.h"

//constructors
Converter::Converter() {
    base = 10;
    numneg = false;
    lastnumneg = false;
    lastnumber = "";
}
Converter::~Converter() {

}

//misc function
string rev(string s) {
    string f;
    for (int i = s.length()-1; i >= 0; i--) {
        f += s.substr(i,1);
    }
    return f;
}
//functions
string Converter::convert() {
    if (op == "^") {
        number = squared(number);
    } else if (op == "r") {
        //number = toString(sqrt(toString(number)));
    } else if (op == "%") {
        number = mod(lastnumber, number);
    } else if (op == "+") {
        number = add(number, lastnumber);
    } else if (op == "-") {
        number = subtract(lastnumber, number);
    } else if (op == "x") {
        number = multiply(number, lastnumber);
    } else if (op == "/") {
        number = divide(lastnumber, number);
    }
    return number;
}
string Converter::add(string input1, string input2) {
    double in1 = toDouble(input1);
    double in2 = toDouble(input2);
    return toString(in1 + in2);
}
string Converter::subtract(string input1, string input2) {
    double in1 = toDouble(input1);
    double in2 = toDouble(input2);
    return toString(in1 - in2);
}
string Converter::multiply(string input1, string input2) {
    double in1 = toDouble(input1);
    double in2 = toDouble(input2);
    return toString(in1 * in2);
}
string Converter::divide(string input1, string input2) {
    double in1 = toDouble(input1);
    double in2 = toDouble(input2);
    return toString(in1/in2);
}
string Converter::mod(string input1, string input2) {
    double in1 = toDouble(input1);
    double in2 = toDouble(input2);
    return toString(fmod(in1, in2));
}
string Converter::squared(string input1) {
    double in1 = toDouble(input1);
    string result = toString(in1*in1);
    return result;
}

double Converter::toDouble(string in1) {
    string input1 = rev(in1);
    double result = 0;
    int multiplier = 1;
    for (int i = 0; i < input1.length(); i++) {
        if (input1[i] == '1') {
            result += multiplier;
        } else if (input1[i] == '2') {
            result += multiplier * 2;
        } else if (input1[i] == '3') {
            result += multiplier * 3;
        } else if (input1[i] == '4') {
            result += multiplier * 4;
        } else if (input1[i] == '5') {
            result += multiplier * 5;
        } else if (input1[i] == '6') {
            result += multiplier * 6;
        } else if (input1[i] == '7') {
            result += multiplier * 7;
        } else if (input1[i] == '8') {
            result += multiplier * 8;
        } else if (input1[i] == '9') {
            result += multiplier * 9;
        } else if (input1[i] == 'A') {
            result += multiplier * 10;
        } else if (input1[i] == 'B') {
            result += multiplier * 11;
        } else if (input1[i] == 'C') {
            result += multiplier * 12;
        } else if (input1[i] == 'D') {
            result += multiplier * 13;
        } else if (input1[i] == 'E') {
            result += multiplier * 14;
        } else if (input1[i] == 'F') {
            result += multiplier * 15;
        }
        multiplier *= base;
    }
    return result;
}

string Converter::toString(double input1) {
    double d = input1;
    string result;

    d -= fmod(d,1);
    int c = 0;
    double l = 1;
    int exponent = 0;
    while (l <= d) {
        l *= base;
        exponent++;
    }
    l /= base;

    for (int i = 0; i < exponent; i++) {
        int add = l;
        int c2 = 0;
        while (add <= d) {
            add += l;
            c2++;
        }

        add -= l;
        d -= add;

        l /= base;

        if (c2 == 0) {
            result += "0";
        } else if (c2 == 1) {
            result += "1";
        } else if (c2 == 2) {
            result += "2";
        } else if (c2 == 3) {
            result += "3";
        } else if (c2 == 4) {
            result += "4";
        } else if (c2 == 5) {
            result += "5";
        } else if (c2 == 6) {
            result += "6";
        } else if (c2 == 7) {
            result += "7";
        } else if (c2 == 8) {
            result += "8";
        } else if (c2 == 9) {
            result += "9";
        } else if (c2 == 10) {
            result += "A";
        } else if (c2 == 11) {
            result += "B";
        } else if (c2 == 12) {
            result += "C";
        } else if (c2 == 13) {
            result += "D";
        } else if (c2 == 14) {
            result += "E";
        } else if (c2 == 15) {
            result += "F";
        }
    }
    if (result == "") {
        result = "0";
    }
    return result;
}




//getters and setters
string Converter::getNumber() {
    return number;
}
string Converter::getLastNumber() {
    return lastnumber;
}
string Converter::getPrevious(int i) {
    return previous[i];
}
int Converter::getBase() {
    return base;
}
string Converter::getOp() {
    return op;
}
bool Converter::getNumNeg() {
    return numneg;
}
bool Converter::getLastNumNeg() {
    return lastnumneg;
}

void Converter::setNumber(string s) {
    number = s;
}
void Converter::setLastNumber(string s) {
    lastnumber = s;
}
void Converter::setPrevious(string s, int i) {
    previous[i] = s;
}
void Converter::setOp(string s) {
    op = s;
}
void Converter::setNumNeg() {
    numneg = !numneg;
}
void Converter::setLastNumNeg() {
    lastnumneg = !lastnumneg;
}
#endif
