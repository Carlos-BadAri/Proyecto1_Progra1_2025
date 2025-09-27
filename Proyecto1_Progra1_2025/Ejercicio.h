#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Ejercicio {
private:
    string nombre;
    string descripcion;
    string areaCuerpo; // pecho-triceps, biceps, piernas, espalda

public:
    Ejercicio(string, string, string);
    Ejercicio();

    void setNombre(string);
    void setDescripcion(string);
    void setAreaCuerpo(string);

    string getNombre();
    string getDescripcion();
    string getAreaCuerpo();

    string toString();

    ~Ejercicio();
};
