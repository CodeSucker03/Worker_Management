#include <iostream>
#include <sstream>
#include <fstream> 
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "Function1.h"
#include "Function2.h"
#include "Function3.h"
#include "Function4.h"
#include "Function5.h"
#include "Function6.h"
using namespace std;
void MenuSeletion();
void exitFunc();
void Menu()
{
    cout << "......WELCOME TO BKCORPORATION.......\n";
    cout << "1) BkCorporation's basic information.\n";

    cout << "2) Search for employee's profile.\n";

    cout << "3) Employee's status.\n";

    cout << "4) Unit's information.\n";

    cout << "5) Update new employee list.\n";

    cout << "6) Update employee's profile.\n";

    cout << "7) Exit program.\n";
}


int main(){                                         //Main 
    Menu();
    MenuSeletion();
}


void exitFunc()
{
    char choice, nextChar;
    cin >> choice;
    if (cin.get(nextChar) && nextChar == '\n')
    {
        // The input contains only one character
        cout << "You entered a single character: " << choice << endl;
    }
    else
    {
        // The input contains more than one character
        cout << "Invalid input. Please enter exactly one character." << endl;
        exitFunc();
    }

    char choosed = tolower(choice);
    if (choosed == 'y')
    {
        main();
    }
    else if (choosed == 'n')
    {
        return;
    }
    else
    {
        cout << "INVALID! enter again: ";
        exitFunc();
    }
};
void MenuSeletion()
{
    int allowedLength = 1;
    string input;
    cout << "Enter your choice: \n";
    cin >> input;
    
    if (input.length() > allowedLength)
    {
        cout << "Invalid input! Please enter a valid choice.\n";
        main();
    };

    if (!isdigit(input[0]))
    {
        cout << "Invalid input! Please enter a valid choice.\n";
        main();
    };
    int number = input[0] - '0';
    cout << "You entered: " << number << "\n";

    if (number <= 7 && number > 0)
    {
        switch (number)
        {
        case 1:
            Function1();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 2:
            Function2();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 3:
            Function3();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 4:
            Function4();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 5:
            changeFunction();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 6:
            runFunction();
            cout << "Exit to main menu ? Y or N: ";
            exitFunc();
            break;
        case 7:
            cout << "Exit program....";
            exit(0);
        }
    }
    else
    {
        cout << "Wrong option!,\nPlease enter a valid choice!\n";
        main();
    }
}

