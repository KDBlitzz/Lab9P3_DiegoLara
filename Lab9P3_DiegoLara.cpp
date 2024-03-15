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
    GestorVentas* administrador = new GestorVentas();
    bool ejercicio1 = true;
    int opcion = 0;
    while (ejercicio1) {
        cout << "1. Agregar Concierto" << endl;
        cout << "2. Eliminar Concierto" << endl;
        cout << "3. Vender Entrada" << endl;
        cout << "4. Listar Conciertos" << endl;
        cout << "5. Carcar Conciertos desde CSV" << endl;
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
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
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