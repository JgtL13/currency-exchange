#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#define _STOCK_H_
using namespace std;

class Stock
{
private:
    string countryName;
    int thousands;
    int hundreds;
    int tens;
    int ones;
public:
    Stock();
    Stock(string cn, int thou, int hun, int ten, int one);
    void changeAmount(int thou, int hun, int ten, int one);
    string getCountryName();
    int getThousands();
    int getHundreds();
    int getTens();
    int getOnes();
    void increase(int thou, int hun, int ten, int one);
    void decrease(int thou, int hun, int ten, int one);
};
