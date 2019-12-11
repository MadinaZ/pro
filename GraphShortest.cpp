//
//  main.cpp
//  Assignment-14
//
//  Created by Madina Sadirmekova on 12/8/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Node
{
    string name;
    
    bool isVisited;
    list<pair<int, double> > neighbors;
    int prev;
    double cost;
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Node>& database)
{
    pair<stack<int>, double> result;
    list<pair<int, double> >::iterator it; // to iterate over neighbors
    // TO DO -- write this function
    queue<int> toDo;
    int vertexIndex;
    
    for (int i = 0; i < database.size(); i++) {
        database[i].isVisited = false;
        database[i].prev = -1;
        database[i].cost = 0;
    }
    
    database[iStart].isVisited = true;
    toDo.push(iStart);
    
    while (!toDo.empty()) {
        vertexIndex = toDo.front();
        toDo.pop();
        
        for (it = database[vertexIndex].neighbors.begin(); it != database[vertexIndex].neighbors.end(); it++) {
            if (!database[it->first].isVisited) {
                database[it->first].isVisited= true;
                database[it->first].cost = 1 + database[vertexIndex].cost;
                database[it->first].prev = vertexIndex;
                toDo.push(it->first);
            }
            if (it->first == iEnd) {
                while (!toDo.empty())
                    toDo.pop();
                break;
            }
        }
    }
    result.second = database[iEnd].cost;
    for (int vertex = iEnd; vertex >= 0; vertex = database[vertex].prev)
        result.first.push(vertex);
    return result;
}

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    ifstream fin;
    fin.open("cities.txt");
    if (!fin.good())
        cout<<"I/O error";
    
    vector<Node> database;
    while (fin.good())
    {
        string fromCity, toCity, cost;
        
        getline(fin, fromCity);
        getline(fin, toCity);
        getline(fin, cost);
        fin.ignore(1000, 10);
        
        int iToNode = -1, iFromNode = -1, i;
        for (i = 0; i < database.size(); i++)
            if (database[i].name == fromCity)
                break;
        if (i == database.size())
        {
            Node fromNode = {fromCity};
            database.push_back(fromNode);
        }
        iFromNode = i;
        
        for (i = 0; i < database.size(); i++)
            if (database[i].name == toCity)
                break;
        if (i == database.size())
        {
            Node toNode = {toCity};
            database.push_back(toNode);
        }
        iToNode = i;
        
        // store bi-directional edges
        double edgeCost = atof(cost.c_str());
        database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
        database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
    }
    fin.close();
    cout << "Input file processed\n\n";
    
    while (true)
    {
        string fromCity, toCity;
        cout << "\nEnter the source city [blank to exit]: ";
        getline(cin, fromCity);
        if (fromCity.length() == 0) break;
        
        int iFrom;
        for (iFrom = 0; iFrom < database.size(); iFrom++)
            if (database[iFrom].name == fromCity)
                break;
        
        cout << "Enter the destination city [blank to exit]: ";
        getline(cin, toCity);
        if (toCity.length() == 0) break;
        
        int iTo;
        for (iTo = 0; iTo < database.size(); iTo++)
            if (database[iTo].name == toCity)
                break;
        
        cout << "Route";
        pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
        for (; !result.first.empty(); result.first.pop())
            cout << '-' << database[result.first.top()].name;
        cout << "Total edges: " << result.second;
        cout << endl;
    }
}

