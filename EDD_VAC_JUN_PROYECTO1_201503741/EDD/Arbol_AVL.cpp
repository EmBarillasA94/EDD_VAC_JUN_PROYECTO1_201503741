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
	return Balancear(raiz);
}

template<class A>
void Arbol_AVL<A>::Actualizar(Node_Arbol<A>* nodo)
{
	int Al_izquierda;
	int Al_derecha;
	//evaluo si tiene un hijo izquiredo y almaceno la altura
	//si es nulo almaceno -1
	if (nodo->getLeft() == 0)
	{
		Al_izquierda = -1;
	}
	else
	{
		Al_izquierda = nodo->getLeft()->getAltura();
	}

	//evaluo si tiene un hijo derecho y almaceno la altura
	//si es nulo almaceno -1
	if (nodo->getRight() == 0)
	{
		Al_derecha = -1;
	}
	else
	{
		Al_derecha = nodo->getRight()->getAltura();
	}

	//evaluo cual de las 2 alturas es mayor y envio esa altura al nodo
	if (Al_izquierda <= Al_derecha)
	{
		nodo->setAltura(1 + Al_izquierda);
	}
	else
	{
		nodo->setAltura(1 + Al_derecha);
	}

	//le envio el factor de equiilibrio 
	nodo->setFactor_E(Al_derecha - Al_izquierda);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::Balancear(Node_Arbol<A>* nodo)
{
	//para que sea necesario balancear el nodo debe tener 
	//como factor de equivlibrio -2 o 2
	//de lo contrario no es necesario balancear
	if (nodo->getFaceto_E() == -2)//si es -2 significa que el nodo de la izquierda tiene mas altura
	{
		if (nodo->getLeft()->getFaceto_E() <= 0)
		{
			return izqui_izqui(nodo);
		}
		else
		{
			return izqui_derec(nodo);
		}
	}
	else if (nodo->getFaceto_E() == 2)// si es 2 el nodo de la derecha tiene mas altura
	{
		if (nodo->getRight()->getFaceto_E() >=0)
		{
			return derec_derec_(nodo);
		}
		else
		{
			return derec_izqui(nodo);
		}
	}
	return nodo;
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::izqui_izqui(Node_Arbol<A>* nodo)
{
	return Rotar_Derec(nodo);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::Rotar_Derec(Node_Arbol<A>* nodo)
{
	Node_Arbol<A> *N_Izquierda = nodo->getLeft();
	nodo->setLeft(N_Izquierda->getRight());
	N_Izquierda->setRight(nodo);
	Actualizar(nodo);
	Actualizar(N_Izquierda);
	return N_Izquierda;
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::izqui_derec(Node_Arbol<A>* nodo)
{
	nodo->setLeft(Rotar_Izqui(nodo->getLeft()));
	return izqui_izqui(nodo);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::Rotar_Izqui(Node_Arbol<A>* nodo)
{
	Node_Arbol<A> N_derecha = nodo->getRight();
	nodo->setRight(N_derecha->getLeft());
	N_derecha->setLeft(nodo);
	Actualizar(nodo);
	Actualizar(N_derecha);
	return N_derecha;
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::derec_derec(Node_Arbol<A>* nodo)
{
	return Rotar_Izqui(nodo);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::derec_izqui(Node_Arbol<A>* nodo)
{
	nodo->setRight(Rotar_Derec(nodo->getRight()));
	return derec_derec(nodo);
}
