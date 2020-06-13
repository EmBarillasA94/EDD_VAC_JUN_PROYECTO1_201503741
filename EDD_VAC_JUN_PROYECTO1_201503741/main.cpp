#include "main.h"
#include "EDD\Lista_Doble_Enlazada_Circular.cpp"
#include "Transaccion.h"
#include "EDD\Matriz_Dispersa.cpp"

#include <iostream>
#include <string>
using namespace std;

int main() {
	//IniciarSesion();
	//Lista_Doble_Enlazada_Circular<Transaccion*> *Lista = new Lista_Doble_Enlazada_Circular <Transaccion*>();
	//Transaccion *t1 = new Transaccion("activo1", "uset1", "Guate", "maxi", "04/06/2020", "2 dias");
	//Lista->add_last(t1);
	//Transaccion *t2 = new Transaccion("activo2", "uset1", "Guate", "maxi", "05/06/2020", "7 dias");
	//Lista->add_last(t2);
	//Transaccion *t3 = new Transaccion("activo3", "uset1", "Guate", "maxi", "10/06/2020", "1 dias");
	//Lista->add_last(t3);
	//Lista->graph();
	Matriz_Dispersa<int> *Matriz = new Matriz_Dispersa<int>();
	return 0;
}

void IniciarSesion()
{
	system("clear");
	cout << "---------------RENTA DE ACTIVOS---------------" << endl;
	cout << "\t 1.- Iniciar Sesión" << endl;
	cout << "\t 2.- Salir" << endl;
	cout << "----------------------------------------------" << endl;
	int opcion;
	cin>> opcion;
	switch (opcion)
	{
	case 1:
		//menu de login
		Login();
		break;
	case 2:
		//salir
		system("exit");
		break;
	default:
		IniciarSesion();
		break;
	}
}

void Login()
{
	system("clear");
	cout << "---------------LOGIIN---------------" << endl;

	cout << "Ingresar Usuario:" << endl;
	cout << "\t";
	string usuario = "";
	cin >> usuario;
	
	cout << "Ingresar Contraseña:" << endl;
	cout << "\t";
	string contrasenia = "";
	cin >> contrasenia;

	cout << "Ingresar Departamento:" << endl;	
	cout << "\t";
	string depto = "";
	cin >> depto;
	
	cout << "Ingresar Empresa:" << endl;
	cout << "\t";
	string empresa = "";
	cin >> empresa;
	cout << "------------------------------------" << endl;
	
	if (usuario == "admin" && contrasenia == "admin" && depto == "admin" && empresa == "admin")
	{
		MenuAdministrador();
	}
	else
	{
		//buscar usuario en la matriz
	}
	
	//cout << "usuario: " << usuario << endl;
	//cout << "contrase: " << contrasenia << endl;
	//cout << "Depto: " << depto << endl;
	//cout << "empresa: " << empresa << endl;
	//system("pause");


}

void MenuUsuario()
{
	system("clear");
	cout << "---------------Nombre de Usuario---------------" << endl;
	cout << "\t 1.- Agregar Activos" << endl;
	cout << "\t 2.- Eliminar Activos" << endl;
	cout << "\t 3.- Modificar Activos" << endl;
	cout << "\t 4.- Rentar Activo" << endl;
	cout << "\t 5.- Activos Rentados" << endl;
	cout << "\t 6.- Mis Activos Rentados" << endl;
	cout << "\t 7.- Cerrar Sesión" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Ingrese Opción:" << endl;
	
	int opcion;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		//menu AgregarActivos
		break;
	case 2:
		//menu EliminarActivos
		break;
	case 3: 
		//menu ModificarActivos
		break;
	case 4:
		//menu RentarActivos
		break;
	case 5:
		// menu ActivosRentados
		break;
	case 6:
		//menu MisActivosRentados
		break;
	case 7:
		//Cerrar Sesion
		break;
	default:
		MenuUsuario();
		break;
	}
}

void AgregarActivos()
{
	system("clear");
	cout << "---------------Agregar Activos---------------" << endl;
	cout << "Ingresar Nombre:" << endl;
	string nombre = "";
	cin >> nombre;
	cout << "Ingresar Descripción:" << endl;
	string descrip = "";
	cin >> descrip;
	cout << "---------------------------------------------" << endl;
	//ingresar el activo en el arbol avl del usuario logeado
}

void MenuAdministrador()
{
	system("clear");
	cout << "------------------------Agregar Activos------------------------" << endl;
	cout << "\t 1.- Registrar Usuario" << endl;
	cout << "\t 2.- Reporte Matriz Dispersa" << endl;
	cout << "\t 3.- Reporte Activos Disponibles de un Departamento" << endl;
	cout << "\t 4.- Reporte Activos Disponibles de una Empresa" << endl;
	cout << "\t 5.- Reporte Transacciones" << endl;
	cout << "\t 6.- Reporte Activos de un Usuario" << endl;
	cout << "\t 7.- Reporte Activos Rentados por un Usuario" << endl;
	cout << "\t 8.- Ordenar Transacciones" << endl;
	cout << "\t 9.- Cerrar Sesion" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Ingrese Opcioin:" << endl;

	int opcion;
	cin >> opcion;
	switch (opcion)
	{
	case 1: 
		//Menu REgistrar Usuario
		CrearUsuarios();
		break;
	case 2:
		//Reporte Matriz dispesa
		break;
	case 3:
		//Reporte Activos Disponibles de un departamento
		break;
	case 4:
		//Reporte Activos Disponibles de una empresa
		break;
	case 5:
		//Reportes Transacciones
		break;
	case 6:
		//Reporte Activos de un usuario
		break;
	case 7:
		//Reporte Activos rentados por un usuario
		break;
	case 8:
		//Ordenar Transacciones
		break;
	case 9:
		//Cerrar Sesion
		IniciarSesion();
	default:
		MenuAdministrador();
		break;
	}
}

void CrearUsuarios()
{
	system("clear");
	cout << "---------------Crear Usuario---------------" << endl;
	cout << "Ingresar Usuario:" << endl;
	cout << "\t";
	string usuario = "";
	cin >> usuario;

	cout << "Ingresar Contraseña:" << endl;
	cout << "\t";
	string contrasenia = "";
	cin >> contrasenia;

	cout << "Ingresar Departamento:" << endl;
	cout << "\t";
	string depto = "";
	cin >> depto;

	cout << "Ingresar Empresa:" << endl;
	cout << "\t";
	string empresa = "";
	cin >> empresa;
	cout << "-------------------------------------------" << endl;

	//crear el usuario en la matriz
}
