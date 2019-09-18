//
//  Array.h
//  Assignment2-part2
//
//  Created by Madina on 9/8/19.
//  Copyright © 2019 Madina. All rights reserved.
//

#ifndef StaticArray_h
#define StaticArray_h
template<typename V, int CAP>
class StaticArray
{
    V values[CAP];
    V dummy;
public:
    StaticArray();
    int capacity() const;
    V operator[](int) const;
    V& operator[](int);
};

template<typename V, int CAP>
StaticArray<V,CAP>::StaticArray()
{
    for(int i = 0; i < CAP; i++)
        values[i] = V();
}
template<typename V, int CAP>
V StaticArray<V,CAP>::operator[](int index) const
{
    if(index < 0)
        return V();
    if(index >= CAP)
        return V();
    else
        return values[index];
}
template<typename V, int CAP>
V& StaticArray<V, CAP>::operator[](int index)
{
    if(index < 0 || index > CAP || index == CAP)
        return dummy;
    return values[index];
}
template<typename V, int CAP>
int StaticArray<V, CAP>:: capacity() const
{
//    int length = sizeof(values)/sizeof(V);
//    assert(length == CAP);
//    return length;
    return CAP;
}
#endif /* Array_h */



