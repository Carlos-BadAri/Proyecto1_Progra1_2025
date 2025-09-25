#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class ClaseGrupal{
private:
	string codigo;
	char tipo;
	int capacidadMax;
	int salon;
	string horario;

public:
	ClaseGrupal(string, char, int, int, string);

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

	~ClaseGrupal();




};

