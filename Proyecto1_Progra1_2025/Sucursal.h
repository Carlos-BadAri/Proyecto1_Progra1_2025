#pragma once
#include "Cliente.h"
class Sucursal{
private:
	string codigo;
	string canton;
	string provincia;
	string correoElec;
	string tele;
	int tam1;
	int cant1;
	Cliente** vCliente;
	int tam2;
	int cant2;
	Instructor** vInstructor;
	//ClaseGrupal* vClase; (es de 0 a 8)

public:
	Sucursal();
	Sucursal(string, string, string, string, string, int, int);

	void setCodigo(string);
	void setCanton(string);
	void setProvincia(string);
	void setCorreoElec(string);
	void setTele(string);
	void setTam1(int);
	void setTam2(int);

	string getCodigo();
	string getCanton();
	string getProvincia();
	string getCorreoElec();
	string getTele();

	void agregarCliente();
	void agregarInstructor();

	~Sucursal();




};

