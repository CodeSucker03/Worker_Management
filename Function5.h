#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
void scanId(), menuSelect(), changeInfo(), changeFile(string myString), changeFunction();
string line, token, idNumber, newLine;
vector<string> components, lines; // every lines in the txt file is passed in the lines vector,each strings in a line is passed in components[x] vector
int i = 0;                        // ex: components[0] = CurrentworkPlace

void scanId()
{
    ifstream readFile("information.txt");
    while (getline(readFile, line))
    {
        lines.push_back(line); // push all lines in a file to a vector and each vector's index holds a line
    }
    readFile.clear();            // clear error
    readFile.seekg(0, ios::beg); // read file from the beginning again.
    cout << "Enter employee's id: ";
    cin >> idNumber;
    while (getline(readFile, line))
    {
        // Use stringstream to split the string by spaces and store each part in the vector
        stringstream ss(line);
        while (ss >> token)
        {
            components.push_back(token);
        };

        if (components[4] == idNumber)
        {
            readFile.close();
            return;
        }
        i++;
        components.clear();
    };
    cout << "ID doesnt exist, Please enter again ";
    scanId();
}
void changeInfo()
{
    menuSelect();
    int number;

    string newName, newUnit, newPosition, newBirthdate, newOrigin, newResidence, newEmail, newPhone;
    cout << " ==> Enter your choice(a number) to make a change or exit: \n";
    cin >> number;
    cin.ignore(); // ignore the buffer in the keyboard for getline later
    if (number == 10)
    {
        cout << "Exit...";
        return;
    }

    if (number > 10 || number < 1)
    {
        cout << "===> INVALID, PLEASE ENTER A VALID CHOICE!\n";
        changeInfo();
    }
    switch (number)
    {
    case 1:

        cout << "New work Unit: ";
        getline(cin, newUnit);
        components[0] = newUnit;
        changeFile(components[0]);
        newLine.clear(); // Refresh newline to hold emty string.
        break;

    case 2:
        cout << "New work position: ";
        getline(cin, newPosition);
        components[1] = newPosition;
        changeFile(components[1]);
        newLine.clear();

        break;
    case 3:
        cout << "Name: ";
        getline(cin, newName);
        components[2] = newName;
        changeFile(components[2]);
        newLine.clear();

        break;
    case 4:
        cout << "Date of birth.Enter with format Day/Month/Year: ";
        getline(cin, newBirthdate);
        components[3] = newBirthdate;
        changeFile(components[3]);
        newLine.clear();

        break;
    case 5:
        cout << "Place of origin: ";
        getline(cin, newOrigin);
        components[5] = newOrigin;
        changeFile(components[5]);
        newLine.clear();

        break;
    case 6:
        cout << "Place of residence: ";
        getline(cin, newResidence);
        components[6] = newResidence;
        changeFile(components[6]);
        newLine.clear();

        break;
    case 7:
        cout << "Email: ";
        getline(cin, newEmail);
        components[7] = newEmail;
        changeFile(components[7]);
        newLine.clear();

        break;
    case 8:
        cout << "Phone number: ";
        getline(cin, newPhone);
        components[8] = newPhone;
        changeFile(components[8]);
        newLine.clear();

        break;
    case 9:
        changeFunction();
        break;
    };
    changeInfo();
};
void menuSelect()
{
    cout << "-- Your Current Profile:\n";
    cout << "ID number: " << components[4] << endl;
    cout << "1) Current work Unit: " << components[0] << endl;
    cout << "2) Current work position: " << components[1] << endl;
    cout << "3) Name: " << components[2] << endl;
    cout << "4) Date of birth: " << components[3] << endl;
    cout << "5) Place of origin: " << components[5] << endl;
    cout << "6) Place of residence: " << components[6] << endl;
    cout << "7) Email: " << components[7] << endl;
    cout << "8) Phone number: " << components[8] << endl;
    cout << "9) Return to search ID " << endl;
    cout << "10)  Back to main Menu " << endl;
};

void changeFile(string myString)
{

    ofstream outFile("information.txt");
    if (!outFile)
    {
        std::cerr << "Error writing to file: " << endl;
        return;
    }
    for (int j = 0; j < components.size(); j++)
    {
        replace(components[j].begin(), components[j].end(), ' ','_'); // replace every space in each element with a ''
        newLine = newLine + components[j] + "  ";
    };
    lines[i] = newLine; // i here is the number of the line holds fixed information
    for (int x = 0; x < lines.size(); x++)
    {
        outFile << lines[x] << endl;
    }
    outFile.close();
}
void changeFunction()
{
    if (i > 0)
    {
        i = 0;
        lines.clear();
    }
    scanId();
    changeInfo();
    return;
};