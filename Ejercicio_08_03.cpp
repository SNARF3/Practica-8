#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Persona {
    char nombre[30];
    int edad;
    char sexo[2];
    char fecha[10];
};

void escritura() {
    ofstream archivoPersonas("Personas.BIN", ios::app | ios::binary);
    if (archivoPersonas.fail()) {
        cerr << "NO se pudo crear el archivo." << endl;
        exit(1);
    }

    Persona personitas;
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(personitas.nombre, 30);

    cout << "Ingrese su edad: ";
    cin >> personitas.edad;

    cout << "Sexo (M/F): ";
    cin.ignore();
    cin.getline(personitas.sexo, 2);

    cout << "Fecha de nacimiento (dd/mm/yyyy): ";
    cin.ignore();
    cin.getline(personitas.fecha, 10);

    archivoPersonas.write(reinterpret_cast<char*>(&personitas), sizeof(Persona));

    archivoPersonas.close();
    cout << "Datos guardados correctamente" << endl;
}

void procesarCandidatos() {
    ifstream archivoPersonas("Personas.BIN", ios::binary);
    ofstream archivoAceptados("ACEPTADOS.DAT", ios::binary);

    if (archivoPersonas.fail() || archivoAceptados.fail()) {
        cerr << "Error al abrir archivos." << endl;
        exit(1);
    }

    Persona candidato;

    cout << "Candidatos aceptados:" << endl;
    cout << left << setw(30) << "Nombre" << setw(10) << "Edad" << setw(5) << "Sexo" << setw(12) << "Fecha Nac." << endl;
    cout << setfill('-') << setw(58) << "-" << setfill(' ') << endl;

    while (archivoPersonas.read(reinterpret_cast<char*>(&candidato), sizeof(Persona))) {
        cout << left << setw(30) << candidato.nombre << setw(10) << candidato.edad << setw(5) << candidato.sexo << setw(12) << candidato.fecha << endl;
        archivoAceptados.write(reinterpret_cast<char*>(&candidato), sizeof(Persona));
    }

    archivoPersonas.close();
    archivoAceptados.close();
}

int main() {
    int n;
    cout << "Ingrese la cantidad de personas que desea ingresar: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        escritura();
    }

    procesarCandidatos();

    return 0;
}

