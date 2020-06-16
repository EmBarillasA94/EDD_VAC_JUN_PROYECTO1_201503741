#include <iostream>
#include <algorithm>
using namespace std;

class Activo
{
public:
	Activo(string nombre_, string descripcion_) {
		this->id = GenerarId(15);
		this->nombre = nombre_;
		this->descripcion = descripcion_;
	}
	string GenerarId(int tamanio);
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

string Activo::GenerarId(int tamanio)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	string id(tamanio, 0);
	std::generate_n(id.begin(), tamanio, randchar);
	return id;
}
