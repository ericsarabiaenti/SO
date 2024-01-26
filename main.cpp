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
	cout << "Contraseña: ";
	cin >> contra;

	for (int i = 0; i < usuarios.size(); i++)
	{
		while (usuarios[i] != usuario || contras[i] != contra)
		{
			cout << "Usuario i/o contraseña incorrecto/a" << endl;
			cout << "Usuario: ";
			cin >> usuario; cout << endl;
			cout << "Contraseña: ";
			cin >> contra; cout << endl;
		}
	}
	bool salir = false;
	short opcion;
	short opcionUser;
	string usuarioNuevo;
	bool usuarioValido = false;
	while (salir == false)
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
				cout << "2- Modificar contraseña" << endl;
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
						}
					}
					cout << "Escribe una contraseña para " << usuarioNuevo << ": ";
					cin >> contra;
					cout << "Vuelva a escribir la contraseña: ";
					cin >> verificacionContra;
					while (contra != verificacionContra)
					{
						cout << "Las contraseñas no coinciden" << endl;
						cout << "Escribe una contraseña para " << usuario << ": ";
						cin >> contra;
						cout << "Vuelva a escribir la contraseña: ";
						cin >> verificacionContra;
					}
					usuarios.push_back(usuarioNuevo);
					contras.push_back(contra);
					break;
				case 2:
					usuarioValido = false;
					while (usuarioValido == false)
					{
						cout << "A que usuario le quieres cambiar la contraseña: ";
						cin >> usuarioNuevo;
						for (int i = 0; i < usuarios.size(); i++) 
						{
							if (usuarioNuevo == usuarios[i])
							{
								usuarioValido = true;
								cout << "Escribe una nueva contraseña para " << usuarioNuevo << ": ";
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
				case 3:
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
				case 4:
					salirMenu1 = true;
					break;
				}
			}
			break;
		case 2:
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
						cout << "Escribe la contraseña para " << usuario << ": ";
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
		case 3:

			

		case 5:
			salir = true;
			break;
			
		}
	}
}