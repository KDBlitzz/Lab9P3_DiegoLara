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
	for (int i = 0; i < this->conciertosDisponibles.size(); i++) // borrar memoria
	{
		delete this->conciertosDisponibles[i];
	}
	this->conciertosDisponibles.clear();
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
	this->conciertosDisponibles.erase(this->conciertosDisponibles.begin() + indiceConcierto); // eliminar el concierto
}

void GestorVentas::venderEntrada(int indiceConcierto, int cantidad) // Calcular el total de las entradas vendidas dependiendo de la cantidad
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

void GestorVentas::guardarConciertosCSV() // guardar los conciertos disponibles adentro del archivo
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

void GestorVentas::cargarConciertosCSV() // cargar los conciertos del archivo al vector de la clase
{
	ifstream archivo;
	archivo.open("Conciertos.csv", ios::app);
	if (archivo.fail())
	{
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	int terminar = 0;
	string temp = "";
	char* archivoDelimitado = nullptr;
	getline(archivo, temp);
	char* token;
	char* temporal = new char[temp.length() + 1];
	strcpy_s(temporal, temp.length() + 1, temp.c_str());
	archivoDelimitado = strtok_s(temporal, ",", &token);
	while (terminar != 2) {
		string nombreTemp = "";
		double precioTemp = 0.0;
		string fechaTemp = "";
		int codigoTemp = 0;
		double recaudadoTemp = 0.0;
		int entradasTemp = 0;
		string doubleToString = "";
		nombreTemp = archivoDelimitado;
		archivoDelimitado = strtok_s(NULL, ",", &token);
		doubleToString = archivoDelimitado;
		precioTemp = stod(doubleToString);
		archivoDelimitado = strtok_s(NULL, ",", &token);
		fechaTemp = archivoDelimitado;
		archivoDelimitado = strtok_s(NULL, ",", &token);
		codigoTemp = atoi(archivoDelimitado);
		Concierto* conciertoTemp = new Concierto(nombreTemp, precioTemp, fechaTemp, codigoTemp);
		conciertosDisponibles.push_back(conciertoTemp);
		getline(archivo, temp);
		strcpy_s(temporal, temp.length() + 1, temp.c_str());
		archivoDelimitado = strtok_s(temporal, ",", &token);
		if (archivo.eof())
		{
			terminar++;
		}
		if (archivoDelimitado == NULL)
		{
			break;
		}
	}
	archivo.close();
}

