#include "Matriz_Dispersa.h"
#include "Usuario.h"

template<class T>
Matriz_Dispersa<T>::Matriz_Dispersa(T data_, string fila_, string columna_)
{
	this->root = new Node<T>(data_, fila_, columna_);
}

template<class T>
void Matriz_Dispersa<T>::Insertar_elemento(T data_, string fila_, string columna_)
{
	Node<T> *n = new Node<T>(data_, fila_, columna_);
	Node<T> fila = Buscar_fila(fila_);
	Node<T> columna = Buscar_columna(columna_);
	//Evaluar condiciones
	if (fila == 0 && columna == 0)//si la fila y la columna no existen
	{
		//crear la fila y columna
		Usuario *n_fila = new Usuario(fila_, fila_, fila_, fila_, fila_);
		fila = new Node<T>(n_fila, fila_, "-1");
		Usuario *n_Columna = new Usuario(columna_, columna_, columna_, columna_, columan_);
		columna = new Node<T>(n_columna, "-1", columna_);
		//enlazar la fila nueva y la columna nueva
		Insertar_fila(fila);
		Insertar_Columna(columna);

	}
	else if (fila != 0 && columna == 0)//si la fila si existe pero la columna no existe
	{

	}
	else if (fila == 0 && columna !=0)// si la fila no existe pero la columna si existe
	{

	}
	else if (fila != 0 && columna != 0)// si la fila y la columna existen
	{

	}
}

template<class T>
Node<T>* Matriz_Dispersa<T>::Buscar_fila(string fila_)
{
	Node<T> *aux = this->root;
	while (aux != 0)
	{
		if (aux->getFila() == fila_)
		{
			return aux;
		}
		aux = aux->getAbajo();
	}
	return 0;
}

template<class T>
Node<T>* Matriz_Dispersa<T>::Buscar_columna(string columna_)
{
	Node<T> *aux = this->root;
	while (aux !=0)
	{
		if (aux->getColumna() == columna_)
		{
			return aux;
		}
		aux = aux->getSiguiente();
	}
	return 0;
}

template<class T>
void Matriz_Dispersa<T>::Insertar_fila(Node<T>* fila_nueva_)
{
	Node<T> *aux = this->root;
	while (aux->getAbajo() != 0) 
	{
		aux = aux->getAbajo();
	}
	aux->setAbajo(fila_nueva_);
	fila_nueva_->setArriba(aux);
}

template<class T>
void Matriz_Dispersa<T>::Insertar_Columna(Node<T>* columna_nueva_)
{
	Node<T> *aux = this->root;
	while (aux->getSiguiente() != 0) 
	{
		aux = aux->getSiguiente();
	}
	aux->setSiguiente(columna_nueva_);
	columna_nueva_->setAnterior(aux);
}

template<class T>
void Matriz_Dispersa<T>::Insertar_Data(Node<T>* fila_, Node<T>* columna_, Node<T>* data_)
{
	Node<T> *aux_fila = fila_;
	Node<T> *aux_columna = columna_;
	//buscamos el nodo de lado izquierdo de donde se debe insertar el nodo data
	while (aux_fila->getSiguiente()->getColumna() != columna_->getColumna())
	{
		aux_fila = aux_fila->getSiguiente();
	}
	//buscamos el nodo de arriba de donde se debe insertar el nodo data
	while (aux_columna->getAbajo()->getFila() != fila_->getFila())
	{
		aux_columna = aux_columna->getAbajo();
	}
	//ya obtenidos los nodos debemos verificar si ya hay un nodo insertado
	//si no hay nodo insertado unimos los enlazes
	//si ya hay un nodo debemos insertarlo hacia atras
	if (aux_fila->getSiguiente() == 0 && aux_columna->getAbajo() == 0)
	{
		//esta vacio
		aux_columna->setAbajo(data_);
		aux_fila->setSiguiente(data_);
		data_->setArriba(aux_columna);
		data_->setAnterior(aux_fila);
	}
	else
	{
		Insertar_data_Atras(fila_->getSiguiente());
	}

}

template<class T>
void Matriz_Dispersa<T>::Insertar_Data_Atras(Node<T> *nodo_inicial_, Node<T> *data_)
{
	Node<T> aux = nodo_inicial_;
	//vamos a recoorrer los enlazes hasta encontrar el ultimo nodo de atras
	while (aux->getAtras() != 0)
	{
		aux = aux->getAtras();
	}
	//enlazamos
	aux->setAtras(data_);
	data_->setAdelante(aux);
}
