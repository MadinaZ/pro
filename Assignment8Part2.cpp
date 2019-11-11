//
//  main.cpp
//  Assignment-8
//
//  Created by Madina Sadirmekova on 10/23/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//
//test specific operations
//1 part
//read the file and parse====it is big O(n)
//1 iteration start with 1000
//think of the base --- we only have 85K lines so it is beter to start with n <= 10K as a base


#include<iostream>
#include<string>

using namespace std;
#include<ctime>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include "DynamicArray.h"
#include<cmath>

bool check_duplication(const string terminfo, const DynamicArray<string>& nonDuplicateClass, int classIndex)
{
    for(int i = 0; i < classIndex; i++)
    {
        if(terminfo == nonDuplicateClass[i])
            return true;
    }
    return false;
}

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";

    DynamicArray<string> nonDuplicateClass;

    srand(time(0));
    rand();
    //the clock starts from opening the file
    int n = 1000;
    string bigOh = "O(n squared)";

    char *token;
    char buf[1000];
    const char* const tab = "\t";
    int classIndex = 0;
    int duplicates = 0;
    string classCode;

    ifstream fin;
    double elapsedSecondsNorm = 0;
    double expectedSeconds = 0;

    for(int cycle = 0; cycle < 4; cycle++, n*=2)
    {

        fin.open("dvc-schedule.txt");
        if(!fin.good())
            cout<<"I/O error \n";

        cout.setf(ios::fixed);
        cout.precision(4);
        
        clock_t startTime = clock();

        for(int i = 0; i < n; i++)
        {
            string line;
            getline(fin,line);
            strcpy(buf, line.c_str());

            if(buf[0] == 0)//empty string
                continue;

            const string term (token = strtok(buf, tab));
            const string section((token = strtok(0, tab)) ? token : "");
            const string course((token = strtok(0, tab)) ? token : "");
            const string instructor((token = strtok(0, tab)) ? token : "");
            const string whenWhere((token = strtok(0, tab)) ? token : "");

            classCode = term + " " + section;
            bool found = check_duplication(classCode, nonDuplicateClass, classIndex);
            if(found)
                duplicates++;
            else
                nonDuplicateClass[classIndex++] = classCode;

        }

        fin.close();

        clock_t endTime = clock();

        double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        double factor = pow(2.0, double(cycle));
        if (cycle == 0)
            elapsedSecondsNorm = elapsedSeconds;
        else if (bigOh == "O(n)")
            expectedSeconds = factor * elapsedSecondsNorm;
        else if (bigOh == "O(n log n)")
            expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
        else if (bigOh == "O(n squared)")
            expectedSeconds = factor * factor * elapsedSecondsNorm;
        // reporting block

        cout << elapsedSeconds;
        if (cycle == 0) cout << " (expected " << bigOh << ')';
        else cout << " (expected " << expectedSeconds << ')';
        cout << " for n=" << n << endl;
    }

    return 0;
}
