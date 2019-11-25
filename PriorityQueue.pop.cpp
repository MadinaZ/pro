//
//  main.cpp
//  PriorityQueue.pop.cpp
//
//  Created by Madina Sadirmekova on 11/18/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "PriorityQueue.h"
#include<cassert>
#include<ctime>
#include<cmath>
using namespace std;

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    int n = 1000000;
    
    const int reps = n/100;
    
    cout.setf(ios::fixed);
    cout.precision(4);
    
    double elapsedSecondsNorm = 0;

    
    string bigOh = "O(log n)";
    
    srand(time(0));

    for(int cycle = 0; cycle < 4; cycle++, n*=2)
    {
        PriorityQueue<int> pq;
        
        for(int i = 0; i < n; i++)
        {
            pq.push(rand()%(1000));
        }
        
        assert(pq.size() == n);
        


        
        for(int i = 0; i < reps; i++)
        {
            pq.push(rand()%(1000));
        }
        
        assert(pq.size() == n + reps);

        clock_t startTime= clock();

        for(int i = 0; i < n + reps; i++)
        {
            pq.pop();
        }
        
        assert(pq.size() == 0);
        
        clock_t endTime = clock();
        
        double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        double factor = pow(2.0, double(cycle));
        if (cycle == 0)
            elapsedSecondsNorm = elapsedSeconds;
        double expectedSecondsLog = log(double(n)) / log(n / factor) * elapsedSecondsNorm;
        double expectedSecondsLog_n = log(double(n + reps)) / log( (n + reps) / factor) * elapsedSecondsNorm;
        
        cout << elapsedSeconds;
        
        if (cycle == 0) cout << " (expected " << bigOh << ')';
        else cout << " (expected " << expectedSecondsLog << " to " << expectedSecondsLog_n <<')';
        cout << " for n=" << n << endl;
    }
    

    return 0;
}
