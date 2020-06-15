#include <iostream>
#include <cstring>
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

private:
	Node_Arbol<A> *root;
};