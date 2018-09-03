#include <iostream>
using namespace std;

int opcion;


void Menu();
void Lista();
void Agregar();
void Quitar();

void main() {
	Menu(); 

	cout << "\nApagando equipo" << endl;

	system("pause");
}


void Menu() {
	cout << "Bienvenido al menu, seleccione una opcion \n1.-Ver lista \n2.-Agregar contacto \n3.-Eliminar contacto \n4.- Salir" << endl;

	cin >> opcion;

	switch (opcion) {
	case 1: Lista();
		break;
	case 2: Agregar();
		break;
	case 3: Quitar();
		break;
	case 4: cout << "saliendo";
		break;
	default: cout << "opcion no valida\n" << endl;
		Menu();
		break;
	}
}
void Lista() {
	cout << "estas en la lista \nsalir?";

	cin >> opcion;

	if (opcion == 1) {
		Menu();
	}
	else {
		cout << "no valido, intente de nuevo\n";
			Lista();
	}

}

void Agregar() {
	cout << "aqui puedes agregar contactos \nsalir?";

	cin >> opcion;

	if (opcion == 1) {
		Menu();
	}
	else {
		cout << "no valido, intente de nuevo\n";
		Agregar();
	}
}

void Quitar() {
	cout << "aqui puedes quitar contactos \nsalir?";

	cin >> opcion;

	if (opcion == 1) {
		Menu();
	}
	else {
		cout << "no valido, intente de nuevo\n";
		Quitar();
	}
}