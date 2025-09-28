#pragma once
#include <iostream>
#include <sstream>
#include "ClaseGrupal.h"
#include "Medicion.h"
#include "Sucursal.h"
using namespace std;

class Instructor{
private:
	string id;
	string nom;
	string tel;
	string correo;
	string fechaNacimiento;
	//Especialidad* especialidad;
	Sucursal* laSucu;
	ClaseGrupal* clase;
	Medicion* medicion;
	//VecEmpleados** v;

public:
	Instructor();
	Instructor(string, string, string, string, string,Sucursal*,Medicion*, ClaseGrupal*);
	Instructor(string, string, string, string, string);

	void setId(string);
	string getId();

	void setNom(string);
	string getNom();

	void setTel(string);
	string getTel();

	void setCorreo(string);
	string getCorreo();

	void setFechaNacimiento(string);
	string getFechaNacimiento();

	void setClase(ClaseGrupal* c);
	ClaseGrupal* getClase();

	string toString();

	~Instructor();


};

