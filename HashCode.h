//
//  HashCode.h
//  Assignment-10
//
//  Created by Madina Sadirmekova on 11/11/19.
//  Copyright © 2019 Madina Sadirme
#ifndef HashCode_h
#define HashCode_h

#include <queue>
#include <list>
using namespace std;

template <typename K, typename T, int CAP >
class HashTable
{
    struct Node
    {
        K key;
        T value;
    };

    list<Node> data[CAP]; //chaining //array
    int (*hashCode)(const K&);// ptr to hashCode function
    int siz; //occupied elements in array
    int n_siz; //total nodes

public:
    HashTable (int(*) (const K&) = 0);
    double loadFactor() const {return 1.0 * siz / CAP; }
    double node_loadFactor() const {return 1.0 *n_siz / CAP; }
    T operator [ ] (const K&) const; //getter
    T& operator [ ] (const K&); //setter
    bool containsKey(const K&) const;//getter
    void deleteKey(const K&);//setter
    queue<K> keys() const;
    int size() const {return siz;}
    int n_size() const {return n_siz;}
    void clear();//each clear you have to delete key //for chaining
    
};

template <typename K, typename T, int CAP >
HashTable<K,T,CAP>::HashTable(int(*hashCode)(const K&))
{
    this->hashCode = hashCode;
    siz = 0;
}

template <typename K, typename T, int CAP >
T HashTable<K,T,CAP>::operator[ ](const K& key) const //getter
{
    int index = HashCode(key)%CAP;
    typename list<Node>::const_iterator it;
    
    for(it = data[index].begin(); it != data[index].end(); it++) //it is a pointer
    {
        if(it->key == key)
            return it->value;
        if(it == data[index].end())
            return T();
    }
}

template <typename K, typename T, int CAP >
T& HashTable<K,T,CAP>::operator[ ](const K& key) //setter
{
    int index = hashCode(key)%CAP;
    if(index < 0)
        index += CAP;
        
    typename list<Node>::iterator it;
    for(it = data[index].begin(); it != data[index].end(); it++) //it is a pointer
    {
        if(it->key == key)
            return it->value;
    }
    
//    Node temp = {key,T()};
    if(data[index].empty())
       siz++;
    Node temp;
    temp.key = key;
    temp.value = T();
    data[index].push_back(temp);
    n_siz++;
    return data[index].back().value;
}

template <typename K, typename T, int CAP >
bool HashTable<K,T,CAP>::containsKey(const K& key) const
{
    int index =  HashCode(key) % CAP;
    if(index < 0)
        index += CAP;
    typename list<Node>::const_iterator it; //getters need to use const_iterator
    for(it = data[index].begin(); it != data[index].end(); it++)
        if(it->key == key)
            return true;
    if( it == data[index].end())
        return false;
}

template <typename K, typename T, int CAP >
void HashTable<K,T, CAP>::deleteKey(const K& key)
{
    int index = HashCode(key)%CAP;
    if(index < 0)
        index += CAP;
    
    typename list<Node>::const_iterator it;
    
    for(it = data[index].begin(); it != data[index].end(); it++) //it is a pointer
    {
        if(it->key == key)
        {
            data[index].erase();
            n_siz--;
            break;
        }
        if(data[index].empty())
            siz--;
    }

}

template <typename K, typename T, int CAP >
queue<K> HashTable<K,T,CAP>::keys() const
{
    queue<K> key_queue;
    for(int i = 0; i < CAP; i++)
    {
        if(!data[i].empty())
        {
            typename list<Node>::const_iterator it;
            for(it = data[i].begin(); it != data[i].end(); it++)
                key_queue.push(it->key);
        }
    }
    return key_queue;
}

template <typename K, typename T, int CAP >
void HashTable<K,T,CAP>::clear()
{
    for(int i = 0; i < CAP; i++)
        data[i].clear();
    siz = 0;
    n_siz = 0;
}

#endif /* HashCode_h */
