#include "myfunctions.hpp"
#include "myfunctions.cpp"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main ()
{
    ///
    string text;
    text = requestString();
    cout << "Text: " << text << endl;

    ///
    int typeText;
    typeText = analyseString(text);
    
    if (typeText == 0)
    {
        // Int -> degree
        cout << "The angle is expressed using degree " << endl; 
    }
    else if (typeText == 1)
    {
        // Float _ radian
        cout << "The angle is expressed using radian " << endl; 
    }
    else
    {
        cout << "Wrong data" << endl;
    }
    
    ///
    float cosValue, sinValue;
    if(typeText == 0)
    {
        int angle;
        stringToAngle(text, angle);
        computeCosSin(angle, cosValue, sinValue);
        cout << "For " << angle << " degrees, cos = " << cosValue << " and  sin = " << sinValue << endl;
    }
    else if (typeText == 1)
    {
        float angle;
        stringToAngle(text, angle);
        computeCosSin(angle, cosValue, sinValue);
        cout << "For " << angle << " radians, cos = " << cosValue << " and  sin = " << sinValue << endl;
    }
    else
    {
        cout << "Type of data not taken into account" << endl;
    }
    return 0;
}

