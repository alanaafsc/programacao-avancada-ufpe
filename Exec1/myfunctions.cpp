#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "myfunctions.hpp"

using namespace std;

int analyseString(string text) {
    int result = -1; //if string text had a dot, it will be a float
     // Find first occurrence of '.'
    size_t found = text.find('.');
    size_t found2 = text.find(',');

    if(text == ""){
        return result;
    }

    for(int i = 0; i < text.size(); i++) {
       if(!isdigit(text[i])) {
            if(found != string::npos || found2 != string::npos) {
                return result = 1;
            } else {
                return result = -1;
            }
       } else {
        result = 0;
       }
    }

    return result;
}

string requestString() {
   string text;
   cout << "Enter the angle you want to calculate sine and cosine for: ";
   getline(cin, text);
   return text;
}

template <class T, class U> void stringToAngle(T &text, U &angle) {
    if(analyseString(text) == 0) {
        stringstream(text) >> angle;
    } else if (analyseString(text) == 1) {
        angle = stof(text);
    }
}

template <class T, class U, class P> void computeCosSin(T &angle, U &cosValue, P &sinValue) { 
    int result;
    if(angle == (int)angle) { 
        result = 0;
    } else {
        result = 1;
    }
    if(result == 1) {
        sinValue = sin(angle);
        cosValue = cos(angle);
    } else if (result == 0){
        float radian=angle*3.14/180;
        sinValue = sin(radian);
        cosValue = cos(radian);
    }
}