#pragma once
#include "Cliente.h"
#include "Instructor.h"

class Cliente;
class Instructor;

class Sucursal {
private:
	string codigo;
	string canton;
	string provincia;
	string correoElec;
	string tele;
	int tamClie;
	int cantClie;
	Cliente** vCliente;
	int tamInstru;
	int cantInstru;
	Instructor** vInstructor;
	int tamClase;
	int cantClase;
	ClaseGrupal** vClase;

public:
	Sucursal();
	Sucursal(string, string, string, string, string, int, int, int);

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

	bool clienteRepetido(Cliente);
	bool agregarCliente(Cliente*);
	bool instructorRepetido(Instructor);
	bool agregarInstructor(Instructor*);

	int getCantClientes();
	Cliente* getCliente(int);

	int getCantInstructores();
	Instructor* getInstructor(int);

	bool claseRepetido(ClaseGrupal);
	bool agregarClase(ClaseGrupal*);
	int getCantClases();
	ClaseGrupal* getClase(int);

	Cliente* buscarCliente(string);
	ClaseGrupal* buscarClase(string);
	Instructor* buscarInstruc(string);

	~Sucursal();
};

