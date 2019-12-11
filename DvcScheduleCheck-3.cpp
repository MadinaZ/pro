//
//  main.cpp
//  DvcScheduleCheck.cpp
//
//  Created by Madina Sadirmekova on 12/1/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    char* token;
    char buf[1000];
    string line;
    multimap<string, string> data;
    map<string, string>::iterator it;
    map<string, string> result;
    ifstream fin;
    string term;
    string section;
    string course;
    int i = 0;
    
    fin.open("dvc-schedule.txt");
    if (!fin.good())
        cout<<"I/O error \n";
    
    while (!fin.eof()) {
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue;
        
        const string term(token = strtok(buf, "\t"));
        const string section(token = strtok(NULL, "\t"));
        const string course(token = strtok(NULL, "\t"));
        const string instructor((token = strtok(NULL, "\t")) ? token : "");
        const string whenWhere((token = strtok(NULL, "\t")) ? token : "");
        
        it = data.find(term + "-" + section);
        if (it == data.end())
            data.insert(make_pair(term + "-" + section, course));
        else if (it->second != course)
            result.insert(make_pair(term + "-" + section + "-" + course, it->first + "-" + it->second));
    }
    
    
    for (it = result.begin(); it != result.end(); it++)
    {
        cout<<"Multiple courses found for key (term-section) - Fall "<<term<<"-"<<section<<endl;
        
        strcpy(buf, it->first.c_str());
        term = (token = strtok(buf, "-"));
        section = (token = strtok(NULL, "-"));
        course = (token =  strtok(NULL, "\t"));
        cout<<course<<endl;
        
        
        strcpy(buf, it->second.c_str());
        term = (token = strtok(buf, "-"));
        section = (token = strtok(NULL, "-"));
        course = (token =  strtok(NULL, "\t"));
        cout<<course<<endl;
    }
    return 0;
}
