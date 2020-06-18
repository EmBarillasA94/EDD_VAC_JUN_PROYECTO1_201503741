#include "main.h"
//#include "EDD\Lista_Doble_Enlazada_Circular.cpp"
#include "Transaccion.h"
#include "EDD\Matriz_Dispersa.cpp"
#include "EDD\Usuario.h"


Matriz_Dispersa<Usuario*> *Matriz = new Matriz_Dispersa<Usuario*>();
Usuario *User = 0;

int main() {
	
	
	//Lista_Doble_Enlazada_Circular<Transaccion*> *Lista = new Lista_Doble_Enlazada_Circular <Transaccion*>();
	//Transaccion *t1 = new Transaccion("activo1", "uset1", "Guate", "maxi", "04/06/2020", "2 dias");
	//Lista->add_last(t1);
	//Transaccion *t2 = new Transaccion("activo2", "uset1", "Guate", "maxi", "05/06/2020", "7 dias");
	//Lista->add_last(t2);
	//Transaccion *t3 = new Transaccion("activo3", "uset1", "Guate", "maxi", "10/06/2020", "1 dias");
	//Lista->add_last(t3);
	//Lista->graph();
	
	
	
	Usuario *user1 = new Usuario("user1", "Eddy Murga", "12456", "Depto1", "Emp1");
	Matriz->Insertar_elemento(user1, user1->getEmpresa(), user1->getDepto());
	Usuario *user2 = new Usuario("user2", "Alejandro barillas", "12456", "Depto1", "Emp5");
	Matriz->Insertar_elemento(user2, user2->getEmpresa(), user2->getDepto());
	Usuario *user3 = new Usuario("user3", "Julio Matzar", "123456", "Depto3", "Emp1");
	Matriz->Insertar_elemento(user3, user3->getEmpresa(), user3->getDepto());
	Usuario *user4 = new Usuario("user4", "Jose Lopezr", "123456", "Depto3", "Emp2");
	Matriz->Insertar_elemento(user4, user4->getEmpresa(), user4->getDepto());
	Usuario *user5 = new Usuario("user5", "Carlos Lopezr", "123456", "Depto2", "Emp5");
	Matriz->Insertar_elemento(user5, user5->getEmpresa(), user5->getDepto());
	Usuario *user6 = new Usuario("user6", "Mario Bros", "123456", "Depto2", "Emp2");
	Matriz->Insertar_elemento(user6, user6->getEmpresa(), user6->getDepto());
	Usuario *user7 = new Usuario("user7", "Link", "12456", "Depto7", "Emp6");
	Matriz->Insertar_elemento(user7, user7->getEmpresa(), user7->getDepto());
	//Matriz->graph();

	IniciarSesion();
	return 0;
}

string GenerarId(int tamanio)
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

void IniciarSesion()
{
	system("cls");
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
	system("cls");
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
		User = Matriz->BuscarUsuario(depto, empresa, usuario, contrasenia);
		if (User != 0)
		{
			//usuario encontrado
			MenuUsuario(User->getUsuario());
		}
		else
		{
			cout << "Usuario Invalido" << endl;
			system("pause");
			Login();
		}
	}
	
	//cout << "usuario: " << usuario << endl;
	//cout << "contrase: " << contrasenia << endl;
	//cout << "Depto: " << depto << endl;
	//cout << "empresa: " << empresa << endl;
	//system("pause");


}

void MenuUsuario(string Nombre_)
{
	system("cls");
	cout << "-----------------------------------------------" << endl;
	cout << "\t\t" << Nombre_ << endl;
	cout << "\t 1.- Agregar Activos" << endl;
	cout << "\t 2.- Eliminar Activos" << endl;
	cout << "\t 3.- Modificar Activos" << endl;
	cout << "\t 4.- Rentar Activo" << endl;
	cout << "\t 5.- Activos Rentados" << endl;
	cout << "\t 6.- Mis Activos Rentados" << endl;
	cout << "\t 7.- Cerrar Sesión" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Ingrese Opcion:" << endl;
	
	int opcion;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		//menu AgregarActivos
		AgregarActivos();
		break;
	case 2:
		//menu EliminarActivos
		EliminarActivos();
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
		User = 0;
		IniciarSesion();
		break;
	default:
		MenuUsuario(Nombre_);
		break;
	}
}

void AgregarActivos()
{
	system("cls");
	cout << "---------------Agregar Activos---------------" << endl;
	cout << "Ingresar Nombre:" << endl;
	string nombre = "";
	cin >> nombre;
	cout << "Ingresar Descripcion:" << endl;
	string descrip = "";
	cin >> descrip;
	cout << "---------------------------------------------" << endl;
	//ingresar el activo en el arbol avl del usuario logeado
	Activo *Act_Nuevo = new Activo(GenerarId(15), nombre, descrip);
	User->Insertar_Activo(Act_Nuevo);
	//User->Graficar_Arbol_por_Usuario(User->getUsuario());
	MenuUsuario(User->getUsuario());
}

void EliminarActivos()
{
	system("cls");
	cout << "---------------Eliminar Activos---------------" << endl;
	cout << endl;
	User->Mostrar_Activos();
	cout << "----------------------------------------------" << endl;
	cout << "Ingrese el ID activo a eliminar:" << endl;
	cout << "(Escriba salir para regresar):" << endl;

	string id_activo;
	cin >> id_activo;
	if (id_activo != "salir")
	{
		User->Eliminar_Activo(id_activo);
		User->Graficar_Arbol_por_Usuario(User->getUsuario());
		EliminarActivos();
	}
	else
	{
		MenuUsuario(User->getNombre());
	}
}

void ModificarActivos()
{
	system("cls");
	cout << "---------------Modificar Activos---------------" << endl;
	cout << endl;
	User->Mostrar_Activos();
	cout << "-----------------------------------------------" << endl;
	cout << "Ingrese el ID activo a Modificar:" << endl;
	string id;
	cin >> id;
	cout << "Ingrese la descripcion nueva:" << endl;
	string desc_nueva;
	cin >> desc_nueva;
	User->Modifcar_Activo(id, desc_nueva);
	MenuUsuario(User->getNombre());
}

void MenuAdministrador()
{
	system("cls");
	cout << "------------------------Menu Administrador------------------------" << endl;
	cout << "\t 1.- Registrar Usuario" << endl;
	cout << "\t 2.- Reporte Matriz Dispersa" << endl;
	cout << "\t 3.- Reporte Activos Disponibles de un Departamento" << endl;
	cout << "\t 4.- Reporte Activos Disponibles de una Empresa" << endl;
	cout << "\t 5.- Reporte Transacciones" << endl;
	cout << "\t 6.- Reporte Activos de un Usuario" << endl;
	cout << "\t 7.- Reporte Activos Rentados por un Usuario" << endl;
	cout << "\t 8.- Ordenar Transacciones" << endl;
	cout << "\t 9.- Cerrar Sesion" << endl;
	cout << "------------------------------------------------------------------" << endl;
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
		Matriz->graph();
		MenuAdministrador();
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
		break;
	default:
		MenuAdministrador();
		break;
	}
}

void CrearUsuarios()
{
	system("cls");
	cout << "---------------Crear Usuario---------------" << endl;
	cout << "Ingresar Usuario:" << endl;
	cout << "\t";
	string usuario = "";
	cin >> usuario;

	cout << "Ingresar Contraseña:" << endl;
	cout << "\t";
	string contrasenia = "";
	cin >> contrasenia;

	cout << "Ingresar Nombre:" << endl;
	cout << "\t";
	string nombre = "";
	cin >> nombre;

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
	bool Insertado = Matriz->Insertar_elemento(new Usuario(usuario, nombre, contrasenia, depto, empresa), empresa, depto);
	if (Insertado == true)
	{
		cout << "----------USUARIO GUARDADO---------" << endl;
		cout << "Usuario: " << usuario << endl;
		cout << "Departamento: " << depto << endl;
		cout << "Empresa: " << empresa << endl;
		system("pause");
		MenuAdministrador();
	}
	else
	{
		cout << "----------Usuario invalido----------" << endl;
		system("pause");
		MenuAdministrador();
	}
}
