#ifndef MATRIZ_DISPERSA_H
#define MATRIZ_DISPERSA_H

#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	Node(T data_) 
	{
		this->data = data_;
		this->arriba = 0;
		this->abajo = 0;
		this->siguiente = 0;
		this->anterior = 0;
	}
	//setters and getters
	Node *getArriba() {
		return this->arriba;
	}
	Node *getAbajo() {
		return this->abajo;
	}
	Node *getSiguiente() {
		return this->Siguiente;
	}
	Node *getAnterior() {
		return this->Anterior;
	}
	T getData() {
		return this->data;
	}
	void setArriba(Node *n) {
		this->arriba = n;
	}
	void setAbajo(Node *n) {
		this->abajo = n;
	}
	void setSiguiente(Node *n) {
		this->Siguiente = n;
	}
	void setAnterior(Node *n) {
		this->anterior = n;
	}
private:
	T data;
	Node *arriba;
	Node *abajo;
	Node *siguiente;
	Node *anterior;
};

template<class T>
class Matriz_Dispersa
{
public:
	Matriz_Dispersa<T>();
	void Insertar();

private:
	Node<T> root;
};


#endif // !MATRIZ_DISPERSA_H

