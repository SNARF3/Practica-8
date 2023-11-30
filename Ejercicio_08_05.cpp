// Materia: Programación I, Paralelo 1

// Autor: MARVIN MOLLO RAMIREZ

// Fecha creación: 26/11/2023

// Fecha modificación: 30/11/2023

// Número de ejericio: 9

/* Problema planteado: Escriba un programa que dados dos ficheros generados por el programa anterior y ordenados
genere un tercer fichero que sea el resultado de mezclar de formar ordenada los dos primeros. */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Producto {
    int codigo;
    int existencia;
    double precio;
    char nombre[30];
};

void ordenarPorCodigo(Producto p[], int tamano) {
    sort(p, p + tamano,
         [](const Producto& a, const Producto& b) {
             return a.codigo < b.codigo;
         });
}

void escribirEnArchivo(Producto p[], int tamano, const char* nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::app);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    for (int i = 0; i < tamano; ++i) {
        archivo << "Codigo: " << p[i].codigo << "\t"
                << "Existencia: " << p[i].existencia << "\t"
                << "Precio: " << p[i].precio << "\t"
                << "Nombre: " << p[i].nombre << endl;
    }
    archivo.close();
}

void leerDeArchivo(Producto p[], int& tamano, const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }
    while (archivo >> p[tamano].codigo >> p[tamano].existencia >> p[tamano].precio) {
        archivo.ignore(); // Ignorar el espacio después del precio
        archivo.getline(p[tamano].nombre, 30);
        tamano++;
    }
    archivo.close();
}

void mezclarFicheros(const char* nombreArchivo1, const char* nombreArchivo2, const char* nombreArchivoSalida) {
    const int MAX_PRODUCTOS = 200; // El doble del tamaño máximo de productos
    Producto p[MAX_PRODUCTOS];
    int tamano1 = 0, tamano2 = 0;

    leerDeArchivo(p, tamano1, nombreArchivo1);
    leerDeArchivo(p + tamano1, tamano2, nombreArchivo2);

    ordenarPorCodigo(p, tamano1 + tamano2);
    escribirEnArchivo(p, tamano1 + tamano2, nombreArchivoSalida);
}

int main() {
    const char* archivo1 = "Archivo1.txt";
    const char* archivo2 = "Archivo2.txt";
    const char* archivoSalida = "ArchivoSalida.txt";

    mezclarFicheros(archivo1, archivo2, archivoSalida);

    return 0;
}
