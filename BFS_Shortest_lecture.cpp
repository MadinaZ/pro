//Solution file for COMSC-210
//Module 13 - Graph Searches
// LabExercise 13 Part 1
//BFS_Shortest.cpp (use a queue to build up the to-do list)

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
  string name;

  int prev; //new
  int cost; // new
  bool isVisited;
  list<int> neighbors;
};

// BFS return a queue contains the indexes of all reachable nodes
stack<int> BFS_Shortest(int iOriginNode, int iEndNode, vector<Node>& database)
{
  stack<int> result; // return this queue of indices
  queue<int> toDo;   // queue

  // initialization of the database
  for(int i = 0; i < database.size(); i++)
  {
    database[i].prev = -1; //new
    database[i].cost = 0; //new
    database[i].isVisited = false;
  }

  // mark start node
  database[iOriginNode].isVisited = true;
  // push to result
//  result.push(iOriginNode);
  // push to "to do" list
  toDo.push(iOriginNode);

  while(!toDo.empty())
  {
    int i = toDo.front(); //node under consideration
    toDo.pop();
    list<int> neighbors = database[i].neighbors;

    for(list<int>::const_iterator it = neighbors.begin(); it != neighbors.end(); ++it)
    {
      if(!database[*it].isVisited)
      {
        database[*it].prev = i; //new
        database[*it].cost = 1 +  database[i].cost; //new
        database[*it].isVisited = true;
    //    result.push(*it);
        toDo.push(*it);
      }
      if (*it == iEndNode)
      { //empty the queue
        while (!toDo.empty())
          toDo.pop();
        break;
      }
    }
  }
  
 // result.push(iEndNode);
  int index = iEndNode;
  while (index != -1){
    result.push(index);
    index = database[index].prev;
  }
  return result;
}

int main()
{
  cout << "Assignment 14\n"
       << "Solution file (Part 1)\n"
       << "File: " << __FILE__ << "\n\n";

  ifstream fin;
  fin.open("cities.txt");
  if(!fin.good()) throw "I/O error";

  // process the input file to build up the database****
  vector<Node> database;
  while(fin.good()) // EOF loop
  {
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator

    // add vertices for new cities included in the edge
    int iToNode = -1, iFromNode = -1, i;
    for(i = 0; i < database.size(); i++) // seek "to" city
      if(database[i].name == fromCity)
        break;
    if(i == database.size()) // not in database yet
    {
      // store the node if it is new
      Node fromNode = {fromCity};
      database.push_back(fromNode);
    }
    iFromNode = i;

    for(i = 0; i < database.size(); i++) // seek "from" city
      if(database[i].name == toCity)
        break;
    if(i == database.size()) // not in vector yet
    {
      // store the node if it is new
      Node toNode = {toCity};
      database.push_back(toNode);
    }
    iToNode = i;

    // store bi-directional edges
    database[iFromNode].neighbors.push_back(iToNode);
    database[iToNode].neighbors.push_back(iFromNode);
  }
  fin.close();
  cout << "Input file processed\n\n";
  // End of process the input file to build up the database****
    
  while(true)
  {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if(startCity.length() == 0) break;

    // find the start city
    int i;
    for(i = 0; i < database.size(); i++)
      if(database[i].name == startCity)
        break;
        
// get the end city for the shortest route
    string endCity;
    cout << "\nEnter the end city [blank to exit]: ";
    getline(cin, endCity);
    if(endCity.length() == 0) break;

    // find the end city
    int j;
    for(j = 0; j < database.size(); j++)
      if(database[j].name == endCity)
        break;
        
    // BFS result by copy-pop
    cout << "BFS - Shortest Route:" << endl;
    for(stack<int> s = BFS_Shortest(i, j, database); !s.empty(); s.pop())
      cout  << '-'<< database[s.top()].name;
    cout << endl;
  }
}
