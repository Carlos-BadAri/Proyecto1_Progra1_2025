#pragma once
#include "Instructor.h"
#include "Medicion.h"
#include "ClaseGrupal.h"
using namespace std;

class Instructor;

class Cliente {
private:
	string id;
	string nom;
	string tel;
	string correo;
	string fechaNacimiento;
	char sexo;
	string fechaInscripcion;
	Instructor* elInstructor;
	ClaseGrupal* vClases[3];
	int cantClases;

	Medicion** vMediciones;
	int cantMediciones;
	const static int maxMediciones = 10; //Asigno directamente 10 porque es el maximo que pueden tener


public:
	Cliente();
	Cliente(string, string, string, string, string, char, string, Instructor*);

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

	void setSexo(char);
	char getSexo();

	void setFechaInscripcion(string);
	string getFechaInscripcion();

	void setInstructor(Instructor*);
	Instructor* getInstructor();

	bool agregarClase(ClaseGrupal*);
	int getCantClases();
	ClaseGrupal* getClase(int pos);
	bool desmatricularDeClase(string);

	bool agregarMedicion(Medicion* nueva);
	Medicion* getMedicion(int pos);
	int getCantMediciones();

	string toString();

	~Cliente();

};

