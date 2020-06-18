#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <iostream>
#include <algorithm>
using namespace std;

class Transaccion
{
public:
	Transaccion(string id_Transaccion_, string id_Activo_, string usuario_, string depto_, string empresa_, string fecha_, string tiempo_) {
		this->id_Transaccion = id_Transaccion_;
		this->id_Activo = id_Activo_;
		this->usuario = usuario_;
		this->depto = depto_;
		this->empresa = empresa_;
		this->fecha = fecha_;
		this->tiempo = tiempo_;
	}
	
	//getters and setters 
	string getInfo() {
		string texto = "Id Transaccion: "+this->id_Transaccion + "\\l" 
			+ "Id Activo: " + this->id_Activo + "\\l" 
			+ "Usuario: "+ this->usuario + "\\l" 
			+ "Departamento: "+ this->depto + "\\l" 
			+ "Empresa: "+ this->empresa + "\\l" 
			+ "Fecha: "+ this->fecha + "\\l" 
			+ "Tiempo Rentado: " + this->tiempo + "\\l";
		return texto;
	}

private:
	string id_Transaccion;//se genera automaticamente
	string id_Activo;
	string usuario;
	string depto;
	string empresa;
	string fecha;
	string tiempo;
};
#endif // !TRANSACCION_H
