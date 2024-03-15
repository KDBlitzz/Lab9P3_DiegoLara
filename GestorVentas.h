#pragma once
#include "Concierto.h"
#include <vector>
#include <fstream>
class GestorVentas
{
private:
	vector<Concierto*> conciertosDisponibles;
public:
	GestorVentas();
	GestorVentas(vector<Concierto*> conciertosDisponibles);
	~GestorVentas();
	vector<Concierto*> getConciertosDisponibles();
	void setConciertosDisponibles(vector<Concierto*> conciertosDisponibles);
	void agregarConcierto(Concierto* nuevoConcierto);
	void eliminarConcierto(int indiceConcierto);
	void venderEntrada(int indiceConcierto, int cantidad);
	void listarConciertos();
	void guardarConciertosCSV();
	void cargarConciertosCSV();
};

