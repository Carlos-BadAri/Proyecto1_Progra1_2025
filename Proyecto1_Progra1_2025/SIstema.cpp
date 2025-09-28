#include "Sistema.h"

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
        cout << "\n--- MENU PRINCIPAL ---\n";
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
            string cod, canton, provincia, correo, tel;
            cout << "Codigo: "; cin >> cod;
            cout << "Canton: "; cin >> canton;
            cout << "Provincia: "; cin >> provincia;
            cout << "Correo: "; cin >> correo;
            cout << "Telefono: "; cin >> tel;

            int tamClientes, tamInstructores, tamClase;
            cout << "Tamano max de clientes: "; 
            cin >> tamClientes;
            cout << "Tamano max de instructores: "; 
            cin >> tamInstructores;
            cout << "Cual es el numero de clases que hay?: ";
            cin >> tamClase;


            Sucursal* nueva = new Sucursal(cod, canton, provincia, correo, tel, tamClientes, tamInstructores, tamClase);
            if (agregarSucursal(nueva))
                cout << "Sucursal agregada con exito.\n";
            else
                cout << "No se pudo agregar (espacio lleno).\n";
            break;
        }
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
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
        cout << "\n--- MENU SUCURSAL (" << suc->getCodigo() << ") ---\n";
        cout << "1. Listar clientes\n";
        cout << "2. Listar instructores\n";
        cout << "3. Agregar cliente\n";
        cout << "4. Agregar instructor\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> op;
      
        switch (op) {
        case 1: {
            cout << listarClientesPorSucursal(suc->getCodigo()) << endl;
            break;
        }
        case 2: {
            cout << listarInstructoresPorSucursal(suc->getCodigo()) << endl;
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
            cout << "Ingrese nombre: ";
            cin >> nom;
            cout << "Ingrese telefono: ";
            cin >> tel;
            cout << "Ingrese correo: ";
            cin >> correo;
            cout << "Ingrese fecha de nacimiento (dd/mm/aaaa): ";
            cin >> fechaNacimiento;
            cout << "Ingrese sexo (M/F): ";
            cin >> sexo;
            cout << "Ingrese fecha de inscripcion (dd/mm/aaaa): ";
            cin >> fechaInscripcion;

            Cliente* nuevoCliente = new Cliente(id, nom, tel, correo, fechaNacimiento, sexo, fechaInscripcion, nullptr);

            if (suc->agregarCliente(nuevoCliente)) {
                cout << "Cliente agregado de manera exitosa" << endl;
            }
            else {
                cout << "El cliente no se pudo agregar, esto se puede deber a que el espacio este lleno o este repetido" << endl;
                delete nuevoCliente;
            }

            break;
        }
        case 4: {
            string idI;
            string nomI;
            string telI;
            string correoI;
            string fechaNacimientoI;

            cout << "Ingrese ID del instructor: ";
            cin >> idI;
            cout << "Ingrese nombre: ";
            cin >> nomI;
            cout << "Ingrese telefono: ";
            cin >> telI;
            cout << "Ingrese correo: ";
            cin >> correoI;
            cout << "Ingrese fecha de nacimiento (dd/mm/aaaa): ";
            cin >> fechaNacimientoI;

            Instructor* nuevoInstructor = new Instructor(idI, nomI, telI, correoI, fechaNacimientoI);

            if (suc->agregarInstructor(nuevoInstructor)) {
                cout << "El instructor se a agregado de manera exitosa" << endl;
            }
            else {
                cout << "El instructor no se pudo agregar de manera correcta, esto se puede deber a que se haya agregado anteriormente o que la sucursal no admita a mas instructores" << endl;
                delete nuevoInstructor;
            }

            break;
        }
        case 0: {
            cout << "Volviendo al menu principal...\n";
            break;
        }
        default:
            cout << "Opcion invalida.\n";
        }
    } while (op != 0);
}


Sistema::~Sistema() {
    for (int i = 0; i < cantSuc; i++) {
        delete vSucursales[i];
    }
    delete[] vSucursales;
}
