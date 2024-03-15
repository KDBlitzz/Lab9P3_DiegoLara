#include <iostream>
#include <locale>
#include "Concierto.h"
void ejercicio_1() {
    bool ejercicio1 = true;
    int opcion = 0;
    while (ejercicio1) {

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