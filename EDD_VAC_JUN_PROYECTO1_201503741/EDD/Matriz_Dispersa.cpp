#include "Matriz_Dispersa.h"

template<class T>
inline Matriz_Dispersa<T>::Matriz_Dispersa()
{
	this->root = new Node_Cabecera<T>("root");
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
