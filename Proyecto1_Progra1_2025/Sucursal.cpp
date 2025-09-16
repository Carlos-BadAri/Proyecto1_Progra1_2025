#include "Sucursal.h"

Sucursal::Sucursal(){
    codigo = " ";
    canton = " ";
    provincia = " ";
    correoElec = " ";
    tele== " ";
    tamClie = 0;
    tamInstru = 0;
    cantClie = 0;
    cantInstru = 0;

}

Sucursal::Sucursal(string codigo, string canton, string provincia, string correoElec, string tele, int tam1, int tam2){
    this->codigo = codigo;
    this->canton = canton;
    this->provincia = provincia;
    this->correoElec = correoElec;
    this->tele = tele;
    this->tamClie = tam1;
    this->tamInstru = tam2;
    cantClie = 0;
    cantInstru = 0;

    vCliente  = new Cliente * [this->tamClie];
    for (int i = 0; i < this->tamClie; i++) {
        vCliente[i] = nullptr;
    }

    vInstructor = new Instructor * [this->tamInstru];
    for (int i = 0; i < this->tamInstru; i++) {
        vInstructor[i] = nullptr;
    }

}

void Sucursal::setCodigo(string codigo) {
    this->codigo = codigo;
}
void Sucursal::setCanton(string canton) {
    this->canton = canton;
}
void Sucursal::setProvincia(string provincia) {
    this->provincia = provincia;
}
void Sucursal::setCorreoElec(string correoElec) {
    this->correoElec = correoElec;
}
void Sucursal::setTele(string tele) {
    this->tele = tele;
}
void Sucursal::setTam1(int tam1) {
    this->tamClie = tam1;
}
void Sucursal::setTam2(int tam2) {
    this->tamInstru = tam2;
}

string Sucursal::getCodigo() {
    return codigo;
}
string Sucursal::getCanton() {
    return canton;
}
string Sucursal::getProvincia() {
    return provincia;
}
string Sucursal::getCorreoElec() {
    return correoElec;
}
string Sucursal::getTele() {
    return tele;
}

bool Sucursal::clienteRepetido(string id) {
    for (int i = 0; i < cantClie; i++) {
        if (vCliente[i]->getId() == id)
            return true;
    }

    return false;
}

bool Sucursal::agregarCliente(string id){
    if (clienteRepetido(id) == true) {
        return false;
    }
    else {
        return true;
    }

}

bool Sucursal::instructorRepetido(string id){
    for (int i = 0; i < cantInstru; i++) {
        if (vInstructor[i]->getId() == id)
            return true;
    }

    return false;
}

bool Sucursal::agregarInstructor(string id){
    if (instructorRepetido(id) == true) {
        return false;
    }
    else {
        return true;
    }

}

Sucursal::~Sucursal(){
    for (int i = 0; i < tamClie; i++) {
        delete vCliente[i];
    }
    delete[] vCliente;
    for (int i = 0; i < tamInstru; i++) {
        delete vInstructor[i];
    }
    delete[] vInstructor;
}
