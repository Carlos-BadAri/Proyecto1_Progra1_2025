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
