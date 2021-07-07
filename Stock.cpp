#include "Stock.h"
#include "Dollar.h"

Stock::Stock()//ting
{

}

Stock::Stock(string cn, int thou, int hun, int ten, int one)//ting
{
    countryName = cn;
    thousands = thou;
    hundreds = hun;
    tens = ten;
    ones = one;
}

void Stock::changeAmount(int thou, int hun, int ten, int one)//ting
{
    thousands += thou;
    hundreds += hun;
    tens += ten;
    ones += one;
}

void Stock::increase(int thou, int hun, int ten, int one)//yo
{
    thousands+=thou;
    hundreds+=hun;
    tens+=ten;
    ones+=one;
}

void Stock::decrease(int thou, int hun, int ten, int one)//yo
{
    thousands-=thou;
    hundreds-=hun;
    tens-=ten;
    ones-=one;
}

string Stock::getCountryName()//ting
{
    return countryName;
}

int Stock::getThousands()//ting
{
    return thousands;
}

int Stock::getHundreds()//ting
{
    return hundreds;
}

int Stock::getTens()//ting
{
    return tens;
}

int Stock::getOnes()//ting
{
    return ones;
}
