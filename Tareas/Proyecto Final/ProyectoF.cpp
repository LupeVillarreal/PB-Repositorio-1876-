#include <iostream>
#include <string>
using namespace std;

struct Alumno
{
	string nombre;
	string apellido;
	char correo[30];
	char telefono[12];
	int matricula;
	float calif1;
	float calif2;
	float calif3;
	float califtotal;
	string dircasa;
	string dircolon;
};

int cont, opc;
Alumno P[20];

void registrar();
void mod();
void mostrar();
void menu();
void instruc();
void edit(int x);
void delet(int x);


void main(){
	locale::global(locale("spanish"));
	cont = 0;
	menu();
}

void menu(){
	system("cls");
	cout << "bienvenidos al sistema \n1.-instrucción \n2.-registrar alumno \n3.-buscar y editar \n4.-mostrar alumnos \n5.-salir" << endl;
	cout << "tu opcion es: ";
	cin >> opc;
	switch (opc) {
	case 1: instruc();
		break;
	case 2: registrar();
		break;
	case 3: mod();
		break;
	case 4: mostrar();
		break;
	default: break;
	}
}

void instruc() {
	system("cls");
	cout << "desde el menu puedes escoger una de las opciones, por medio de registro podrias agregar los datos de un alumno" << endl << "por medio de eliminar podras eliminarlo de la lista, por medio de calificaciones ingresaras sus notas, cuando acabes podras darle a salir";
	system("pause>nul");
	menu();
}

void registrar() {
	system("cls");
	cin.ignore();
	cout << "Nombre ";
	getline(cin, P[cont].nombre);
	cout << "Apellidos ";
	getline(cin, P[cont].apellido);
	cout << "Correo electrónico ";
	bool condition1 = false, condition2 = false;
	int i, x = 0;
	while (!condition1 || !condition2) {
		cin >> P[cont].correo;
		for (i = 0; i < 30; i++) {
			if (P[cont].correo[i] == 64) {
				condition1 = true;
				break;
				x = i;
			}
		}
		for (i = x; i < 30; i++) {
			if (P[cont].correo[i] == 46) {
				if (P[cont].correo[i + 1] == 99) {
					if (P[cont].correo[i + 2] == 111) {
						if (P[cont].correo[i + 3] == 109) {
							condition2 = true;
							break;
						}
					}
				}
			}
		}
		if (!condition1 || !condition2) {
			cout << "correo incorrecto, vuelva a registrar los datos\n";
		}
	}
	cout << "Telefono ";
	x = 0;
	bool condition3 = false;
	while (!condition3) {
		cin >> P[cont].telefono;
		for (i = 0; i < 12; i++) {
			if (P[cont].telefono[i] >= 48 && P[cont].telefono[i] <= 57) {
				x++;
			}
		}
		if (x >= 8) {
			condition3 = true;
		}
		if (!condition3) {
			cout << "telefono incorrecto, vuelva a registrar los datos\n";
		}
	}
	cout << "Matricula ¿generar(0) o ingresar(1)? ";
	int opm;
	cin >> opm;
	while (opm != 0 && opm != 1) {
		cout << "ingrese otra opción ";
		cin >> opm;
	}
	if (opm == 0) {
		P[cont].matricula = cont + 1;
	}
	else if (opm == 1) {
		cout << "Ingrese matrícula ";
		cin >> P[cont].matricula;
	}
	cin.ignore();
	cout << "Casa y calle ";
	getline(cin, P[cont].dircasa);
	cout << "Colonia ";
	getline(cin, P[cont].dircolon);
	cout << "Califiación del primer parcial ";
	cin >> P[cont].calif1;
	while (P[cont].calif1 > 100 || P[cont].calif1 < 0) {
		if (P[cont].calif1 > 100 || P[cont].calif1 < 0) {
			cout << "\nNo es valido, ponga otra calificación ";
		}
		cin >> P[cont].calif1;
	}
	cout << "Calificación del segundo parcial ";
	cin >> P[cont].calif2;
	while (P[cont].calif2 > 100 || P[cont].calif2 < 0) {
		if (P[cont].calif2 > 100 || P[cont].calif2 < 0) {
			cout << "\nNo es valido, ponga otra calificación ";
		}
		cin >> P[cont].calif2;
	}
	cout << "Califiación del tercer parcial ";
	cin >> P[cont].calif3;
	while (P[cont].calif3 > 100 || P[cont].calif3 < 0) {
		if (P[cont].calif3 > 100 || P[cont].calif3 < 0) {
			cout << "\nNo es valido, ponga otra calificación ";
		}
		cin >> P[cont].calif3;
	}
	P[cont].califtotal = (P[cont].calif1*0.3) + (P[cont].calif2*0.45) + (P[cont].calif3*0.25);
	cont++;
	menu();
}

void mostrar(){
	system("cls");
	int i;
	for (i = 0; i < cont; i++) {
		cout << "Nombre: " << P[i].nombre << endl;
		cout << "Apellido: " << P[i].apellido << endl;
		cout << "Matrícula: " << P[i].matricula << endl;
		cout << "Correo: " << P[i].correo << endl;
		cout << "Teléfono: " << P[i].telefono << endl;
		cout << "Dirección: Colonia " << P[i].dircolon << ", " << P[i].dircasa << endl;
		cout << "Calificación del primer parcial: " << P[i].calif1 << endl;
		cout << "Calificación del segundo parcial: " << P[i].calif2 << endl;
		cout << "Calificación del tercer parcial: " << P[i].calif3 << endl;
		cout << "Calificación final: " << P[i].califtotal << endl << endl;
	}
	system("pause>nul");
	menu();
}

void mod() {
	system("cls");
	cout << "¿a quien deseas buscar? (Matricula): ";
	int buscado, elegido, opmod;
	bool encontrado = false;
	cin >> buscado;
	for (int i = 0; i < cont; i++) {
		if (P[i].matricula == buscado) {
			cout << "Se encontro a " << P[i].matricula << "\nNombre: " << P[i].nombre << "\nApellido: " << P[i].apellido << "\n¿Que desea hacer? ";
			elegido = i;
			encontrado = true;
			break;
		}
	}
	if (!encontrado) {
		cout << "no se encontró, caballero :(" << endl;
		cout << "volver a intentar(1) o regresar(2): ";
		cin >> opmod;
		while (opmod != 1 && opmod != 2) {
			cout << "no valido, vuelva a seleccionar: ";
			cin >> opmod;
		}
		switch (opmod)
		{
		case 1: mod();
			break;
		case 2: menu();
			break;
		}
	}
	else {
		cout << "\n¿Que desea hacer con el usuario\n" << P[elegido].matricula << "?" << endl;
		cout << "1.- Modificar \n 2.-Eliminar\n";
		cin >> opmod;
		while (opmod != 1 && opmod != 2) {
			cout << "no valido, vuelva a seleccionar: ";
			cin >> opmod;
		}
		switch (opmod)
		{
		case 1: edit(elegido);
			break;
		case 2: delet(elegido);
			break;
		}
	}
}

void edit(int x) {
	system("cls");
	cout << "¿que desea editar del usuario " << P[x].matricula << "?";
	cout << "\n1.-Nombre \n2.-Apellido \n3.-Correo \n4.-Teléfono \n5.-Calle \n6.-Colonia \n7.-primer parcial \n8.-segundo parcial \n9.-tercer parcial\n";
	int opedit, x2;
	bool califnueva = false, condition1, condition2, condition3;
	cin >> opedit;
	switch (opedit) {
	case 1: cout << "Inserte el nuevo nombre: ";
		cin.ignore();
		getline(cin, P[x].nombre);
		break;
	case 2: cout << "Inserte nuevo apellido: ";
		cin.ignore();
		getline(cin, P[x].apellido);
		break;
	case 3: cout << "Inserte nuevo correo electrónico: ";
		condition1 = false, condition2 = false;
		int i;
		x2 = 0;
		while (!condition1 || !condition2) {
			cin >> P[x].correo;
			for (i = 0; i < 30; i++) {
				if (P[x].correo[i] == 64) {
					condition1 = true;
					break;
					x2 = i;
				}
			}
			for (i = x2; i < 30; i++) {
				if (P[x].correo[i] == 46) {
					if (P[x].correo[i + 1] == 99) {
						if (P[x].correo[i + 2] == 111) {
							if (P[x].correo[i + 3] == 109) {
								condition2 = true;
								break;
							}
						}
					}
				}
			}
			if (!condition1 || !condition2) {
				cout << "correo incorrecto, vuelva a registrar los datos\n";
			}
		}
		break;
	case 4: cout << "Inserte nuevo telefono: ";
		x2 = 0;
		condition3 = false;
		while (!condition3) {
			cin >> P[x].telefono;
			for (i = 0; i < 12; i++) {
				if (P[x].telefono[i] >= 48 && P[x].telefono[i] <= 57) {
					x2++;
				}
			}
			if (x2 >= 8) {
				condition3 = true;
			}
			if (!condition3) {
				cout << "telefono incorrecto, vuelva a registrar los datos\n";
			}
		}
		break;
	case 5: cout << "Ingresar nueva casa y calle: ";
		cin.ignore();
		getline(cin, P[x].dircasa);
		break;
	case 6: cout << "Ingresar nueva colonia: ";
		cin.ignore();
		getline(cin, P[x].dircolon);
		break;
	case 7: cout << "Califiación del primer parcial ";
		cin >> P[x].calif1;
		while (P[x].calif1 > 100 || P[x].calif1 < 0) {
			if (P[x].calif1 > 100 || P[x].calif1 < 0) {
				cout << "\nNo es valido, ponga otra calificación ";
			}
			cin >> P[x].calif1;
		}
		califnueva = true;
		break;
	case 8: cout << "Califiación del segundo parcial ";
		cin >> P[x].calif2;
		while (P[x].calif2 > 100 || P[x].calif2 < 0) {
			if (P[x].calif2 > 100 || P[x].calif2 < 0) {
				cout << "\nNo es valido, ponga otra calificación ";
			}
			cin >> P[x].calif2;
		}
		califnueva = true;
		break;
	case 9: cout << "Califiación del tercer parcial ";
		cin >> P[x].calif3;
		while (P[x].calif3 > 100 || P[x].calif3 < 0) {
			if (P[x].calif3 > 100 || P[x].calif3 < 0) {
				cout << "\nNo es valido, ponga otra calificación ";
			}
			cin >> P[x].calif3;
		}
		califnueva = true;
		break;
	}
	if (califnueva) {
		P[x].califtotal = (P[x].calif1*0.3) + (P[x].calif2*0.45) + (P[x].calif3*0.25);
	}
	cout << "deseas editar algo más (1) o regresar al menú (2): ";
		cin >> opedit;
	while (opedit != 1 && opedit != 2) {
		cout << "no valido, vuelva a seleccionar: ";
		cin >> opedit;
	}
	switch (opedit)
	{
	case 1: edit(x);
		break;
	case 2: menu();
		break;
	}

}

	void delet(int x) {
	system("cls");
	int opdelet;
	cout << "¿desea eliminar a " << P[x].nombre << ", (" << P[x].matricula << ") ? (1-Si/2-No): ";
	cin >> opdelet;
	while (opdelet != 1 && opdelet != 2) {
		cout << "no valido, vuelva a seleccionar: ";
		cin >> opdelet;
	}
	if (opdelet == 1 && cont != 0) {
		for (int i = x; i < cont; i++) {
			P[x] = P[x + 1];
		}
		cont--;
		cout << "se a eliminado exitosamente" << endl;
		system("pause>nul");
		menu();
	}
	else if (opdelet == 2) {
		menu();
	}
}