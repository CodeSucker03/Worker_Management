#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>

using namespace std;

void Function1()
{
    string currentLine, pieces;
    vector<string> piecesContainer;
    vector<size_t> maxLength(10, 0);
    int k, nowString;
    vector<vector<string>> twoDVector;
    k = 0;
    nowString = 0;
    ifstream ScanFile("information.txt");

    while (getline(ScanFile, currentLine))
    {
        stringstream currentStream(currentLine);
        while (currentStream >> pieces)
        {
            piecesContainer.push_back(pieces);
        }
        twoDVector.push_back(piecesContainer); // Add the entire row to twoDVector

        if (k >= 3) // get string length from line 4
        {
            for (int s = 0; s < 10; s++)
            {
                if (piecesContainer[s].length() > maxLength[s])
                {
                    maxLength[s] = piecesContainer[s].length();
                }
            };
        }
        k++;
        piecesContainer.clear();
    }
    ScanFile.close();

    // Print table
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
    for (int i = 3; i < k; ++i) // row
    {
        for (int j = 0; j < 10; ++j) // column
        {
            if (j < twoDVector[i].size()) // condition to avoid error printing
            {
                nowString = (int)maxLength[j] - (int)twoDVector[i][j].length();

                string spacing(abs(nowString), ' ');
                replace(twoDVector[i][j].begin(), twoDVector[i][j].end(), '_', ' ');
                cout << twoDVector[i][j] << spacing << "  |  ";
            }
        }
        cout << endl;
    }
    twoDVector.clear();
    currentLine.clear();
    maxLength.clear();
    pieces.clear();

    
    ifstream inputFile("information.txt");                                  //Count number of employee
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
     
    }
    int lineCount = 0;
    string line;
    while (getline(inputFile, line)) {
        lineCount++;
    }
    inputFile.close();
    cout << "Total number of employees is: " << lineCount -3 << endl;  //The number of line without information is 3
}
