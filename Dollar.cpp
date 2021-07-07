#include "Dollar.h"

Dollar::Dollar(string a,double b,double c)//yo
{
    CountryName=a;
    BuyIn=b;
    SellOut=c;
}

void Dollar::changeCurrency(double buy, double sell)//ting
{
    BuyIn = buy;
    SellOut = sell;
}

string Dollar::get_CountryName()//yo
{
    return CountryName;
}

double Dollar::get_BuyIn()//yo
{
    return BuyIn;
}

double Dollar::get_SellOut()//yo
{
    return SellOut;
}
