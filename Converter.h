#ifndef guard2
#define guard2

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>

class Converter{
    public:
        Converter();
        ~Converter();

        string convert();
        //Operators
        string add(string input1, string input2);
        string subtract(string input1, string input2);
        string multiply(string input1, string input2);
        string divide(string input1, string input2);
        string mod(string input1, string input2);
        string squared(string input1);
        //Changes the string into a Double for calculations
        double toDouble(string input1);
        //Changes the float back to a string
        string toString(double input1);
        //getters/setters
        string getNumber();
        string getOp();
        string getLastNumber();
        string getPrevious(int);
        bool getNumNeg();
        bool getLastNumNeg();

        int getBase();
        void setOp(string);
        void setNumber(string);
        void setLastNumber(string);
        void setPrevious(string, int);
        void setNumNeg();
        void setLastNumNeg();
    private:
        //string used to hold number after the operator
        string number;
        //string to hold the number used before the operator
        string lastnumber;
        //operator
        string op;
        //array of previous numbers (can hold up to 100)
        string previous[100];
        //current base
        int base;
        //number is negative
        bool numneg;
        //last number is negative
        bool lastnumneg;
};

#endif
