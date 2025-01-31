#include "main.h"
#include "EDD\Lista_Doble_Enlazada_Circular.cpp"
#include "Transaccion.h"
#include "EDD\Matriz_Dispersa.cpp"
#include "EDD\Usuario.h"


Matriz_Dispersa<Usuario*> *Matriz = new Matriz_Dispersa<Usuario*>();
Usuario *User = 0;
Lista_Doble_Enlazada_Circular<Transaccion*> *Lista = new Lista_Doble_Enlazada_Circular <Transaccion*>();

int main() {
	
	
	//Transaccion *t1 = new Transaccion("activo1", "uset1", "Guate", "maxi", "04/06/2020", "2 dias");
	//Lista->add_last(t1);
	//Transaccion *t2 = new Transaccion("activo2", "uset1", "Guate", "maxi", "05/06/2020", "7 dias");
	//Lista->add_last(t2);
	//Transaccion *t3 = new Transaccion("activo3", "uset1", "Guate", "maxi", "10/06/2020", "1 dias");
	//Lista->add_last(t3);
	//Lista->graph();
	
	
	
	//Usuario *user1 = new Usuario("user1", "Eddy Murga", "123456", "Depto1", "Emp1");
	////user1->Insertar_Activo(new Activo(GenerarId(15), "carro", "carro 4 puertas"));
	////user1->Insertar_Activo(new Activo(GenerarId(15), "casa", "casa 2 niveles"));
	////user1->Insertar_Activo(new Activo(GenerarId(15), "mesa", "mesa de metal"));
	//Matriz->Insertar_elemento(user1, user1->getEmpresa(), user1->getDepto());
	////
	//Usuario *user2 = new Usuario("user2", "Alejandro barillas", "123456", "Depto1", "Emp5");
	////user2->Insertar_Activo(new Activo(GenerarId(15), "silla", "silla"));
	////user2->Insertar_Activo(new Activo(GenerarId(15), "lapiz", "lapiz"));
	////user2->Insertar_Activo(new Activo(GenerarId(15), "calculadora", "calculadora"));
	//Matriz->Insertar_elemento(user2, user2->getEmpresa(), user2->getDepto());

	//Usuario *user3 = new Usuario("user3", "Julio Matzar", "123456", "Depto3", "Emp1");
	////user3->Insertar_Activo(new Activo(GenerarId(15), "laptop", "laptop"));
	////user3->Insertar_Activo(new Activo(GenerarId(15), "canionera", "canionera"));
	////user3->Insertar_Activo(new Activo(GenerarId(15), "monitor", "monitor"));
	//Matriz->Insertar_elemento(user3, user3->getEmpresa(), user3->getDepto());
	////
	//Usuario *user4 = new Usuario("user4", "Jose Lopezr", "123456", "Depto3", "Emp2");
	//Matriz->Insertar_elemento(user4, user4->getEmpresa(), user4->getDepto());
	////
	//Usuario *user5 = new Usuario("user5", "Carlos Lopezr", "123456", "Depto2", "Emp5");
	//Matriz->Insertar_elemento(user5, user5->getEmpresa(), user5->getDepto());
	////
	//Usuario *user6 = new Usuario("user6", "Mario Bros", "123456", "Depto2", "Emp2");
	////user6->Insertar_Activo(new Activo(GenerarId(15), "ropa", "ropa"));
	////user6->Insertar_Activo(new Activo(GenerarId(15), "Sombrero", "Sombrero"));
	////user6->Insertar_Activo(new Activo(GenerarId(15), "Capa", "Capa"));
	//Matriz->Insertar_elemento(user6, user6->getEmpresa(), user6->getDepto());
	////
	//Usuario *user7 = new Usuario("user7", "Link", "123456", "Depto7", "Emp6");
	////user7->Insertar_Activo(new Activo(GenerarId(15), "pokebola", "pokebola"));
	////user7->Insertar_Activo(new Activo(GenerarId(15), "pokedex", "pokedex"));
	////user7->Insertar_Activo(new Activo(GenerarId(15), "posion", "posion"));
	//Matriz->Insertar_elemento(user7, user7->getEmpresa(), user7->getDepto());
	////Matriz->graph();

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
	cout << "\t 1.- Iniciar Sesion" << endl;
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
	
	cout << "Ingresar Contrase�a:" << endl;
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
	cout << "\t 7.- Cerrar Sesi�n" << endl;
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
		ModificarActivos();
		break;
	case 4:
		//menu RentarActivos
		RentarActivos();
		break;
	case 5:
		// menu ActivosRentados
		ActivosRentados();
		break;
	case 6:
		//menu MisActivosRentados
		MisActivosRentados();
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
		//User->Graficar_Arbol_por_Usuario(User->getUsuario());
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

void RentarActivos()
{
	system("cls");
	cout << "---------------Catalogo de Activos---------------" << endl;
	cout << endl;
	Matriz->Mostrar_Activos_Disponibles(User);
	cout << endl;
	cout << "\t 1.- Rentar Activo" << endl;
	cout << "\t 2.- Regresar a Menu" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "Ingresa una opcion:" << endl;
	int opcion;
	cin >> opcion;
	if (opcion == 1)
	{
		cout << "Ingrese el ID del Activo:" << endl;
		string id;
		cin >> id;
		cout << "Ingrese la fecha:" << endl;
		string fecha;
		cin >> fecha;
		cout << "Ingrese la cantidad de dias por rentar:" << endl;
		string dias;
		cin >> dias;
		cout << endl;
		//creo la transaccion
		Transaccion *Nueva_Transaccion = new Transaccion(GenerarId(15), id, User->getUsuario(), User->getDepto(), User->getEmpresa(), fecha, dias);
		//hay que rentar el activo
		Matriz->Rentar_Activo(id, User);
		//metemos la nueva transaccion a la lista
		Lista->add_last(Nueva_Transaccion);
		MenuUsuario(User->getUsuario());
	}
	else
	{
		MenuUsuario(User->getUsuario());
	}
}

void ActivosRentados()
{
	system("cls");
	cout << "---------------Activos Rentados---------------" << endl;
	cout << endl;
	Lista->Mostrar_Transacciones_de_Usuario(User->getUsuario());
	cout << endl;
	cout << "\t 1.- Registrar Devolucion" << endl;
	cout << "\t 2.- Regresar a Menu" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Ingrese una opcion" << endl;
	string opcion;
	cin >> opcion;
	if (opcion == "1")
	{
		cout << "Ingrese el ID del Activo" << endl;
		string id;
		cin >> id;
		//modificar la trasaccion
		Lista->Registrar_Devolucion(id, User->getUsuario());
		//hay que devolver el activo a disponible
		Matriz->Devolver_Activo(id, User);
		MenuUsuario(User->getUsuario());
	}
	else
	{
		MenuUsuario(User->getUsuario());
	}
}

void MisActivosRentados()
{
	system("cls");
	cout << "---------------Mis Activos Rentados---------------" << endl;
	cout << endl;
	User->Mostrar_Activos_Rentados();
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	system("pause");
	MenuUsuario(User->getUsuario());
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
		//Reporte Matriz dispersa
		Matriz->graph();
		MenuAdministrador();
		break;
	case 3:
		//Reporte Activos Disponibles de un departamento
		ReporteActivosPorDepto();
		break;
	case 4:
		//Reporte Activos Disponibles de una empresa
		ReporteActivosPorEmpresa();
		break;
	case 5:
		//Reportes Transacciones
		Lista->graph();
		MenuAdministrador();
		break;
	case 6:
		//Reporte Activos de un usuario
		ReporteActivosDeUnUsuario();
		break;
	case 7:
		//Reporte Activos rentados por un usuario
		ReporteActivosRentadosPorUsuario();
		MenuAdministrador();
		break;
	case 8:
		//Ordenar Transacciones
		OrdenarTrasacciones();
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

	cout << "Ingresar Contrase�a:" << endl;
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

void ReporteActivosPorDepto()
{
	cout << "Ingrese el departamento:" << endl;
	string depto;
	cin >> depto;
	Matriz->graph_por_Depto(depto);
	MenuAdministrador();
}

void ReporteActivosPorEmpresa()
{
	cout << "Ingrese la empresa:" << endl;
	string depto;
	cin >> depto;
	Matriz->graph_por_Empresa(depto);
	MenuAdministrador();
}

void ReporteActivosRentadosPorUsuario()
{
	cout << endl;
	cout << "Ingrese el usuario:" << endl;
	string usu;
	cin >> usu;
	cout << "Ingrese la empresa:" << endl;
	string emp;
	cin >> emp;
	cout << "Ingrese el departamento:" << endl;
	string depto;
	cin >> depto;
	Lista->graph_por_Usuario(usu, emp, depto);
}

void ReporteActivosDeUnUsuario()
{
	cout << endl;
	cout << "Ingrese el usuario:" << endl;
	string usu;
	cin >> usu;
	cout << "Ingrese la empresa:" << endl;
	string emp;
	cin >> emp;
	cout << "Ingrese el departamento:" << endl;
	string depto;
	cin >> depto;
	Usuario *usuario = Matriz->BuscarUsuario2(depto, emp, usu);
	if (usuario != 0)
	{
		//usuario encontrado
		usuario->Graficar_Arbol_por_Usuario(usuario->getUsuario());
		MenuAdministrador();
	}
	else
	{
		cout << "Usuario Invalido" << endl;
		system("pause");
	}
}

void OrdenarTrasacciones()
{
	cout << "\t 1.- Orden Ascendente" << endl;
	cout << "\t 2.- Orden Desendente" << endl;
	cout << "Ingrese una opcion" << endl;
	int opcion;
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		Lista->OrdenarAscendente();
		MenuAdministrador();
		break;
	case 2:
		Lista->OrdenarDesendente();
		MenuAdministrador();
		break;
	default:
		break;
	}
}
