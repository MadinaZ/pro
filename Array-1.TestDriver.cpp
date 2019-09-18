//
//  main.cpp
//  Assignment2
//
//  Created by Madina on 9/4/19.
//  Copyright © 2019 Madina. All rights reserved.
//

#include "Array.h"

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    Array a;
    
    cout<<"Testing Array::capacity \n";
    cout<<"EXPECTED: 100\n";
    cout<<"ACTUAL: "<<a.capacity()<<endl;
    assert(100 == a.capacity());
    cout<<"Pass \n";
    
    cout<<"Testing Array::Array \n";
    for(int i = 0; i < a.capacity(); i++)
        assert(a[i] == 0);
    cout<<"Pass \n";
    cout<<"Testing the Array::operator[ ]setter \n";
    a[99] = 34;
    a[5] = 666;
    cout<<"EXPECTED: 34 for a[99]"<<endl;
    cout<<"ACTUAL: "<<a[99]<<endl;
    assert(34 == a[99]);
    cout<<"EXPECTED: 666 for a[5]"<<endl;
    cout<<"ACTUAL: "<<a[5]<<endl;
    assert(666 == a[5]);
    cout<<"Pass \n";
    
    cout<<"Testing the Array::operator[ ]getter \n";
    const Array b = a;
    for(int i = 0; i < 100; i++)
        assert(a[i] == b[i]);
    cout<<"Pass \n";
    
    cout<<"Testing the Array::Array in const object \n";
    const Array c;
    assert(c.capacity());
    assert(c[0] == c[0]);
    assert(c[-1] == c[-1]);
    cout<<"Pass \n";
    return 0;
}
