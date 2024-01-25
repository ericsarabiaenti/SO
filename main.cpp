#include <iostream>
#include <list>
#include <vector>

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
	cout << "Contrase�a: ";
	cin >> contra;

	for (int i = 0; i < usuarios.size(); i++)
	{
		while (usuarios[i] != usuario || contras[i] != contra)
		{
			cout << "Usuario i/o contrase�a incorrecto/a" << endl;
			cout << "Usuario: ";
			cin >> usuario; cout << endl;
			cout << "Contrase�a: ";
			cin >> contra; cout << endl;
		}
	}
	bool salir = false;
	short opcion;
	short opcionUser;
	string usuarioNuevo;
	while(salir == false)
	{
		bool salirMenu1 = false;
		cout << "Estas logueado como " << usuario << endl; cout << endl;
		if (usuario == usuarios[0])
		{
			cout << "1- Gestionar usuario" << endl;
			cout << "2- Cambiar usuario" << endl;
			cout << "3- Gestionar directorios" << endl;
			cout << "4- Gestionar tareas" << endl;
			cout << "5- Salir" << endl;
			cout << endl; cout << "Que quieres hacer: ";
			cin >> opcion; cout << endl; cout << endl;
		}
		else if (usuario != usuarios[0])
		{
			cout << "1- Cambiar usuario" << endl;
			cout << "2- Gestionar directorios" << endl;
			cout << "3- Gestionar tareas" << endl;
			cout << "4- Salir" << endl; 
			cout << endl; cout << "Que quieres hacer: ";
			cin >> opcionUser; cout << endl; cout << endl;
			opcion = opcionUser + 1;
		}
		
		switch (opcion)
		{
		case 1:
			while (salirMenu1 == false)
			{
				if (usuario == "admin")
				{
					cout << "Estas logueado como admin" << endl; cout << endl;
				}
				else
				{
					cout << "Estas logueado como " << usuario << endl; cout << endl;
				}
				cout << "1- Crear usuario" << endl;
				cout << "2- Modificar contrase�a" << endl;
				cout << "3- Eliminar usuario" << endl;
				cout << "4- Volver" << endl;
				cout << endl; cout << "Que quieres hacer: ";
				cin >> opcion; cout << endl; cout << endl;

				switch (opcion)
				{
				case 1:
					cout << "Nombre del usuario nuevo: ";
					cin >> usuarioNuevo;
					for (int i = 0; i < usuarios.size(); i++)
					{
						while (usuarioNuevo == usuarios[i])
						{
							cout << "Este usuario ya existe!!!" << endl;
							cout << "Nombre del usuario nuevo: ";
							cin >> usuarioNuevo;
							i = 0;
						}
					}
					cout << "Escribe una contrase�a para " << usuarioNuevo << ": ";
					cin >> contra;
					cout << "Vuelva a escribir la contrase�a: ";
					cin >> verificacionContra;
					while (contra != verificacionContra)
					{
						cout << "Las contrase�as no coinciden" << endl;
						cout << "Escribe una contrase�a para " << usuario << ": ";
						cin >> contra;
						cout << "Vuelva a escribir la contrase�a: ";
						cin >> verificacionContra;
					}
					usuarios.push_back(usuarioNuevo);
					contras.push_back(contra);
					break;
				case 2:
					cout << "A que usuario le quieres cambiar la contrase�a: ";
					cin >> usuarioNuevo;
					for (int i = 0; i < usuarios.size(); i++)
					{
						if (usuarioNuevo == usuarios[i])
						{
							cout << "Escribe una nueva contrase�a para " << usuarioNuevo << ": ";
							cin >> contra;
							contras[i] = contra;
						}
						while (i == usuarios.size())
						{
							cout << "El usuario que has puesto no existe!!!" << endl;
							cout << "Vuelve a escibir el usuario: ";
							cin >> usuarioNuevo;
							i = 0;
						}
					}
					break;
				case 3:
					cout << "Escribe el usuario que quieres eliminar: ";
					cin >> usuarioNuevo;
					for (int i = 0; i < usuarios.size(); i++)
					{
						if (usuarioNuevo == usuarios[i])
						{
							cout << "Estas seguro que quieres eliminar el usuario " << usuarioNuevo << " (S/N): ";
							cin >> usuarioNuevo;
							while (usuarioNuevo != "S" || usuarioNuevo != "N")
							{
								cout << "Porfavor pon S o N: ";
								cin >> usuarioNuevo;
							}
							if (usuarioNuevo == "S")
							{
								usuarios.erase(usuarios.begin() + i);
							}
							else if (usuarioNuevo == "N")
							{
								break;
							}
						}
						while (i == usuarios.size())
						{
							cout << "El usuario que has puesto no existe!!!" << endl;
							cout << "Vuelve a escibir el usuario: ";
							cin >> usuarioNuevo;
							i = 0;
						}
					}
					break;
				case 4:
					salirMenu1 = true;
					break;
				}
			}
			break;
		case 2:
			cout << "Escribe el usuario al que quieres acceder: ";
			cin >> usuario;
			for (int i = 0; i < usuarios.size(); i++)
			{
				while (i == usuarios.size())
				{
					cout << "Este usuario no existe!!!" << endl;
					cout << "Escribe el usuario al que quieres acceder: ";
					cin >> usuario;
					i = 0;
				}
				if (usuario == usuarios[i])
				{
					cout << "Escribe la contrasena: ";
					cin >> contra;
					while (contra != contras[i])
					{
						cout << "La contrasena es incorrecta: ";
						cin >> contra;
					}
				}
			break;



		case 5: 
			salir = true;
			break;
		}
	}
}