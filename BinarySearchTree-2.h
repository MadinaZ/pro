//
//  Header.h
//  lab-12
//
//  Created by Madina Sadirmekova on 11/25/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include<queue>

template<typename K, typename V>
class BinarySearchTree
{
    struct Node
    {
        K key;
        V value;
        Node *left;
        Node *right;
    };

    Node *rootNode;
    int siz;
    void Keys(const Node*, queue<K> &) const;
    void clear(Node*);
    void copyTree(Node*, const Node*);

    /*
     Node *temp = new Node;
     {orignial.rootNode->key, original.rootNode->value};
     rootNode = temp;

     3 case -- when you delete the nide dont forget to initialize the deleted node to zero

     if(prev->left = p) prev->left = p->right
     */
public:
    BinarySearchTree() {rootNode = 0; siz = 0;}
    BinarySearchTree(const BinarySearchTree&);
    BinarySearchTree<K,V>& operator = (const BinarySearchTree<K,V> &);
    ~BinarySearchTree() {clear();}
    //setter is kind of push
    //clear just like destructor
    int size() {return siz;}
    V operator[ ](const K&) const;
    V& operator [ ](const K&);
    bool containsKey(const K&);
    void deleteKey(const K&);
    queue<K> Keys() const;
    void clear();
};

template<typename K, typename V>
void BinarySearchTree<K,V>::Keys(const Node* p, queue<K>& q)const
{
    if(!p) return;
    Keys(p->left, q);
    q.push(p->key);
    Keys(p->right, q);
}

template<typename K, typename V>
void BinarySearchTree<K,V>::clear(Node *p)
{
    if(!p) return;
    clear(p->left);
    clear(p->right);
    delete p;
}

template<typename K, typename V>
void BinarySearchTree<K,V>::copyTree(Node* p, const Node* copiedTree)
{
    if(!p) return;
    p->key = copiedTree->key;
    p->value = copiedTree->value;
    p->left = p->right = 0;
    if(copiedTree->left)
        copyTree(p->left = new Node, copiedTree->left);
    if(copiedTree->right)
        copyTree(p->right = new Node, copiedTree->right);
}

template<typename K, typename V>
BinarySearchTree<K,V>::BinarySearchTree(const BinarySearchTree& original)
{
    rootNode = 0;
    if(original.rootNode)
        copyTree(rootNode = new Node, original.rootNode);
    siz = original.siz;
}

template<typename K, typename V>
BinarySearchTree<K,V>& BinarySearchTree<K,V>::operator=(const BinarySearchTree<K,V>& original)
{
    if(this != &original)
    {
        clear();
        rootNode = 0;
        if(original.rootNode)
           copyTree(rootNode = new Node, original.rootNode);
        siz = original.siz;
    }
    return *this;
}

template<typename K, typename V>
V BinarySearchTree<K,V>::operator[](const K& key) const//getter
{
    Node *p = rootNode;
    while(p)
    {
        if(p->key == key)
            return p->value;
        if(p->key < key)
            p = p->right;
        //        if(p->key > key)--->to the left
        else
            p = p->left;

    }
    return V();
}

template<typename K, typename V>
V& BinarySearchTree<K,V>::operator[](const K& key)//setter
{
    if(rootNode == 0)
    {
        siz++;
        rootNode = new Node;
        rootNode->key = key;
        rootNode->value = V();
        rootNode->left = rootNode->right = 0;
        return rootNode->value;
    }
    Node *p = rootNode;
    Node * prev = 0;
    while(p)
    {
        if(p->key == key)
        {
            return p->value;
        }
        prev = p;//?
        if(p->key < key)
            p = p->right;
        //        if(p->key > key)--->to the left
        else
            p = p->left;
    }
    //if the key is not found, create new Node
    //before creating a node increment your size
    siz++;
    p = new Node;
    p->key = key;
    p->value = V();
    p->left = p->right = 0;

    if (prev == 0) {
        rootNode = p;
        return p->value;
    } else {
        if (prev->key < key) prev->right = p;
        else prev->left = p;
        return p->value;
    }
}

//Alex Carla Denise Fred is the order right_child is greater than the left_child
template<typename K, typename V>
bool BinarySearchTree<K,V>::containsKey(const K& key) //getter
{
    Node *p = rootNode;
    while(p)
    {
        if(p->key == key)
            return true;
        if(p->key < key)
            p = p->right;
        if(p->key > key)
            p = p->left;

    }
    return false;
}
//we need to replace the rootnode from the smallest node. for ex, if we choose left side we picj the roght most and vice versa

template<typename K, typename V>
void BinarySearchTree<K, V>::deleteKey(const K& key)//getter
{
    Node *p = rootNode;
    Node * prev = 0;

    while(p)
    {
        if(p->key == key)
            break;
        if(p->key < key)
            p = p->right;
            //        if(p->key > key)--->to the left
            else
                p = p->left;

    }

    if(!p)
        return;
    if(p->left == 0&& p->right == 0)
    {
        if(prev == 0)
            rootNode = 0;
            else
            {
                if(prev->left == p)
                    prev->left = 0;
                    else
                        prev->right = 0;
                        }
        delete p;
        siz--;

    }
}


template<typename K, typename V>
queue<K> BinarySearchTree<K,V>::Keys()const
{
    queue<K> keys;
    Keys(rootNode, keys);
    return keys;
}

template<typename K, typename V>
void BinarySearchTree<K,V>::clear()
{
    clear(rootNode);
    rootNode = 0;
    siz = 0;
}

#endif /* Header_h */
