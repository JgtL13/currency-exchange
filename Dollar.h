#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#define _Dollar_H_
using namespace std;

class Dollar
{
private:
    string CountryName;
    double BuyIn;
    double SellOut;

public:
    Dollar(string a,double b,double c);
    void changeCurrency(double buy, double sell);
    string get_CountryName();
    double get_BuyIn();
    double get_SellOut();
};
