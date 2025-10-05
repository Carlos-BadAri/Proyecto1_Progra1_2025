#pragma once
#include <iostream>
#include <sstream>
#include "Sucursal.h"
#include "ClaseGrupal.h"
using namespace std;

class Sistema {
private:
    Sucursal** vSucursales;
    int tamSuc;
    int cantSuc;

public:
    Sistema(int = 30);

    void menu();

    bool agregarSucursal(Sucursal*);
    Sucursal* buscarSucursal(string codigo);

    string listarSucursales();
    string listarClientesPorSucursal(string codigo);
    string listarInstructoresPorSucursal(string codigo);

    void menuSucursal(Sucursal*);

    ~Sistema();
};

