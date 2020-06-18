#include <iostream>
#include <cstring>
#include <string>
//#include <fstream>
using namespace std;

template<class A>
class Node_Arbol
{
public:
	Node_Arbol(A data_) {
		this->data = data_;
		this->Altura = 0;
		this->Facetor_E = 0;
		this->left = 0;
		this->right = 0;
	}
	//setters and getters
	Node_Arbol *getLeft() {
		return this->left;
	}
	Node_Arbol *getRight() {
		return this->right;
	}
	A getData() {
		return this->data;
	}
	int getAltura() {
		return this->Altura;
	}
	int getFaceto_E() {
		return this->Facetor_E;
	}
	void setLeft(Node_Arbol *n) {
		this->left = n;
	}
	void setRight(Node_Arbol *n) {
		this->right = n;
	}
	void setAltura(int a) {
		this->Altura = a;
	}
	void setFactor_E(int f) {
		this->Facetor_E = f;
	}
	void setData(A data_) {
		this->data = data_;
	}
private:
	A data;
	int Altura;
	int Facetor_E;
	Node_Arbol *left;
	Node_Arbol *right;
};

template<class A>
class Arbol_AVL
{
public:
	Arbol_AVL<A>();
	void Insertar(A nuevo);
	Node_Arbol<A> *Insertar_P(Node_Arbol<A> *raiz, A nuevo);
	void Actualizar(Node_Arbol<A> *nodo);
	Node_Arbol<A> *Balancear(Node_Arbol<A> *nodo);
	Node_Arbol<A> *izqui_izqui(Node_Arbol<A> *nodo);
	Node_Arbol<A> *Rotar_Derec(Node_Arbol<A> *nodo);
	Node_Arbol<A> *izqui_derec(Node_Arbol<A> *nodo);
	Node_Arbol<A> *Rotar_Izqui(Node_Arbol<A> *nodo);
	Node_Arbol<A> *derec_derec(Node_Arbol<A> *nodo);
	Node_Arbol<A> *derec_izqui(Node_Arbol<A> *nodo);
	void Mostrar_Activos();
	void Mostrar_por_Nodo(Node_Arbol<A> *nodo);
	void Eliminar(string id_activo);
	Node_Arbol<A> *Eliminar_nodo(Node_Arbol<A> *nodo, string id_activo, bool eliminado);
	Node_Arbol<A> *getSucesorDerecha(Node_Arbol<A> *nodo);
	void Modificar_Activo(string id_ ,string descripcion_);
	Node_Arbol<A> *Modificar_nodo(Node_Arbol<A> *nodo, string id_, string descripcion_);
	void Graph_Por_Usuario(string usuario_);
	ofstream file;
	void Escribir_Encabezado(string usuario_);
	void Graficar_nodos(Node_Arbol<A> *raiz);
	void Enlazar_nodos(Node_Arbol<A> *raiz);
	void Escribir_final();
private:
	Node_Arbol<A> *root;
};