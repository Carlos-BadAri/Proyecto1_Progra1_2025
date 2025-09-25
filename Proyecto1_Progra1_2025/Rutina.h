#pragma once
#include <iostream>
#include <sstream>
#include "Ejercicio.h"
using namespace std;

class Rutina {
private:
    Ejercicio** vEjercicios;
    int tam;
    int cant;

public:
    Rutina(int);

    bool agregarEjercicio(Ejercicio*);
    bool eliminarEjercicio(string nombre);
    Ejercicio* buscarEjercicio(string nombre);

    int getCant();
    int getTam();

    string toString();

    ~Rutina();
};
