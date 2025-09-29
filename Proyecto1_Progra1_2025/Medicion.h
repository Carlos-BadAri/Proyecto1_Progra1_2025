#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Medicion {
private:
    string fecha;
    double peso;
    double estatura;
    double porcentajeGrasa;
    double porcentajeMusculo;
    int edadMetabolica;
    double grasaVisceral;
    double cintura;
    double cadera;
    double pecho;
    double muslo;

public:
    Medicion(string, double, double, double, double, int, double, double, double, double, double);

    void setFecha(string);
    void setPeso(double);
    void setEstatura(double);
    void setPorcentajeGrasa(double);
    void setPorcentajeMusculo(double);
    void setEdadMetabolica(int);
    void setGrasaVisceral(double);
    void setCintura(double);
    void setCadera(double);
    void setPecho(double);
    void setMuslo(double);

    string getFecha();
    double getPeso();
    double getEstatura();
    double getPorcentajeGrasa();
    double getPorcentajeMusculo();
    int getEdadMetabolica();
    double getGrasaVisceral();
    double getCintura();
    double getCadera();
    double getPecho();
    double getMuslo();
    double getIMC();

    string clasificacionIMC();
    double calcularProteina(char, bool);
    int calcularVasosAgua();

    string toString();

    ~Medicion();
};

