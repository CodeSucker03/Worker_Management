#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void Function2(){
    vector<string> employees;
    vector<string> partsContainer;
    vector<vector<string>> nameVector;
    string search_term, parts;
    vector<size_t> maxLength(10, 0);
    int k = 0, nowString;
    cout << "Enter the employee's name to search for: ";
    cin.ignore();
    getline(cin, search_term);
    replace(search_term.begin(), search_term.end(), ' ', '_');
    string line;
    bool found = false;

    ifstream inputFile("information.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening the file." << endl;
    }

    while (getline(inputFile, line))
    {
        if (k >= 3)
        {
            istringstream iss(line);
            while (iss >> parts)
            {
                partsContainer.push_back(parts);
            }
            if (partsContainer[2].find(search_term) != string::npos)
            {
                found = true;
                nameVector.push_back(partsContainer);
            }
            for (int s = 0; s < 10; s++)
            {
                if (partsContainer[s].length() > maxLength[s])
                {
                    maxLength[s] = partsContainer[s].length();
                }
            };
        }
        k++;
        partsContainer.clear();
    }

    vector<string> Headers = {"Company", "Level", "Name(Last/Mid/First)", "Birthdate", "ID", "Origin", "Residence", "Email", "Phone", "JobTaken"};
    for (int j = 0; j < Headers.size(); ++j) // column
    {
        int st = (int)Headers[j].length();
        int nt = (int)maxLength[j];
        int et = nt - st;
        string headerSpace(abs(et), ' ');
        cout << Headers[j] << headerSpace << "  |  ";
    }
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < nameVector.size(); i++) // row
    {
        for (int j = 0; j < 10; ++j) // column
        {
            if (j < nameVector[i].size()) // condition to avoid error printing
            {
                nowString = (int)maxLength[j] - (int)nameVector[i][j].length();

                string spacing(abs(nowString), ' ');
                replace(nameVector[i][j].begin(), nameVector[i][j].end(), '_', ' ');
                cout << nameVector[i][j] << spacing << "  |  ";
            }
        }
        cout << endl;
    }

    inputFile.close();

    if (!found)
    {
        cout << "Employee not found in the file." << endl;
    }
}
