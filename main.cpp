#include <iostream>
#include <list>
#include <vector>

using namespace std;

void main()
{
	while (true) 
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

		while (usuarios[0] != usuario || contras[0] != contra)
		{
			cout << "Usuario i/o contraseña incorrecto/a" << endl;
			cout << "Usuario: "; 
			cin >> usuario; cout << endl;
			cout << "Contraseña: "; 
			cin >> contra; cout << endl;
		}

		cout << "Estas logueado como Admin" << endl; cout << endl;

		cout << "1- Gestionar usuario" << endl;
		cout << "2- Cambiar usuario" << endl;
		cout << "3- Gestionar directorios" << endl;
		cout << "4- Gestionar tareas" << endl;
		cout << "5- Salir" << endl;

		short opcion;

		cout << endl; cout << "Que quieres hacer: "; 
		cin >> opcion; cout << endl; cout << endl;

		switch (opcion)
		{
		case 1:
			cout << "1- Credar usuario" << endl;
			cout << "2- Modificar contraseña" << endl;
			cout << "3- Eliminar usuario" << endl;
			cout << "4- Volver" << endl;
			cout << endl; cout << "Que quieres hacer: "; 
			cin >> opcion; cout << endl; cout << endl;

			switch (opcion) 
			{
			case 1: 
				cout << "Nombre del usuario nuevo: "; 
				cin >> usuario;
				for (int i = 0; i < usuarios.size(); i++)
				{
					while (usuario == usuarios[i])
					{
						cout << "Este usuario ya existe!!!" << endl;
						cout << "Nombre del usuario nuevo: "; 
						cin >> usuario;
						i = 0;
					}
				}
				cout << "Escribe una contraseña para " << usuario << ": "; 
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
				usuarios.push_back(usuario);
				contras.push_back(contra);
				break;
			case 2:
				cout << "A que usuario le quieres cambiar la contraseña: ";
				cin >> usuario;
				for (int i = 0; i < usuarios.size(); i++)
				{
					if (usuario == usuarios[i]) 
					{
						cout << "Escribe una nueva contraseña para " << usuario << ": ";
						cin >> contra;
						contras[i] = contra;
					}
					else if (i == usuarios.size())
					{
						cout << "El usuario que has puesto no existe!!!" << endl;
						cout << "Vuelve a escibir el usuario: ";
						cin >> usuario;
						i = 0;
					}
				}
				break;
			case 3:
				break;
			}
		}
	}
}