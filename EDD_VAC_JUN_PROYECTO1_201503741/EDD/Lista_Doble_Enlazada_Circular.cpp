#include "Lista_Doble_Enlazada_Circular.h"

template<class T>
inline Lista_Doble_Enlazada_Circular<T>::Lista_Doble_Enlazada_Circular()
{
	this->first = 0;
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
	Node *n = new Node(data_);
	if (isEmpty())
	{
		this->first = n;
		this->first->setBefore(this->last);
		this->last->setNext(this->first);
		this->size++;
	}
	else
	{
		n->setNext(this->first);
		this->first->setBefore(n);
		this->first = n;
		this->last->setNext(this->first);
		this->first->setBefore(this->last);
		this->size++;
	}
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::add_last(T data_)
{
	Node *n = new Node(data_)
	if (isEmpty())
	{
		add_firts();
	}
	else
	{
		n->setBefore(this->last);
		this->last->setNext(n);
		this->last = n;
		this->last->setNext(this->firts);
		this->firts->setBefore(this->last);
		this->size++;
	}
}

template<class T>
void Lista_Doble_Enlazada_Circular<T>::eliminiar(String id_)
{
	Node *aux = this->first;
	for (int i = 0; i < this->size; i++)
	{
		if (id_ == aux->getData())
		{
			if (i ==0)
			{
				this->first = aux->getNext();
				this->last->setNext(this->first);
				this->first->setBefore(this->last);
				this->size--;
				cout << "Eliminado: " << aux->getData();
				delete aux;
				break;
			}
			else if (i == this->size - 1)
			{
				this->last = aux->getBefore();
				this->first->setBefore(this->last);
				this->last->setNext(this->first);
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
void Lista_Doble_Enlazada_Circular<T>::graph()
{
	Node *aux = this->firts;
	ofstream file;
	char comillas = '"';
	file.open("C:\\Users\\EDDY\\Desktop\\Lista_Enlazada_Circular.txt");
	file << "digraph G { \n";
	file << "rankdir = LR \n";
	file << "node[shape = box] \n";
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
