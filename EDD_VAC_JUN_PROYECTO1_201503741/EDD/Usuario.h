#ifndef USUARIO_H
#define USUARIO_H

#include "Arbol_AVL.cpp"
#include "Activo.h"

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
		this->ArbolAVL = new Arbol_AVL<Activo*>();
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
			+ this->contrasenia + "\\l"
			+ this->empresa + "\\l"
			+ this->depto + "\\l";
		return texto;
	}
	void Insertar_Activo(Activo * act) {
		this->ArbolAVL->Insertar(act);
	}
	void Mostrar_Activos() {
		this->ArbolAVL->Mostrar_Activos();
	}
	void Graficar_Arbol_por_Usuario(string usuario_) {
		this->ArbolAVL->Graph_Por_Usuario(usuario_);
	}
	void Eliminar_Activo(string id_activo) {
		this->ArbolAVL->Eliminar(id_activo);
	}
private:
	string usuario;
	string nombre;
	string contrasenia;
	string depto;
	string empresa;
	Arbol_AVL<Activo*> *ArbolAVL;
};

#endif // !USUARIO_H

