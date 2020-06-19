#include "Lista_Doble_Enlazada_Circular.h"
#include <fstream>

template<class T>
inline Lista_Doble_Enlazada_Circular<T>::Lista_Doble_Enlazada_Circular()
{
	this->firts = 0;
	this->last = 0;
	this->size = 0;
}

template<class T>
inline bool Lista_Doble_Enlazada_Circular<T>::isEmpty()
{
	return this->size == 0;
}

template<class T>
int Lista_Doble_Enlazada_Circular<T>::getSize()
{
	return this->size;
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::add_firts(T data_)
{
	Node<T> *n = new Node<T>(data_);
	if (isEmpty())
	{
		this->firts = n;
		this->last = n;
		this->firts->setBefore(this->last);
		this->last->setNext(this->firts);
		this->size++;
	}
	else
	{
		n->setNext(this->firts);
		this->firts->setBefore(n);
		this->firts = n;
		this->last->setNext(this->firts);
		this->firts->setBefore(this->last);
		this->size++;
	}
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::add_last(T data_)
{
	if (isEmpty())
	{
		add_firts(data_);
	}
	else
	{
		Node<T> *n = new Node<T>(data_);
		n->setBefore(this->last);
		this->last->setNext(n);
		this->last = n;
		this->last->setNext(this->firts);
		this->firts->setBefore(this->last);
		this->size++;
	}
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::eliminiar(string id_)
{
	Node<T> *aux = this->firts;
	for (int i = 0; i < this->size; i++)
	{
		if (id_ == aux->getData())
		{
			if (i ==0)
			{
				this->firts = aux->getNext();
				this->last->setNext(this->firts);
				this->firts->setBefore(this->last);
				this->size--;
				cout << "Eliminado: " << aux->getData();
				delete aux;
				break;
			}
			else if (i == this->size - 1)
			{
				this->last = aux->getBefore();
				this->firts->setBefore(this->last);
				this->last->setNext(this->firts);
				this->size--;
				cout << "Eliminado " << aux->getData();
				delete aux;
				break;
			}
			else
			{
				aux->getBefore()->setNext(aux->getNext());
				aux->getNext()->setBefore(aux->getBefore);
				this->size--;
				cout << "Eliminado: " << aux->getData();
				delete aux;
				break;
			}
		}
		aux = aux->getNext();
	}
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::Mostrar_Transacciones_de_Usuario(string usuario_)
{
	Node<T> *aux = this->firts;
	for (int i = 0; i < this->size; i++)
	{
		if (aux->getData()->getUsuario() == usuario_ && !aux->getData()->getEstado_Devolucion())
		{
			//imprimir en consola la transaccion
			cout << aux->getData()->getDatos_Transaccion() << endl;
		}
		aux = aux->getNext();
	}
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::Registrar_Devolucion(string id_Activo, string usuario)
{
	Node<T> *aux = this->firts;
	for (int i = 0; i < this->size; i++)
	{
		if (aux->getData()->getId_Activo() == id_Activo && aux->getData()->getUsuario() == usuario && !aux->getData()->getEstado_Devolucion())
		{
			aux->getData()->Devolver_Activo();
		}
		aux = aux->getNext();
	}
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::graph()
{
	Node<T> *aux = this->firts;
	ofstream file;
	char comillas = '"';
	file.open("C:\\Users\\EDDY\\Desktop\\Lista_Enlazada_Circular.txt");
	file << "digraph G { \n";
	file << "rankdir = LR \n";
	file << "node[shape = box] \n";

	for (int i = 0; i < this->size; i++)
	{
		if (aux->getData()->getEstado_Devolucion())
		{
			file << comillas << aux->getData() << comillas << "[label=" << comillas << aux->getData()->getInfo() << comillas << ", color=green]" << endl;
		}
		else
		{
			file << comillas << aux->getData() << comillas << "[label=" << comillas << aux->getData()->getInfo() << comillas << ", color=red]" << endl;
		}
		aux = aux->getNext();
	}
	aux = this->firts;
	for (int i = 0; i < this->size; i++)
	{
		file << comillas << aux->getData() << comillas << " -> " << comillas << aux->getNext()->getData() << comillas << "\n";
		file << comillas << aux->getNext()->getData() << comillas << " -> " << comillas << aux->getData() << comillas << "\n";
		aux = aux->getNext();
	}
	file << "}";
	file.close();

	system("C:\\release\\bin\\dot.exe -Tpng C:\\Users\\EDDY\\Desktop\\Lista_Enlazada_Circular.txt -o C:\\Users\\EDDY\\Desktop\\Grafica_Lista_Enlazada_Circular.png");
	system("C:\\Users\\EDDY\\Desktop\\Grafica_Lista_Enlazada_Circular.png");
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::graph_por_Usuario(string usuario_, string empresa_, string depto_)
{
	Node<T> *aux = this->firts;
	ofstream file;
	char comillas = '"';
	file.open("C:\\Users\\EDDY\\Desktop\\Lista_Enlazada_Circular_por_Usuario.txt");
	file << "digraph G { \n";
	file << "rankdir = LR \n";
	file << "node[shape = box] \n";
	bool bandera = false;
	for (int i = 0; i < this->size; i++)
	{
		if (aux->getData()->getUsuario() == usuario_ && aux->getData()->getEmpresa() == empresa_ && aux->getData()->getDepto() == depto_)
		{
			if (aux->getData()->getEstado_Devolucion())
			{
				file << comillas << aux->getData() << comillas << "[label=" << comillas << aux->getData()->getInfo() << comillas << ", color=green]" << endl;
			}
			else
			{
				file << comillas << aux->getData() << comillas << "[label=" << comillas << aux->getData()->getInfo() << comillas << ", color=red]" << endl;
			}
		}
		aux = aux->getNext();
	}
	aux = this->firts;
	for (int i = 0; i < this->size; i++)
	{
		if (aux->getData()->getUsuario() == usuario_ && aux->getData()->getEmpresa() == empresa_ && aux->getData()->getDepto() == depto_)
		{
			if (bandera)
			{
				file << "->";
			}
			file << comillas << aux->getData() << comillas;
			bandera = true;
		}
		aux = aux->getNext();
	}
	file << "\n";
	file << "}";
	file.close();

	system("C:\\release\\bin\\dot.exe -Tpng C:\\Users\\EDDY\\Desktop\\Lista_Enlazada_Circular_por_Usuario.txt -o C:\\Users\\EDDY\\Desktop\\Grafica_Lista_Enlazada_Circular_por_Usuario.png");
	system("C:\\Users\\EDDY\\Desktop\\Grafica_Lista_Enlazada_Circular_por_Usuario.png");
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::OrdenarAscendente()
{
	Node<T> *P = this->firts;
	Node<T> *aux = 0;
	T Tran;
	for (int i = 1; i < this->size; i++)//1
	{
		aux = P->getNext();
		for (int j = 1; j < this->size; j++)//5-1=4    j=0
		{
			if (P->getData()->getId_Transaccion() > aux->getData()->getId_Transaccion())
			{
				Tran = aux->getData();
				aux->setData(P->getData());
				P->setData(Tran);
			}
			if (aux != this->last)
			{
				aux = aux->getNext();
			}
		}
		P = P->getNext();
	}
	graph();
}
