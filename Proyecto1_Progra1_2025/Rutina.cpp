#include "Rutina.h"

Rutina::Rutina(int tam) {
    this->tam = tam;
    cant = 0;
    vEjercicios = new Ejercicio * [tam];
    for (int i = 0; i < tam; i++) {
        vEjercicios[i] = nullptr;
    }
}

bool Rutina::agregarEjercicio(Ejercicio* nuevo) {
    if (cant < tam) {
        for (int i = 0; i < cant; i++) {//Este for es para poder comprobar si el ejercicio ya esta, para que el cliente no tenga dos ejercicios repetidos
            if (vEjercicios[i]->getNombre() == nuevo->getNombre()) {
                return false; // Ya existe
            }
        }
        vEjercicios[cant++] = nuevo;
        return true;
    }
    return false;
}

bool Rutina::eliminarEjercicio(string nombre) {
    for (int i = 0; i < cant; i++) {
        if (vEjercicios[i]->getNombre() == nombre) {
            delete vEjercicios[i];
            for (int j = i; j < cant - 1; j++) {
                vEjercicios[j] = vEjercicios[j + 1];
            }
            vEjercicios[--cant] = nullptr;
            return true;
        }
    }
    return false;
}

Ejercicio* Rutina::buscarEjercicio(string nombre) {
    for (int i = 0; i < cant; i++) {
        if (vEjercicios[i]->getNombre() == nombre) {
            return vEjercicios[i];
        }
    }
    return nullptr;
}

int Rutina::getCant() {
    return cant;
}

int Rutina::getTam() {
    return tam;
}

string Rutina::toString() {
    stringstream s;
    s << "Rutina (" << cant << "/" << tam << " ejercicios):" << endl;
    for (int i = 0; i < cant; i++) {
        s << "- " << vEjercicios[i]->toString() << endl;
    }
    return s.str();
}

Rutina::~Rutina() {
    for (int i = 0; i < cant; i++) {
        delete vEjercicios[i];
    }
    delete[] vEjercicios;
}
