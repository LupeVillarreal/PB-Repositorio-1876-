#include <iostream>
#include <string>
using namespace std;

struct Alumno
{
	string nombre;
	string apellido;
	char correo[30];
	char telefono[12];
	char matricula[7];
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
	int contador = 0;
	cout << "Matrícula ";
	condition1 = false;
	while (!condition1) {
		cin >> P[cont].matricula;
		for (i = 0; i < 7; i++) {
			if (P[cont].matricula[i] >= 48 && P[cont].matricula[i] <= 57) {
				contador++;
			}
		}
		if (contador == 7) {
			condition1 = true;
		}
		else {
			cout << "matricula incorrecta, vovler a registrar\n";
		}
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

}