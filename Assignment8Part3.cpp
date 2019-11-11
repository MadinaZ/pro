//
//  main.cpp
//  Assignment-8-part-3
//
//  Created by Madina Sadirmekova on 10/26/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#include<iostream>
#include<algorithm>
using namespace std;
#include<ctime>
#include<cassert>
#include<cstdlib>
#include "DynamicArray.h"
#include<cmath>

int main()
{

    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";

    srand(time(0));

    string bigOh = "O(n squared)";
    DynamicArray<double> a;
    int n = 1000;

    double elapsedSecondsNorm = 0;
    double expectedSeconds = 0;
    a.capacity(n);



    for(int cycle = 0; cycle < 4; cycle++, n*=2)
    {
        
        for(int i = 0; i < n; i++)
        {
            a[i] = rand()%(1000);
        }
        a.capacity(n);
        assert(a.capacity() == n);

        clock_t startTime = clock();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[i] > a[j])
                    swap(a[i], a[j]);
            }
        }
        clock_t endTime = clock();

        for(int i = 1; i < n; i++)
            assert(a[i - 1] <= a[i]);

        double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        double factor = pow(2.0, double(cycle));
        if (cycle == 0)
            elapsedSecondsNorm = elapsedSeconds;
        else if (bigOh == "O(n)")
            expectedSeconds = factor * elapsedSecondsNorm;
        else if (bigOh == "O(n log n)")
            expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
        else if (bigOh == "O(n squared)")
            expectedSeconds = factor * factor * elapsedSecondsNorm;
        // reporting block

        cout << elapsedSeconds;
        if (cycle == 0) cout << " (expected " << bigOh << ')';
        else cout << " (expected " << expectedSeconds << ')';
        cout << " for n=" << n << endl;
    }

    return 0;
}
