//
//  main.cpp
//  Test
//
//  Created by Madina Sadirmekova on 11/24/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#include<iostream>
using namespace std;
#include<cstdlib>
#include<cctype>
#include<cassert>
#include "SortableArray.h"

const bool Placed = true;
int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    SortableArray<double> a;
    SortableArray<bool> storeStatus;
    int count = 0;
    char ch[15], chi[15], chi_size[15];
    double value;
    int index = 0;
    while(chi[0] != 'Q' || chi[0] != 'q')
    {
        cout<<"Input an index and a value [Q to quit]: ";
        cin>>chi;
        if(chi[0] == 'Q' || chi[0] == 'q')
            break;
        cin>>ch;
        value = atof(ch);
        if(isalpha(chi[0]))
            index = 0;
        else
            index = atoi(chi);
        
        a[index] = value;
        storeStatus[index] = Placed;
        
    }
    //cout<<"CAPACITY: "<<a.capacity()<<endl;
    
    for(int i = 0; i < a.capacity(); i++)
    {
        if(storeStatus[i] == Placed)
            count++;
    }
    cout<<"You stored this many values: "<<count<<endl;
    
    cout<<"The index-value pairs are:"<<endl;
    for(int i = 0; i < a.capacity(); i++)
    {
        if(storeStatus[i] != 0)
            cout<<i<<" -> "<<a[i]<<endl;
    }
    
    cout<<"Input the size to be sort [Q to quit]: ";
    cin>>chi_size;
    if(chi_size[0] == 'Q' || chi_size[0] == 'q')
        exit(0);
    
    int size = atoi(chi_size);
    cout<<"Sorted till "<<chi_size<<endl;
    
    a.sort(size);
    for(int i = 0; i < a.capacity(); i++)
    {
        if(storeStatus[i] != 0)
            cout<<i<<" -> "<<a[i]<<endl;
    }
    
    while(chi[0] != 'Q' || chi[0] != 'q')
    {
        cout<<"Input an index for me to look up [Q to quit]: ";
        cin>>chi;
        if(chi[0] == 'Q' || chi[0] == 'q')
            break;
        index = atof(chi);
        if(a[index] != 0 && (index >=0 && index < a.capacity()))
            cout<<"Found it -- the value stored at "<<index<<" is "<<a[index]<<endl;
        else
            cout<<"I didn't find it \n";
    }
    
    return 0;
}
