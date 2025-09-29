#include "Sistema.h"
using namespace std;

Sistema::Sistema(int tam) {
    tamSuc = tam;
    cantSuc = 0;
    vSucursales = new Sucursal * [tamSuc];
    for (int i = 0; i < tamSuc; i++) {
        vSucursales[i] = nullptr;
    }
}

void Sistema::menu() {
    int opcion;
    do {
        cout << "--- MENU PRINCIPAL ---\n";
        cout << "1. Listar sucursales" << endl;
        cout << "2. Buscar sucursal" << endl;
        cout << "3. Agregar sucursal" << endl;;
        cout << "0. Salir" << endl;;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            cout << listarSucursales() << endl;
            break;
        case 2: { //Con esta opcion se accede al submenu
            string cod;
            cout << "Ingrese codigo de sucursal: ";
            cin >> cod;
            Sucursal* suc = buscarSucursal(cod);
            if (suc != nullptr) {
                menuSucursal(suc);
            }
            else {
                cout << "No existe la sucursal." << endl;
            }
            break;
        }

        case 3: {
            string cod;
            string canton;
            string provincia;
            string correo;
            string tel;

            cout << "Codigo: ";
            cin >> cod;
            cout << "Canton: ";
            cin >> canton;
            cout << "Provincia: ";
            cin >> provincia;
            cout << "Correo: ";
            cin >> correo;
            cout << "Telefono: ";
            cin >> tel;

            int tamClientes, tamInstructores, tamClase;
            cout << "Tamano max de clientes: ";
            cin >> tamClientes;
            cout << "Tamano max de instructores: ";
            cin >> tamInstructores;
            cout << "Cual es el numero de clases que hay?: ";
            cin >> tamClase;


            Sucursal* nueva = new Sucursal(cod, canton, provincia, correo, tel, tamClientes, tamInstructores, tamClase);
            if (agregarSucursal(nueva)) {
                cout << "Sucursal agregada con exito" << endl;
            }
            else {
                cout << "No se pudo agregar (espacio lleno)" << endl;
            }

            break;
        }
        case 0:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
        }
    } while (opcion != 0);
}

bool Sistema::agregarSucursal(Sucursal* newSucu) {
    if (cantSuc < tamSuc) {
        vSucursales[cantSuc++] = newSucu;
        return true;
    }
    return false;
}

Sucursal* Sistema::buscarSucursal(string codigo) {
    for (int i = 0; i < cantSuc; i++) {
        if (vSucursales[i]->getCodigo() == codigo) {
            return vSucursales[i];
        }
    }
    return nullptr;
}

string Sistema::listarSucursales() {
    stringstream s;
    s << "Sucursales registradas (" << cantSuc << "):" << endl;
    for (int i = 0; i < cantSuc; i++) {
        s << "- Codigo: " << vSucursales[i]->getCodigo()
            << ", Canton: " << vSucursales[i]->getCanton()
            << ", Provincia: " << vSucursales[i]->getProvincia() << endl;
    }
    return s.str();
}

string Sistema::listarClientesPorSucursal(string codigo) {
    Sucursal* suc = buscarSucursal(codigo);
    if (suc == nullptr) {
        return "Sucursal no encontrada.";
    }

    stringstream s;
    s << "Clientes de la sucursal " << codigo << ":" << endl;
    for (int i = 0; i < suc->getCantClientes(); i++) {
        Cliente* c = suc->getCliente(i);
        if (c != nullptr) {
            s << "- " << c->getNom() << " (" << c->getId() << ")" << endl;
        }
    }
    return s.str();
}

string Sistema::listarInstructoresPorSucursal(string codigo) {
    Sucursal* suc = buscarSucursal(codigo);
    if (suc == nullptr) {
        return "Sucursal no encontrada.";
    }

    stringstream s;
    s << "Instructores de la sucursal " << codigo << ":" << endl;
    for (int i = 0; i < suc->getCantInstructores(); i++) {
        Instructor* ins = suc->getInstructor(i);
        if (ins != nullptr) {
            s << "- " << ins->getNom() << " (" << ins->getId() << ")" << endl;
        }
    }
    return s.str();
}

//Este es un menu secundario, trabaja con el primer menu. 
//Es para administrar la sucursal que se busca por codigo
void Sistema::menuSucursal(Sucursal* suc) {
    int op;
    do {
        cout << "entrnado al submenu de la sede" << endl;
        cout << "--- MENU SUCURSAL (" << suc->getCodigo() << ") ---" << endl;
        cout << "1. Listar clientes" << endl;
        cout << "2. Listar instructores" << endl;
        cout << "3. Agregar cliente" << endl;
        cout << "4. Agregar instructor" << endl;
        cout << "5. Gestionar mediciones (por cliente)" << endl;
        cout << "6. Gestionar rutinas (por cliente)" << endl;
        cout << "7. Gestionar clases grupales" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> op;
        cin.ignore();

        switch (op) {
        case 1: {
            cout << "--- Lista de clientes ---" << endl;
            for (int i = 0; i < suc->getCantClientes(); i++)
                cout << suc->getCliente(i)->toString() << endl;
            break;
        }
        case 2: {
            cout << "--- Lista de instructores ---" << endl;
            for (int i = 0; i < suc->getCantInstructores(); i++)
                cout << suc->getInstructor(i)->toString() << endl;
            break;
        }
        case 3: {
            string id;
            string nom;
            string tel;
            string correo;
            string fechaNacimiento;
            char sexo;
            string fechaInscripcion;

            cout << "Ingrese ID del cliente: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese nombre: ";
            getline(cin, nom);
            cout << "Ingrese telefono: ";
            cin >> tel;
            cout << "Ingrese correo: ";
            cin >> correo;
            cin.ignore();
            cout << "Ingrese fecha de nacimiento (dd/mm/aaaa): ";
            getline(cin, fechaNacimiento);
            cout << "Ingrese sexo (M/F): ";
            cin >> sexo;
            cin.ignore();
            cout << "Ingrese fecha de inscripcion (dd/mm/aaaa): ";
            getline(cin, fechaInscripcion);

            Cliente* nuevoCliente = new Cliente(id, nom, tel, correo, fechaNacimiento, sexo, fechaInscripcion, nullptr);

            if (suc->agregarCliente(nuevoCliente))
                cout << "Cliente agregado exitosamente." << endl;
            else {
                cout << "No se pudo agregar el cliente (repetido o espacio lleno)." << endl;
                delete nuevoCliente;
            }
            break;
        }
        case 4: {
            string id;
            string nom;
            string tel;
            string correo;
            string fechaNacimiento;

            cout << "Ingrese ID del instructor: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese nombre: ";
            getline(cin, nom);
            cout << "Ingrese telefono: ";
            cin >> tel;
            cout << "Ingrese correo: ";
            cin >> correo;
            cin.ignore();
            cout << "Ingrese fecha de nacimiento (dd/mm/aaaa): ";
            getline(cin, fechaNacimiento);

            Instructor* nuevoInstructor = new Instructor(id, nom, tel, correo, fechaNacimiento);

            if (suc->agregarInstructor(nuevoInstructor))
                cout << "Instructor agregado exitosamente" << endl;
            else {
                cout << "No se pudo agregar el instructor (repetido o espacio lleno)" << endl;
                delete nuevoInstructor;
            }
            break;
        }
        case 5: {
            string idCliente;

            cout << "Ingrese ID del cliente: ";
            cin >> idCliente;

            Cliente* c = suc->buscarCliente(idCliente);
            if (!c) {
                cout << "Cliente no encontrado." << endl;
                break;
            }

            int opMed;
            do {
                cout << "--- Mediciones de " << c->getNom() << " ---" << endl;
                cout << "1. Registrar medicion" << endl;
                cout << "2. Mostrar mediciones" << endl;
                cout << "0. Volver" << endl;
                cout << "Opcion: ";
                cin >> opMed;
                cin.ignore();

                if (opMed == 1) {
                    string fecha;
                    double peso;
                    double est;
                    double g;
                    double m;
                    double gv;
                    double cist;
                    double cadera;
                    double pecho;
                    double muslo;
                    int edad;
                    cout << "Fecha: " << endl;
                    getline(cin, fecha);
                    cout << "Peso:" << endl;
                    cin >> peso;
                    cout << "Estatura:" << endl;
                    cin >> est;
                    cout << "Porc. Grasa:" << endl;
                    cin >> g;
                    cout << "Porc. Musculo: " << endl;
                    cin >> m;
                    cout << "Edad Metabolica: " << endl;
                    cin >> edad;
                    cout << "Grasa Visceral: " << endl;
                    cin >> gv;
                    cout << "Cintura:" << endl;
                    cin >> cist;
                    cout << "Cadera: " << endl;
                    cin >> cadera;
                    cout << "Pecho: " << endl;
                    cin >> pecho;
                    cout << "Muslo: " << endl;
                    cin >> muslo;
                    cin.ignore();

                    Medicion* med = new Medicion(fecha, peso, est, g, m, edad, gv, cist, cadera, pecho, muslo);
                    if (c->agregarMedicion(med)) {
                        cout << "Medicion registrada." << endl;
                    }
                    else {
                        cout << "No se puede agregar mas mediciones." << endl;
                        delete med;
                    }
                }
                else if (opMed == 2) {
                    for (int i = 0; i < c->getCantMediciones(); i++) {
                        cout << c->getMedicion(i)->toString() << endl;
                    }
                }

            } while (opMed != 0);
            break;
        }
        case 7: {
            int opClaseGru;
            do {
                cout << "--- Clases Grupales ---" << endl;
                cout << "1. Matricular cliente" << endl;
                cout << "2. Desmatricular cliente" << endl;
                cout << "3. Mostrar inscritos" << endl;
                cout << "0. Volver" << endl;
                cout << "Opcion: ";
                cin >> opClaseGru;
                cin.ignore();

                if (opClaseGru == 1) {
                    string idCliente;
                    string codClase;

                    cout << "ID Cliente: ";
                    cin >> idCliente;
                    cout << "Codigo Clase: ";
                    cin >> codClase;
                    Cliente* c = suc->buscarCliente(idCliente);
                    ClaseGrupal* cl = suc->buscarClase(codClase);
                    if (c && cl) {
                        if (cl->agregarCliente(c)) {
                            cout << "Cliente matriculado" << endl;
                        }
                        else cout << "No se pudo matricular" << endl;
                    }
                    else cout << "El cliente, la clase o ambos no fueron encontrados" << endl;
                }
                else if (opClaseGru == 2) {
                    string idCliente;
                    string codClase;

                    cout << "ID Cliente: ";
                    cin >> idCliente;
                    cout << "Codigo Clase: ";
                    cin >> codClase;

                    Cliente* c = suc->buscarCliente(idCliente);
                    ClaseGrupal* cl = suc->buscarClase(codClase);

                    if (c && cl) {
                        if (cl->eliminarCliente(idCliente)) cout << "Cliente desmatriculado" << endl;
                        else cout << "No se pudo desmatricular" << endl;
                    }
                    else cout << "Cliente o clase no encontrado" << endl;
                }
                else if (opClaseGru == 3) {
                    string codClase;
                    cout << "Codigo Clase: ";
                    cin >> codClase;

                    ClaseGrupal* cl = suc->buscarClase(codClase);
                    if (cl) {
                        cout << cl->listarClientes() << endl;
                    }
                    else cout << "Clase no encontrada" << endl;
                }

            } while (opClaseGru != 0);
            break;
        }
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (op != 0);
}


Sistema::~Sistema() {
    for (int i = 0; i < cantSuc; i++) {
        delete vSucursales[i];
    }
    delete[] vSucursales;
}
