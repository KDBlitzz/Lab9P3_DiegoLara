#include "Concierto.h"

Concierto::Concierto()
{
}

Concierto::Concierto(string nombreBanda, double precioEntrada, string fechaConcierto, int codigo)
{
	this->nombreBanda = nombreBanda;
	this->precioEntrada = precioEntrada;
	this->fechaConcierto = fechaConcierto;
	this->codigo = codigo;
	 
}

Concierto::~Concierto()
{
}

string Concierto::getNombreBanda()
{
	return this->nombreBanda;
}

void Concierto::setNombreBanda(string nombreBanda)
{
	this->nombreBanda = nombreBanda;
}

double Concierto::getPrecioEntrada()
{
	return precioEntrada;
}

void Concierto::setPrecioEntrada(double precioEntrada)
{
	this->precioEntrada = precioEntrada;
}

string Concierto::getFechaConcierto()
{
	return this->fechaConcierto;
}

void Concierto::setFechaConcierto(string fechaConcierto)
{
	this->fechaConcierto = fechaConcierto;
}

int Concierto::getCodigo()
{
	return this->codigo;
}

void Concierto::setCodigo(int codigo)
{
	this->codigo = codigo;
}

double Concierto::getTotalRecaudado()
{
	return this->totalRecaudado;
}

void Concierto::setTotalRecaudado(double totalRecaudado)
{
	this->totalRecaudado = totalRecaudado;
}

int Concierto::getEntradasVendidas()
{
	return this->entradasVendidas;
}

void Concierto::setEntradasVendidas(int entradasVendidas)
{
	this->entradasVendidas = entradasVendidas;
}

void Concierto::toString()
{
	cout << "Nombre de la Banda: " << this->nombreBanda << endl;
	cout << "Precio de la entrada: " << this->precioEntrada << endl;
	cout << "Fecha del Concierto: " << this->fechaConcierto << endl;
	cout << "Codigo: " << this->codigo << endl;
	cout << "Total recaudado: " << this->totalRecaudado << endl;
	cout << "Entradas vendidas: " << this->entradasVendidas << endl;
}

