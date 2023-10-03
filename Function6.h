#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>
using namespace std;
vector<string> newWorker, checkLine, IdCheck;
void newInput(), scanForId(), runFunction(), returnFunc();
string createRandomIdNum();
string RandomIdString, IDNUM, fileLine;
string currentWorkUnit, currentWorkPos, currentName, currentBirth, currentOrigin, currentReside, currentEmail, currentPhonenum, addNewLine, jobTaken;

void newInput()
{
    currentWorkUnit.clear();
    currentWorkPos.clear();
    currentName.clear();
    currentBirth.clear();
    currentOrigin.clear();
    currentReside.clear();
    currentEmail.clear();
    currentPhonenum.clear();
    jobTaken.clear();
    addNewLine.clear();
    cin.ignore();
    cout << "---Enter employee's information---\n";
    cout << "1) Current work Unit: ";
    getline(cin, currentWorkUnit);
    cout << endl;
    cout << "2) Current work position: ";
    getline(cin, currentWorkPos);
    cout << endl;
    cout << "3) Name: ";
    getline(cin, currentName);
    cout << endl;
    cout << "4) Date of birth (day/month/year): ";
    getline(cin, currentBirth);
    cout << endl;
    cout << "5) Place of origin: ";
    getline(cin, currentOrigin);
    cout << endl;
    cout << "6) Place of residence: ";
    getline(cin, currentReside);
    cout << endl;
    cout << "7) Email: ";
    getline(cin, currentEmail);
    cout << endl;
    cout << "8) Phone number: ";
    getline(cin, currentPhonenum);
    cout << endl;
    cout << "9) Job taken day: ";
    getline(cin, jobTaken);
    cout << endl;
}

string createRandomIdNum()
{
    random_device rd;  // Create a random device to seed the engine
    mt19937 rng(rd()); // Create the Mersenne Twister engine and seed it with a random value from the random device

    int min_value = 70;
    int max_value = 99;
    uniform_int_distribution<int> dist(min_value, max_value);

    int randomNumber = dist(rng);             // Generate a random number between min_value and max_value
    RandomIdString = to_string(randomNumber); // to string
    return RandomIdString;
};

void scanForId()
{
    string parts;
    if (!fileLine.empty())
    {
        fileLine.clear();
    }

    ifstream readFIle("information.txt");
    while (getline(readFIle, fileLine))
    {
        newWorker.push_back(fileLine);
        stringstream stream(fileLine);
        while (stream >> parts)
        {
            checkLine.push_back(parts);
        }
        IdCheck.push_back(checkLine[4]);
        checkLine.clear();
    };
    readFIle.close();
    bool found;
    do
    {
        IDNUM = createRandomIdNum(); // Generate a new random number

        // Check if the generated number exists in the array
        found = false;
        for (int i = 0; i < IdCheck.size(); i++)
        {
            if (IdCheck[i] == IDNUM)
            {
                found = true;
                break;
            }
        }
    } while (found);
}

void runFunction()
{
    if (IDNUM != "")
    {
        IDNUM.clear();
    }
    if (!IdCheck.empty())
    {
        IdCheck.clear();
    }

    if (!newWorker.empty())
    {
        newWorker.clear();
    }
    scanForId(); // scan to crate new id

    newInput();
    replace(currentWorkUnit.begin(), currentWorkUnit.end(), ' ', '_');
    replace(currentWorkPos.begin(), currentWorkPos.end(), ' ', '_');
    replace(currentName.begin(), currentName.end(), ' ', '_');
    replace(currentBirth.begin(), currentBirth.end(), ' ', '_');
    replace(currentOrigin.begin(), currentOrigin.end(), ' ', '_');
    replace(currentReside.begin(), currentReside.end(), ' ', '_');
    replace(currentEmail.begin(), currentEmail.end(), ' ', '_');
    replace(currentPhonenum.begin(), currentPhonenum.end(), ' ', '_');
    replace(jobTaken.begin(), jobTaken.end(), ' ', '_');
    addNewLine = currentWorkUnit + "  " + currentWorkPos + "  " + currentName + "  " + currentBirth + "  " + IDNUM + "  " + currentOrigin + "  " + currentReside + "  " + currentEmail + "  " + currentPhonenum + "  " + jobTaken;

    newWorker.push_back(addNewLine);
    ofstream writeFile("information.txt");
    for (size_t s = 0; s < newWorker.size(); s++)
    {
        writeFile << newWorker[s] << endl;
    }
    writeFile.close();
    return;
}

