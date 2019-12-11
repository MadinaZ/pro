//
//  Header.h
//  Assignement-12
//
//  Created by Madina Sadirmekova on 11/24/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#ifndef DynamicArray_h
#define DynamicArray_h

template<typename V>
class SortableArray
{
    V* value;
    int cap;
    V dummy = V();
public:
    SortableArray(int = 2);
    SortableArray(const SortableArray<V>&);
    ~SortableArray(){delete [ ] value;}
    SortableArray<V>& operator = (const SortableArray<V>&);
    int capacity() const {return cap;}
    void capacity(int);
    V operator[ ] (int) const;
    V& operator[ ] (int);
    
    void sort(int);
};

template<typename V>
SortableArray<V>::SortableArray(int cap)
{
    this->cap = cap;
    value = new V[cap];
    
    for(int i = 0; i < cap; i++)
        value[i] = V();
}

template<typename V>
SortableArray<V>::SortableArray(const SortableArray<V>& original)
{
    cap = original.cap;
    value = new V[cap];
    
    for(int i = 0; i < cap; i++)
        value[i] = original.value[i];
    dummy = original.dummy;
}

template<typename V>
SortableArray<V>& SortableArray<V>::operator=(const SortableArray<V>& original)
{
    if(this != &original)
    {
        delete [ ] value;
        
        cap = original.cap;
        value = new V[cap];
        for(int i = 0; i < cap; i++)
            value[i] = original.value[i];
        dummy = original.dummy;
    }
    return *this; //to match the data type
}

template<typename V>
void SortableArray<V>:: capacity(int cap)
{
    V* temp = new V[cap];
    for(int i = 0; i < this->cap; i++)
        temp[i] = value[i];
    
    for(int i = this->cap; i < cap; i++)
        temp[i] = V();
    delete [ ] value;
    value = temp;
    this->cap = cap; //reassign our capacity to the newly created one.
}

template<typename V>
V SortableArray<V>::operator[](int index) const
{
    if(index < 0)
        return dummy;
    if(index >= cap)
        return dummy;
    else
        return value[index];
}

template<typename V>
V& SortableArray<V>:: operator[ ] (int index)
{
    if(index < 0)
        return dummy;
    if(index >= cap)
        capacity(index*2);
        return value[index];
}

template<typename V>
void SortableArray<V>::sort(int size)
{
    for(int index = 1; index < size; index++)
       {
           int parentIndex = 0;
           while(true)
           {
               parentIndex = (index + 1)/ 2 - 1;
               if(parentIndex < 0)
                   break;
               if(value[parentIndex] >= value[index])
                   break;
               
               swap(value[parentIndex], value[index]);
               index = parentIndex;
           }
       }

    for(int index = size - 1; index > 0; index--)
    {
        swap(value[0], value[index]);
        int parentIndex = 0;
        while(true)
        {
            int l_child = 2 * parentIndex + 1;
            int r_child = 2 * parentIndex + 2;
            if(l_child >= index)
                break;
            if(r_child >= index)
            {
                if(value[l_child] <= value[parentIndex])
                    break;
                swap(value[l_child], value[parentIndex]);
                parentIndex = l_child;
            }
            else if(value[r_child] < value[l_child])
            {
                if(value[l_child] <= value[parentIndex])
                    break;
                swap(value[l_child], value[parentIndex]);
                parentIndex = l_child;
            }
            else
            {
                if(value[r_child] <= value[parentIndex])
                    break;
                swap(value[r_child], value[parentIndex]);
                parentIndex = r_child;
            }

        }
    }
}
  
#endif /* DynamicArray_h */
