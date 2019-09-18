//
//  StaticArray.TestDriver.cpp
//  Assignment2-part2
//
//  Created by Madina on 9/11/19.
//  Copyright © 2019 Madina. All rights reserved.
//
#include<iostream>
#include<string>
#include <cassert>
#include "StaticArray.h"
using namespace std;

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    StaticArray<int, 100> a;
    StaticArray<double, 100> b;
    StaticArray<char, 100> c;
    StaticArray<string, 100> d;
    
    cout<<"Testing Array::capacity \n";
    cout<<"EXPECTED: 100\n";
    cout<<"ACTUAL: "<<a.capacity()<<endl;
    assert(100 == a.capacity());
    cout<<"Pass \n";
    
    cout<<"Testing Array::Array \n";
    for(int i = 0; i < a.capacity(); i++)
        assert(a[i] == 0);
    cout<<"Pass \n";
    //test for int values
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
    //test for doubles
    b[35] = 2.2;
    b[56] = -48.2;
    b[98] = 32.3;
    
    cout<<"EXPECTED: 2.2 for b[35]"<<endl;
    cout<<"ACTUAL: "<<b[35]<<endl;
    assert(2.2 == b[35]);
    cout<<"EXPECTED: -48.2 for b[56]"<<endl;
    cout<<"ACTUAL: "<<b[56]<<endl;
    assert(-48.2 == b[56]);
    cout<<"EXPECTED: 32.3 for b[98]"<<endl;
    cout<<"ACTUAL: "<<b[98]<<endl;
    assert(32.3 == b[98]);
    cout<<"Pass \n";
    
    //test for char
    c[42] = 'C';
    c[50] = '*';
    
    cout<<"EXPECTED: C for c[42]"<<endl;
    cout<<"ACTUAL: "<<c[42]<<endl;
    assert('C' == c[42]);
    cout<<"EXPECTED: * for c[50]"<<endl;
    cout<<"ACTUAL: "<<c[50]<<endl;
    assert('*' == c[50]);
    
    //test for string
    d[6] = "six";
    d[90] = "ninety";
    cout<<"EXPECTED: six for d[6]"<<endl;
    cout<<"ACTUAL: "<<d[6]<<endl;
    assert("six" == d[6]);
    cout<<"EXPECTED: ninety for d[90]"<<endl;
    cout<<"ACTUAL: "<<d[90]<<endl;
    assert("ninety" == d[90]);
    
    cout<<"Testing the Array::operator[ ]getter \n";
    const StaticArray<int, 100> x = a;
    for(int i = 0; i < 100; i++)
        assert(a[i] == x[i]);
    cout<<"Pass \n";
    
    cout<<"Testing the Array::operator[ ]getter \n";
    const StaticArray<double, 100> y = b;
    for(int i = 0; i < 100; i++)
        assert(y[i] == b[i]);
    cout<<"Pass \n";

    cout<<"Testing the Array::operator[ ]getter \n";
    const StaticArray<char, 100> z = c;
    for(int i = 0; i < 100; i++)
        assert(c[i] == z[i]);
    cout<<"Pass \n";

    cout<<"Testing the Array::operator[ ]getter \n";
    const StaticArray<string, 100> s = d;
    for(int i = 0; i < 100; i++)
        assert(d[i] == s[i]);
    cout<<"Pass \n";
    
    cout<<"Testing the Array::Array in const object \n";
    const StaticArray<int, 100> co;
    assert(co.capacity());
    assert(co[0] == co[0]);
    assert(co[-1] == co[-1]);
    cout<<"Pass \n";
    return 0;
}

