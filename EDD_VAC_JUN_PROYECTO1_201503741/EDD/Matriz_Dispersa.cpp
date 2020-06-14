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
	if (fila == 0)
	{
		Usuario *n_fila = new Usuario("cabecera", fila_, fila_, fila_, fila_);
		fila = new NodeMatriz<N>(n_fila, fila_, "-1");
		//enlazamos la nueva fila con las demas
		Insertar_en_fila(fila);
	}
	
	//buscamos la columna
	NodeMatriz<N> columna = Buscar_columna(columna_);
	//si la columna no existe la creamos
	if (columna ==0)
	{
		Usuario *n_Columna = new Usuario("cabecera", columna_, columna_, columna_, columna_);
		columna = new NodeMatriz<N>(n_columna, "-1", columna_);
		//enlazamos la nueva columna con la demas
		Insertar_en_columna(columna);
	}
	
	//enlazamos la fila y la columna con el nodo nuevo
	
	
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
void Matriz_Dispersa<N>::Insertar_en_fila(NodeMatriz<N> *cabecera, NodeMatriz<N>* nodo_nuevo_)
{
	while (cabecera->getAbajo() != 0) 
	{
		//encontrar el nodo arriba de donde debe ser insertado el nuevo nodo
		if (cabecera->getAbajo()->getFila() < nodo_nuevo_->getFila() )
		{
			cabecera = cabecera->getAbajo();
		}
		else
		{
			//se paso del nodo de arriba
			//subir una posicion y salir del ciclo
			cabecera = cabecera->getArriba();
			break;
		}
		
	}
	//pregunto si el nodo tiene otro nodo abajo o = 0
	if (cabecera->getAbajo() != 0)
	{
		//ya hay un nodo entonces hay que verificar que no tenga la misma columna y fila
		//si las tiene hay que enlazar hasta atras de ese nodo
		if (cabecera->getAbajo()->getFila == nodo_nuevo_->getFila() && cabecera->getAbajo()->getColumna() == nodo_nuevo_->getColumna())
		{
			//hay que insertar hasta atras de ese nodo
			bool insertado = Insertar_Data_Atras(cabecera->getAbajo(), nodo_nuevo_);
			if (insertado)
			{
				cout << "Usuario Insertado" << endl;
				system("pause");
			}
			else
			{
				cout << "Usuario Repetido intente con otro usuario" << endl;
				system("pause");
			}
		}
		//hay que enlazar el nodo de abajo de cabecera tambien 
		nodo_nuevo_->setAbajo(cabecera->getAbajo());
		cabecera->getAbajo()->setArriba(nodo_nuevo_);
		cabecera->setAbajo(nodo_nuevo_);
		nodo_nuevo_->setArriba(cabecera);
	}
	else
	{
		//el nodo es el ultimo de todos
		cabecera->setAbajo(nodo_nuevo_);
		nodo_nuevo_->setArriba(cabecera);
	}
}

template<class N>
void Matriz_Dispersa<N>::Insertar_en_columna(NodeMatriz<N> *cabecera, NodeMatriz<N> *columna_nueva_)
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
bool Matriz_Dispersa<N>::Insertar_Data_Atras(NodeMatriz<N> *nodo_inicial_, NodeMatriz<N> *data_)
{
	NodeMatriz<N> aux = nodo_inicial_;
	//vamos a recoorrer los enlazes hasta encontrar el ultimo nodo de atras
	while (aux->getAtras() != 0)
	{
		if (aux->getData()->getUsuario() == data_->getData()->getUsuario())
		{
			//no puede repetirse el nombre de usuario en la misma fila y columna
			return false;
		}
		aux = aux->getAtras();
	}
	//enlazamos
	aux->setAtras(data_);
	data_->setAdelante(aux);
	return true;
}
