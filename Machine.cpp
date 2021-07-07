#include "Machine.h"
#include "Dollar.h"
#include "User.h"
#include "Administrator.h"

Machine::Machine()//ting
{

}

int Machine::greeting()//ting
{
    int choose = 0;
    int request = 0;
    while(true)
    {
        system("cls");
        if(request == 13)
        {
            break;
        }
        else
        {
            cout << "Please choose your identity" << endl;
            if(choose == 0)
                cout << "-> " << "User" << endl << "   " << "Administrator" << endl << endl << "   " << "Exit" << endl;
            else if(choose == 1)
                cout << "   " << "User" << endl << "-> " << "Administrator" << endl << endl << "   " << "Exit" << endl;
            else if(choose == 2)
                cout << "   " << "User" << endl << "   " << "Administrator" << endl << endl << "-> " << "Exit" << endl;
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
                if(choose != 2)
                {
                    choose++;
                }
            }
        }
    }
    return choose;
}

int Machine::chooseCountry(int situation)//ting
{
    unsigned int chooseCountry = 0;
    if(situation == 1)
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

        int request = 0;
        while(true)
        {
            system("cls");
            if(request == 13)
            {
                break;
            }
            else
            {
                cout << "Please choose the country that you would like to process" << endl << endl;
                cout << stock[chooseCountry].getCountryName() << endl;
                cout << "Thousands remaining:";
                cout << stock[chooseCountry].getThousands() << " dollar bill(s)" << endl;
                cout << "Hundreds remaining:";
                cout << stock[chooseCountry].getHundreds() << " dollar bill(s)" << endl;
                cout << "Tens remaining:";
                cout << stock[chooseCountry].getTens() << " coin(s)" << endl;
                cout << "Ones remaining:";
                cout << stock[chooseCountry].getOnes() << " coin(s)" << endl;
            }

            request = getch();
            if(request == 224)
            {
                request = getch();
                switch(request)
                {
                    case 72:
                    if(chooseCountry == 0)
                    {
                        break;
                    }
                    else if(chooseCountry != 0)
                    {
                        chooseCountry--;
                        break;
                    }
                    case 80:
                    if((unsigned)chooseCountry == stock.size())
                    {
                        break;
                    }
                    else if(chooseCountry != stock.size() - 1)
                    {
                        chooseCountry++;
                        break;
                    }
                    break;
                }
            }
        }
    }
    else if(situation == 2)
    {
        string cn;
        double buy, sell;
        string input;
        stringstream ss;
        vector <Dollar> dollar;
        ifstream inFile("Currency.txt");
        while(!inFile.eof())
        {
            getline(inFile, input);
            ss << input;
            ss >> cn >> buy >> sell;
            Dollar Dollar(cn, buy, sell);
            dollar.push_back(Dollar);
        }
        inFile.close();

        int request = 0;
        while(true)
        {
            system("cls");
            if(request == 13)
            {
                break;
            }
            else
            {
                cout << "Please choose the country that you would like to process" << endl << endl;
                cout << dollar[chooseCountry].get_CountryName() << endl;
                cout << "Buy Currency:";
                cout << dollar[chooseCountry].get_BuyIn() << endl;
                cout << "Sell Currency:";
                cout << dollar[chooseCountry].get_SellOut() << endl;
            }

            request = getch();
            if(request == 224)
            {
                request = getch();
                switch(request)
                {
                    case 72:
                    if(chooseCountry == 0)
                    {
                        break;
                    }
                    else if(chooseCountry != 0)
                    {
                        chooseCountry--;
                        break;
                    }
                    case 80:
                    if(chooseCountry == dollar.size())
                    {
                        break;
                    }
                    else if(chooseCountry != dollar.size() - 1)
                    {
                        chooseCountry++;
                        break;
                    }
                    break;
                }
            }
        }
    }
    return chooseCountry;
}

bool Machine::CorB(int situation, bool chooseCountryFunctionUsed, int country)//ting
{
    int request = 0;
    int choose = 0;
    while(true)
    {
        system("cls");
        if(request == 13)
        {
            break;
        }
        else
        {
            if(situation == 1 && chooseCountryFunctionUsed == false)
            {

                cout << "Wrong password" << endl << endl;
                cout << "Go to home page?" << endl;
            }
            else if(situation == 2 && chooseCountryFunctionUsed == true)
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
                ifstream openFile("Stock.txt");
                cout << "Process complete!" << endl << endl;
                cout << stock[country].getCountryName() << endl;
                cout << "Thousands remaining:";
                cout << stock[country].getThousands() << " dollar bill(s)" << endl;
                cout << "Hundreds remaining:";
                cout << stock[country].getHundreds() << " dollar bill(s)" << endl;
                cout << "Tens remaining:";
                cout << stock[country].getTens() << " coin(s)" << endl;
                cout << "Ones remaining:";
                cout << stock[country].getOnes() << " coin(s)" << endl << endl;
                cout << endl << "Continue processing?" << endl;
            }
            else if(situation == 3 && chooseCountryFunctionUsed == false)
            {
                cout << "Process complete!" << endl << endl;
                cout << "Add another country?" << endl;
            }
            else if(situation == 4 && chooseCountryFunctionUsed == true)
            {
                string cn;
                double buy, sell;
                string input;
                stringstream ss;
                vector <Dollar> dollar;
                ifstream inFile("Currency.txt");
                while(!inFile.eof())
                {
                    getline(inFile, input);
                    ss << input;
                    ss >> cn >> buy >> sell;
                    Dollar Dollar(cn, buy, sell);
                    dollar.push_back(Dollar);
                }
                inFile.close();
                ifstream openFile("Currency.txt");
                cout << "Process complete!" << endl << endl;
                cout << dollar[country].get_CountryName() << endl;
                cout << "Buy Currency";
                cout << dollar[country].get_BuyIn() << endl;
                cout << "Sell Currency:";
                cout << dollar[country].get_SellOut() << endl;
                cout << endl << "Continue processing?" << endl;
            }
            if(choose == 0)
                cout << "-> " << "Yes" << endl << "   " << "No" << endl;
            else if(choose == 1)
                cout << "   " << "Yes" << endl << "-> " << "No" << endl;
        }

        request = getch();
        if(request == 224)
        {
            request = getch();
            if(request == 72 && choose == 1)
            {
                choose = 0;
            }
            else if(request == 80 && choose == 0)
            {
                choose = 1;
            }
        }
    }

    if(choose == 0)
    {
        return true;
    }
    else if(choose == 1)
    {
        return false;
    }
}

void Machine::chooseFunction()//yo
{
    int request = 0;
    int choose = 0;
    while(true)
    {
        User u;
        Administrator a;
        system("cls");
        if(request==13)
        {
            if(choose==0)
                u.checkCurrency();
            else if(choose == 1)
            {
                bool valid=false;
                while(valid==false)
                {
                    valid = u.trade();
                }
                system("cls");
                bool nextStep=false;
                while(nextStep==false)
                {
                    nextStep=u.chooseInput();

                }
                u.input();
                u.chooseOutput();
                u.output();
                u.print();
                system("pause");
                request = 0;
                continue;

            }
            else if(choose == 2)
            {
                break;
            }
            request=getch();
            if(request==27)
                break;
            else
                continue;
        }

        else
        {
            if(choose==0)
            {
                cout<<"-> "<<"Check currency"<<endl;
                cout<<"   "<<"Foreign exchange"<<endl<<endl;
                cout<<"   "<<"Return"<<endl;
            }
            else if(choose==1)
            {
                cout<<"   "<<"Check currency"<<endl;
                cout<<"-> "<<"Foreign exchange"<<endl<< endl;
                cout<<"   "<<"Return"<<endl;
            }
            else if(choose == 2)
            {
                cout<<"   "<<"Check currency"<<endl;
                cout<<"   "<<"Foreign exchange"<<endl << endl;
                cout<<"-> "<<"Return"<< endl;
            }
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
                if(choose != 2)
                {
                    choose++;
                }
            }
        }
    }
}

string Machine::toLower(string s)//ting
{
    string newS;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            newS += (s[i] - ('A' - 'a'));
        }
        else
        {
            newS += s[i];
        }
    }
    return newS;
}
