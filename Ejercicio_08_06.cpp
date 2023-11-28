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
void leer(){
    ifstream archivo;
    archivo.open("Archivo.txt");
    
}

int main() {
    const int MAX_PRODUCTOS = 100;
    Producto p[MAX_PRODUCTOS];
    int tamano = 0;

    while (true) {
       
    }

    return 0;
}

