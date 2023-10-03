#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

struct Employee {
    string no;
    string day, month, year;
    string name;
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
};

void Function3(){
    ifstream inputFile("workingtime.txt");                            //Print data 
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
    }
    string search_term;
    cout << "Enter the ID to search for: ";
    cin.ignore(); 
    getline(cin, search_term);                             //Searching for ID
            cout <<"---------------------------------------------------------------------------------------------------------------------" <<endl;
            cout << "No.         Name                           Day of work                  Start Time               End Time" << endl;
            cout <<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    string line;
    bool found = false;
    int i;
    int start1 = 0; 
    int end1 = 10;   
    string range1;   
    while (getline(inputFile, line )) {
        range1 = line.substr(start1, end1 - start1 + 1);       //Choose a range
        if (range1.find(search_term) !=string::npos) {      //Read a range of data
            replace(line.begin(), line.end(), '_', ' ');
            cout << line << endl;
            found = true;       
        }
    }
    inputFile.close();
    if (!found) {
        cout << "Employee not found in the file." << endl;
    }
    
    
    ifstream file("workingtime.txt");
    vector<Employee> employees;
    double shortfallinMonth  = 0;
    if (!file) {
        cerr << "Error opening the file.\n";
       
    }
                                                                
    while (std::getline(file, line)) {
        Employee emp;
        std::istringstream iss(line);
        iss >> emp.no >> emp.name >> emp.day >> emp.month >> emp.year;
        iss >> emp.startHour  >> emp.startMinute;
        iss >> emp.endHour >>  emp.endMinute;
        employees.push_back(emp);
    }


        for (const auto& emp : employees) {   
             if (emp.no == search_term) {   // Calculate the time shortfall for each day
        int totalStartMinutes = emp.startHour * 60 + emp.startMinute;
        int totalEndMinutes = emp.endHour * 60 + emp.endMinute;
        int expectedWorkMinutes = 10 * 60;                                   // 8 hours workday + 2 hour break
        int actualWorkMinutes = totalEndMinutes - totalStartMinutes;
        double shortfallMinutes = (expectedWorkMinutes - actualWorkMinutes) / 60.0;
        if(shortfallMinutes < 0){
        cout << "This employee has worked " << round(abs(shortfallMinutes)) << " hours more a day.\n";
        }
        else{
            cout <<"This employee has worked "<< round(abs(shortfallMinutes)) << " hours less a day.\n";
        }
            shortfallinMonth = shortfallinMonth + shortfallMinutes;
        }
     }
     if(shortfallinMonth < 0){
        cout << "This employee has worked " << round(abs(shortfallinMonth)) << " hours more in a month" << endl;
     }
     else{
        cout <<"This employee has worked " << round(abs(shortfallinMonth)) << " hours less in a month" << endl;
     }
    

    file.close(); 
}