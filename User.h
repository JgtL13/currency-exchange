#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#define _USER_H_
using namespace std;

class User
{
private:
    double buy,sell;
    string country1,country2;
    int total1,total2;
    int thousand1,thousand2;
    int hundred1,hundred2;
    int ten1,ten2;
    int one1,one2;

public:
    User();
    void checkCurrency();
    bool trade();
    bool chooseInput();
    void chooseOutput();
    void input();
    void output();
    void print();
};
