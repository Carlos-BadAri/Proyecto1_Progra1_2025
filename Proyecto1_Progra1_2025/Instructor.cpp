#include "Instructor.h"
Instructor::Instructor(){
    id = " ";
    nom = " ";
    tel = "";
    correo = " ";
    fechaNacimiento = " ";
}

Instructor::Instructor(string id, string nom, string tel, string correo, string fechaNaci){
    this->id = id;
    this->nom = nom;
    this->tel = tel;
    this->correo = correo;
    fechaNacimiento = fechaNaci;
}
void Cliente::setId(string id) {
    this->id = id;
}

string Cliente::getId() {
    return id;
}

void Cliente::setNom(string nom) {
    this->nom = nom;
}

string Cliente::getNom() {
    return nom;
}

void Cliente::setTel(string tel) {
    this->tel = tel;
}

string Cliente::getTel() {
    return tel;
}

void Cliente::setCorreo(string) {
    this->correo = correo;
}

string Cliente::getCorreo() {
    return correo;
}

void Cliente::setFechaNacimiento(string fechaNaci) {
    fechaNacimiento = fechaNaci;
}

string Cliente::getFechaNacimiento() {
    return fechaNacimiento;
}
