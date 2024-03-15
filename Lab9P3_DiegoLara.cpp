#include <iostream>
#include <locale>
#include "Concierto.h"
#include "GestorVentas.h"
void ejercicio_1() {
	string nombre = "";
	double precio = 0.0;
	string fecha = "";
	int codigo = 0;
	int deleteConcierto = 0;
	int indiceVender = 0;
	int cantidadEntradas = 0;
	GestorVentas* administrador = new GestorVentas();
	bool ejercicio1 = true;
	int opcion = 0;
	while (ejercicio1) {
		cout << "1. Agregar Concierto" << endl;
		cout << "2. Eliminar Concierto" << endl;
		cout << "3. Vender Entrada" << endl;
		cout << "4. Listar Conciertos" << endl;
		cout << "5. Cargar Conciertos desde CSV" << endl;
		cout << "6. Guardar Conciertos en CSV" << endl;
		cout << "7. Salir" << endl;
		cout << "Seleccione una opcion: " << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "Ingrese el nombre de la banda: " << endl;
			getline(cin, nombre);
			cout << "Ingrese el precio de la entrada: " << endl;
			cin >> precio;
			cout << "Ingrese la fecha del concierto (dd/mm/aaaa): " << endl;
			getline(cin, fecha);
			cout << "Ingrese el codigo: " << endl;
			cin >> codigo;
			for (int i = 0; i < administrador->getConciertosDisponibles().size(); i++)
			{
				while (administrador->getConciertosDisponibles()[i]->getCodigo() == codigo) {
					cout << "Ingrese un codigo que no exista localmente." << endl;
					cin >> codigo;
				}
			}
			cout << "Concierto Agregado Correctamente" << endl;
			administrador->getConciertosDisponibles().push_back(new Concierto(nombre, precio, fecha, codigo));
			break;
		case 2:
			if (administrador->getConciertosDisponibles().empty())// validacion
			{
				cout << "No hay ningun concierto disponible, cargue los conciertos guardados o agregue un concierto" << endl;
			}
			else {
				for (int i = 0; i < administrador->getConciertosDisponibles().size(); i++)
				{
					administrador->getConciertosDisponibles()[i]->toString();
				}
				cout << "Seleccione el concierto a eliminar: " << endl;
				cin >> deleteConcierto;
				while (administrador->getConciertosDisponibles().size() < deleteConcierto) {
					cout << "Elija un concierto que no se pase del indice que existen" << endl;
					cin >> deleteConcierto;
				}
				administrador->eliminarConcierto(deleteConcierto);
				cout << "Concierto eliminado exitosamente" << endl;
			}
			break;
		case 3:
			if (administrador->getConciertosDisponibles().empty())// validacion
			{
				cout << "No hay ningun concierto disponible, cargue los conciertos guardados o agregue un concierto" << endl;
			}
			else {
				for (int i = 0; i < administrador->getConciertosDisponibles().size(); i++)
				{
					administrador->getConciertosDisponibles()[i]->toString();
				}
				cout << "Ingrese el indice del concierto al que desea vender entradas: " << endl;
				cin >> indiceVender;
				while (administrador->getConciertosDisponibles().size() < indiceVender) {
					cout << "Elija un concierto que no se pase del indice que existen" << endl;
					cin >> indiceVender;
				}
				cout << "Ingrese la cantidad de entradas a vender: " << endl;
				cin >> cantidadEntradas;
				while (cantidadEntradas <= 0) {
					cout << "Ingrese numeros mayores a 0" << endl;
					cin >> cantidadEntradas;
				}
				administrador->venderEntrada(indiceVender, cantidadEntradas);
				cout << "Resumen de Venta" << endl << endl;
				cout << "-----------------" << endl;
				cout << "Banda: " << administrador->getConciertosDisponibles()[indiceVender]->getNombreBanda() << endl;
				cout << "Fecha: " << administrador->getConciertosDisponibles()[indiceVender]->getFechaConcierto() << endl;
				cout << "Entradas compradas: " << cantidadEntradas;
				cout << "Total Pagado: $" << administrador->getConciertosDisponibles()[indiceVender]->getPrecioEntrada() * cantidadEntradas << endl;
			}
			break;
		case 4:
			if (administrador->getConciertosDisponibles().empty())// validacion
			{
				cout << "No hay ningun concierto disponible, cargue los conciertos guardados o agregue un concierto" << endl;
			}
			else {
				for (int i = 0; i < administrador->getConciertosDisponibles().size(); i++)
				{
					administrador->getConciertosDisponibles()[i]->toString();
				}
			}
			break;
		case 5:
			administrador->cargarConciertosCSV();
			break;
		case 6:
			if (administrador->getConciertosDisponibles().empty())// validacion
			{
				cout << "No hay ningun concierto disponible agregue un concierto para poder guardarlo" << endl;
			}
			else {
				administrador->guardarConciertosCSV();
			}
			break;
		case 7:
			ejercicio1 = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
void menu() {
	int option = 0;
	bool menu = true;
	while (menu) {
		cout << "Ejercicio Práctico 1 – Taquilla de Conciertos" << endl;
		cout << "2. Salir" << endl;
		cin >> option;
		switch (option) {
		case 1:
			ejercicio_1();
			break;
		case 2:
			menu = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "spanish");
	menu();
}