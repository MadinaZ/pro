//
//  main.cpp
//  Assignment-8-part-1
//
//  Created by Madina Sadirmekova on 10/26/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;
#include<ctime>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<cmath>

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    srand(time(0));
    rand();
    //the clock starts from opening the file
    int n = 8000;
    string bigOh = "O(n)";
    
    char *token;
    char buf[1000];
    const char* const tab = "\t";
    
    ifstream fin;
    

    
    double elapsedSecondsNorm = 0;
    double expectedSeconds = 0;
    
    clock_t startTime = clock();
    for(int cycle = 0; cycle < 4; cycle++, n*=2)
    {
        fin.open("dvc-schedule.txt");
        if(!fin.good())
            cout<<"I/O error \n";
        cout.setf(ios::fixed);
        cout.precision(4);
        while(fin.good())
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

