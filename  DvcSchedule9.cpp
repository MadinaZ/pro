//
//  main.cpp
//  Assignment-9
//
//  Created by Madina Sadirmekova on 11/1/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

//course name - 210
//count["Comsc"]["Comsc-210"]++;
//queue<string> q_subjects = count.keys();
//queue or stack can't be sorted
//pop all the values to the newly created dynamic array and then sort it
//when you sort the dynamic array you dint have a size
//but we know the size from the count.keys();
//int subject_size = count.size();

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "AssociativeArray.h"

using namespace std;

string* sorting(queue<string>&, int);

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";

    AssociativeArray<string, AssociativeArray<string, bool> > alreadySeen;
    AssociativeArray<string, AssociativeArray<string, int> > count;
    char *token;
    char buf[1000];
    const char* const tab = "\t";

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
        strcpy(buf, line.c_str());

        if(buf[0] == 0)//empty string
            continue;

        const string term (token = strtok(buf, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        if(course.find('-') == string::npos)
            continue;
        const string subjectCode(course.begin(), course.begin() + course.find('-'));
        
        if(alreadySeen[term][section])
            duplicates++;
        else
        {
            alreadySeen[term][section] = true;
            count[subjectCode][course]++;
        }
        
    }

   queue<string> subKeys = count.keys();
   queue<string> courseKeys = count[subjectCode].keys();
   int subject_size = (int)count.size();
      cout<<"Total duplicates: "<<duplicates<<endl;


        string* subkeys = sorting(subKeys, subject_size);

        for(int i = 0; i < subject_size; i++)
        {
          queue<string> courseKeys = count[subkeys[i]].keys();
          int courseList_size = (int)courseKeys.size();
          string* coursekeys = sorting(courseKeys, courseList_size);

          int total = (int)count[subkeys[i]].size();
          cout << subkeys[i] << ", " <<  total << " course(s)" <<endl;

          for(int j = 0; j < courseList_size; j++)
            cout << "  " << coursekeys[j] << ", " << count[subkeys[i]][coursekeys[j]] << " section(s)" << endl;
        }

    fin.close();
    return 0;
}

// a function to copy a queue to a string array
string* sorting(queue<string> &original, int size)
{
  string* keys = new string[size];
  for(int i = 0; i < size; i++)
  {
    keys[i] = original.front();
    original.pop();
  }
  sort(keys, keys + size);

  return keys;
}

