#include "Cliente.h"
#include "Instructor.h"

Cliente::Cliente() {
    id = " ";
    nom = " ";
    tel = " ";
    correo = " ";
    fechaNacimiento = " ";
    sexo = ' ';
    fechaInscripcion = " ";
    elInstructor = nullptr;

    cantClases = 0;
    for (int i = 0; i < 3; i++) {
        vClases[i] = nullptr;
    }

    cantMediciones = 0;
    vMediciones = new Medicion * [maxMediciones];
    for (int i = 0; i < maxMediciones; i++) vMediciones[i] = nullptr;
}

Cliente::Cliente(string id, string nom, string tel, string correo, string fechaNaci, char sexo, string fechaInscri, Instructor* elIns) {
    this->id = id;
    this->nom = nom;
    this->tel = tel;
    this->correo = correo;
    fechaNacimiento = fechaNaci;
    this->sexo = sexo;
    fechaInscripcion = fechaInscri;
    elInstructor = elIns;
    cantClases = 0;

    for (int i = 0; i < 3; i++) {
        vClases[i] = nullptr;
    }

    cantMediciones = 0;
    vMediciones = new Medicion * [maxMediciones];
    for (int i = 0; i < maxMediciones; i++) vMediciones[i] = nullptr;
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

void Cliente::setCorreo(string correo) {
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

void Cliente::setSexo(char sexo) {
    this->sexo = sexo;
}

char Cliente::getSexo() {
    return sexo;
}

void Cliente::setFechaInscripcion(string fechaInscri) {
    fechaInscripcion = fechaInscri;
}

string Cliente::getFechaInscripcion()
{
    return fechaInscripcion;
}

void Cliente::setInstructor(Instructor* newIstructor) {
    elInstructor = newIstructor;
}

Instructor* Cliente::getInstructor() {
    return elInstructor;
}

bool Cliente::agregarClase(ClaseGrupal* nueva) {
    if (nueva == nullptr) {
        return false;
    }

    for (int i = 0; i < cantClases; i++) {
        if (vClases[i] == nueva) {
            return false;
        }
    }

    if (cantClases == 3) {
        return false;
    }


    if (!nueva->agregarCliente(this)) {//Aqui la validacion le toca a la clase grupal(recordar hacer esto al otro lado)
        return false; //la clase rechazo al cliente porque o ya estaba llena o porque ya el cliente estaba inscrito en ella
    }

    vClases[cantClases++] = nueva;
    return true;
}

bool Cliente::desmatricularDeClase(string codigoClase) {
    for (int i = 0; i < cantClases; i++) {
        if (vClases[i] != nullptr && vClases[i]->getCodigo() == codigoClase) {//Aqui estoy haciendo es buscar entre las lcases matriucladas por el cliente
            bool bandera = vClases[i]->eliminarCliente(this->getId());//Aqui elimino al cliente, pero desde la clase

            for (int j = i; j < cantClases - 1; j++) {//Corrimiento para que no hayan huecos.
                vClases[j] = vClases[j + 1];
            }
            vClases[--cantClases] = nullptr;
            return bandera;
        }
    }
    return false;
}

int Cliente::getCantClases() {
    return cantClases;
}

ClaseGrupal* Cliente::getClase(int pos) {
    if (pos >= 0 && pos < cantClases) {
        return vClases[pos];
    }
    return nullptr;
}

bool Cliente::agregarMedicion(Medicion* nueva) {
    if (cantMediciones < maxMediciones) {
        vMediciones[cantMediciones++] = nueva;
        return true;
    }
    return false;
}
Medicion* Cliente::getMedicion(int pos) {
    if (pos >= 0 && pos < cantMediciones) {
        return vMediciones[pos];
    }
    return nullptr;
}

int Cliente::getCantMediciones() {
    return cantMediciones;
}



string Cliente::toString() {
    stringstream s;
    s << "El numero de identificacion del cliente es: " << id << endl;
    s << "El nombre del cliente es: " << nom << endl;
    s << "El telefono del cliente es: " << tel << endl;
    s << "El correo del cliente es: " << correo << endl;
    s << "La fecha de nacimiento del cliente es: " << fechaNacimiento << endl;
    s << "El sexo del cliente es: " << sexo << endl;
    s << "La fecha de inscripcion del cliente es: " << fechaInscripcion << endl;

    if (elInstructor != nullptr) {
        s << "El nombre del instructor del cliente es: " << elInstructor->getNom() << endl;
    }
    else {
        s << "El cliente no tiene instructor asignado." << endl;
    }

    if (cantClases > 0) {
        s << "El cliente tiene " << cantClases << " inscritas" << endl;

        for (int i = 0; i < cantClases; i++) {
            s << vClases[i]->getCodigo() << endl;
        }

    }
    else {
        s << "El cliente no está matriculado en ninguna clase grupal." << endl;
    }

    return s.str();
}

Cliente::~Cliente() {
    for (int i = 0; i < cantMediciones; i++) {
        delete vMediciones[i];
    }
    delete[] vMediciones;
}

