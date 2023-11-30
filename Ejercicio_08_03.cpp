// Materia: Programación I, Paralelo 1

// Autor: MARVIN MOLLO RAMIREZ

// Fecha creación: 26/11/2023

// Fecha modificación: 30/11/2023

// Número de ejericio: 9

/* Problema planteado: Amplíe el programa anterior que procesa clientes de una agencia matrimonial para que tome
los datos de todos los candidatos a estudiar del fichero PERSONAS.DAT del ejercicio anterior,
lea el cliente del teclado y finalmente genere como resultado un listado por pantalla con los
nombres de los candidatos aceptados y un fichero llamado ACEPTADOS.DAT con toda la
información correspondiente a los candidatos aceptados.
Una persona del fichero PERSONAS.DAT se considerará aceptable como candidato si tiene
diferente sexo y que haya nacido en el mes y año (El programa debe ser capaz de trabajar con
cualquier número de personas en el fichero PERSONAS.DAT). */


#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Persona {
    char nombre[30];
    int edad;
    char sexo[2];
    char fecha[10];
};

void escritura() {
    ofstream archivoPersonas;
    archivoPersonas.open("Personas.BIN", ios::app | ios::binary);

    if (archivoPersonas.fail()) {
        cout << "No se pudo crear el archivo." << endl;
        exit(1);
    }

    Persona persona;
    cout << "Nombre: " << endl;
    fflush(stdin);
    cin.getline(persona.nombre, 30);

    if (persona.nombre[0] == ' ') {
        cerr << "Nombre no válido." << endl;
        exit(1);
    }

    cout << "Ingrese su edad: " << endl;
    cin >> persona.edad;

    if (persona.edad > 100 || persona.edad < 1) {
        cout << "Ingrese su edad nuevamente: " << endl;
        cin >> persona.edad;
    }

    cin.ignore();  // Limpiar el buffer de entrada antes de getline

    cout << "Sexo (M/F): ";
    cin.ignore();
    cin.getline(persona.sexo, 2);

    if (persona.sexo[0] != 'M' && persona.sexo[0] != 'F') {
        cout << "Sexo no válido. Por favor, ingrese 'M' o 'F': " << endl;
        cin.getline(persona.sexo, 2);  // Asegúrate de tener suficiente espacio para '\0'
    }

    cout << "Fecha de nacimiento (dd/mm/yyyy): " << endl;
    cin.ignore();
    cin.getline(persona.fecha, 10);

    archivoPersonas.write(reinterpret_cast<char*>(&persona), sizeof(Persona));
    archivoPersonas.close();
    cout << "Datos guardados correctamente" << endl;
}

void leer_personas() {
    ifstream archivoPersonas("Personas.BIN", ios::binary);

    if (!archivoPersonas.is_open()) {
        cerr << "No se pudo abrir el archivo de personas." << endl;
        exit(1);
    }

    Persona persona;
    while (archivoPersonas.read(reinterpret_cast<char*>(&persona), sizeof(Persona))) {
        cout << "Nombre: " << persona.nombre << ", Edad: " << persona.edad << ", Sexo: " << persona.sexo << ", Fecha de nacimiento: " << persona.fecha << endl;
    }

    archivoPersonas.close();
}

void buscar_y_mostrar_candidatos(const Persona& candidato) {
    ifstream archivoPersonas("Personas.BIN", ios::binary);

    if (!archivoPersonas.is_open()) {
        cerr << "No se pudo abrir el archivo de personas." << endl;
        exit(1);
    }

    Persona persona;
    while (archivoPersonas.read(reinterpret_cast<char*>(&persona), sizeof(Persona))) {
        // Condiciones para ser un candidato aceptable
        if (candidato.edad >= 18 && candidato.edad <= 100 &&
            strcmp(candidato.sexo, persona.sexo) != 0 &&
            strncmp(candidato.fecha, persona.fecha + 3, 7) == 0) {
            cout << "Nombre: " << persona.nombre << ", Edad: " << persona.edad << ", Sexo: " << persona.sexo << ", Fecha de nacimiento: " << persona.fecha << endl;
        }
    }

    archivoPersonas.close();
}

int main() {
    // Leer datos del candidato desde el teclado
    Persona candidato;
    cout << "Ingrese sus datos:" << endl;
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(candidato.nombre, 30);

    cout << "Edad: ";
    cin >> candidato.edad;

    cout << "Sexo (M/F): ";
    cin.ignore();
    cin.getline(candidato.sexo, 2);

    cout << "Fecha de nacimiento (dd/mm/yyyy): ";
    cin.ignore();
    cin.getline(candidato.fecha, 10);

    // Mostrar candidatos aceptables
    cout << "Candidatos aceptables: " << endl;
    buscar_y_mostrar_candidatos(candidato);

    return 0;
}
