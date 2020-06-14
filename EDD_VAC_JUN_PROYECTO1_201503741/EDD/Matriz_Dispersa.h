

#include <iostream>
#include <cstring>
using namespace std;

template<class N>
class NodeMatriz
{
public:
	NodeMatriz(N data_, string fila_, string columna_) 
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
	NodeMatriz *getArriba() {
		return this->arriba;
	}
	NodeMatriz *getAbajo() {
		return this->abajo;
	}
	NodeMatriz *getSiguiente() {
		return this->siguiente;
	}
	NodeMatriz *getAnterior() {
		return this->anterior;
	}
	NodeMatriz *getAdelante() {
		return this->adelante;
	}
	NodeMatriz *getAtras() {
		return this->atras;
	}
	N getData() {
		return this->data;
	}
	string getFila() {
		return this->fila;
	}
	string getColumna() {
		return this->columna;
	}
	void setArriba(NodeMatriz *n) {
		this->arriba = n;
	}
	void setAbajo(NodeMatriz *n) {
		this->abajo = n;
	}
	void setSiguiente(NodeMatriz *n) {
		this->siguiente = n;
	}
	void setAnterior(NodeMatriz *n) {
		this->anterior = n;
	}
	void setAdelante(NodeMatriz *n) {
		this->adelante = n;
	}
	void setAtras(NodeMatriz *n) {
		this->atras = n;
	}

private:
	N data;
	string fila;
	string columna;
	NodeMatriz *arriba;
	NodeMatriz *abajo;
	NodeMatriz *siguiente;
	NodeMatriz *anterior;
	NodeMatriz *adelante;
	NodeMatriz *atras;
};

template<class N>
class Matriz_Dispersa
{
public:
	Matriz_Dispersa<N>();
	bool Insertar_elemento(N data_, string fila_, string columna_);
	NodeMatriz<N> *Buscar_fila(string fila_);
	NodeMatriz<N> *Buscar_columna(string columna_);
	bool Insertar_en_fila(NodeMatriz<N> *cabecera, NodeMatriz<N> *nodo_nuevo_);
	bool Insertar_en_columna(NodeMatriz<N> *cabecera, NodeMatriz<N> *nodo_nuevo_);
	bool Insertar_Data_Atras(NodeMatriz<N> *nodo_inicial_, NodeMatriz<N> *data_);
	void graph();
private:
	NodeMatriz<N> *root;
};
