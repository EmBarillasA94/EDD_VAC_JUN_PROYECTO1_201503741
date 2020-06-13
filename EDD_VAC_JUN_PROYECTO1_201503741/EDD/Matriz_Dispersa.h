#ifndef MATRIZ_DISPERSA_H
#define MATRIZ_DISPERSA_H

#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	Node(T data_, string fila_, string columna_) 
	{
		this->data = data_;
		this->fila = fila_;
		this->columna = columna_;
		this->arriba = 0;
		this->abajo = 0;
		this->siguiente = 0;
		this->anterior = 0;
		this->adelante = 0;
		this->atras = 0;
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
	Node *getAdelante() {
		return this->adelante;
	}
	Node *getAtras() {
		return this->atras;
	}
	T getData() {
		return this->data;
	}
	string getFila() {
		return this->fila;
	}
	string getColumna() {
		return this->columna;
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
	void setAdelante(Node *n) {
		this->adelante = n;
	}
	void setAtras(Node *n) {
		this->atras = n;
	}

private:
	T data;
	string fila;
	string columna;
	Node *arriba;
	Node *abajo;
	Node *siguiente;
	Node *anterior;
	Node *adelante;
	Node *atras;
};

template<class T>
class Matriz_Dispersa
{
public:
	Matriz_Dispersa();
	void Insertar_elemento(T data_, string fila_, string columna_);
	Node<T> *Buscar_fila(string fila_);
	Node<T> *Buscar_columna(string columna_);

private:
	Node<T> root;
};


#endif // !MATRIZ_DISPERSA_H

