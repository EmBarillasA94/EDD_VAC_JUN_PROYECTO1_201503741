

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

	Node *getBefore() {
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
	T data = 0;
	Node *next = 0;
	Node *before = 0;
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
	void eliminiar(string id_);
	void Mostrar_Transacciones_de_Usuario(string usuario_);
	void Registrar_Devolucion(string id_Activo, string usuario);
	void graph();
	void graph_por_Usuario(string usuario_, string empresa_, string depto_);

private:
	Node<T> *firts;
	Node<T> *last;
	int size;
};
