// Materia: Programación I, Paralelo 1

// Autor: MARVIN MOLLO RAMIREZ

// Fecha creación: 26/11/2023

// Fecha modificación: 30/11/2023

// Número de ejericio: 9

/* Problema planteado: Escriba un programa que tome como entrada el fichero del ejercicio 4 y una condición sobre el
campo Precio. La condición podrá ser:
Precio mayo o igual a 100 o cualquier otro dato ingresado por teclado.
Este programa debe generar como salida un fichero llamado "salida.dat" que contenga todos
aquellos artículos para los que se cumple la condición de entrada.
Mostrar el archivo de salida “salida.dat”
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Producto {
    int codigo;
    int existencia;
    double precio;
    char nombre[30];
};

void leerDesdeArchivo(vector<Producto>& productos) {
    ifstream archivoEntrada("Archivo.txt");
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        exit(1);
    }

    Producto producto;
    while (archivoEntrada >> producto.codigo >> producto.existencia >> producto.precio) {
        archivoEntrada.ignore();  // Ignorar el espacio en blanco después del precio
        archivoEntrada.getline(producto.nombre, 30);
        productos.push_back(producto);
    }

    archivoEntrada.close();
}

void escribirEnArchivo(const vector<Producto>& productos, const char* nombreArchivo) {
    ofstream archivoSalida(nombreArchivo);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return;
    }

    for (const auto& producto : productos) {
        archivoSalida << "Codigo: " << producto.codigo << "\t"
                      << "Existencia: " << producto.existencia << "\t"
                      << "Precio: " << producto.precio << "\t"
                      << "Nombre: " << producto.nombre << endl;
    }

    archivoSalida.close();
    cout << "Se ha generado el archivo de salida '" << nombreArchivo << "'." << endl;
}

void filtrarYGuardarPorPrecio(const vector<Producto>& productos, double precioLimite) {
    vector<Producto> productosFiltrados;
    
    for (const auto& producto : productos) {
        if (producto.precio >= precioLimite) {
            productosFiltrados.push_back(producto);
        }
    }

    escribirEnArchivo(productosFiltrados, "salida.txt");
}

int main() {
    vector<Producto> productos;
    leerDesdeArchivo(productos);

    filtrarYGuardarPorPrecio(productos, 100);

    return 0;
}
