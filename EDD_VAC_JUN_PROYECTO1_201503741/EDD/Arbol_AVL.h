#include <iostream>
#include <cstring>
using namespace std;

template<class A>
class Node_Arbol
{
public:
	Node_Arbol(A data_) {
		this->data = data_;
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
	void setLeft(Node_Arbol *n) {
		this->left = n;
	}
	void setRight(Node_Arbol *n) {
		this->right = n;
	}
private:
	A data;
	Node_Arbol *left;
	Node_Arbol *right;
};

template<class A>
class Arbol_AVL
{
public:
	Arbol_AVL<A>();
	

private:
	Node_Arbol<A> *root;
};