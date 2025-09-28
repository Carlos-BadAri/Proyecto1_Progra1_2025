#include "ClaseGrupal.h"
ClaseGrupal::ClaseGrupal() {
    codigo = " ";
    tipo = ' ';
    capacidadMax = 0;
    salon = 0;
    horario = " ";
    cant = 0;
    vClientes = nullptr;
}
ClaseGrupal::ClaseGrupal(string codigo, char tipo, int capMax, int salon, string horario) {
    this->codigo = codigo;
    this->tipo = tipo;
    this->capacidadMax = capMax;
    this->salon = salon;
    this->horario = horario;
    cant = 0;
    vClientes = new Cliente * [capacidadMax];
    for (int i = 0; i < capacidadMax; i++) {
        vClientes[i] = nullptr;
    }
}

void ClaseGrupal::setCodigo(string codigo) {
    this->codigo = codigo;
}
void ClaseGrupal::setTipo(char tipo){
    this->tipo = tipo;
}
void ClaseGrupal::setCapacidad(int capMax){
    capacidadMax = capMax;
}
void ClaseGrupal::setSalon(int salon){
    this->salon = salon;
}
void ClaseGrupal::setHorario(string horario){
    this->horario = horario;
}

string ClaseGrupal::getCodigo() {
    return codigo;
}
char ClaseGrupal::getTipo(){
    return tipo;
}
int ClaseGrupal::getCapacidad(){
    return capacidadMax;
}
int ClaseGrupal::getSalon(){
    return salon;
}
string ClaseGrupal::getHorario(){
    return horario;
}
bool ClaseGrupal::agregarCliente(Cliente* c) {
    if (cant = capacidadMax) {
        return false;//Esto en caso de que no haya mas campo en la clase
    }
    for (int i = 0; i < cant; i++) {
        if (vClientes[i]->getId() == c->getId()) {
            return false; // Aqui ya el cliente estaria inscrito
        }
    }
    vClientes[cant] = c;
    cant++;
    return true;
}

bool ClaseGrupal::eliminarCliente(string idCliente) {
    for (int i = 0; i < cant; i++) {
        if (vClientes[i]->getId() == idCliente) {
            for (int j = i; j < cant - 1; j++) {
                vClientes[j] = vClientes[j + 1];
            }
            vClientes[--cant] = nullptr;
            return true;
        }
    }
    return false;
}

string ClaseGrupal::listarClientes() {
    stringstream s;
    s << "Clientes en clase " << codigo << " (" << cant << "/" << capacidadMax << "):" << endl;;
    if (cant == 0) {
        s << "   Ninguno." << endl;;
    }
    else {
        for (int i = 0; i < cant; i++) {
            s << "   - " << vClientes[i]->getNom()
                << " (ID: " << vClientes[i]->getId() << ")" << endl;;
        }
    }
    return s.str();
}

int ClaseGrupal::getCant() {
    return cant;
}

string ClaseGrupal::toString() {
    stringstream s;
    s << "Clase " << codigo << endl;
    s << " | Tipo: " << tipo << endl;
    s << " | Capacidad: " << capacidadMax << endl;
    s << " | Salón: " << salon << endl;
    s << " | Horario: " << horario << endl;
    s << listarClientes();
    return s.str();
}

ClaseGrupal::~ClaseGrupal() {
    delete[] vClientes;
}
