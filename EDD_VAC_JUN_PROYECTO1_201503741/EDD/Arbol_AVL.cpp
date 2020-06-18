#include "Arbol_AVL.h"
#include <fstream>

template<class A>
inline Arbol_AVL<A>::Arbol_AVL()
{
	this->root = 0;
}
template<class A>
inline void Arbol_AVL<A>::Insertar(A nuevo)
{
	this->root = Insertar_P(this->root, nuevo);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::Insertar_P(Node_Arbol<A>* raiz, A nuevo)
{
	if (raiz == 0)
	{
		Node_Arbol<A> *n = new Node_Arbol<A>(nuevo);
		raiz = n;
		cout << "Activo Agregado" << endl;
		cout << n->getData()->getDatos() << endl;
		system("pause");
		return raiz;
	}
	else
	{
		if (raiz->getData()->getId() > nuevo->getId())
		{
			raiz->setLeft(Insertar_P(raiz->getLeft(), nuevo));
		}
		else
		{
			raiz->setRight(Insertar_P(raiz->getRight(), nuevo));
		}
	}
	Actualizar(raiz);
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
	if (Al_izquierda >= Al_derecha)
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
			return derec_derec(nodo);
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
	Node_Arbol<A> *N_derecha = nodo->getRight();
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

template<class A>
void Arbol_AVL<A>::Mostrar_Activos()
{
	Node_Arbol<A> *aux = this->root;
	Mostrar_por_Nodo(aux);
}

template<class A>
void Arbol_AVL<A>::Mostrar_por_Nodo(Node_Arbol<A>* nodo)
{
	if (nodo != 0)
	{
		Mostrar_por_Nodo(nodo->getLeft());
		//imprimir
		cout << nodo->getData()->getDatos() << endl;
		Mostrar_por_Nodo(nodo->getRight());
	}
}

template<class A>
void Arbol_AVL<A>::Eliminar(string id_activo)
{
	this->root = Eliminar_nodo(this->root, id_activo, true);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::Eliminar_nodo(Node_Arbol<A> *nodo, string id_activo, bool mostrar)
{
	if (nodo == 0)
	{
		return 0;
	}
	else if (id_activo < nodo->getData()->getId())
	{
		nodo->setLeft(Eliminar_nodo(nodo->getLeft(), id_activo, mostrar));
	}
	else if (id_activo > nodo->getData()->getId())
	{
		nodo->setRight(Eliminar_nodo(nodo->getRight(), id_activo, mostrar));
	}
	else
	{
		if (nodo->getLeft() == 0)
		{
			if (mostrar)
			{
				cout << "Activo Eliminado" << endl;
				cout << nodo->getData()->getDatos() << endl;
				system("pause");
			}
			return nodo->getRight();
		}
		else if (nodo->getRight() == 0)
		{
			if (mostrar)
			{
				cout << "Activo Eliminado" << endl;
				cout << nodo->getData()->getDatos() << endl;
				system("pause");
			}
			return nodo->getLeft();
		}
		else
		{
			Node_Arbol<A> *sucesor = getSucesorDerecha(nodo->getLeft());
			nodo->setData(sucesor->getData());
			//nodo = sucesor;
			//nodo->setRight(Eliminar_nodo(nodo->getRight(), id_activo));
			if (mostrar)
			{
				cout << "Activo Eliminado" << endl;
				cout << nodo->getData()->getDatos() << endl;
				system("pause");
			}
			nodo->setLeft(Eliminar_nodo(nodo->getLeft(), nodo->getData()->getId(), false));
		}
	}
	Actualizar(nodo);
	return Balancear(nodo);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::getSucesorDerecha(Node_Arbol<A>* nodo)
{
	while (nodo->getRight() != 0)
	{
		nodo = nodo->getRight();
	}
	return nodo;
}

template<class A>
void Arbol_AVL<A>::Modificar_Activo(string id_, string descripcion_)
{
	Node_Arbol<A> *aux = this->root;
	Modificar_nodo(aux, id_, descripcion_);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::Modificar_nodo(Node_Arbol<A>* nodo, string id_, string descripcion_)
{
	if (nodo != 0)
	{
		if (id_ < nodo->getData()->getId())
		{
			nodo->setLeft(Modificar_nodo(nodo->getLeft(), id_, descripcion_));
			return nodo;
		}
		else if (id_ > nodo->getData()->getId())
		{
			nodo->setRight(Modificar_nodo(nodo->getRight(), id_, descripcion_));
			return nodo;
		}
		else
		{
			//encontrado
			nodo->getData()->setDescripcion(descripcion_);
			cout << "Activo Modificado" << endl;
			cout << nodo->getData()->getDatos()<< endl;
			system("pause");
			return nodo;
		}
	}
	return 0;
}

template<class A>
void Arbol_AVL<A>::Mostrar_Activos_Disponibles()
{
	Node_Arbol<A> *aux = this->root;
	Mostrar_Nodo_Act_Disponibles(aux);
}

template<class A>
void Arbol_AVL<A>::Mostrar_Nodo_Act_Disponibles(Node_Arbol<A>* nodo)
{
	if (nodo != 0)
	{
		Mostrar_Nodo_Act_Disponibles(nodo->getLeft());
		//verificar si esta disponible el activo
		if (nodo->getData()->getDisponibilidad())
		{
			cout << nodo->getData()->getDatos() << endl;
		}
		//cout << nodo->getData()->getDatos() << endl;
		Mostrar_Nodo_Act_Disponibles(nodo->getRight());
	}
}

template<class A>
void Arbol_AVL<A>::Rentar_Activo(string id_)
{
	this->root = Rentar_Activo_P(this->root, id_);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::Rentar_Activo_P(Node_Arbol<A>* nodo, string id_)
{
	if (nodo != 0)
	{
		if (id_ < nodo->getData()->getId())
		{
			nodo->setLeft(Rentar_Activo_P(nodo->getLeft(), id_));
			return nodo;
		}
		else if (id_ > nodo->getData()->getId())
		{
			nodo->setRight(Rentar_Activo_P(nodo->getRight(), id_));
			return nodo;
		}
		else
		{
			//encontrado
			nodo->getData()->Rentar();
			cout << "Activo Rentado" << endl;
			cout << nodo->getData()->getDatos() << endl;
			system("pause");
			return nodo;
		}
	}
	return 0;
}

template<class A>
void Arbol_AVL<A>::Devolver_Activo(string id_)
{
	this->root = Devolver_Activo_P(this->root, id_);
}

template<class A>
Node_Arbol<A>* Arbol_AVL<A>::Devolver_Activo_P(Node_Arbol<A>* nodo, string id_)
{
	if (nodo != 0)
	{
		if (id_ < nodo->getData()->getId())
		{
			nodo->setLeft(Devolver_Activo_P(nodo->getLeft(), id_));
			return nodo;
		}
		else if (id_ > nodo->getData()->getId())
		{
			nodo->setRight(Devolver_Activo_P(nodo->getRight(), id_));
			return nodo;
		}
		else
		{
			//encontrado
			nodo->getData()->Devolver();
			cout << "Activo Devuelto:" << endl;
			cout << nodo->getData()->getDatos() << endl;
			system("pause");
			return nodo;
		}
	}
	return 0;
}

template<class A>
A Arbol_AVL<A>::Buscar_Activo(string id_)
{
	Node_Arbol<A> *aux = this->root;
	return Buscar_Act_P(aux, id_);
}

template<class A>
A Arbol_AVL<A>::Buscar_Act_P(Node_Arbol<A>* nodo, string id_)
{
	Node_Arbol<A> *actual = nodo;
	while (actual != 0)
	{
		if (id_ == actual->getData()->getId()) {
			//encontrado
			break;
		}
		else if (id_ < actual->getData()->getId())
		{
			actual = actual->getLeft();
		}
		else if (id_ > actual->getData()->getId())
		{
			actual = actual->getRight();
		}
	}
	return actual->getData();
}

template<class A>
void Arbol_AVL<A>::Mostrar_Activos_Rentados()
{
	Node_Arbol<A> *aux = this->root;
	Mostrar_Nodos_Activos_Rentados(aux);
}

template<class A>
void Arbol_AVL<A>::Mostrar_Nodos_Activos_Rentados(Node_Arbol<A>* nodo)
{
	if (nodo != 0)
	{
		Mostrar_Nodos_Activos_Rentados(nodo->getLeft());
		//verificar si esta disponible el activo
		if (!nodo->getData()->getDisponibilidad())
		{
			cout << nodo->getData()->getDatos() << endl;
		}
		//cout << nodo->getData()->getDatos() << endl;
		Mostrar_Nodos_Activos_Rentados(nodo->getRight());
	}
}

template<class A>
void Arbol_AVL<A>::Nombre_Activo(string id_Act)
{
	Node_Arbol<A> *actual = this->root;
	while (actual != 0)
	{
		if (id_Act == actual->getData()->getId()) {
			//encontrado
			cout << actual->getData()->getNombre();
		}
		else if (id_Act < actual->getData()->getId())
		{
			actual = actual->getLeft();
		}
		else if (id_Act > actual->getData()->getId())
		{
			actual = actual->getRight();
		}
	}
}

template<class A>
void Arbol_AVL<A>::Graph_Por_Usuario(string usuario_)
{
	Node_Arbol<A> *aux = this->root;
	char com = '"';
	this->file.open("C:\\Users\\EDDY\\Desktop\\Arbol_por_Usuario.txt");
	Escribir_Encabezado(usuario_);
	Graficar_nodos(aux);
	this->file << com << usuario_ << com << "->" << com << this->root->getData() << com << "\n";
	aux = this->root;
	Enlazar_nodos(aux);
	Escribir_final();
}

template<class A>
void Arbol_AVL<A>::Escribir_Encabezado(string usuario_)
{
	char com = '"';
	this->file << "digraph G { \n";
	this->file << "node[shape=box, color=red] \n";
	this->file << com << usuario_ << com << "[label=" << usuario_ << "]" << "\n";
	this->file << "node[shape=oval] \n";
}

template<class A>
void Arbol_AVL<A>::Graficar_nodos(Node_Arbol<A>* raiz)
{
	if (raiz != 0)
	{
		char com = '"';
		this->file << com << raiz->getData() << com << "[label=" <<raiz->getData()->getInfo()<< "\n";
		Graficar_nodos(raiz->getLeft());
		Graficar_nodos(raiz->getRight());
	}
}

template<class A>
void Arbol_AVL<A>::Enlazar_nodos(Node_Arbol<A>* raiz)
{
	if (raiz != 0)
	{
		char com = '"';
		if (raiz->getLeft() != 0)
		{
			this->file << com << raiz->getData() << com << "->" << com << raiz->getLeft()->getData() << com << "\n";
		}
		if (raiz->getRight() != 0)
		{
			this->file << com << raiz->getData() << com << "->" << com << raiz->getRight()->getData() << com << "\n";
		}
		Enlazar_nodos(raiz->getLeft());
		Enlazar_nodos(raiz->getRight());
	}
}

template<class A>
void Arbol_AVL<A>::Escribir_final()
{
	this->file << "}";
	this->file.close();

	system("C:\\release\\bin\\dot.exe -Tpng C:\\Users\\EDDY\\Desktop\\Arbol_por_Usuario.txt -o C:\\Users\\EDDY\\Desktop\\Grafica_Arbol_por_Usuario.png");
	system("C:\\Users\\EDDY\\Desktop\\Grafica_Arbol_por_Usuario.png");
}
