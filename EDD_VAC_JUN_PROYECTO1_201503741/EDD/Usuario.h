#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

class Usuario
{
public:
	Usuario(string usuario_, string nombre_, string contrasenia_) {
		this->usuario = usuario_;
		this->nombre = nombre_;
		this->contrasenia = contrasenia_;
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

private:
	string usuario;
	string nombre;
	string contrasenia;
	//arbol avl
};

#endif // !USUARIO_H

