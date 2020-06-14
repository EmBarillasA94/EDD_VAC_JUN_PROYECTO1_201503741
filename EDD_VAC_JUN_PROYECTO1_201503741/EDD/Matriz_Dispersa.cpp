#include "Matriz_Dispersa.h"
#include "Usuario.h"
#include <fstream>

template<class N>
inline Matriz_Dispersa<N>::Matriz_Dispersa()
{
	Usuario *u = new Usuario("root", "root", "root", "-1", "-1");
	this->root = new NodeMatriz<N>(u, u->getEmpresa(), u->getDepto());
}

template<class N>
bool Matriz_Dispersa<N>::Insertar_elemento(N data_, string fila_, string columna_)
{
	//cramos el nodo nuevo
	NodeMatriz<N> *n = new NodeMatriz<N>(data_, fila_, columna_);
	
	//buscamos la fila 
	NodeMatriz<N> *fila = Buscar_fila(fila_);
	//si la fila no existe la creamos
	if (fila == 0)
	{
		Usuario *n_fila = new Usuario("cabecera", fila_, fila_, fila_, fila_);
		fila = new NodeMatriz<N>(n_fila, fila_, "-1");
		//enlazamos la nueva fila con las demas
		NodeMatriz<N> * aux = this->root;
		Insertar_en_fila(aux, fila);
	}
	
	//buscamos la columna
	NodeMatriz<N> *columna = Buscar_columna(columna_);
	//si la columna no existe la creamos
	if (columna ==0)
	{
		Usuario *n_columna = new Usuario("cabecera", columna_, columna_, columna_, columna_);
		columna = new NodeMatriz<N>(n_columna, "-1", columna_);
		//enlazamos la nueva columna con la demas
		NodeMatriz<N> * aux = this->root;
		Insertar_en_columna(aux, columna);
	}
	
	//insertar el nodo en la columna correspondiente
	bool insertando_columna = Insertar_en_fila(columna, n);
	//insertar el nodo en la fila correspondiente
	bool insertando_fila = Insertar_en_columna(fila, n);
	
	return insertando_columna && insertando_fila;
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
bool Matriz_Dispersa<N>::Insertar_en_fila(NodeMatriz<N> *cabecera, NodeMatriz<N> *nodo_nuevo_)
{
	while (cabecera->getAbajo() != 0) 
	{
		//encontrar el nodo arriba de donde debe ser insertado el nuevo nodo
		//si verificamos el nodo de abajo y resulta ser de la misma fila hay
		//que verificar que no sea de la misma columna 
		if (cabecera->getAbajo()->getFila() == nodo_nuevo_->getFila())
		{
			if (cabecera->getAbajo()->getColumna() == nodo_nuevo_->getColumna())
			{
				//si es de la misma fila y columna pero el usuario es el mismo NO insertamos 
				if (cabecera->getAbajo()->getData()->getUsuario() != nodo_nuevo_->getData()->getUsuario())
				{
					return Insertar_Data_Atras(cabecera->getAbajo(), nodo_nuevo_);
				}
				else
				{
					return false;
				}
			}
			break;
		}
		else if (cabecera->getAbajo()->getFila() < nodo_nuevo_->getFila() )
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
		//hay que enlazar el nodo de abajo de cabecera tambien 
		nodo_nuevo_->setAbajo(cabecera->getAbajo());
		cabecera->getAbajo()->setArriba(nodo_nuevo_);
		cabecera->setAbajo(nodo_nuevo_);
		nodo_nuevo_->setArriba(cabecera);
		return true;
	}
	else
	{
		//el nodo es el ultimo de todos
		cabecera->setAbajo(nodo_nuevo_);
		nodo_nuevo_->setArriba(cabecera);
		return true;
	}
}

template<class N>
bool Matriz_Dispersa<N>::Insertar_en_columna(NodeMatriz<N> *cabecera, NodeMatriz<N> *nodo_nuevo_)
{
	while (cabecera->getSiguiente() != 0)
	{
		//encontrar el nodo anterior de donde debe ser insertado el nuevo nodo
		//verificamos que el nodo siguiente sea igual al nodo que estamos buscando
		if (cabecera->getSiguiente()->getColumna() == nodo_nuevo_->getColumna())
		{
			//ya no evaluo si es la misma fila y columna por que eso se evaluo en 
			//insertar_en_fila
			break;
		}
		if (cabecera->getSiguiente()->getColumna() < nodo_nuevo_->getColumna())
		{
			cabecera = cabecera->getSiguiente();
		}
		else
		{
			//se paso del nodo anterior
			//regresar una posicion y salir del ciclo
			cabecera = cabecera->getAnterior();
			break;
		}
	}
	//pregunto si el nodo tiene otro nodo siguiente o = 0
	if (cabecera->getSiguiente() != 0)
	{
		//pregunto si el nodo siguiente es de la misma fila y columna 
		if (cabecera->getSiguiente()->getFila() == nodo_nuevo_->getFila() && cabecera->getSiguiente()->getColumna() == nodo_nuevo_->getColumna())
		{
			//si son iguales ya no llamo a la funcion Insertar_Data_Atras 
			//por eso ya lo inserto en el Insertar_en_Fila
			return true;
		}
		//hay que enlazar el nodo siguiente de la cabecera tambien 
		nodo_nuevo_->setSiguiente(cabecera->getSiguiente());
		cabecera->getSiguiente()->setAnterior(nodo_nuevo_);
		cabecera->setSiguiente(nodo_nuevo_);
		nodo_nuevo_->setAnterior(cabecera);
		return true;
	}
	else
	{
		//el nodo es el ultimo de todos
		cabecera->setSiguiente(nodo_nuevo_);
		nodo_nuevo_->setAnterior(cabecera);
		return true;
	}
}

template<class N>
bool Matriz_Dispersa<N>::Insertar_Data_Atras(NodeMatriz<N> *nodo_inicial_, NodeMatriz<N> *data_)
{
	NodeMatriz<N> *aux = nodo_inicial_;
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

template<class N>
void Matriz_Dispersa<N>::graph()
{
	NodeMatriz<N> *auxC = this->root;
	NodeMatriz<N> *auxF = this->root;
	char comillas = '"';
	ofstream file;
	file.open("C:\\Users\\EDDY\\Desktop\\Matriz.txt");
	file << "digraph G { \n";
	//file << "node[shape = box] \n";
	file << "graph[nodesep = 1.0] \n";

	//file << "rankdir=LR \n";
	//filas
	int grupo = 0;
	while (auxF != 0)
	{

		while (auxC != 0)
		{
			if (auxC->getData()->getUsuario() == "cabecera" || auxC->getData()->getUsuario() == "root")
			{
				file << comillas << auxC->getData() << comillas << "[ shape = rectangle, label = " << comillas << auxC->getData()->getNombre() << comillas << ", group = " << grupo << " ]; \n";
				auxC = auxC->getSiguiente();
			}
			else
			{
				file << comillas << auxC->getData() << comillas << "[ shape = rectangle, label = " << comillas << auxC->getData()->getInfo() << comillas << ", group = " << grupo << " ]; \n";
				auxC = auxC->getSiguiente();
			}
			NodeMatriz<N> *auxZ = auxC;
			while (auxZ != 0)
			{
				auxZ = auxZ->getAtras();
				file << comillas << auxZ->getData() << comillas << "[ shape = rectangle, label = " << comillas << auxZ->getData()->getInfo() << comillas << ", group = " << grupo << " ]; \n";
			}
			
		}
		grupo++;

		auxC = auxF;
		auxC = auxC->getAbajo();
		auxF = auxF->getAbajo();

	}

	auxC = this->root;
	auxF = this->root;


	while (auxF != 0)
	{
		//recorro una fila

		while (auxC != 0)
		{
			file << comillas << auxC->getData() << comillas;
			auxC = auxC->getSiguiente();
			if (auxC != 0)
			{
				file << " -> ";
			}
		}
		auxC = auxF;
		if (auxC->getColumna() == "-1") {
			file << "[dir=both]; \n";
			//file << "; \n";
		}
		else {

			//file << "[constraint = same, dir=both]; \n";
		}
		/*grupo++;*/
		file << "{rank=same ";
		auxC = auxF;
		while (auxC != 0)
		{
			file << comillas << auxC->getData() << comillas;
			auxC = auxC->getSiguiente();
			if (auxC != 0)
			{
				file << " ";
			}

		}
		file << "} \n \n";
		//cambio a auxF al siguiente de abajo
		auxC = auxF;
		auxC = auxC->getAbajo();
		auxF = auxF->getAbajo();
	}

	//columnas
	//file << "rankdir= TB \n";
	auxC = this->root;
	auxF = this->root;
	while (auxC != 0)
	{
		//recorro filas
		while (auxF != 0)
		{
			file << comillas << auxF->getData() << comillas;
			auxF = auxF->getAbajo();
			if (auxF != 0)
			{
				file << " -> ";
			}

		}
		file << "[dir=both]; \n \n";

		////cod
		//file << "{rank=same ";
		//auxF = auxC;
		//while (auxF != 0)
		//{
		//	file << comillas << auxF->getData() << comillas;
		//	auxF = auxF->getAbajo();
		//	if (auxF != 0)
		//	{
		//		file << " ";
		//	}

		//}
		//file << "} \n \n";
		//cod

		auxC = auxC->getSiguiente();
		auxF = auxC;
	}

	file << "}";
	file.close();

	system("C:\\release\\bin\\dot.exe -Tpng C:\\Users\\EDDY\\Desktop\\Matriz.txt -o C:\\Users\\EDDY\\Desktop\\Grafica_Matriz.png");
	system("C:\\Users\\EDDY\\Desktop\\Grafica_Matriz.png");
}
