#include "Instructor.h"
Instructor::Instructor(){
    id = " ";
    nom = " ";
    tel = "";
    correo = " ";
    fechaNacimiento = " ";
    clase = nullptr;
    medicion = nullptr;
    laSucu = nullptr;
    
}

Instructor::Instructor(string id, string nom, string tel, string correo, string fechaNaci, Sucursal* laSucu,Medicion* medicion,ClaseGrupal* clase){
    this->id = id;
    this->nom = nom;
    this->tel = tel;
    this->correo = correo;
    fechaNacimiento = fechaNaci;
    this->laSucu = laSucu;
    this->medicion = medicion;
    this->clase = clase;
}

void Instructor::setId(string id) {
    this->id = id;
}

string Instructor::getId() {
    return id;
}

void Instructor::setNom(string nom) {
    this->nom = nom;
}

string Instructor::getNom() {
    return nom;
}

void Instructor::setTel(string tel) {
    this->tel = tel;
}

string Instructor::getTel() {
    return tel;
}

void Instructor::setCorreo(string correo) {
    this->correo = correo;
}

string Instructor::getCorreo() {
    return correo;
}

void Instructor::setFechaNacimiento(string fechaNaci) {
    fechaNacimiento = fechaNaci;
}

string Instructor::getFechaNacimiento() {
    return fechaNacimiento;
}
void Instructor::setClase(ClaseGrupal* c) { 
    clase = c; }
ClaseGrupal* Instructor::getClase() {
    return clase; }


string Instructor::toString() {

}

Instructor::~Instructor(){

}

