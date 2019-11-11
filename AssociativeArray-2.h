//
//  AssociativeArray.h
//  Assignment-9
//
//  Created by Madina Sadirmekova on 11/1/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.

#include <queue>
using namespace std;

template <typename K, typename T>
class AssociativeArray{
    struct Node{
        K key;
        T value;
        Node *next;
    };

    Node* firstNode;
    int siz;

public:
    AssociativeArray();
    AssociativeArray(const AssociativeArray&);
    AssociativeArray<K,T>& operator=(const AssociativeArray<K,T>&);
    ~AssociativeArray();
    T operator[](const K&) const;
    T& operator[](const K&);
    bool containsKey(const K&) const;
    void deleteKey(const K&);
    queue<K> keys() const;
    void clear();
    int size(){return siz;}
};

template<typename K, typename T>
AssociativeArray<K,T>::AssociativeArray()
{
    firstNode = 0;
    siz = 0;
}

template<typename K, typename T>
AssociativeArray<K,T>::AssociativeArray(const AssociativeArray& original)
{
    firstNode = 0;
    Node* lastNode = 0;
    siz = original.siz;
    for(Node* p = original.firstNode; p; p = p->next){
        Node* temp = new Node;
        temp->key = p->key;
        temp->value = p->value;
        temp->next = 0;
        if(lastNode) lastNode->next = temp;
        else firstNode = temp;
        lastNode = temp;
    }
}

template<typename K, typename T>
AssociativeArray<K,T>& AssociativeArray<K,T>::operator=(const AssociativeArray<K,T>& original)
{
    if(this != &original){
        while(firstNode){
            Node* p = firstNode;
            firstNode = firstNode->next;
            delete p;
        }

        Node* lastNode = 0;
        for(Node* p = original.firstNode; p; p = p->next){
            Node* temp = new Node;
            temp->key = p->key;
            temp->value = p->value;
            temp->next = 0;
            if(lastNode) lastNode->next = temp;
            else firstNode = temp;
            lastNode = temp;
        }
        siz = original.siz;
    }
    return *this;
}

template<typename K, typename T>
AssociativeArray<K,T>::~AssociativeArray()
{
    while(firstNode){
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        siz--;
    }
}

template<typename K, typename T>
T AssociativeArray<K,T>::operator[](const K& key) const
{
    for(Node* p = firstNode; p; p = p->next)
        if(p->key == key)
            return p->value;
}

template<typename K, typename T>
T& AssociativeArray<K,T>::operator[](const K& key)
{
    for(Node* p = firstNode; p; p = p->next)
        if(p->key == key)
            return p->value;

    Node* temp = new Node;
    temp->key = key;
    temp->value = T();
    temp->next = firstNode;
    firstNode = temp;
    siz++;
    return firstNode->value;
}

template<typename K, typename T>
bool AssociativeArray<K,T>::containsKey(const K& key) const
{
    for(Node* p = firstNode; p; p = p->next){
        if(p->key == key)
            return true;
    }
    return false;
}

template<typename K, typename T>
void AssociativeArray<K,T>::deleteKey(const K& key)
{
    Node* p, *prev;
    for(p = firstNode, prev = 0; p; prev = p, p = p->next)
        if(p->key == key)
            break;
    if(p)
    {
        if(prev) prev->next = p->next;
        else firstNode = p->next;
        delete p;
        siz--;
    }
}

template<typename K, typename T>
queue<K> AssociativeArray<K,T>::keys() const
{
    queue<K> keyList;
    for(Node* p = firstNode; p; p = p->next)
    {
        keyList.push(p->key);
    }
    return keyList;
}

template<typename K, typename T>
void AssociativeArray<K,T>::clear()
{
    while(firstNode){
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        siz--;
    }
}
