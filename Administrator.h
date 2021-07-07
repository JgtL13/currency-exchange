#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#define _ADMINISTRATOR_H_
using namespace std;

class Administrator
{
private:
    string password;
public:
    Administrator();
    string inputPassword();
    int changeCurrency();
    void changeValue(int);
    void addCountry();
    bool isAdmin(string);
    int choose();
};
