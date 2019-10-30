//
//  AssociativeArray.LabExercise8.h
//  Lab-8
//
//  Created by Madina Sadirmekova on 10/28/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//


//Programmer:Madina Sadirmekova
//Programmer's ID:1736270
#ifndef AssociativeArray_LabExercise8_h
#define AssociativeArray_LabExercise8_h

#include<queue>
using namespace std;

template<typename K, typename V>
class AssociativeArray
{
    struct Node
    {
        K key;
        V value;
        bool inUse;
    };
    
    Node *values;
    int siz;
    int cap;
    void capacity(int);
public:
    AssociativeArray(int = 2);
    AssociativeArray(const AssociativeArray<K,V> &);
    AssociativeArray<K,V>& operator = (const AssociativeArray<K,V> &);
    ~AssociativeArray(){delete [ ] values;}
    V operator[](const K&) const; //getter
    V& operator[](const K&); //setter
    bool containsKey(const K&) const; // do we have this key or not
    void deleteKey(const K&);
    queue<K> keys() const; //STL queue will return all the key from the associative array
    int size() const{return siz;}
    void clear();
};

template<typename K, typename V>
void AssociativeArray<K,V>::capacity(int cap)
{
    V* temp = new V[cap];
    for(int i = 0; i < this->cap; i++)
        temp[i] = values[i];
    
    for(int i = this->cap; i < cap; i++)
        temp[i] = V();
    delete [ ] values;
    values = temp;
    this->cap = cap;
}

template<typename K, typename V>
AssociativeArray<K,V>::AssociativeArray(int cap)
{
    values = new Node[cap];
    this->cap = cap;
    siz = 0;
    for(int i = 0; i < cap; i++)
    {
        values[i].inUse = false;
        //V() or K() is ok
    }
}

template<typename K, typename V>
AssociativeArray<K,V>::AssociativeArray(const AssociativeArray<K,V>& original)
{
    siz = original.siz;
    values = new V[siz];
    
    for(int i = 0; i < siz; i++)
        values[i] = original.value[i];
    //values[i].key = original[i].key;
    //values[i].original = original[i].original;
}

template<typename K, typename V>
AssociativeArray<K,V>& AssociativeArray<K,V>::operator=(const AssociativeArray<K,V>& original)
{
    if(this != &original)
    {
        delete [ ] values;
        
        siz = original.siz;
        values = new Node[siz];
        for(int i = 0; i < siz; i++)
            values[i] = original.values[i];
    }
    return *this; //to match the data type
}

//--------
template<typename K, typename V>
V& AssociativeArray<K,V>::operator[ ](const K& key)
{
    int firstNotUsedIndex = cap;
    for(int i = 0; i < cap; i++)
    {
        if(values[i].key == key && values[i].inUse == true)
            return values[i].value;
        if(values[i].inUse == false && firstNotUsedIndex == cap)
            firstNotUsedIndex = i;
    }
    //assign the key to the first unused node
    if(firstNotUsedIndex == cap)
        capacity(2*cap);
        
        values[firstNotUsedIndex].key = key;
        values[firstNotUsedIndex].inUse = true;
        values[firstNotUsedIndex].value = V();//need it in case if the user wants to cout
        siz++;
    return values[firstNotUsedIndex].value;
}

template<typename K, typename V>
V AssociativeArray<K,V>::operator[ ](const K& key) const
{
    for(int i = 0; i < cap; i++)
    {
        if(values[i].key == key && values[i].inUse == true)
            return values[i].value;
    }
    return V();
}

template<typename K, typename V>
bool AssociativeArray<K,V>::containsKey(const K& key) const
{
    for(int i = 0; i < cap; i++)
    {
        if(values[i].key == key && values[i].inUse == true)
            return true;
    }
    return false;
}
template<typename K, typename V>
void AssociativeArray<K,V>::deleteKey(const K& key)
{
    for(int i = 0; i < cap; i++)
    {
        if(values[i].key == key && values[i].inUse == true)
        {
            values[i].inUSe = false;
            siz--;
        }
    }
}

template<typename K, typename V>
queue<K> AssociativeArray<K,V>::keys() const
{
    queue<K> k_queue;
    for(int i = 0; i < cap; ++i)
    {
        if(values[i].inUse)
            k_queue.push(values[i].key);
    }
    return k_queue;
}

template<typename K, typename V>
void AssociativeArray<K,V>:: clear()
{
    for(int i = 0; i < cap; i++)
    {
        values[i].inUse = false;
        siz = 0;
    }
}


#endif /* AssociativeArray_LabExercise8_h */
