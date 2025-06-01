#ifndef HELPER_H
#define HELPER_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int BUFFER_SIZE = 1000;

void ClearInputError();
string SetUpper(string rhs);
string GetString(string prompt);
int GetNum(string prompt);
int GiveRanVal(int minVal, int maxVal);


#endif