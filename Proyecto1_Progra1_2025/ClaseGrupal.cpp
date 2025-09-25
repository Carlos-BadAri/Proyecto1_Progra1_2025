#include "ClaseGrupal.h"
ClaseGrupal::ClaseGrupal(string codigo, char tipo, int capMax, int salon, string horario){
    this->codigo = codigo;
    this->tipo = tipo;
    capacidadMax = capMax;
    this->salon = salon;
    this->horario = horario;
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

ClaseGrupal::~ClaseGrupal(){
}
