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
	for (int i = 0; i < this->conciertosDisponibles.size(); i++) {
		cout << "Cuenta: " << (i + 1) << endl;
		this->conciertosDisponibles[i]->toString(); // mostrar los conciertos disponibles
		cout << endl;
	}
}

void GestorVentas::guardarConciertosCSV()
{
	ofstream archivo;
	archivo.open("Conciertos.csv", ios::out);
	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	for (int i = 0; i < this->conciertosDisponibles.size(); i++)
	{
		archivo << this->conciertosDisponibles[i]->getNombreBanda() << "," <<
			this->conciertosDisponibles[i]->getPrecioEntrada() << "," <<
			this->conciertosDisponibles[i]->getFechaConcierto() << "," <<
			this->conciertosDisponibles[i]->getCodigo() << "," <<
			this->conciertosDisponibles[i]->getTotalRecaudado() << "," <<
			this->conciertosDisponibles[i]->getEntradasVendidas() << endl;
	}
	archivo.close();
}

void GestorVentas::cargarConciertosCSV()
{
	ifstream archivo;
	archivo.open("Conciertos.csv", ios::app);
	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	string temp = "";
	char* archivoDelimitado = nullptr;
	getline(archivo, temp);
	char* temporal = new char [temp.length()+1];
	strcpy_s(temporal, temp.length() + 1, temp.c_str());
	archivoDelimitado = strtok(temporal, ",");
	Concierto* conciertoTemp = nullptr;
	string nombreTemp = "";
	double precioTemp = 0.0;
	string fechaTemp = "";
	int codigoTemp = 0;
	double recaudadoTemp = 0.0;
	int entradasTemp = 0;
	int contador = 0;
	while (archivoDelimitado != NULL) {
		nombreTemp = to_string(archivoDelimitado[contador]);
		contador++;
		precioTemp = (double)(archivoDelimitado[contador]);
		contador++;
		fechaTemp = to_string(archivoDelimitado[contador]);
		contador++;
		codigoTemp = (int)(archivoDelimitado[contador]);
		contador++;
		recaudadoTemp = (double)(archivoDelimitado[contador]);
		contador++;
		entradasTemp = (int)(archivoDelimitado[contador]);
		contador++;
		Concierto* conciertoTemp = new Concierto(nombreTemp, precioTemp, fechaTemp, codigoTemp);
		conciertoTemp->setTotalRecaudado(recaudadoTemp);
		conciertoTemp->setEntradasVendidas(entradasTemp);
		conciertosDisponibles.push_back(conciertoTemp);
	}
	archivo.close();
}

