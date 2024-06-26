#pragma once
#include <string>
#include <iostream>
using namespace std;
class Concierto
{
private:
	string nombreBanda;
	double precioEntrada;
	string fechaConcierto; //formato dia,mes,a�o
	int codigo; // entre 1000 y 9999 y debe ser unico
	double totalRecaudado = 0;
	int entradasVendidas = 0;
public:
	Concierto();
	Concierto(string nombreBanda, double precioEntrada, string fechaConcierto, int codigo);
	~Concierto();
	string getNombreBanda();
	void setNombreBanda(string nombreBanda);
	double getPrecioEntrada();
	void setPrecioEntrada(double precioEntrada);
	string getFechaConcierto();
	void setFechaConcierto(string fechaConcierto);
	int getCodigo();
	void setCodigo(int codigo);
	double getTotalRecaudado();
	void setTotalRecaudado(double totalRecaudado);
	int getEntradasVendidas();
	void setEntradasVendidas(int entradasVendidas);
	void toString();

};

