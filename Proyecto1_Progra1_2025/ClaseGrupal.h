#pragma once
#include <iostream>
#include <sstream>
#include "Cliente.h"
using namespace std;

class ClaseGrupal{
private:
	string codigo;
	char tipo;
	Cliente** vClientes; 
	int cant;
	int capacidadMax;//Este es tam
	int salon;
	string horario;

public:
	ClaseGrupal(string, char, int, int, string);
	ClaseGrupal();

	void setCodigo(string);
	void setTipo(char);
	void setCapacidad(int);
	void setSalon(int);
	void setHorario(string);

	string getCodigo();
	char getTipo();
	int getCapacidad();
	int getSalon();
	string getHorario();

	bool agregarCliente(Cliente*);
	bool eliminarCliente(string idCliente);
	string listarClientes();

	int getCant();

	string toString();
	~ClaseGrupal();




};

