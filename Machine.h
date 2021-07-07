#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include "Stock.h"
#define _MACHINE_H_
using namespace std;

struct Machine
{
    Machine();
    int greeting();
    int chooseCountry(int situation);
    bool CorB(int situation, bool chooseCountryFunctionUsed, int country);
    void chooseFunction();
    string toLower(string s);
};
