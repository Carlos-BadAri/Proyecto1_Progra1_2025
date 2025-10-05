#include "Instructor.h"
#include "Sucursal.h"
#include "Medicion.h"
#include "ClaseGrupal.h"

Instructor::Instructor() {
    id = " ";
    nom = " ";
    tel = "";
    correo = " ";
    fechaNacimiento = " ";
    clase = nullptr;
    medicion = nullptr;
    laSucu = nullptr;

    tamEspecialidades = 5; // Se le asigna 5 de una vez porque es el maximo de especialidades que puede tener
    cantEspecialidades = 0;
    vEspecialidades = new string[tamEspecialidades];
}

Instructor::Instructor(string id, string nom, string tel, string correo, string fechaNaci) {
    this->id = id;
    this->nom = nom;
    this->tel = tel;
    this->correo = correo;
    fechaNacimiento = fechaNaci;
    clase = nullptr;
    medicion = nullptr;
    laSucu = nullptr;

    tamEspecialidades = 5;
    cantEspecialidades = 0;
    vEspecialidades = new string[tamEspecialidades];
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
    // Validar que tenga la especialidad requerida
    string especialidadReq;
    if (c->getTipo() == 'C') especialidadReq = "CrossFit";
    else if (c->getTipo() == 'Y') especialidadReq = "Yoga";
    else especialidadReq = "General";

    if (tieneEspecialidad(especialidadReq)) {
        clase = c;
    }
    else {
        clase = nullptr;//Aqui le asigno nullptr porque la clase siguiria basia, ya que no tiene la esppecialidad
    }
}
ClaseGrupal* Instructor::getClase() {
    return clase;
}

bool Instructor::agregarEspecialidad(string especialidad) {
    if (cantEspecialidades < tamEspecialidades) {
        for (int i = 0; i < cantEspecialidades; i++) {
            if (vEspecialidades[i] == especialidad) {
                return false;
            }
        }
        vEspecialidades[cantEspecialidades++] = especialidad;
        return true;
    }
    return false;
}

bool Instructor::tieneEspecialidad(string especialidad) {
    for (int i = 0; i < cantEspecialidades; i++) {
        if (vEspecialidades[i] == especialidad) {
            return true;
        }
    }
    return false;
}



string Instructor::toString() {
    stringstream ss;
    ss << "ID: " << id << endl;
    ss << "Nombre: " << nom << endl;
    ss << "Telefono: " << tel << endl;
    ss << "Correo: " << correo << endl;
    ss << "Fecha de nacimiento: " << fechaNacimiento << endl;

    if (laSucu)
        ss << "Sucursal: " << laSucu->getCodigo() << endl;
    else
        ss << "Sucursal: Ninguna" << endl;

    if (clase)
        ss << "Clase asignada: " << clase->getCodigo() << endl;
    else
        ss << "Clase asignada: Ninguna" << endl;

    ss << "Especialidades: ";
    if (cantEspecialidades > 0) {
        for (int i = 0; i < cantEspecialidades; i++) {
            ss << vEspecialidades[i];
            if (i < cantEspecialidades - 1) ss << ", ";
        }
        ss << endl;
    }
    else {
        ss << "Ninguna" << endl;
    }

    return ss.str();
}

Instructor::~Instructor() {
    delete[] vEspecialidades;
}
