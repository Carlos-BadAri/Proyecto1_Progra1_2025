#include "Cliente.h"
#include "Instructor.h"

Cliente::Cliente(){
    id = " ";
    nom = " ";
    tel = " ";
    correo = " ";
    fechaNacimiento = " ";
    sexo = ' ';
    fechaInscripcion = " ";
    elInstructor = nullptr;
}

Cliente::Cliente(string id, string nom, string tel, string correo, string fechaNaci, char sexo, string fechaInscri, Instructor* elIns){
    this->id = id;
    this->nom = nom;
    this->tel = tel;
    this->correo = correo;
    fechaNacimiento = fechaNaci;
    this->sexo = sexo;
    fechaInscripcion = fechaInscri;
    elInstructor = elIns;
}

void Cliente::setId(string id){
    this->id = id;
}

string Cliente::getId(){
    return id;
}

void Cliente::setNom(string nom){
    this->nom = nom;
}

string Cliente::getNom(){
    return nom;
}

void Cliente::setTel(string tel){
    this->tel = tel;
}

string Cliente::getTel(){
    return tel;
}

void Cliente::setCorreo(string){
    this->correo = correo;
}

string Cliente::getCorreo(){
    return correo;
}

void Cliente::setFechaNacimiento(string fechaNaci){
    fechaNacimiento = fechaNaci;
}

string Cliente::getFechaNacimiento(){
    return fechaNacimiento;
}

void Cliente::setSexo(char){
    this->sexo = sexo;
}

char Cliente::getSexo(){
    return sexo;
}

void Cliente::setFechaInscripcion(string fechaInscri){
    fechaInscripcion = fechaInscri;
}

string Cliente::getFechaInscripcion()
{
    return fechaInscripcion;
}

void Cliente::setInstructor(Instructor* newIstructor){
    elInstructor = newIstructor;
}

Instructor* Cliente::getInstructor(){
    return elInstructor;
}

string Cliente::toString(){
    stringstream s;
    s << "El numero de identificacion del cliente es: " << id << endl;
    s << "El nombre del cliente es: " << nom << endl;
    s << "El telefono del cliente es: " << tel << endl;
    s << "El correo del cliente es: " << correo << endl;
    s << "La fecha de nacimiento del cliente es: " << fechaNacimiento << endl;
    s << "El sexo del cliente es: " << sexo << endl;
    s << "La fecha de inscripcion del cliente es: " << fechaInscripcion << endl;
    s << "El nombre del instructor del cliente es: " << elInstructor->getNom() << endl;
    return s.str();
}

Cliente::~Cliente()
{
}
