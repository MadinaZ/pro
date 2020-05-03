//Programmers name : Kamaluddin Shamsi & Shota Yamamoto
//Programmers ID : 1626888
#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
	struct Node {
		T value;
		Node* next;
	};

	Node* firstNode;
	int siz = 0;

public:
	Stack();
	Stack(const Stack<T>&); //Copy constructor
	~Stack();
	Stack<T>& operator = (const Stack<T>&);
	void push(const T&);
	const T& peek() const;
	void pop();
	int size() const;
	bool empty() const;
	void clear();
};

template <typename T>
Stack<T>::Stack() {
	firstNode = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& original) {
	firstNode = 0;
	Node* lastNode = 0;
	siz = original.siz;
	for (Node* p = original.firstNode; p; p = p->next) {
		Node* temp = new Node;
		temp->value = p->value;
		temp->next = 0;
		if (lastNode) lastNode->next = temp;
		else firstNode = temp;
		lastNode = temp;
	}
}

template <typename T>
Stack<T>::~Stack() {
	while (firstNode) {
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		siz--;
	}
}

//Assignment Operator
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& original) {
	if (this != &original) {
		//deallocate existing list
		while (firstNode) {
			Node* p = firstNode;
			firstNode = firstNode->next;
			delete p;
		}

		//build new stack
		Node* lastNode = 0; //Temporary tail
		for (Node* p = original.firstNode; p; p = p->next) {
			Node* temp = new Node;
			temp->value = p->value;
			temp->next = 0;
			if (lastNode) lastNode->next = temp;
			else firstNode = temp;
			lastNode = temp;
		}
		siz = original.siz;
	}
	return *this;
}

template <typename T>
void Stack<T>::push(const T& value) {
	Node* temp = new Node;
	temp->value = value;
	temp->next = firstNode;
	firstNode = temp;
	siz++;
}

template <typename T>
const T& Stack<T>::peek() const {
	if (firstNode == 0) return T();
	return firstNode->value;
}

template <typename T>
void Stack<T>::pop() {
	if (firstNode) {
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		siz--;
	}
}

template <typename T>
int Stack<T>::size() const {
	return siz;
}

template <typename T>
bool Stack<T>::empty() const {
	if (firstNode == 0) return true;
	else return false;
}

template <typename T>
void Stack<T>::clear() {
	while (firstNode) {
		Node* p = firstNode;
		firstNode = firstNode->next;
		delete p;
		siz--;
	}
}

#endif
