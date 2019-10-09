//
//  main.cpp
//  Assignment-5
//
//  Created by Madina Sadirmekova on 10/4/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include "DynamicArray.h"
#include "StaticArray.h"
using namespace std;
struct SectionForTerm
{
    string term;
    DynamicArray<string> seenSectionNumber;
    int numberOfSectionSeen;
};

struct subject
{
    string subjectCode;
    int count;
};

int checkTerm(const string term, const StaticArray<SectionForTerm, 100>& alreadySeen, int alreadySeenIndex)
{
    int index;
    for(index = 0; index < alreadySeenIndex; index++)
    {
        if(term == alreadySeen[index].term)
            return index;
    }
    return -1;
}

//const because I wanna check not modify it
bool checkSection(const string section, const SectionForTerm& alreadySeen)
{
    for(int i = 0; i < alreadySeen.numberOfSectionSeen; i++)
    {
        if(alreadySeen.seenSectionNumber[i] == section)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";

    DynamicArray<subject> subjectCount(100); //enough b/c we have only 60 terms
    StaticArray<SectionForTerm, 100> alreadySeen;
    char *token;
    char buf[1000];
    const char* const tab = "\t";
    int count = 0;

    int subjectIndex = 0;
    int alreadySeenIndex = 0;
    int duplicates = 0;
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
        if(course.find('-') == string::npos)
            continue;
        const string subjectCode(course.begin(), course.begin() + course.find('-'));

        int term_index;
        term_index = checkTerm(term, alreadySeen, alreadySeenIndex);
        bool found = false;

        if (term_index != -1) {
            found = checkSection(section, alreadySeen[term_index]);     //Checking to see if section exists in term
            if (found)
                duplicates++;
            else
                alreadySeen[term_index].seenSectionNumber[alreadySeen[term_index].numberOfSectionSeen++] = section;
        }
        else
        {
            alreadySeen[alreadySeenIndex].term = term;
            alreadySeen[alreadySeenIndex].numberOfSectionSeen = 1;
            alreadySeen[alreadySeenIndex].seenSectionNumber[0] = section;
            alreadySeenIndex++;
        }

        if(!found)
        {
            for(int i = 0; i < subjectIndex; i++)
            {
                if((subjectCount[i].subjectCode == subjectCode))
                {
                    found = true;
                    subjectCount[i].count++;
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
