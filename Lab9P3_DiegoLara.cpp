#include <iostream>
#include <locale>
#include "Concierto.h"
#include "GestorVentas.h"
void ejercicio_1() { // Variables
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
		case 1: // Agregar un nuevo concierto a el vector de la clase admin
			cout << "Ingrese el nombre de la banda: " << endl;
			cin.ignore();
			getline(cin, nombre);
			cout << "Ingrese el precio de la entrada: " << endl;
			cin >> precio;
			cout << "Ingrese la fecha del concierto (dd/mm/aaaa): " << endl;
			cin.ignore();
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
			administrador->agregarConcierto(new Concierto(nombre, precio, fecha, codigo));
			break;
		case 2: // Eliminar un concierto existente
			if (administrador->getConciertosDisponibles().empty())// validacion
			{
				cout << "No hay ningun concierto disponible, cargue los conciertos guardados o agregue un concierto" << endl;
			}
			else {
				administrador->listarConciertos();
				cout << "Seleccione el concierto a eliminar: " << endl;
				cin >> deleteConcierto;
				while (administrador->getConciertosDisponibles().size() < deleteConcierto-1) {
					cout << "Elija un concierto que no se pase del indice que existen" << endl;
					cin >> deleteConcierto;
				}
				administrador->eliminarConcierto(deleteConcierto-1);
				cout << "Concierto eliminado exitosamente" << endl;
			}
			break;
		case 3: // Comprar entradas a un concierto existente
			if (administrador->getConciertosDisponibles().empty())// validacion
			{
				cout << "No hay ningun concierto disponible, cargue los conciertos guardados o agregue un concierto" << endl;
			}
			else {
				administrador->listarConciertos();
				cout << "Ingrese el indice del concierto al que desea vender entradas: " << endl;
				cin >> indiceVender;
				while (administrador->getConciertosDisponibles().size() < indiceVender-1) {
					cout << "Elija un concierto que no se pase del indice que existen" << endl;
					cin >> indiceVender;
				}
				cout << "Ingrese la cantidad de entradas a vender: " << endl;
				cin >> cantidadEntradas;
				while (cantidadEntradas <= 0) {
					cout << "Ingrese numeros mayores a 0" << endl;
					cin >> cantidadEntradas;
				}
				administrador->venderEntrada(indiceVender-1, cantidadEntradas);
				cout << "Resumen de Venta" << endl << endl;
				cout << "-----------------" << endl;
				cout << "Banda: " << administrador->getConciertosDisponibles()[indiceVender-1]->getNombreBanda() << endl;
				cout << "Fecha: " << administrador->getConciertosDisponibles()[indiceVender-1]->getFechaConcierto() << endl;
				cout << "Entradas compradas: " << cantidadEntradas << endl;
				cout << "Total Pagado: $" << administrador->getConciertosDisponibles()[indiceVender-1]->getPrecioEntrada() * cantidadEntradas << endl;
			}
			break;
		case 4: // Listar los conciertos
			if (administrador->getConciertosDisponibles().empty())// validacion
			{
				cout << "No hay ningun concierto disponible, cargue los conciertos guardados o agregue un concierto" << endl;
			}
			else {
					administrador->listarConciertos();
			}
			break;
		case 5: // Cargar los conciertos al vector de la clase admin
			administrador->cargarConciertosCSV();
			cout << "Se ha cargado exitosamente" << endl;
			break;
		case 6: // Guardar y reescribir los conciertos locales hacia el archivo
			if (administrador->getConciertosDisponibles().empty())// validacion
			{
				cout << "No hay ningun concierto disponible agregue un concierto para poder guardarlo" << endl;
			}
			else {
				administrador->guardarConciertosCSV();
				cout << "Se ha guardado exitosamente" << endl;
			} 
			break;
		case 7: // Salir
			ejercicio1 = false;
			delete administrador;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
void menu() { // Menu
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