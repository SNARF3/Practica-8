// Materia: Programación I, Paralelo 1

// Autor: MARVIN MOLLO RAMIREZ

// Fecha creación: 26/11/2023

// Fecha modificación: 30/11/2023

// Número de ejericio: 9

/* Problema planteado: Codifique un programa que cree un fichero para contener los datos relativos a los artículos de
un almacén.
Para cada artículo habrá de guardar la siguiente información:
• Código del artículo (Numérico)
• Nombre del artículo (Cadena de caracteres)
• Existencias actuales (Numérico)
• Precio (Numérico decimal).
Se deberán pedir datos de cada artículo por teclado hasta que como código se teclee el código
0.
El fichero se habrá de crear ordenado por el código del artículo. */

#include <iostream>
#include <fstream>
#include <stdlib.h>
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

void escribirEnArchivo(Producto p[], int tamano) {
    ofstream archivo("Archivo.txt", ios::app);
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

void pedirDatos(Producto p[], int& tamano) {
    Producto w;
    cout << "Ingrese el codigo del producto (0 para salir): ";
    cin >> w.codigo;

    if (w.codigo == 0) {
        exit(1);
    }

    cout << "Ingrese la cantidad existente del producto: ";
    cin >> w.existencia;

    cout << "Ingrese el precio del producto: ";
    cin >> w.precio;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    cin.getline(w.nombre, 30);

    p[tamano++] = w;
}

int main() {
    const int MAX_PRODUCTOS = 100;
    Producto p[MAX_PRODUCTOS];
    int tamano = 0;

    while (true) {
        pedirDatos(p, tamano);

        if (tamano == 0) {
            cout << "No se ingresaron productos. Saliendo del programa." << endl;
            break;
        }

        ordenarPorCodigo(p, tamano);
        escribirEnArchivo(p, tamano);
    }

    return 0;
}

