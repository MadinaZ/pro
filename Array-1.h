//
//  Array.h
//  Assignment2-part2
//
//  Created by Madina on 9/8/19.
//  Copyright © 2019 Madina. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <iostream>
#include <cassert>
#include<string>
#include<cctype>
#include<cstdlib>
using namespace std;

class Array
{
    int values[100];
    int dummy;
public:
    Array();
    int capacity() const;
    int operator[](int) const;
    int& operator[](int);
};
Array::Array()
{
    for(int i = 0; i < 100; i++)
        values[i] = 0;
}
int Array::operator[](int index) const
{
    if(index < 0 || index >= 100)
        return 0;
    else
        return values[index];
}
int& Array::operator[](int index)
{
    if(index < 0 || index >= 100)
        return dummy;
    return values[index];
}
int Array:: capacity() const
{
    int length = sizeof(values)/sizeof(int);
    assert(length == 100);
    return length;
}
#endif /* Array_h */

