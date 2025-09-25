#pragma once
#include "Instructor.h"
using namespace std;

class Cliente{
private:
	string id;
	string nom;
	string tel;
	string correo;
	string fechaNacimiento;
	char sexo;
	string fechaInscripcion;
	Instructor* elInstructor;
	ClaseGrupal* laClase;

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

	string toString();

	~Cliente();

};

