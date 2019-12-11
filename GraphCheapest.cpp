//
//  main.cpp
//  GraphCheapest.cpp
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

struct Terminus
{
  int vertex;
  int prev;
  double cost;
};

bool operator < (const Terminus& a, const Terminus& b)
{
    return b.cost < a.cost;
}
pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Node>& database)
{
    pair<stack<int>, double> result;
    list<pair<int, double> >::iterator it;
    priority_queue<Terminus> container_Queue;
    Terminus new_Container;
    Terminus terminus;
    int nodeIndex;
    
    for (int i = 0; i < database.size(); i++) {
      database[i].isVisited = false;
      database[i].cost = 0;
      database[i].prev = -1;
    }
    
    new_Container.vertex = iStart;
    new_Container.cost = 0;
    new_Container.prev = -1;
    
    container_Queue.push(new_Container);

    while (!container_Queue.empty()) {
      terminus = container_Queue.top();
      container_Queue.pop();
      nodeIndex = terminus.vertex;
      
      if (database[nodeIndex].isVisited) continue;
      database[nodeIndex].isVisited = true;
      database[nodeIndex].cost = terminus.cost;
      database[nodeIndex].prev = terminus.prev;
      if (nodeIndex >= database.size()) break;
      for (it = database[nodeIndex].neighbors.begin(); it != database[nodeIndex].neighbors.end(); it++) {
        if (!database[it->first].isVisited) {
          Terminus terminus_neighbor;
          terminus_neighbor.cost = database[nodeIndex].cost + it->second;
          terminus_neighbor.prev = nodeIndex;
          terminus_neighbor.vertex = it->first;
          container_Queue.push(terminus_neighbor);
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

      pair<int, double> edge;
      edge.first = iToNode;
      edge.second = atof(cost.c_str());
      database[iFromNode].neighbors.push_back(edge);
      edge.first = iFromNode;
      database[iToNode].neighbors.push_back(edge);
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
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


