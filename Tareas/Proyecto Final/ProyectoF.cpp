#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
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
float califraw;
Alumno P[20];

void registrar();
void mod();
void mostrar();
void menu();
void instruc();
void edit(int x);
void delet(int x);
void renovar();


void main(){
	locale::global(locale("spanish"));
	cont = 0; 
	ifstream lista;
	lista.open("memoriaalumnos.data", ios::binary);
	lista.read((char*)&P, sizeof(P));
	lista.close();
	for (int i = 0; i < 20; i++)
	{
		if (P[i].matricula != 0) {
			cont++;
		}
	}
	menu();
}

void menu(){
	system("cls");
	cout << "bienvenidos al sistema \n1.-instrucci�n \n2.-registrar alumno \n3.-buscar y editar \n4.-mostrar alumnos \n5.-salir" << endl;
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
	default:
		break;
	}
}

void instruc() {
	system("cls");
	cout << "Por medio del men� central usted seleccionar� la opci�n" << endl;
	cout << "que usted desee, tecleando el n�mero al cual esta" << endl;
	cout << "relacionada la opci�n." << endl << endl;
	cout << "En la opci�n de registrar podr� agregar un alumno a la lista," << endl;
	cout << "a�adir� cada uno de sus datos en el orden por defecto programado" << endl;
	cout << "y al finalizar volver� al men�." << endl << endl;
	cout << "En buscar y editar, podr� buscar a cualquier usuario por su" << endl;
	cout << "matr�cula, al ser encontrado podr� escoger entre editarlo o" << endl;
	cout << "eliminarlo." << endl;
	cout << "Si desea editarlo, escoger� de una lista el dato a editar de su" << endl;
	cout << "elecci�n, al acabar con ese dato, puede finalizar o editar otro" << endl;
	cout << "m�s." << endl;
	cout << "Con la opci�n de eliminar, se le preguntar� si desea eliminarlo" << endl;
	cout << "definitivamente o si quiere dejar el registro del alumno, s�" << endl;
	cout << "escoge dejar el alumno, se devolver� directamente al men� sin m�s." << endl << endl;
	cout << "En Mostrar alumnos, se mostraran los datos de todos los alumnos" << endl;
	cout << "en el orden en que fueron registrados." << endl;
	cout << "Y con la opci�n salir, cerrar� el programa una vez acabara con todo.";
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
	cout << "Correo electr�nico ";
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
	cout << "Matricula �generar(1) o ingresar(2)? ";
	int opm;
	cin >> opm;
	bool unica = false;
	while (opm != 1 && opm != 2) {
		cout << "ingrese otra opci�n ";
		cin >> opm;
	}
	if (opm == 1) {
		P[cont].matricula = cont + 1;
	}
	else if (opm == 2) {
		cout << "Ingrese matr�cula ";
		cin >> P[cont].matricula;
	}
	if (cont == 0) {
		unica = true;
	}
	else {
		while (!unica) {
			for (int i = 0; i < cont; i++) {
				if (P[cont].matricula == P[i].matricula) {
					cout << "Matr�cula ya existente, ingrese otra: ";
					cin >> P[cont].matricula;
				}
				else {
					unica = true;
				}
			}
		}
	}
	cin.ignore();
	cout << "Casa y calle ";
	getline(cin, P[cont].dircasa);
	cout << "Colonia ";
	getline(cin, P[cont].dircolon);
	cout << "Califiaci�n del primer parcial ";
	cin >> P[cont].calif1;
	while (P[cont].calif1 > 100 || P[cont].calif1 < 0) {
		if (P[cont].calif1 > 100 || P[cont].calif1 < 0) {
			cout << "\nNo es valido, ponga otra calificaci�n ";
		}
		cin >> P[cont].calif1;
	}
	cout << "Calificaci�n del segundo parcial ";
	cin >> P[cont].calif2;
	while (P[cont].calif2 > 100 || P[cont].calif2 < 0) {
		if (P[cont].calif2 > 100 || P[cont].calif2 < 0) {
			cout << "\nNo es valido, ponga otra calificaci�n ";
		}
		cin >> P[cont].calif2;
	}
	cout << "Califiaci�n del tercer parcial ";
	cin >> P[cont].calif3;
	while (P[cont].calif3 > 100 || P[cont].calif3 < 0) {
		if (P[cont].calif3 > 100 || P[cont].calif3 < 0) {
			cout << "\nNo es valido, ponga otra calificaci�n ";
		}
		cin >> P[cont].calif3;
	}
	califraw = (P[cont].calif1*0.3) + (P[cont].calif2*0.45) + (P[cont].calif3*0.25);
	P[cont].califtotal = (round(califraw * 100)) / 100;
	cont++;
	renovar();
	menu();
}

void mostrar(){
	system("cls");
	int i;
	for (i = 0; i < cont; i++) {
		cout << "Nombre: " << P[i].nombre << endl;
		cout << "Apellido: " << P[i].apellido << endl;
		cout << "Matr�cula: " << P[i].matricula << endl;
		cout << "Correo: " << P[i].correo << endl;
		cout << "Tel�fono: " << P[i].telefono << endl;
		cout << "Direcci�n: Colonia " << P[i].dircolon << ", " << P[i].dircasa << endl;
		cout << "Calificaci�n del primer parcial: " << P[i].calif1 << endl;
		cout << "Calificaci�n del segundo parcial: " << P[i].calif2 << endl;
		cout << "Calificaci�n del tercer parcial: " << P[i].calif3 << endl;
		cout << "Calificaci�n final: " << P[i].califtotal << endl << endl;
	}
	system("pause>nul");
	menu();
}

void mod() {
	system("cls");
	cout << "�a quien deseas buscar? (Matricula): ";
	int buscado, elegido, opmod;
	bool encontrado = false;
	cin >> buscado;
	for (int i = 0; i < cont; i++) {
		if (P[i].matricula == buscado) {
			cout << "Se encontro a " << P[i].matricula << "\nNombre: " << P[i].nombre << "\nApellido: " << P[i].apellido;
			elegido = i;
			encontrado = true;
			break;
		}
	}
	if (!encontrado) {
		cout << "\nno se encontr�, caballero :(" << endl;
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
		cout << "\n�Que desea hacer con el usuario " << P[elegido].matricula << "?" << endl;
		cout << "1.-Modificar \n2.-Eliminar\n";
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
	cout << "�que desea editar del usuario " << P[x].matricula << "?";
	cout << "\n1.-Nombre \n2.-Apellido \n3.-Correo \n4.-Tel�fono \n5.-Calle \n6.-Colonia \n7.-primer parcial \n8.-segundo parcial \n9.-tercer parcial\n";
	int opedit, x2;
	bool califnueva = false, condition1, condition2, condition3;
	cin >> opedit;
	system("cls");
	switch (opedit) {
	case 1: cout << "Inserte el nuevo nombre: ";
		cin.ignore();
		getline(cin, P[x].nombre);
		break;
	case 2: cout << "Inserte nuevo apellido: ";
		cin.ignore();
		getline(cin, P[x].apellido);
		break;
	case 3: cout << "Inserte nuevo correo electr�nico: ";
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
	case 7: cout << "Califiaci�n del primer parcial ";
		cin >> P[x].calif1;
		while (P[x].calif1 > 100 || P[x].calif1 < 0) {
			if (P[x].calif1 > 100 || P[x].calif1 < 0) {
				cout << "\nNo es valido, ponga otra calificaci�n ";
			}
			cin >> P[x].calif1;
		}
		califnueva = true;
		break;
	case 8: cout << "Califiaci�n del segundo parcial ";
		cin >> P[x].calif2;
		while (P[x].calif2 > 100 || P[x].calif2 < 0) {
			if (P[x].calif2 > 100 || P[x].calif2 < 0) {
				cout << "\nNo es valido, ponga otra calificaci�n ";
			}
			cin >> P[x].calif2;
		}
		califnueva = true;
		break;
	case 9: cout << "Califiaci�n del tercer parcial ";
		cin >> P[x].calif3;
		while (P[x].calif3 > 100 || P[x].calif3 < 0) {
			if (P[x].calif3 > 100 || P[x].calif3 < 0) {
				cout << "\nNo es valido, ponga otra calificaci�n ";
			}
			cin >> P[x].calif3;
		}
		califnueva = true;
		break;
	}
	if (califnueva) {
		califraw = (P[x].calif1*0.3) + (P[x].calif2*0.45) + (P[x].calif3*0.25);
		P[x].califtotal = (round(califraw * 100)) / 100;
	}
	renovar();
	system("cls");
	cout << "deseas editar algo m�s (1) o regresar al men� (2): ";
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
	cout << "�desea eliminar a " << P[x].nombre << ", (" << P[x].matricula << ") ? (1-Si/2-No): ";
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
		renovar();
		menu();
	}
	else if (opdelet == 2) {
		menu();
	}
}

void renovar() {
	ofstream lista;
	lista.open("memoriaalumnos.data", ios::binary);
	lista.write((char*)&P, sizeof(P));
	lista.close();
	}