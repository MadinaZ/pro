//
//  main.cpp
//  Assignment-10
//
//  Created by Madina Sadirmekova on 11/11/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include"HashCode.h"
#include<cmath>
#include<ctime>
using namespace std;

struct subject
{
    string subjectCode;
    int count;
};

int hashCode(const string &);
int d_hashCode(const string &);
string* sorting(queue<string>&, int);


int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    HashTable<string, bool, 75000>record(d_hashCode);
    HashTable<string, int, 100>subClass(hashCode);
    
    clock_t startTime = clock();
    
    char *token;
    char buf[1000];
    const char* const tab = "\t";
    int count = 0;
    
    //    int subjectIndex = 0;
    //    int classIndex = 0;
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
        
        if(course.find('-') == string::npos)
            continue;
        const string subjectCode(course.begin(), course.begin() + course.find('-'));
        
        classCode = term + " " + section;
        
        if(record[classCode])
            duplicates++;
        else
        {
            record[classCode] = true;
            subClass[subjectCode]++;
        }
    }
    
    
    clock_t endTime = clock();
    double elapsedTime = (double)(endTime - startTime)/ CLOCKS_PER_SEC;
    cout<<"hashTable size = 75000/100, runtime: "<<elapsedTime<<" second(s)"<<endl;
    cout<<"The load factor for the duplication check: "<<record.loadFactor()<<endl;
    cout<<"The node load factor for the duplication check: "<<record.node_loadFactor()<<endl;
    cout<<"The average list size for the duplication check: "<<record.node_loadFactor() / record.loadFactor()<<endl;
    cout << "The load factor for the subject code check: " << subClass.loadFactor() << endl;
    cout << "Total duplications: "<<duplicates << endl;
    
    queue<string> courseKeys = subClass.keys();
    int subject_size = (int)subClass.size();
    
    for(int i = 0; i < subject_size; i++)
    {
        int courseList_size = (int)courseKeys.size();
        string* coursekeys = sorting(courseKeys, courseList_size);
        
        for(int j = 0; j < courseList_size; j++)
            cout << "  " << coursekeys[j] << ", " << subClass[coursekeys[j]] << " section(s)" << endl;
    }
    
    fin.close();
    return 0;
}


int hashCode(const string &key)
{
    int result = 0;
    for(int i = 0; i < key.length(); i++)
        result += key.at(i);
    
    return result;
}

int d_hashCode(const string &key)
{
    int result = 0;
    int i;
    
    for(i = 0; i < key.length() - 4; i++)
        result += key.at(i);
    
    for(int j = 0; j < 4; j++)
        result += (int)(key.at(i + j)) * pow(10, j);
    
    return result;
}

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
