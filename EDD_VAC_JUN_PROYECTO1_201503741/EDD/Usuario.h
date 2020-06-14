#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

class Usuario
{
public:
	Usuario(string usuario_, string nombre_, string contrasenia_, string depto_, string empresa_) {
		this->usuario = usuario_;
		this->nombre = nombre_;
		this->contrasenia = contrasenia_;
		this->depto = depto_;
		this->empresa = empresa_;
	}
	//set and get
	string getUsuario() {
		return this->usuario;
	}
	string getNombre() {
		return this->nombre;
	}
	string getContrasenia() {
		return this->contrasenia;
	}
	string getEmpresa() {
		return this->empresa;
	}
	string getDepto() {
		return this->depto;
	}
	string getInfo() {
		string texto = this->usuario + "\\l"
			+ this->nombre + "\\l"
			+ this->contrasenia + "\\l";
		return texto;
	}
private:
	string usuario;
	string nombre;
	string contrasenia;
	string depto;
	string empresa;
	//arbol avl
};

#endif // !USUARIO_H

