//
//  main.cpp
//  Assignment-13
//
//  Created by Madina Sadirmekova on 12/01/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include<set>
#include<map>
#include <cstring>

using namespace std;

string searchSemester(int);

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    char* token;
    char buf[100];
    const char* const tab = "\t";
    int counter = 0, sem_num;
    map<string,set<int>>allClass;
    
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if(!fin.good())
        cout<<"I/O error";
    
    cout << endl;
    
    while(fin.good())
    {
        string line;
        
        getline(fin, line);
        strcpy(buf, line.c_str());
        
        
        if(buf[0] == 0) continue;
        
        char* term(token = strtok(buf, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if(course.find('-') == string::npos) continue;
        const string subjectCode(course.begin(), course.begin() + course.find('-'));
        
        string classCode = term;
        classCode += ".";
        classCode.append(section);
        counter++;
        
        char* semester= strtok(term, " ");
        char* year = strtok(NULL, " ");
        
        if(strcmp(semester,"Spring")) strcat(year,"1");
        else if(strcmp(semester,"Summer")) strcat(year,"2");
        else if(strcmp(semester,"Fall")) strcat(year,"3");
        
        sem_num = atoi(year);
        
        allClass[course].insert(sem_num);
    }
    fin.close();
    

    while(buf[0] != 'X'  || buf[0] != 'x')
    {
        cout << "Enter a course name(like, COMSC-210) to search for the first/last semester course offered [X/x to exit]:" << endl;
        cout << "     ";
        cin >> buf;
        if(buf[0] == 'X' || buf[0] =='x')
            break;
        
        if(allClass.find(buf) == allClass.end())
            cout << "I didn't find " << buf << endl << endl;
        else
        {
            cout << buf << " was first offered in " << searchSemester(*allClass[buf].begin()) << endl;
            cout << buf << " was last offered in " << searchSemester(*allClass[buf].rbegin()) << endl;
            cout << endl;
        }
    }
    
    return 0;
}

string searchSemester(int num)
{
    int year = num / 10;
    int seme = num % 10;
    switch(seme)
    {
        case 1: return "Spring " + to_string(year);
        case 2: return "Summer " + to_string(year);
        case 3: return "Fall " + to_string(year);
    }
    return "Error\n";
}



