#include "Ejercicio.h"

Ejercicio::Ejercicio(string nombre, string descripcion, string areaCuerpo) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->areaCuerpo = areaCuerpo;
}

void Ejercicio::setNombre(string nombre) {
    this->nombre = nombre;
}
void Ejercicio::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}
void Ejercicio::setAreaCuerpo(string areaCuerpo) {
    this->areaCuerpo = areaCuerpo;
}

string Ejercicio::getNombre() {
    return nombre;
}
string Ejercicio::getDescripcion() {
    return descripcion;
}
string Ejercicio::getAreaCuerpo() {
    return areaCuerpo;
}

string Ejercicio::toString() {
    stringstream s;
    s << "Nombre: " << nombre << endl;
    s << "Descripcion: " << descripcion << endl;
    s << "Area del cuerpo: " << areaCuerpo << endl;
    return s.str();
}

Ejercicio::~Ejercicio() {}
