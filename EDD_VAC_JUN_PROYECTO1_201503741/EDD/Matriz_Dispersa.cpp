#include "Matriz_Dispersa.h"
#include "Usuario.h"

template<class N>
Matriz_Dispersa<N>::Matriz_Dispersa(N data_, string fila_, string columna_)
{
	this->root = new NodeMatriz<N>(data_, fila_, columna_);
}

template<class N>
void Matriz_Dispersa<N>::Insertar_elemento(N data_, string fila_, string columna_)
{
	//cramos el nodo nuevo
	NodeMatriz<N> *n = new NodeMatriz<N>(data_, fila_, columna_);
	
	//buscamos la fila 
	NodeMatriz<N> fila = Buscar_fila(fila_);
	//si la fila no existe la creamos
	if (fila ==0)
	{
		Usuario *n_fila = new Usuario("cabecera", fila_, fila_, fila_, fila_);
		fila = new NodeMatriz<N>(n_fila, fila_, "-1");
		//enlazamos la nueva fila con las demas
		Insertar_fila(fila);
	}
	
	//buscamos la columna
	NodeMatriz<N> columna = Buscar_columna(columna_);
	//si la columna no existe la creamos
	if (columna ==0)
	{
		Usuario *n_Columna = new Usuario("cabecera", columna_, columna_, columna_, columna_);
		columna = new NodeMatriz<N>(n_columna, "-1", columna_);
		//enlazamos la nueva columna con la demas
		Insertar_Columna(columna);
	}
	
	//enlazamos la fila y la columna con el nodo nuevo
	Insertar_Data(fila, columna, n);
	
}

template<class N>
NodeMatriz<N>* Matriz_Dispersa<N>::Buscar_fila(string fila_)
{
	NodeMatriz<N> *aux = this->root;
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

template<class N>
NodeMatriz<N>* Matriz_Dispersa<N>::Buscar_columna(string columna_)
{
	NodeMatriz<N> *aux = this->root;
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

template<class N>
void Matriz_Dispersa<N>::Insertar_fila(NodeMatriz<N>* fila_nueva_)
{
	NodeMatriz<N> *aux = this->root;
	while (aux->getAbajo() != 0) 
	{
		aux = aux->getAbajo();
	}
	aux->setAbajo(fila_nueva_);
	fila_nueva_->setArriba(aux);
}

template<class N>
void Matriz_Dispersa<N>::Insertar_Columna(NodeMatriz<N>* columna_nueva_)
{
	NodeMatriz<N> *aux = this->root;
	while (aux->getSiguiente() != 0) 
	{
		aux = aux->getSiguiente();
	}
	aux->setSiguiente(columna_nueva_);
	columna_nueva_->setAnterior(aux);
}

template<class N>
void Matriz_Dispersa<N>::Insertar_Data(NodeMatriz<N>* fila_, NodeMatriz<N>* columna_, NodeMatriz<N>* data_)
{
	NodeMatriz<N> *aux_fila = fila_;
	
	
	


	//buscamos la columna anterior de donde debe ser insertado el nodo
	NodeMatriz<N> *aux = this->root;
	bool encontrado = false;
	while (aux->getSiguiente() != 0 && !encontrado)
	{
		if (data_->getColumna() == aux->getSiguiente()->getColumna())//depto 3 == depto 3
		{
			//columna encontrada
			//movemos el nodo aux_fila a esa columna
			while (aux_fila->getSiguiente() != 0 && aux_fila->getColumna() != aux->getColumna())
			{
				aux_fila = aux_fila->getSiguiente();
			}
			encontrado = true;
		}
		else
		{
			aux = aux->getSiguiente();

		}
	}
	
	//buscamos la fila de arrbia donde debe de ser insertado el nodo
	aux = this->root;
	encontrado = false;
	while (aux->getAbajo() != 0 && !encontrado)
	{
		while (aux_columna->getAbajo()->getFila() != fila_->getFila())
		{
			aux_columna = aux_columna->getAbajo();
		}
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
		cout << "El usuario ha sido insertado" << endl;
	}
	else
	{
		Insertar_data_Atras(fila_->getSiguiente(), data_);
	}

}

template<class N>
void Matriz_Dispersa<N>::Insertar_Data_Atras(NodeMatriz<N> *nodo_inicial_, NodeMatriz<N> *data_)
{
	NodeMatriz<N> aux = nodo_inicial_;
	//vamos a recoorrer los enlazes hasta encontrar el ultimo nodo de atras
	while (aux->getAtras() != 0)
	{
		aux = aux->getAtras();
	}
	//enlazamos
	aux->setAtras(data_);
	data_->setAdelante(aux);
}
