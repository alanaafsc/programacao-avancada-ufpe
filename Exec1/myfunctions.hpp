#include <iostream>
#include <string>
#include <sstream>
#include <math.h> 
using namespace std;

#ifndef __MYFUNCTIONS_H_ //NOME DO HEADER
#define __MYFUNCTIONS_H_  //DEFINICAO DO HEADER

int analyseString(string text);
string requestString();
template <class T, class U> void stringToAngle(T &text, U &angle);
template <class T, class U, class P> void computeCosSin(T &angle, U &cosValue, P &sinValue); 

#endif