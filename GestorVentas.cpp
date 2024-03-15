#include "GestorVentas.h"

GestorVentas::GestorVentas()
{
}

GestorVentas::GestorVentas(vector<Concierto*> conciertosDisponibles)
{
	this->conciertosDisponibles = conciertosDisponibles;
}

GestorVentas::~GestorVentas()
{
}

vector<Concierto*> GestorVentas::getConciertosDisponibles()
{
	return this->conciertosDisponibles;
}

void GestorVentas::setConciertosDisponibles(vector<Concierto*> conciertosDisponibles)
{
	this->conciertosDisponibles = conciertosDisponibles;
}

void GestorVentas::agregarConcierto(Concierto* nuevoConcierto)
{
	this->conciertosDisponibles.push_back(nuevoConcierto);
}

void GestorVentas::eliminarConcierto(int indiceConcierto)
{
	this->conciertosDisponibles.erase(this->conciertosDisponibles.begin() + indiceConcierto); // eliminar la cuenta
}

void GestorVentas::venderEntrada(int indiceConcierto, int cantidad)
{
	double totalTemp = 0;
	totalTemp = this->conciertosDisponibles[indiceConcierto]->getPrecioEntrada() * cantidad;
	this->conciertosDisponibles[indiceConcierto]->setEntradasVendidas(this->conciertosDisponibles[indiceConcierto]->getEntradasVendidas() + cantidad);
	this->conciertosDisponibles[indiceConcierto]->setTotalRecaudado(this->conciertosDisponibles[indiceConcierto]->getTotalRecaudado() + totalTemp);
}

void GestorVentas::listarConciertos()
{
	if (this->conciertosDisponibles.empty())// validacion
	{
		cout << "No hay ningun concierto disponible, cargue los conciertos guardados o agregue un concierto" << endl;
	}
	else {
		for (int i = 0; i < this->conciertosDisponibles.size(); i++) {
			cout << "Cuenta: " << (i + 1) << endl;
			this->conciertosDisponibles[i]->toString(); // mostrar los conciertos disponibles
			cout << endl;
		}
	}
}

void GestorVentas::guardarConciertosCSV()
{
}

void GestorVentas::cargarConciertosCSV()
{
}

