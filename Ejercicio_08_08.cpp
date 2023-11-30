// Materia: Programación I, Paralelo 1

// Autor: Marvin Mollo Ramirez

// Fecha creación: 30/11/2023

// Fecha modificación: 30/11/2023

// Número de ejericio: 8

/* Problema planteado: Escribir un programa que genere a partir de un fichero de entrada que contiene una tabla de
números reales otro fichero de salida <nombre>.BIN grabado en formato binario. */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generar_archivo_reales(const string&);
void convertir_a_binario(const string&, const string&);

int main() {
    const string archivo_reales = "SALIDAs.txt";
    const string archivo_binarios = "SALIDABIN.bin";

    // Generar el archivo "reales.txt" con números del 14 al 110
    generar_archivo_reales(archivo_reales);

    // Convertir los números a binario y guardar en "binarios.BIN"
    convertir_a_binario(archivo_reales, archivo_binarios);

    return 0;
}

void generar_archivo_reales(const string& nombre_archivo) {
    ofstream salida(nombre_archivo);

    if (!salida.is_open()) {
        cout << "No se pudo abrir el archivo de salida." << endl;
        return;
    }

    srand(time(0));
    int inferior = 14;
    int superior = 110;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; j++) {
            double valores = inferior + rand() % (superior - inferior + 1);
            double numero = valores;
            salida << numero << " ";
        }
        salida << "\n";
    }

    cout << "Archivo llenado correctamente con nmeros aleatorios" << endl;
    salida.close();
}

void convertir_a_binario(const string& nombre_archivo_entrada, const string& nombre_archivo_salida) {
    ifstream entrada(nombre_archivo_entrada);
    ofstream salida(nombre_archivo_salida, ios::binary);
    double numero;
    while (entrada >> numero) {
        salida.write(reinterpret_cast<const char*>(&numero), sizeof(double));
    }

    entrada.close();
    salida.close();
}


