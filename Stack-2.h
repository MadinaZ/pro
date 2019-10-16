//
//  Stack.h
//  HW6-2-2
//
//  Created by Madina Sadirmekova on 10/10/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//
//Programmer: Madina Sadirmekova
//Programmer's ID: 1736270

#ifndef Stack_h
#define Stack_h

template<typename V>
class Stack
{
    struct Node
    {
        V value;
        Node* next;
    };
    
    Node* firstNode;
    int siz;
    
public:
    Stack();
    Stack(const Stack<V>&);
    ~Stack();
    Stack<V>& operator = (const Stack<V>&);
    void push(const V&);
    const V& peek() const;
    void pop();
    void clear();
    int size() const;
    bool empty() const;
};
template<typename V>
Stack<V>::Stack()
{
    firstNode = 0;
    siz = 0;
};

template<typename V>
Stack<V>::Stack(const Stack<V>& original)//copy
{
    firstNode = 0;
    Node* lastNode = 0;
    siz = original.siz;
    for(Node* p = original.firstNode; p; p = p->next)
    {
        Node* temp = new Node;
        temp->value = p->value;
        temp->next = 0;
        if(lastNode)
            lastNode->next = temp;
        else
            firstNode = temp;
        lastNode = temp;
    }
}

template<typename V>
Stack<V>::~Stack()
{
    while(firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        siz--;
    }
}

template<typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)//assign
{
    if(this != &original)
    {
        while(firstNode)
        {
            Node *p = firstNode;
            firstNode = firstNode->next;
            delete p;
        }
        
        Node* lastNode = 0;
        for(Node* p = original.firstNode; p; p = p->next)
        {
            Node* temp = new Node;
            temp->value = p->value;
            temp->next = 0;
            if(lastNode)
                lastNode->next = temp;
            else
                firstNode = temp;
            lastNode = temp;
        }
        siz = original.siz;
    }
    return *this; //to match the data type
}

template<typename V>
void Stack<V>::push(const V& value)
{
    Node* temp = new Node;
    temp->value = value;
    temp->next = firstNode;
    firstNode = temp;
    siz++;
}

template<typename V>
const V& Stack<V>::peek() const
{
    if(firstNode == 0)
        return V();
    return firstNode->value;
}

template<typename V>
void Stack<V>::pop()
{
    if(firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}

template<typename V>
void Stack<V>::clear()
{
    while(firstNode)
    {
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        --siz;
    }
}

template<typename V>
int Stack<V>:: size() const
{
    return siz;
}

template<typename V>
bool Stack<V>:: empty() const
{
    if(siz == 0)
        return true;
    else
        return false;
}

#endif /* Stack_h */
