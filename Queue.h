//Programming name : Kamaluddin Shamsi
//Programming ID : 1626888

#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue{
    struct Node{
        T value;
        Node* next;
    };

    Node* firstNode;
    Node* lastNode;
    int siz = 0;

public:
    Queue();
    Queue(const Queue<T>&); //Copy constructor
    ~Queue();
    Queue<T>& operator = (const Queue<T>&);
    void push(const T&);
    const T& front() const;
    const T& back() const;
    void pop();
    int size() const;
    bool empty() const;
    void clear();
};

template <typename T>
Queue<T>::Queue(){
    firstNode = 0;
    lastNode = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& original){
    firstNode = 0;
    lastNode = 0;
    siz = original.siz;
    for(Node* p = original.firstNode; p; p = p->next){
        Node* temp = new Node;
        temp->value = p->value;
        temp->next = 0;
        if(lastNode) lastNode->next = temp;
        else firstNode = temp;
        lastNode = temp;
    }
}

template <typename T>
Queue<T>::~Queue(){
    while(firstNode){
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        siz--;
    }
}

//Assignment Operator
template <typename T>
Queue<T>& Queue<T>::operator = (const Queue<T>& original){
    if(this != &original){
        //deallocate existing list
        while(firstNode){
            Node* p = firstNode;
            firstNode = firstNode->next;
            delete p;
        }

        //build new queue
        lastNode = 0; //Temporary tail
        for(Node* p = original.firstNode; p; p = p->next){
            Node* temp = new Node;
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

template <typename T>
void Queue<T>::push(const T& value){
    Node* temp = new Node;
    temp->value = value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
    siz++;
}

//Get the value of the first node
template <typename T>
const T& Queue<T>::front() const{
    if(firstNode == 0) return T();
    return firstNode->value;
}

//Get the value of the last node
template <typename T>
const T& Queue<T>::back() const{
    if(firstNode == 0) return T();
    return lastNode->value;
}

template <typename T>
void Queue<T>::pop(){
    if (firstNode){
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        siz--;
    }
    if (size() == 0)
        lastNode = 0;
}

template <typename T>
int Queue<T>::size() const{
    return siz;
}

template <typename T>
bool Queue<T>::empty() const{
    if(firstNode == 0) return true;
    else return false;
}

template <typename T>
void Queue<T>::clear(){
    while(firstNode){
        Node* p = firstNode;
        firstNode = firstNode->next;
        delete p;
        siz--;
    }
    lastNode = 0;
}

#endif
