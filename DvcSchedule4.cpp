//
//  main.cpp
//  Assignment_5
//
//  Created by Madina on 9/25/19.
//  Copyright © 2019 Madina. All rights reserved.
//

#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include "DynamicArray.h"
using namespace std;

struct subject
{
    string subjectCode;
    int count;
};

bool found = true;

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
    DynamicArray<subject> subjectCount;
    char *token;
    char buf[1000];
    const char* const tab = "\t";
    int count = 0;
    
    int subjectIndex = 0;
    int classIndex = 0;
    int duplicates = 0;
    string classCode;
    string subjectCode;
    
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if(!fin.good())
        cout<<"I/O error \n";
    while(fin.good())
    {
        string line;
        getline(fin,line);
        count++;
        strcpy(buf, line.c_str());
        
        if(buf[0] == 0)//empty string
            continue;

        const string term (token = strtok(buf, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        
        classCode = term + " " + section;
        subjectCode = course;
        bool found = check_duplication(classCode, nonDuplicateClass, classIndex);
        if(found)
            duplicates++;
        else
        {
            nonDuplicateClass[classIndex++] = classCode;
            for(int i = 0; i < subjectIndex; i++)
            {
                if((subjectCount[i].subjectCode == subjectCode))
                {
                    subjectCount[i].count++;
                    found = true;
                    break;
                }
            }
        }
        
        if(!found)
        {
            subjectCount[subjectIndex].subjectCode = subjectCode;
            subjectCount[subjectIndex].count = 1;
            subjectIndex++;
        }
        
        if(count % 1000 == 0)
            cout << '.'; cout.flush();
        
    }
    
    for(int i = 0; i < subjectIndex; i++)
    {
        for(int j = i + 1; j < subjectIndex; j++)
        {
            if(subjectCount[j].subjectCode < subjectCount[i].subjectCode)
                swap(subjectCount[i], subjectCount[j]);
        }
    }
    for(int  i = 0; i < subjectIndex; i++)
    {
        cout<<subjectCount[i].subjectCode<<","<<subjectCount[i].count<<" section"<<endl;
    }
    
    cout<<"Total counts: "<<count<<endl;
    cout<<"Total duplicates: "<<duplicates<<endl;
    cout<<"Total subjects: "<<subjectIndex<<endl;
    fin.close();
    return 0;
}
