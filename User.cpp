#include "User.h"
#include "Dollar.h"
#include "Machine.h"
#include <iomanip>

User::User()//yo
{
    total1=0,total2=0;
    thousand1=0,thousand2=0;
    hundred1=0,hundred2=0;
    ten1=0,ten2=0;
    one1=0,one2=0;
}

void User::checkCurrency()//yo
{
    string getcontent;
    stringstream ss;
    string country;
    double b, s;
    ifstream openfile ("Currency.txt");
    if(openfile.is_open())
    {
        cout << setw(10) << left << "Country" << setw(10) << "Buy" << setw(10) << "Sell" << endl;
        for(int i = 1; i <= 30; ++i)
        {
            cout << '-';
        }
        cout << endl;
        while(!openfile.eof())
        {
            getline(openfile, getcontent);
            ss << getcontent;
            ss >> country >> b >> s;
            ss.clear();
            cout << fixed << left << setw(10) << country << setw(10) << setprecision(5) << b << setw(10) << setprecision(5) << s << endl;
        }
    }
    cout<<endl;
    cout<<"Press ESC key to go home"<<endl;
    cout<<"Press any key to go back"<<endl;
}

bool User::trade()//yo
{
    Machine m;
    vector <Dollar> dollar;
    stringstream ss;
    string line,Country;
    double Buy,Sell;

    string Country1,Country2;
    bool finded1=false,finded2=false;

    ifstream openfile("Currency.txt");
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            getline(openfile,line);
            ss<<line;
            ss>>Country>>buy>>sell;
            ss.clear();
            Dollar Dollar(Country,buy,sell);
            dollar.push_back(Dollar);
        }
    }

    cout<<"From Country: ";
    cin>>Country1;
    cout<<"To Country: ";
    cin>>Country2;
    string lowerCountry1 = m.toLower(Country1);
    string lowerCountry2 = m.toLower(Country2);

    for(unsigned int x=0;x<dollar.size();x++)
    {
        string lowerDollar = m.toLower(dollar[x].get_CountryName());
        if(lowerCountry1==lowerDollar)
        {
            Buy=dollar[x].get_BuyIn();
            country1=dollar[x].get_CountryName();
            finded1=true;
        }
        if(lowerCountry2==lowerDollar)
        {
            Sell=dollar[x].get_SellOut();
            country2=dollar[x].get_CountryName();
            finded2=true;
        }
    }

    if(finded1 && finded2)
    {
        buy=Buy;
        sell=Sell;
        return true;
    }
    else
    {
        system("cls");
        cout<<"Country is invalid, please enter again" << endl;
        return false;
    }
}

bool User::chooseInput()//yo
{
    int request=0;
    int choose=0;
    while(true)
    {
        system("cls");
        if(request == 13 && choose==4)
        {
            vector <Stock> stock;
            stringstream ss;
            string line,country;
            int store3,store2,store1,store;

            ifstream openfile("Stock.txt");
            if(openfile.is_open())
            {
                while(!openfile.eof())
                {
                    getline(openfile,line);
                    ss<<line;
                    ss>>country>>store3>>store2>>store1>>store;
                    ss.clear();
                    Stock Stock(country,store3,store2,store1,store);
                    stock.push_back(Stock);
                }
            }

            for(unsigned int x=0;x<stock.size();x++)
            {
                if(country2==stock[x].getCountryName())
                {
                    if(total2<=stock[x].getThousands()*1000+stock[x].getHundreds()*100+stock[x].getTens()*10+stock[x].getOnes())
                    {
                        return true;
                    }
                    else
                    {
                        cout << "Storage not enough!" << endl;
                        system("pause");
                        return false;
                    }
                }
            }
        }
        else
        {
            cout << "Your input: " << total1 <<' '<< country1 << " Dollars" << endl;
            if(choose == 0)
            {
                cout<< "-> " << "Thousand(s): " << thousand1 <<endl
                    << "   " << "Hundred(s): " << hundred1<< endl
                    << "   " << "Ten(s): " << ten1 << endl
                    << "   " << "One(s): " << one1 << endl << endl
                    << "   " << "Next"<<endl;
            }
            else if(choose == 1)
            {
                cout<< "   " << "Thousand(s): " << thousand1 <<endl
                    << "-> " << "Hundred(s): " << hundred1<< endl
                    << "   " << "Ten(s): " << ten1 << endl
                    << "   " << "One(s): " << one1 << endl << endl
                    << "   " << "Next"<<endl;
            }
            else if(choose == 2)
            {
                cout<< "   " << "Thousand(s): " << thousand1 <<endl
                    << "   " << "Hundred(s): " << hundred1<< endl
                    << "-> " << "Ten(s): " << ten1 << endl
                    << "   " << "One(s): " << one1 << endl << endl
                    << "   " << "Next"<<endl;
            }
            else if(choose == 3)
            {
                cout<< "   " << "Thousand(s): " << thousand1 <<endl
                    << "   " << "Hundred(s): " << hundred1<< endl
                    << "   " << "Ten(s): " << ten1 << endl
                    << "-> " << "One(s): " << one1 << endl << endl
                    << "   " << "Next"<<endl;
            }
            else if(choose == 4)
            {
                cout<< "   " << "Thousand(s): " << thousand1 <<endl
                    << "   " << "Hundred(s): " << hundred1<< endl
                    << "   " << "Ten(s): " << ten1<< endl
                    << "   " << "One(s): " << one1 << endl << endl
                    << "-> " << "Next"<<endl;
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
                if(choose != 4)
                {
                    choose++;
                }
            }
        }
        else if(request==43)
        {
            if(choose==0)
            {
                thousand1++;
                total1+=1000;
            }
            else if(choose==1)
            {
                hundred1++;
                total1+=100;
            }
            else if(choose==2)
            {
                ten1++;
                total1+=10;
            }
            else if(choose==3)
            {
                one1++;
                total1++;
            }
        }
        else if(request==45)
        {
            if(choose==0 && thousand1!=0)
            {
                thousand1--;
                total1-=1000;
            }
            else if(choose==1 && hundred1!=0)
            {
                hundred1--;
                total1-=100;
            }
            else if(choose==2 && ten1!=0)
            {
                ten1--;
                total1-=10;
            }
            else if(choose==3 && one1!=0)
            {
                one1--;
                total1--;
            }
        }
        total2=total1*buy/sell;
    }
}

void User::input()//yo
{
    vector <Stock> stock;
    stringstream ss;
    string line,country;
    int store3,store2,store1,store;

    ifstream openfile("Stock.txt");
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            getline(openfile,line);
            ss<<line;
            ss>>country>>store3>>store2>>store1>>store;
            ss.clear();
            Stock Stock(country,store3,store2,store1,store);
            stock.push_back(Stock);
        }
    }

    for(unsigned int x=0;x<stock.size();x++)
    {
        if(country1==stock[x].getCountryName())
        {
            stock[x].increase(thousand1,hundred1,ten1,one1);
        }
    }

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
}
void User::chooseOutput()//yo
{
    vector <Stock> stock;
    stringstream ss;
    string line,country;
    int store3,store2,store1,store;

    ifstream openfile("Stock.txt");
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            getline(openfile,line);
            ss<<line;
            ss>>country>>store3>>store2>>store1>>store;
            ss.clear();
            Stock Stock(country,store3,store2,store1,store);
            stock.push_back(Stock);
        }
    }
    for(unsigned int x=0;x<stock.size();x++)
    {
        if(country2==stock[x].getCountryName())
        {
            store3=stock[x].getThousands();
            store2=stock[x].getHundreds();
            store1=stock[x].getTens();
            store=stock[x].getOnes();
        }
    }
    int request=0;
    int choose=0;
    while(true)
    {
        system("cls");
        if(request == 13 && choose==4 && total2==0)
        {
            break;
        }
        else
        {
            cout << "Choose amount: " << total2 <<' '<< country2 << " Dollars" << endl;
            if(choose == 0)
            {
                cout<< "-> " << "Thousand(s): " << thousand2 <<endl
                    << "   " << "Hundred(s): " << hundred2<< endl
                    << "   " << "Ten(s): " << ten2 << endl
                    << "   " << "One(s): " << one2 << endl << endl
                    << "   " << "Finish"<<endl;
            }
            else if(choose == 1)
            {
                cout<< "   " << "Thousand(s): " << thousand2 <<endl
                    << "-> " << "Hundred(s): " << hundred2<< endl
                    << "   " << "Ten(s): " << ten2 << endl
                    << "   " << "One(s): " << one2 << endl << endl
                    << "   " << "Finish"<<endl;
            }
            else if(choose == 2)
            {
                cout<< "   " << "Thousand(s): " << thousand2 <<endl
                    << "   " << "Hundred(s): " << hundred2<< endl
                    << "-> " << "Ten(s): " << ten2 << endl
                    << "   " << "One(s): " << one2 << endl << endl
                    << "   " << "Finish"<<endl;
            }
            else if(choose == 3)
            {
                cout<< "   " << "Thousand(s): " << thousand2 <<endl
                    << "   " << "Hundred(s): " << hundred2<< endl
                    << "   " << "Ten(s): " << ten2 << endl
                    << "-> " << "One(s): " << one2 << endl << endl
                    << "   " << "Finish"<<endl;
            }
            else if(choose == 4)
            {
                cout<< "   " << "Thousand(s): " << thousand2 <<endl
                    << "   " << "Hundred(s): " << hundred2<< endl
                    << "   " << "Ten(s): " << ten2<< endl
                    << "   " << "One(s): " << one2 << endl << endl
                    << "-> " << "Finish"<<endl;
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
                if(choose != 4)
                {
                    choose++;
                }
            }
        }
        else if(request==43)
        {
            if(choose==0 && total2>=1000 && thousand2<=store3)
            {
                thousand2++;
                total2-=1000;
            }
            else if(choose==1 && total2>=100 && hundred2<=store2)
            {
                hundred2++;
                total2-=100;
            }
            else if(choose==2 && total2>=10 && ten2<store1)
            {
                ten2++;
                total2-=10;
            }
            else if(choose==3 && total2>=1 && one2<store)
            {
                one2++;
                total2--;
            }
        }
        else if(request==45)
        {
            if(choose==0 && thousand2!=0)
            {
                thousand2--;
                total2+=1000;
            }
            else if(choose==1 && hundred2!=0)
            {
                hundred2--;
                total2+=100;
            }
            else if(choose==2 && ten2!=0)
            {
                ten2--;
                total2+=10;
            }
            else if(choose==3 && one2!=0)
            {
                one2--;
                total2++;
            }
        }
    }
}

void User::output()//yo
{
    vector <Stock> stock;
    stringstream ss;
    string line,country;
    int store3,store2,store1,store;

    ifstream openfile("Stock.txt");
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            getline(openfile,line);
            ss<<line;
            ss>>country>>store3>>store2>>store1>>store;
            ss.clear();
            Stock Stock(country,store3,store2,store1,store);
            stock.push_back(Stock);
        }
    }

    for(unsigned int x=0;x<stock.size();x++)
    {
        if(country2==stock[x].getCountryName())
        {
            stock[x].decrease(thousand2,hundred2,ten2,one2);
        }
    }

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
}

void User::print()//yo
{
    cout<<"Trade sucessful,you get :"<<endl;
    cout<<"1000 x"<<thousand2<<endl;
    cout<<"100  x"<<hundred2<<endl;
    cout<<"10   x"<<ten2<<endl;
    cout<<"1    x"<<one2<<endl;
    cout<<endl;
}
