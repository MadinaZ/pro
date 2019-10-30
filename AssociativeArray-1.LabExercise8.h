#ifndef ASSOCIATIVEARRAY_LABEXERCISE8_H_INCLUDED
#define ASSOCIATIVEARRAY_LABEXERCISE8_H_INCLUDED
#include <queue>

using namespace std;


template <typename K, typename V>
class AssociativeArray
{
    struct Node
    {
        K key;
        V value;
        bool inUse;
    };
    Node* values;
    int siz;
    int cap;
    void capacity(int);

public:
    AssociativeArray(int = 2);
    AssociativeArray(const AssociativeArray<K, V> &);
    AssociativeArray<K, V>& operator=(const AssociativeArray<K, V> &);
    ~AssociativeArray( );
    V operator[ ](const K&) const;
    V& operator[ ] (const K&);
    bool containsKey(const K&) const;
    void deleteKey(const K&);
    queue<K> keys() const;
    int size( ) const;
    void clear( );
};

template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(int cap) //main contructor
{
    values = new Node[cap];
    this -> cap = cap;
    siz = 0;
    for(int i = 0; i < cap; i++)
	values[i].inUse = false;
}

template <typename K, typename V>  //copy constructor
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>& original)
{
    cap = original.cap;
    siz = original.siz;

    values = new V[cap];

    for (int i = 0; i < cap; i++)
        values[i] = original[i].values;
}

template <typename K, typename V>  // assignment operator
AssociativeArray<K, V>& AssociativeArray<K, V>::operator = (const AssociativeArray<K, V>& original)
{
    if (this != &original)
    {
        delete [ ] values;

        cap = original.cap;
        values = new V[cap];
        for(int i = 0; i < cap; i++)
            values[i] = original.values[i];
    }
    return *this;
}

template <typename K, typename V> // destructor function
AssociativeArray<K, V>::~AssociativeArray( )
{
    delete [ ] values;
}

template <typename K, typename V>
V AssociativeArray<K, V>::operator[](const K& key) const //getter function
{
    for(int i = 0; i < cap; i++)
    {
	if(values[i].key == key && values[i].inUse == true)
	return values[i].value;
    }
    return V();
}

template <typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key) //setter function
{
    int indexOfFirstUnusedKey = cap;
    for(int i = 0; i < cap; i++)
    {
	if(values[i].key == key && values[i].inUse == true)
	    return values[i].value;
	if(values[i].inUse == false && indexOfFirstUnusedKey == cap)
	    indexOfFirstUnusedKey = i;
    }
    //No matching key was found. Meaning we reached the end of the array
    if(indexOfFirstUnusedKey == cap) capacity(2 * cap);
    values[indexOfFirstUnusedKey].key = key;
    values[indexOfFirstUnusedKey].inUse = true;
    values[indexOfFirstUnusedKey].value = V();
    siz++;
    return values[indexOfFirstUnusedKey].value;
}

template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const //getter for key bool
{
    for(int i = 0; i < cap; i++)
    {
	if(values[i].key == key && values[i].inUse == true)
	return true;
    }
    return false;
}

template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key) //setter to delete
{
    for(int i = 0; i < cap; i++)
    {
	if(values[i].key == key && values[i].inUse == true)
	values[i].inUse = false;
	siz--;
    }
}

template <typename K, typename V>
queue<K> AssociativeArray<K, V>::keys( ) const
{
    queue<K> k_queue;
    for(int i = 0; i < cap; i++)
	if(values[i].inUse)
	    k_queue.push(values[i].key);

    return k_queue;
}

template <typename K, typename V>
int AssociativeArray<K, V>::size( ) const
{
    return siz;
}

template <typename K, typename V>
void AssociativeArray<K, V>::clear( )
{
    for(int i = 0; i < cap; i++)
    {
        if(values[i].inUse == true)
            values[i].inUse = false;
        siz = 0;
    }
}
#endif // ASSOCIATIVEARRAY_LABEXERCISE8_H_INCLUDED
