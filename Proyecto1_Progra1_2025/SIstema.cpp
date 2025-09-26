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
        cout << "1. Listar sucursales\n";
        cout << "2. Buscar sucursal\n";
        cout << "3. Agregar sucursal\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << listarSucursales() << endl;
            break;
        case 2: {
            string cod;
            cout << "Ingrese codigo de sucursal: ";
            cin >> cod;
            Sucursal* suc = buscarSucursal(cod);
            if (suc != nullptr)
                cout << "Sucursal encontrada: " << suc->getCodigo() << endl;
            else
                cout << "No existe la sucursal." << endl;
            break;
        }
        case 3: {
            string cod, canton, provincia, correo, tel;
            cout << "Codigo: "; cin >> cod;
            cout << "Canton: "; cin >> canton;
            cout << "Provincia: "; cin >> provincia;
            cout << "Correo: "; cin >> correo;
            cout << "Telefono: "; cin >> tel;

            int tamClientes, tamInstructores;
            cout << "Tamano max de clientes: "; cin >> tamClientes;
            cout << "Tamano max de instructores: "; cin >> tamInstructores;

            Sucursal* nueva = new Sucursal(cod, canton, provincia, correo, tel, tamClientes, tamInstructores);
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
    // Aquí deberías recorrer vCliente (cuando implementes getter en Sucursal)
    // Por ahora dejamos un placeholder
    s << "(Falta implementar lista de clientes)" << endl;
    return s.str();
}

string Sistema::listarInstructoresPorSucursal(string codigo) {
    Sucursal* suc = buscarSucursal(codigo);
    if (suc == nullptr) {
        return "Sucursal no encontrada.";
    }

    stringstream s;
    s << "Instructores de la sucursal " << codigo << ":" << endl;
    // Aquí deberías recorrer vInstructor (cuando implementes getter en Sucursal)
    s << "(Falta implementar lista de instructores)" << endl;
    return s.str();
}

Sistema::~Sistema() {
    for (int i = 0; i < cantSuc; i++) {
        delete vSucursales[i];
    }
    delete[] vSucursales;
}
