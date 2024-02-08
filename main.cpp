#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void main()
{
	vector<string> usuarios;//vector que guarda usuarios
	vector<string> contras;//vector que guarda usuarios
	usuarios.push_back("admin");//meto admin en usuarios
	contras.push_back("admin");//meto admin en contra

	string usuario;//string donde el usuario escribe el user al que quiere acceder
	string contra;//contra del usuario que accede
	cout << "Bienvenido a ENTI-OS" << endl;
	cout << "Usuario: ";
	cin >> usuario;//escribe el usuario
	cout << "Contraseña: ";
	cin >> contra;//escribe la contra del usuario

	while (usuarios[0] != usuario || contras[0] != contra)//verifico si ha escrito bien el admin
	{
		cout << "Usuario i/o contraseña incorrecto/a" << endl;
		cout << "Usuario: ";
		cin >> usuario;
		cout << endl;
		cout << "Contraseña: ";
		cin >> contra;
		cout << endl;
	}

	bool usuarioValido = false;//sirve para salr cuando el usuario este verificado
	string verificacionContra;//string para verificar contra
	string usuarioNuevo;//para escribir el usuario nuevo

	vector<queue<string>> usuariosTareas;//sirve para meter queues en el vector
	queue<string> tareas;//sirve para meter las tareas en la queue
	usuariosTareas.push_back(tareas);//sirve para inicializar el vector en admin

	char opcion;//sirve para que el usuario seleccione lo que quiere hacer
	bool volver = false;//sirve para volver al menu principal

	vector <string> dir;//sirve para meter directorios
	dir.push_back("C:/");//el primer directorio hardcodeado
	string dirNombre;//escribir el nombre del directorio
	bool dirValido = false;//para verificar el directorio

	bool salir = false;//booleano para salir de la aplicacion
	while (salir == false)//no saldra de la app hasta que sea true
	{
		bool opcionin = false;//sirve para verificar que ha seleccionado entre un numero y otro
		cout << "Estas logueado como " << usuario << endl;//muestra el usuario con el que estas logueado
		cout << endl;
		if (usuario == usuarios[0])//si eres admin muestra este menu
		{
			//muestro el menu
			cout << "1- Gestionar usuario" << endl;
			cout << "2- Cambiar usuario" << endl;
			cout << "3- Gestionar directorios" << endl;
			cout << "4- Gestionar tareas" << endl;
			cout << "5- Salir" << endl;
			while (!opcionin)//no sale hasta que sea true
			{
				cout << endl; cout << "Que quieres hacer: ";
				cin >> opcion;//pone lo que quiere hacer

				cout << endl;
				cout << endl;

				if (opcion > 48 && opcion < 54)//verifico que el numero este entre el 1 y el 5
				{
					opcionin = true;//sale del bucle
				}
				else
				{
					cout << "Escribe un numero entre en 1 y el 5: ";//le digo que escribe entre el 1 y el 5
				}
			}
		}
		else//si no es admin le quito la opcion de gestionar usuarios
		{
			//muestro el menu
			cout << "1- Cambiar usuario" << endl;
			cout << "2- Gestionar directorios" << endl;
			cout << "3- Gestionar tareas" << endl;
			cout << "4- Salir" << endl;
			cout << endl;
			while (!opcionin)//no sale hasta que sea true
			{
				cout << endl;
				cout << "Que quieres hacer: ";
				cin >> opcion;//pone lo que quiere hacer
				cout << endl; 
				cout << endl;

				if (opcion >= '1' && opcion <= '4')//verifico que pongo entre el 1 y el 4
				{
					opcionin = true;//sale del bucle
					opcion += 1;//le sumo uno para que cuando ponga uno entre en el 2 y asi todo el rato
				}
				else
				{
					cout << "Escribe un numero entre en 1 y el 4: ";//le especifico que escriba entre el 1 y el 4
				}
			}
		}
		switch (opcion)//depende de la opcion escogida entra en un sitio o en otro
		{
		case '1'://si pone 1
			volver = false;
			while (volver == false)//hasta que no sea true no vuelve al menu anterior
			{
				cout << "Estas logueado como " << usuario << endl; //muestro con que user estas logueado
				cout << endl;
				//muestro el menu
				cout << "1- Crear usuario" << endl;
				cout << "2- Modificar contraseña" << endl;
				cout << "3- Eliminar usuario" << endl;
				cout << "4- Volver" << endl;
				cout << endl;
				cout << "Que quieres hacer: ";
				cin >> opcion; //escribe lo que quiere hacer
				cout << endl; 
				cout << endl;
				switch (opcion)//depende la opcion escogida entra en un sitio o en otro
				{
				case '1'://si pone 1
					cout << "Nombre del usuario nuevo: ";
					cin >> usuarioNuevo;//escribe el nuevo nombre de usuario
					for (int i = 0; i < usuarios.size(); i++)//no sale hasta que usuarios
					{
						while (usuarioNuevo == usuarios[i])//si el usuario que escribe existe
						{
							cout << "Este usuario ya existe!!!" << endl;
							cout << "Nombre del usuario nuevo: ";
							cin >> usuarioNuevo;//escribe otro nombre
						}
					}
					cout << "Escribe una contraseña para " << usuarioNuevo << ": ";//muestro el nombre del nuevo usuario
					cin >> contra;//escribe la contra del nuevo user
					cout << "Vuelva a escribir la contraseña: ";
					cin >> verificacionContra;//verifica la contra anterior
					while (contra != verificacionContra)//si no coinciden
					{
						cout << "Las contraseñas no coinciden" << endl;
						cout << "Escribe una contraseña para " << usuario << ": ";
						cin >> contra;//vuelve a escribir
						cout << "Vuelva a escribir la contraseña: ";
						cin >> verificacionContra;//vuelve a verificar
					}
					usuarios.push_back(usuarioNuevo);//meto el user en el vector usuarios
					contras.push_back(contra);//meto la contra en el vector de contras
					usuariosTareas.push_back(tareas);//inicializo el vector de queues para este usuario
					break;//sale del case
				case '2'://si la opcion es 2
					usuarioValido = false;
					while (usuarioValido == false)//mientras sea falso
					{
						cout << "A que usuario le quieres cambiar la contraseña: ";
						cin >> usuarioNuevo;//pongo al usuario que quiero cambiar la contra
						for (int i = 0; i < usuarios.size(); i++)//no para el bucle hasta que i sea igual a la medida de usuarios
						{
							if (usuarioNuevo == usuarios[i])//si encuentra el usuario
							{
								usuarioValido = true;//para salir del bucle
								cout << "Escribe una nueva contraseña para " << usuarioNuevo << ": ";//muestro el usuario al que se lo cambias
								cin >> contra;//escribe la nueva contra
								contras[i] = contra;//la reemplazo en el vector de contras
							}
						}
						if (usuarioValido == false)//si no ha encontrado el usuario
						{
							cout << "El usuario que has puesto no existe!!!" << endl;//le digo que no existe el usuario y no sale del bucle
						}
					}
					break;//sale del case
				case '3'://si selecciona 3
					usuarioValido = false;
					while (usuarioValido == false)//mientras sea falso
					{
						cout << "Escribe el usuario que quieres eliminar: ";
						cin >> usuarioNuevo;//escribe el usuario
						for (int i = 0; i < usuarios.size(); i++)//no para el bucle hasta que i sea igual a la medida de usuarios
						{
							if (usuarioNuevo == usuarios[i])//si encuentra el usuario
							{
								usuarioValido = true;//para salir del bucle
								cout << "Estas seguro que quieres eliminar el usuario " << usuarioNuevo << " (S/N): ";//muestro el usuario al que se lo cambias
								cin >> usuarioNuevo;//escribe S o N
								if (usuarioNuevo == "S")//si en S
								{
									usuarios.erase(usuarios.begin() + i);//borra el usuario
								}
								else if (usuarioNuevo == "N")//Si es N
								{
									break;//sale del bucle
								}
								while (usuarioNuevo != "S" && usuarioNuevo != "N")//si es diferente a S o N
								{
									cout << "Porfavor pon S o N: ";
									cin >> usuarioNuevo;//le vuelvo a pedir que escriba S o N
								}
							}
							else if (usuarioValido == false)//si no se ha verificado el usuario 
							{
								cout << "Este usuario no existe!!!" << endl;//le digo que no existe
							}
						}
					}
					break;//sale del case 3
				case '4'://si escoge 4
					volver = true;//sale del bucle y vuelve al menu principal
					break;//sale del case 4
				}
			}
			break;//sale del case 1
		case '2'://si escoge case 2
			usuarioValido = false;
			while (usuarioValido == false)//mientras sea falso
			{
				cout << "Escribe el usuario al que quieres acceder: ";
				cin >> usuario;//escribe el usuario
				for (int i = 0; i < usuarios.size(); i++)//no para el bucle hasta que i sea igual a la medida de usuarios
				{
					if (usuario == usuarios[i])//si existe el usuario
					{
						usuarioValido = true;//sale del bucle
						cout << "Escribe la contraseña para " << usuario << ": ";
						cin >> contra;//escribe la contra dle user
						while (contra != contras[i])//si la contra no coincide
						{
							cout << "La contrasena es incorrecta, intentalo de nuevo: ";
							cin >> contra;//la vuelve a escribie
						}
					}
				}
				if (usuarioValido == false)//si no encuentra el user repite todo
				{
					cout << "El usuario que has puesto no existe!!!" << endl;
				}
			}
			break;//sale del case 2
		case '3'://si escoge case 3
			volver = false;
			while (volver == false)//mientras sea falso
			{
				//muestro el menu
				cout << "1- Ver directorios" << endl;
				cout << "2- Crear directorios" << endl;
				cout << "3- Renombrar directorios" << endl;
				cout << "4- Eliminar directorio" << endl;
				cout << "5- Volver" << endl;
				cout << endl;
				cout << "Que quieres hacer: ";
				cin >> opcion;//escoge lo que quiere hacer
				cout << endl;
				cout << endl;
				switch (opcion)//depende la opcion escogida entra en un sitio o en otro
				{
				case '1'://si escoge 1
					cout << "Estos son tus directorios: " << endl;
					cout << endl;
					for (short i = 0; i < dir.size(); i++)//no para el bucle hasta que i sea igual a la medida de los directorios
					{
						cout << dir[i] << "/";//le muestro los directorios
					}
					cout << endl;
					cout << endl;
					break;//sale del case
				case '2'://si escoge 2
					dirValido = false;
					while (!dirValido)//mientras dirValido sea falso
					{
						short suma = 0;//creo un short que se llama suma (para sumar)
						cout << "Que directorio quieres crear(solo el nombre y un directorio, no poner /): ";
						cin >> dirNombre;//escribe el nombre del directorio
						for (short i = 0; i < dir.size(); i++)//no para el bucle hasta que i sea igual a la medida de los directorios
						{
							if (dirNombre[i] == '/')//si encuentra una barra
							{
								suma++;//sumo
							}
						}
						if (suma > 0)//si suma tiene mas de 0 
						{
							cout << "No pongas dos directorios o el simbolo /" << endl;//le digo que lo hace mal
							dirValido = false;//no sale del bucle
						} 
						else if (suma == 0)//si es igual a 0
						{
							dirValido = true;//sale del bucle
							dir.push_back(dirNombre);//meto el directorio en el vector
						}
					}
					break;//salgo del bucle
				case '3'://si escoge 3
					dirValido = false;
					while (!dirValido)//mientras sea falso
					{
						//muestro lo directorios
						cout << "Estos son tus directorios: " << endl;
						cout << endl;
						for (short i = 0; i < dir.size(); i++)//no para el bucle hasta que i sea igual a la medida de los directorios
						{
							cout << dir[i] << "/";//muestra los directorios
						}
						cout << endl;
						cout << endl;
						cout << "Que directorio quieres renombrar: ";
						cin >> dirNombre;//escribe el directorio que quiere cambiar
						for (int i = 0; i < dir.size(); i++)//no para el bucle hasta que i sea igual a la medida de los directorios
						{
							if (dirNombre == dir[i])//si el nombre coincide
							{
								cout << "Que nombre le quieres poner: ";
								cin >> dirNombre;//escribes el nombre nuevo
								dir[i] = dirNombre;//lo escribo
								dirValido = true;//sale del bucle
							}
						}
						if (dirValido == false)//;si no existe el directorio
						{
							cout << "Este directorio no existe." << endl;//le digo que lo escribe mal
							cout << endl;
						}
					}
					break;//sale del case 3
				case '4'://escoge el caso 4
					cout << "ESTA OPCION NO ESTA DISPONIBLE :)" << endl;//pues eso no esta disponible
					break;//sale del caso 4
				case '5'://escoge el caso 5
					volver = true;//sale del bucle y vuelve al menu principal
					break;//sale del caso 5
				}

			}
			break;//sale del caso 3
		case '4'://si escoge 4
			volver = false;
			while (volver == false)//mientras volver sea falso
			{
				string tarea;//variable string para escribir las tareas
				char user;//char para alamcenar la posicion del usuario
				for (short i = 0; i < usuarios.size(); i++)//no para el bucle hasta que i sea igual a la medida de usuarios
				{
					if (usuario == usuarios[i])//si coincide el usuario
					{
						user = i;//guardo la posicion del user en user
					}
				}
				cout << "Estas logueado como " << usuario << endl; cout << endl;//muestro con que user estas logueado
				//muestro el menu
				cout << "1- Crear tarea" << endl;
				cout << "2- Mostrar siguiente tarea" << endl;
				cout << "3- Completar tarea" << endl;
				cout << "4- Volver" << endl;
				cout << endl; cout << "Que quieres hacer: ";
				cin >> opcion;//escoge lo que quiere hacer
				cout << endl;
				cout << endl;

				switch (opcion)//depende la opcion escogida entra en un sitio o en otro
				{
				case '1'://si escoge 1
					cout << "Que tarea quieres escribir: ";
					cin >> tarea;//escribe la tarea
					usuariosTareas[user].push(tarea);//lo guardo en la posicion del usuario en el vector de queue
					break;//sale del case 1
				case '2'://si escoge 2
					if (!usuariosTareas[user].empty())//si no esta vacio
					{
						cout << "La tarea que tienes que hacer es: " << usuariosTareas[user].front() << endl;//muestra la primera tarea
					}
					else//si esta vacio
					{
						cout << "No hay tareas." << endl;//le digo que no hay tareas
					}
					break;//salgo del case 2
				case '3'://si escoge 3
					if (!usuariosTareas[user].empty())//si no esta vacio
					{
						cout << "Acabas de completrar esta tarea: " << usuariosTareas[user].front() << endl;//muestro la tarea
						usuariosTareas[user].pop();//borro la tarea mostrada
					}
					else//si esta vacio
					{
						cout << "No hay tareas." << endl;//le muestro que esta vacio
					}
					break;//salir de case 3
				case '4'://si escoge 4
					volver = true;//sale del bucle y vuelve al menu principal
					break;//sale del case 4
				}
			}
			break;//sale del case 4
		case '5'://si escoge 5
			salir = true;//sale del bucle y del programa
			break;//sale de 5;
		}
	}
}
