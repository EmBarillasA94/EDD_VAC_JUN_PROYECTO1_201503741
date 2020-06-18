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
		this->disponible = true;
	}
	string getId() {
		return id;
	}
	string getDatos() {
		string text = this->id + " " + this->nombre + " " + this->descripcion;
		return text;
	}
	string getInfo() {
		string texto = '"'+ this->id + "\\l"
			+ this->nombre + "\\l";

		if (this->disponible)
		{
			texto = texto + "Disponible \\l"+'"'+", color=back] \n";
			return texto;
		}
		else
		{
			texto = texto + "No Disponible \\l" + '"' + ", color=yellow]";
			return texto;
		}
	}
	void setNombre(string nombre_) {
		this->nombre = nombre_;
	}
	void setDescripcioin(string descripcion_) {
		this->descripcion = descripcion_;
	}
	void Rentar() {
		this->disponible = false;
	}
	void Devolver() {
		this->disponible = true;
	}
private:
	string id;
	string nombre;
	string descripcion;
	bool disponible;
};
