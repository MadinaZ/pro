//   PriorityQueue.h
//  Assignment-11
//
//  Created by Madina Sadirmekova on 11/13/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#ifndef _PriorityQueue_h
#define _PriorityQueue_h

#include<algorithm>
using namespace std;

template<typename V>
class PriorityQueue
{
    V *values;
    int cap;
    int siz;
    void capacity(int);

public:
    PriorityQueue(int = 2);
    PriorityQueue(const PriorityQueue<V>&);
    ~PriorityQueue() { delete [ ] values;}
    PriorityQueue<V>& operator = (const PriorityQueue<V>&);

    void push(const V&);
    void pop();
    V top() const { return values[0];}
    int size() const {return siz;}
    bool empty() const {return siz == 0 ? true : false;}
    void clear() { siz = 0;}
};

template<typename V>
void PriorityQueue<V>::capacity(int cap)
{
    V* temp = new V[cap];
    for(int i = 0; i < this->cap; i++)
        temp[i] = values[i];

    for(int i = this->cap; i < cap; i++)
        temp[i] = V();
    delete [ ] values;
    values = temp;
    this->cap = cap; //reassign our capacity to the newly created one.
}

template<typename V>
PriorityQueue<V>::PriorityQueue(int newcap)
{
    siz = 0;
    cap = newcap;
    values = new V[cap]; //you don't have to use for loop
}
template<typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)//copy
{
    cap = original.cap;
    siz = original.siz;

    values = new V[cap];

    for(int i = 0; i < cap; i++)
        values[i] = original.values[i];
}

template<typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)//assign
{
    if(this != &original)
       {
           delete [ ] values;

           cap = original.cap;
           siz = original.siz;

           values = new V[cap];
           for(int i = 0; i < cap; i++)
               values[i] = original.values[i];
       }
       return *this; //to match the data type
}
template<typename V>
void PriorityQueue<V>::push(const V& value)
{
    if(cap == siz)
        capacity(cap * 2);
    values[siz] = value;
    int index = siz;

    while(index != 0)
    {
        int p_index = (index + 1)/2 - 1;
        if(values[index] < values[p_index])
            break;

        swap(values[index], values[p_index]);
        index = p_index;
    }
    siz++;

}

template <typename V>
void PriorityQueue <V>::pop()
{
  if (siz == 0)
    return;//return nothing since it is a void function

  int index = 0;
  while (true)
  {
    int l_index = 2 * index + 1;
    int r_index = 2 * index + 2;

    if (l_index >= siz)
      break;

    if (values[r_index] < values[l_index] || r_index >= siz)
    {
      values[index] = values[l_index];
      index = l_index;
    }
    else
    {
      values[index] = values[r_index];
      index = r_index;
    }
  }
  siz--;
    if(index == siz)
  values[index] = values[siz];

  while (true)
  {
    int p_index = ((index + 1) / 2) - 1;
    if (p_index < 0 || values[index] < values[p_index])
      break;

      swap(values[index], values[p_index]);
    index = p_index;
  }
}


#endif /* _PriorityQueue_h */
