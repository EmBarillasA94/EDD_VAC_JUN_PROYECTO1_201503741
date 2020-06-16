#include "Arbol_AVL.h"

template<class A>
inline Arbol_AVL<A>::Arbol_AVL()
{
	this->root = 0;
}
template<class A>
inline void Arbol_AVL<A>::Insertar(A nuevo)
{
	this->root;
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::Insertar_P(Node_Arbol<A>* raiz, A nuevo)
{
	if (raiz != 0)
	{
		Node_Arbol<A> *n = new Node_Arbol<A>(nuevo);
		raiz = n;
		return raiz;
	}
	else
	{
		if (raiz->getData()->getId() < nuevo->getId())
		{
			raiz->setLeft(Insertar_P(raiz->getLeft(), nuevo));
		}
		else
		{
			raiz->setRight(Insertar_P(raiz->getRight(), nuevo));
		}
	}
	Acturalizar(raiz);

	return 0;
}
