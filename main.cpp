#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void main()
{
	vector<string> usuarios;
	vector<string> contras;
	string usuario;
	string contra;
	string verificacionContra;

	usuarios.push_back("admin");
	contras.push_back("admin");

	cout << "Bienvenido a ENTI-OS" << endl;
	cout << "Usuario: ";
	cin >> usuario;
	cout << "Contraseņa: ";
	cin >> contra;

	for (int i = 0; i < usuarios.size(); i++)
	{
		while (usuarios[i] != usuario || contras[i] != contra)
		{
			cout << "Usuario i/o contraseņa incorrecto/a" << endl;
			cout << "Usuario: ";
			cin >> usuario; cout << endl;
			cout << "Contraseņa: ";
			cin >> contra; cout << endl;
		}
	}
	bool salirMenu1 = false;
	bool salir = false;

	string usuarioNuevo;
	bool usuarioValido = false;
	vector<queue<string>> usuariosTareas;
	queue<string> tareas;
	usuariosTareas.push_back(tareas);


	char opcion;
	char opcionUser;
	while (salir == false)
	{
		bool opcionin = false;
		cout << "Estas logueado como " << usuario << endl; cout << endl;
		if (usuario == usuarios[0])
		{
			cout << "1- Gestionar usuario" << endl;
			cout << "2- Cambiar usuario" << endl;
			cout << "3- Gestionar directorios" << endl;
			cout << "4- Gestionar tareas" << endl;
			cout << "5- Salir" << endl;
			while (!opcionin)
			{
				cout << endl; cout << "Que quieres hacer: ";
				cin >> opcion;

				cout << endl; cout << endl;

				if ((int)opcion > 48 && (int)opcion < 54)
				{
					opcionin = true;
				}
				else 
				{
					cout << "Escribe un numero entre en 1 y el 5: ";
				}
			}
		}
		else
		{
			cout << "1- Cambiar usuario" << endl;
			cout << "2- Gestionar directorios" << endl;
			cout << "3- Gestionar tareas" << endl;
			cout << "4- Salir" << endl;
			cout << endl;
			while (!opcionin)
			{
				cout << endl; 
				cout << "Que quieres hacer: ";
				cin >> opcionUser;

				cout << endl; cout << endl;

				if ((int)opcionUser > 48 && (int)opcionUser < 53)
				{
					opcionin = true;
					opcion = opcionUser;
					opcion += 1;
				}
				else
				{
					cout << "Escribe un numero entre en 1 y el 4: ";
				}
			}
		}
		
		switch (opcion)
		{
		case '1':
			while (salirMenu1 == false)
			{

				cout << "Estas logueado como " << usuario << endl; cout << endl;
				cout << "1- Crear usuario" << endl;
				cout << "2- Modificar contraseņa" << endl;
				cout << "3- Eliminar usuario" << endl;
				cout << "4- Volver" << endl;
				cout << endl; cout << "Que quieres hacer: ";
				cin >> opcion; cout << endl; cout << endl;
				switch (opcion)
				{
				case '1':
					cout << "Nombre del usuario nuevo: ";
					cin >> usuarioNuevo;
					for (int i = 0; i < usuarios.size(); i++)
					{
						while (usuarioNuevo == usuarios[i])
						{
							cout << "Este usuario ya existe!!!" << endl;
							cout << "Nombre del usuario nuevo: ";
							cin >> usuarioNuevo;
						}
					}
					cout << "Escribe una contraseņa para " << usuarioNuevo << ": ";
					cin >> contra;
					cout << "Vuelva a escribir la contraseņa: ";
					cin >> verificacionContra;
					while (contra != verificacionContra)
					{
						cout << "Las contraseņas no coinciden" << endl;
						cout << "Escribe una contraseņa para " << usuario << ": ";
						cin >> contra;
						cout << "Vuelva a escribir la contraseņa: ";
						cin >> verificacionContra;
					}
					usuarios.push_back(usuarioNuevo);
					contras.push_back(contra);
					usuariosTareas.push_back(tareas);
					break;
				case '2':
					usuarioValido = false;
					while (usuarioValido == false)
					{
						cout << "A que usuario le quieres cambiar la contraseņa: ";
						cin >> usuarioNuevo;
						for (int i = 0; i < usuarios.size(); i++)
						{
							if (usuarioNuevo == usuarios[i])
							{
								usuarioValido = true;
								cout << "Escribe una nueva contraseņa para " << usuarioNuevo << ": ";
								cin >> contra;
								contras[i] = contra;
							}
						}
						if (usuarioValido == false)
						{
							cout << "El usuario que has puesto no existe!!!" << endl;
						}
					}
					break;
				case '3':
					usuarioValido = false;
					while (usuarioValido == false)
					{
						cout << "Escribe el usuario que quieres eliminar: ";
						cin >> usuarioNuevo;
						for (int i = 0; i < usuarios.size(); i++)
						{
							if (usuarioNuevo == usuarios[i])
							{
								usuarioValido = true;
								cout << "Estas seguro que quieres eliminar el usuario " << usuarioNuevo << " (S/N): ";
								cin >> usuarioNuevo;
								if (usuarioNuevo == "S")
								{
									usuarios.erase(usuarios.begin() + i);
								}
								else if (usuarioNuevo == "N")
								{
									break;
								}
								while (usuarioNuevo != "S" && usuarioNuevo != "N")
								{
									cout << "Porfavor pon S o N: ";
									cin >> usuarioNuevo;
								}
							}
							else if (usuarioValido == false)
							{
								cout << "Este usuario no existe!!!" << endl;
							}
						}
					}
					break;
				case '4':
					salirMenu1 = true;
					break;
				}
			}
			break;
		case '2':
			usuarioValido = false;
			while (usuarioValido == false)
			{
				cout << "Escribe el usuario al que quieres acceder: ";
				cin >> usuario;
				for (int i = 0; i < usuarios.size(); i++)
				{
					if (usuario == usuarios[i])
					{
						usuarioValido = true;
						cout << "Escribe la contraseņa para " << usuario << ": ";
						cin >> contra;
						while (contra != contras[i])
						{
							cout << "La contrasena es incorrecta, intentalo de nuevo: ";
							cin >> contra;
						}
					}
				}
				if (usuarioValido == false)
				{
					cout << "El usuario que has puesto no existe!!!" << endl;
				}
			}
			break;
		case '3':
			salirMenu1 = false;
			while (salirMenu1 == false)
			{
				cout << "1- Ver directorios" << endl;
				cout << "2- Crear directorios" << endl;
				cout << "3- Renombrar directorios" << endl;
				cout << "4- Eliminar tareas" << endl;
				cout << "5- Volver" << endl;


			}
			break;
		case '4':
			while (salirMenu1 == false)
			{
				salirMenu1 = false;
				string tarea;
				char user;
				for (int i = 0; i < usuarios.size(); i++)
				{
					if (usuario == usuarios[i])
					{
						user = i;
					}
				}
				cout << "Estas logueado como " << usuario << endl; cout << endl;
				cout << "1- Crear tarea" << endl;
				cout << "2- Mostrar siguiente tarea" << endl;
				cout << "3- Completar tarea" << endl;
				cout << "4- Volver" << endl;
				cout << endl; cout << "Que quieres hacer: ";
				cin >> opcion; cout << endl; cout << endl;

				switch (opcion)
				{
				case '1':
					cout << "Que tarea quieres escribir: ";
					cin >> tarea;
					usuariosTareas[user].push(tarea);
					break;
				case '2':
					if (!usuariosTareas[user].empty())
					{
						cout << "La tarea que tienes que hacer es: " << usuariosTareas[user].front() << endl;
					}
					else
					{
						cout << "No hay tareas" << endl;
					}
					break;
				case '3':
					if (!usuariosTareas[user].empty())
					{
						cout << "Acabas de completrar esta tarea: " << usuariosTareas[user].front() << endl;
						usuariosTareas[user].pop();
					}
					else
					{
						cout << "No hay tareas" << endl;
					}
					break;
				case '4':
					salirMenu1 = true;
					break;
				}
			}
		case '5':
			salir = true;
			break;

		}
	}
}