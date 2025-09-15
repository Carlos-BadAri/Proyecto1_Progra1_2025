#include "Sucursal.h"

Sucursal::Sucursal(){
    codigo = " ";
    canton = " ";
    provincia = " ";
    correoElec = " ";
    tele== " ";
    tam1 = 0;
    tam2 = 0;
    cant1 = 0;
    cant2 = 0;

}

Sucursal::Sucursal(string codigo, string canton, string provincia, string correoElec, string tele, int tam1, int tam2){
    this->codigo = codigo;
    this->canton = canton;
    this->provincia = provincia;
    this->correoElec = correoElec;
    this->tele = tele;
    this->tam1 = tam1;
    this->tam2 = tam2;
    cant1 = 0;
    cant2 = 0;

    vCliente  = new Cliente * [this->tam1];
    for (int i = 0; i < this->tam1; i++) {
        vCliente[i] = nullptr;
    }

    vInstructor = new Instructor * [this->tam2];
    for (int i = 0; i < this->tam2; i++) {
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
    this->tam1 = tam1;
}
void Sucursal::setTam2(int tam2) {
    this->tam2 = tam2;
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


void Sucursal::agregarCliente()
{
}

void Sucursal::agregarInstructor()
{
}

Sucursal::~Sucursal(){
    for (int i = 0; i < tam1; i++) {
        delete vCliente[i];
    }
    delete[] vCliente;
    for (int i = 0; i < tam2; i++) {
        delete vInstructor[i];
    }
    delete[] vInstructor;
}
