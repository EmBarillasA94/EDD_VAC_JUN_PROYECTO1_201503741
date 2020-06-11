#ifndef LISTA_DOBLE_ENLAZADA_CIRCULAR_H
#define LISTA_DOBLE_ENLAZADA_CIRCULAR_H

#include <iostream>
#include <cstring>
using namespace std;

template<class T>
class Node
{
public:
	Node(T data_) {
		data = data_;
		next = 0;
		before = 0;
	}
	//setters and getters
	Node *getNext() {
		return next;
	}

	Node *getLast() {
		return before;
	}

	T getData() {
		return data;
	}

	void setNext(Node *n) {
		next = n;
	}
	
	void setBefore(Node *n) {
		before = n;
	}

private:
	T data;
	Node *next;
	Node *before;
};

template <class T>
class Lista_Doble_Enlazada_Circular
{
public:
	Lista_Doble_Enlazada_Circular<T>();
	bool isEmpty();
	int getSize();
	void add_firts(T data_);
	void add_last(T data_);
	void eliminiar(String id_);
	void graph();

private:
	Node *first;
	Node *last;
	int size;
};

#endif // !LISTA_DOBLE_ENLAZADA_CIRCULAR_H