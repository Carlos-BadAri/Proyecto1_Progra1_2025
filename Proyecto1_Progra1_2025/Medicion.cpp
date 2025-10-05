#include "Medicion.h"

Medicion::Medicion(string fecha, double peso, double estatura, double porcentajeGrasa, double porcentajeMusculo, int edadMetabolica, double grasaVisceral, double cintura, double cadera, double pecho, double muslo) {
    this->fecha = fecha;
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = porcentajeGrasa;
    this->porcentajeMusculo = porcentajeMusculo;
    this->edadMetabolica = edadMetabolica;
    this->grasaVisceral = grasaVisceral;
    this->cintura = cintura;
    this->cadera = cadera;
    this->pecho = pecho;
    this->muslo = muslo;

}

void Medicion::setFecha(string f) {
    fecha = f;
}
void Medicion::setPeso(double p) {
    peso = p;

}
void Medicion::setEstatura(double e) {
    estatura = e;

}
void Medicion::setPorcentajeGrasa(double g) {
    porcentajeGrasa = g;
}
void Medicion::setPorcentajeMusculo(double m) {
    porcentajeMusculo = m;
}
void Medicion::setEdadMetabolica(int e) {
    edadMetabolica = e;
}
void Medicion::setGrasaVisceral(double gv) {
    grasaVisceral = gv;
}
void Medicion::setCintura(double c) {
    cintura = c;
}
void Medicion::setCadera(double c) {
    cadera = c;
}
void Medicion::setPecho(double p) {
    pecho = p;
}
void Medicion::setMuslo(double m) {
    muslo = m;
}

string Medicion::getFecha() {
    return fecha;
}
double Medicion::getPeso() {
    return peso;
}
double Medicion::getEstatura() {
    return estatura;
}
double Medicion::getPorcentajeGrasa() {
    return porcentajeGrasa;
}
double Medicion::getPorcentajeMusculo() {
    return porcentajeMusculo;
}
int Medicion::getEdadMetabolica() {
    return edadMetabolica;
}
double Medicion::getGrasaVisceral() {
    return grasaVisceral;
}
double Medicion::getCintura() {
    return cintura;
}
double Medicion::getCadera() {
    return cadera;
}
double Medicion::getPecho() {
    return pecho;
}
double Medicion::getMuslo() {
    return muslo;
}
double Medicion::getIMC() {
    if (estatura > 0) {
        return peso / (estatura * estatura);
    }
    else {
        return 0;
    }
}


string Medicion::clasificacionIMC() {
    double imc = getIMC();
    if (imc < 16.0) {
        return "Delgadez severa";
    }
    else if (imc < 17.0) {
        return "Delgadez moderada";
    }
    else if (imc < 18.5) {
        return "Delgadez leve";
    }
    else if (imc < 25.0) {
        return "Normal";
    }
    else if (imc < 30.0) {
        return "Pre-obesidad";
    }
    else if (imc < 35.0) {
        return "Obesidad leve";
    }
    else if (imc < 40.0) {
        return "Obesidad media";
    }
    else {
        return "Obesidad mórbida";
    }
}

double Medicion::calcularProteina(char sexo, bool haceEjercicio) {
    if (!haceEjercicio) {
        return peso * 0.8;
    }
    else {
        if (sexo == 'M' || sexo == 'm') {
            return peso * 2.0; // rango entre 1.7 y 2.5 
        }
        else {
            return peso * 1.7; // rango entre 1.6 y 1.8 
        }
    }
}

int Medicion::calcularVasosAgua() {
    return peso / 7.0;
}

string Medicion::toString() {
    stringstream s;
    s << "Fecha: " << fecha << endl;
    s << "Peso: " << peso << " kg" << endl;
    s << "Estatura: " << estatura << " m" << endl;
    double imc = getIMC();
    if (imc > 0)
        s << "IMC: " << imc << " (" << clasificacionIMC() << ")" << endl;
    else
        s << "IMC: No calculado (estatura inválida)" << endl;

    s << "Grasa corporal: " << porcentajeGrasa << "%" << endl;
    s << "Músculo: " << porcentajeMusculo << "%" << endl;
    s << "Edad metabólica: " << edadMetabolica << endl;
    s << "Grasa visceral: " << grasaVisceral << endl;
    s << "Medidas (cm) - Cintura: " << cintura
        << ", Cadera: " << cadera
        << ", Pecho: " << pecho
        << ", Muslo: " << muslo << endl;
    return s.str();
}

Medicion::~Medicion() {
}

Medicion::~Medicion() {
}
