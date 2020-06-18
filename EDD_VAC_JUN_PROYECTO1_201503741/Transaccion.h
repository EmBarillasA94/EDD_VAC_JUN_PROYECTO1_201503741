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
		this->devuelto = "No";
	}
	
	//getters and setters 
	string getInfo() {
		string texto = "Id Transaccion: "+this->id_Transaccion + "\\l" 
			+ "Id Activo: " + this->id_Activo + "\\l" 
			+ "Usuario: "+ this->usuario + "\\l" 
			+ "Departamento: "+ this->depto + "\\l" 
			+ "Empresa: "+ this->empresa + "\\l" 
			+ "Fecha: "+ this->fecha + "\\l" 
			+ "Tiempo Rentado: " + this->tiempo + "\\l"
			+ "Devuelto: " + this->devuelto + "\\l";
		return texto;
	}
	bool getEstado_Devolucion() {
		if (this->devuelto == "Si")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string getDatos_Transaccion() {
		string text = "Id Activo = " + this->id_Activo + " ; Nombre = " + " ; Tiempo de Renta = " + this->tiempo;
		return text;
	}
	
	string getId_Transaccion() {
		return this->id_Transaccion;
	}
	string getId_Activo() {
		return this->id_Activo;
	}
	string getUsuario() {
		return this->usuario;
	}
	void Devolver_Activo() {
		this->devuelto = "Si";
	}
private:
	string id_Transaccion;
	string id_Activo;
	string usuario;
	string depto;
	string empresa;
	string fecha;
	string tiempo;
	string devuelto;
};
#endif // !TRANSACCION_H
