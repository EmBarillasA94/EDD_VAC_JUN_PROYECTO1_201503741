#include <iostream>
#include <algorithm>
using namespace std;

class Activo
{
public:
	Activo(string id_, string nombre_, string descripcion_) {
		this->id = id_;
		this->nombre = nombre_;
		this->descripcion = descripcion_;
	}
	string getId() {
		return id;
	}
	void setNombre(string nombre_) {
		this->nombre = nombre_;
	}
	void setDescripcioin(string descripcion_) {
		this->descripcion = descripcion_;
	}
private:
	string id;
	string nombre;
	string descripcion;
};
