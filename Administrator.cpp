#include "Administrator.h"
#include "Machine.h"
#include "Dollar.h"

Administrator::Administrator()//ting
{
    password = "ncyucsie";
}

string Administrator::inputPassword()//ting
{
    Machine m;
    string input;
    char p[9999] = {};
    int i = 0;
    while(true)
    {
        system("cls");
        cout << "Please enter your password" << endl;
        for(int j = 0; j < i; ++j)
        {
            cout << "*";
        }
        p[i]=getch();
        cout << endl;
        if(p[i] == 8)//press backspace
        {
            --i;
        }
        else if(p[i]==13)//press enter
        {
            for(int j = 0; j < i; ++j)
            {
                input += p[j];
            }
            break;
        }
        else
        {
            ++i;
        }
    }
    return input;
}

int Administrator::changeCurrency()//ting
{
    Machine m;
    string input, cn, country;
    stringstream ss;
    string buyS, sellS;
    double buy, sell;
    vector <Dollar> dollar;
    ifstream inFile("Currency.txt");
    while(!inFile.eof())
    {
        getline(inFile, input);
        ss << input;
        ss >> cn >> buy >> sell;
        Dollar Dollar(cn, buy, sell);
        dollar.push_back(Dollar);
        ss.clear();
    }
    inFile.close();

    cout << "Please choose the country you would like to process" << endl;
    int choose = m.chooseCountry(2);
    country = dollar[choose].get_CountryName();
    while(true)
    {
        while(true)
        {
            int dotCounter = 0;
            bool inValid = false;
            cout << "Please enter buy currency:";
            cin >> buyS;
            for(int i = 0; i < buyS.size(); ++i)
            {
                if(buyS[i] == '.')
                {
                    ++dotCounter;
                    continue;
                }
                else if(!isdigit(buyS[i]))
                {
                    inValid = true;
                    break;
                }
            }
            if(inValid || dotCounter > 1)
            {
                system("cls");
                continue;
            }
            else
            {
                ss << buyS;
                ss >> buy;
                ss.clear();
                break;
            }
        }
        while(true)
        {
            int dotCounter = 0;
            bool inValid = false;
            cout << "Please enter sell currency:";
            cin >> sellS;
            for(int i = 0; i < sellS.size(); ++i)
            {
                if(sellS[i] == '.')
                {
                    ++dotCounter;
                    continue;
                }
                else if(!isdigit(sellS[i]))
                {
                    inValid = true;
                    break;
                }
            }
            if(inValid || dotCounter > 1)
            {
                system("cls");
                cout << "Please enter buy currency:" << buy << endl;
                continue;
            }
            else
            {
                ss << sellS;
                ss >> sell;
                ss.clear();
                break;
            }
        }
        if(buy < sell && buy != 0 && sell != 0)
        {
            dollar[choose].changeCurrency(buy, sell);
            break;
        }
        else
        {
            system("cls");
            cout << "The currency you entered is invalid" << endl
                 << "(buy currency must be smaller than sell currency)" << endl
                 << "Please enter again" << endl << endl;
            continue;
        }
    }

    ofstream outFile;
    outFile.open("Currency.txt");
    for(unsigned int i = 0; i < dollar.size(); ++i)
    {
        outFile << dollar[i].get_CountryName() << " "
                << dollar[i].get_BuyIn() << " "
                << dollar[i].get_SellOut() << " ";
        if(i != dollar.size() - 1)
        {
            outFile << endl;
        }
    }
    outFile.close();
    return choose;
}

void Administrator::changeValue(int choose)//ting
{
    string cn;
    int thou, hun, ten, one;
    string input;
    stringstream ss;
    vector <Stock> stock;
    ifstream inFile("Stock.txt");
    while(!inFile.eof())
    {
        getline(inFile, input);
        ss << input;
        ss >> cn >> thou >> hun >> ten >> one;
        Stock stk(cn, thou, hun, ten, one);
        stock.push_back(stk);
    }
    inFile.close();

    string thS, hS, teS, oS;
    int th, h, te, o;
    while(true)
    {
        bool wrong = false;
        system("cls");
        cout << "Please enter process value" << endl;
        cout << "Thousand(s):";
        cin >> thS;
        if(isdigit(thS[0]) || thS[0] == '-' || thS[0] == '+')
        {
            wrong = false;
        }
        for(int i = 1; i < thS.size(); ++i)
        {
            if(!isdigit(thS[i]))
            {
                wrong = true;
                break;
            }
        }
        if(wrong)
        {
            continue;
        }
        else
        {
            ss << thS;
            ss >> th;
            ss.clear();
            break;
        }
    }
    while(true)
    {
        bool wrong = false;
        system("cls");
        cout << "Please enter process value" << endl;
        cout << "Thousand(s):" << thS << endl;
        cout << "Hundred(s):";
        cin >> hS;
        if(isdigit(hS[0]) || hS[0] == '-' || hS[0] == '+')
        {
            wrong = false;
        }
        for(int i = 1; i < hS.size(); ++i)
        {
            if(!isdigit(hS[i]))
            {
                wrong = true;
                break;
            }
        }
        if(wrong)
        {
            continue;
        }
        else
        {
            ss << hS;
            ss >> h;
            ss.clear();
            break;
        }

    }
    while(true)
    {
        bool wrong = false;
        system("cls");
        cout << "Please enter process value" << endl;
        cout << "Thousand(s):" << thS << endl;
        cout << "Hundred(s):" << hS << endl;
        cout << "Ten(s):";
        cin >> teS;
        if(isdigit(teS[0]) || teS[0] == '-' || teS[0] == '+')
        {
            wrong = false;
        }
        for(int i = 1; i < teS.size(); ++i)
        {
            if(!isdigit(teS[i]))
            {
                wrong = true;
                break;
            }
        }
        if(wrong)
        {
            continue;
        }
        else
        {
            ss << teS;
            ss >> te;
            ss.clear();
            break;
        }
    }
    while(true)
    {
        bool wrong = false;
        system("cls");
        cout << "Please enter process value" << endl;
        cout << "Thousand(s):" << thS << endl;
        cout << "Hundred(s):" << hS << endl;
        cout << "Ten(s):" << teS << endl;
        cout << "One(s):";
        cin >> oS;
        if(isdigit(oS[0]) || oS[0] == '-' || oS[0] == '+')
        {
            wrong = false;
        }
        for(int i = 1; i < oS.size(); ++i)
        {
            if(!isdigit(oS[i]))
            {
                wrong = true;
                break;
            }
        }
        if(wrong)
        {
            continue;
        }
        else
        {
            ss << oS;
            ss >> o;
            ss.clear();
            break;
        }
    }
    stock[choose].changeAmount(th, h, te, o);
    ofstream outFile;
    outFile.open("Stock.txt");
    for(unsigned int i = 0; i < stock.size(); ++i)
    {
        outFile << stock[i].getCountryName() << " "
                << stock[i].getThousands() << " "
                << stock[i].getHundreds() << " "
                << stock[i].getTens() << " "
                << stock[i].getOnes() << " ";
        if(i != stock.size() - 1)
        {
            outFile << endl;
        }
    }
    outFile.close();
}

void Administrator::addCountry()//ting
{
    Machine m;
    string cn;
    string country;
    int thou, hun, ten, one;
    string input;
    stringstream ss;
    vector <Stock> stock;
    ifstream inFile1("Stock.txt");
    while(!inFile1.eof())
    {
        getline(inFile1, input);
        ss << input;
        ss >> cn >> thou >> hun >> ten >> one;
        Stock stk(cn, thou, hun, ten, one);
        stock.push_back(stk);
        ss.clear();
    }
    inFile1.close();

    bool repeat = true;
    while(true)
    {
        unsigned int counter = 0;
        if(repeat == true)
        {
            cout << "Please enter country name:";
            cin >> country;
        }
        for(unsigned int i = 0; i < stock.size(); ++i)
        {
            if(m.toLower(stock[i].getCountryName()) == m.toLower(country))
            {
                system("cls");
                cout << "This country has already been created!" << endl;
                repeat = true;
                break;
            }
            else if(country.size() > 10)
            {
                system("cls");
                cout << "This country has too many characters!" << endl;
                repeat = true;
                break;
            }
            else
            {
                ++counter;
            }
        }
        if(counter == stock.size())
        {
            repeat = false;
        }
        if(repeat == false)
        {
            break;
        }
    }
    Stock stk(country, 0, 0, 0, 0);
    stock.push_back(stk);
    ofstream outFile1;

    outFile1.open("Stock.txt");
    for(unsigned int i = 0; i < stock.size(); ++i)
    {
        outFile1 << stock[i].getCountryName() << " "
                << stock[i].getThousands() << " "
                << stock[i].getHundreds() << " "
                << stock[i].getTens() << " "
                << stock[i].getOnes() << " ";
        if(i != stock.size() - 1)
        {
            outFile1 << endl;
        }
    }
    outFile1.close();

    double buy, sell;
    vector <Dollar> dollar;
    ifstream inFile2("Currency.txt");
    while(!inFile2.eof())
    {
        getline(inFile2, input);
        ss << input;
        ss >> cn >> buy >> sell;
        Dollar Dollar(cn, buy, sell);
        dollar.push_back(Dollar);
        ss.clear();
    }
    inFile2.close();

    Dollar Dollar(country, 1, 1);
    dollar.push_back(Dollar);
    ofstream outFile2;

    outFile2.open("Currency.txt");
    for(unsigned int i = 0; i < dollar.size(); ++i)
    {
        outFile2 << dollar[i].get_CountryName() << " "
                << dollar[i].get_BuyIn() << " "
                << dollar[i].get_SellOut() << " ";
        if(i != dollar.size() - 1)
        {
            outFile2 << endl;
        }
    }
    outFile2.close();
}

int Administrator::choose()//ting
{
    int choose = 0;
    int request = 0;
    while(true)
    {
        system("cls");
        if(request == 13)
        {
            return choose;
            break;
        }
        else
        {
            if(choose == 0)
                cout << "-> " << "Add Country" << endl << "   " << "Adjust Money" << endl <<  "   " << "Change Currency" << endl << endl << "   " << "Return" << endl;
            else if(choose == 1)
                cout << "   " << "Add Country" << endl << "-> " << "Adjust Money" << endl <<  "   " << "Change Currency" << endl << endl << "   " << "Return" << endl;
            else if(choose == 2)
                cout << "   " << "Add Country" << endl << "   " << "Adjust Money" << endl <<  "-> " << "Change Currency" << endl << endl << "   " << "Return" << endl;
            else if(choose == 3)
                cout << "   " << "Add Country" << endl << "   " << "Adjust Money" << endl <<  "   " << "Change Currency" << endl << endl << "-> " << "Return" << endl;
        }

        request = getch();
        if(request == 224)
        {
            request = getch();
            if(request == 72)
            {
                if(choose != 0)
                {
                    choose--;
                }
            }
            else if(request == 80)
            {
                if(choose != 3)
                {
                    choose++;
                }
            }
        }
    }
    return choose;
}

bool Administrator::isAdmin(string input)//ting
{
    return (input == password);
}
