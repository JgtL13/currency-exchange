#include "Machine.h"
#include "User.h"
#include "Administrator.h"
#include <string>
#include <iostream>
#include <cstdlib>

int main()
{
    Machine m;
    User u;
    Administrator a;
    while(true)
    {
        string input;
        bool again = true;
        int choose;

        choose = m.greeting();
        if(choose == 0)
        {
            m.chooseFunction();
        }

        else if(choose == 1)
        {
            input = a.inputPassword();
            system("cls");
            if(a.isAdmin(input))
            {
                while(true)
                {
                    int temp = a.choose();
                    if(temp == 3)
                    {
                        break;
                    }
                    while(true)
                    {
                        if(temp == 0)
                        {
                            a.addCountry();
                            again = m.CorB(3, false, NULL);
                        }
                        else if(temp == 1)
                        {
                            int chosenCountry = m.chooseCountry(1);
                            a.changeValue(chosenCountry);
                            again = m.CorB(2, true, chosenCountry);
                        }
                        else if(temp == 2)
                        {
                            int chosenCountry = a.changeCurrency();
                            again = m.CorB(4, true, chosenCountry);

                        }
                        if(again == true)
                        {
                            continue;
                        }
                        else if(again == false)
                        {
                            break;
                        }
                    }
                }
            }
            else if(!a.isAdmin(input))
            {
                again = m.CorB(1, false, NULL);
                if(again == true)
                {
                    continue;
                }
                else if(again == false)
                {
                    break;
                }
            }
        }
        else if(choose == 2)
        {
            break;
        }
    }
}

