#include "Sucursal.h"
#include "ClaseGrupal.h"

Sucursal::Sucursal(){
    codigo = "";
    canton = "";
    provincia = "";
    correoElec = "";
    tele = " ";
    tamClie = 0;
    tamInstru = 0;
    cantClie = 0;
    cantInstru = 0;
    cantClase = 0;
    tamClase = 8;

    vCliente = new Cliente * [this->tamClie];
    for (int i = 0; i < this->tamClie; i++) {
        vCliente[i] = nullptr;
    }

    vInstructor = new Instructor * [this->tamInstru];
    for (int i = 0; i < this->tamInstru; i++) {
        vInstructor[i] = nullptr;
    }

    vClase = new ClaseGrupal * [this->tamClase];
    for (int i = 0; i < this->tamClase; i++) {
        vClase[i] = nullptr;
    }

}

Sucursal::Sucursal(string codigo, string canton, string provincia, string correoElec, string tele, int tam1, int tam2, int tam3){
    this->codigo = codigo;
    this->canton = canton;
    this->provincia = provincia;
    this->correoElec = correoElec;
    this->tele = tele;
    tamClie = tam1;
    tamInstru = tam2;
    tamClase = tam3;
   cantClie = 0;
    cantInstru = 0;
    cantClase = 0;

    vCliente  = new Cliente * [this->tamClie];
    for (int i = 0; i < this->tamClie; i++) {
        vCliente[i] = nullptr;
    }

    vInstructor = new Instructor * [this->tamInstru];
    for (int i = 0; i < this->tamInstru; i++) {
        vInstructor[i] = nullptr;
    }

    vClase = new ClaseGrupal * [this->tamClase];
    for (int i = 0; i < this->tamClase; i++) {
        vClase[i] = nullptr;
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
string Sucursal::getCodigo() {
    return codigo;
}


bool Sucursal::clienteRepetido(Cliente elCliente) {
    for (int i = 0; i < cantClie; i++) {
        if (vCliente[i]->getId() == elCliente.getId())
            return true;
    }

    return false;
}

bool Sucursal::agregarCliente(Cliente* elCliente) {
    if (clienteRepetido(*elCliente)) {
        return false;
    }
    if (cantClie < tamClie) {
        vCliente[cantClie++] = elCliente;
        return true;
    }
    return false;
}


bool Sucursal::instructorRepetido(Instructor elInstructor){
    for (int i = 0; i < cantInstru; i++) {
        if (vInstructor[i]->getId() == elInstructor.getId())
            return true;
    }

    return false;
}

bool Sucursal::agregarInstructor(Instructor* elInstructor){
        if (instructorRepetido(*elInstructor)) {
            return false;
        }
        if (cantInstru < tamInstru) {
            vInstructor[cantInstru++] = elInstructor;
            return true;
        }
        return false;
    }
int Sucursal::getCantClientes() {
    return cantClie;
}

Cliente* Sucursal::getCliente(int pos) {
    if (pos >= 0 && pos < cantClie) {
        return vCliente[pos];
    }
    return nullptr;
}

int Sucursal::getCantInstructores() {
    return cantInstru;
}

Instructor* Sucursal::getInstructor(int pos) {
    if (pos >= 0 && pos < cantInstru) {
        return vInstructor[pos];
    }
    return nullptr;
}



Sucursal::~Sucursal(){
    for (int i = 0; i < cantClie; i++) {
        delete vCliente[i];
    }
    delete[] vCliente;
    for (int i = 0; i < cantInstru; i++) {
        delete vInstructor[i];
    }
    delete[] vInstructor;
    for (int i = 0; i < tamClase; i++) {
        delete vClase[i];
    }
    delete[] vClase;

}
