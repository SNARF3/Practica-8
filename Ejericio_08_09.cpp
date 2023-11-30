// Materia: Programación I, Paralelo 1

// Autor: MARVIN MOLLO RAMIREZ

// Fecha creación: 30/11/2023

// Fecha modificación: 30/11/2023

// Número de ejericio: 9

/* Problema planteado: Dado una tabla grabada en un fichero en formato binario <nombre>.BIN hallar la suma
horizontal y vertical y grabar la tabla y los resultados en otro fichero de texto o binario según se
introduzca por pantalla. */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void leer_desde_binario(const string& archivo, vector<vector<double>>& matriz);
void calcular_suma_horizontal_vertical(vector<vector<double>>& matriz);
void imprimir_matriz(vector<vector<double>> matriz);
void guardar_resultados(vector<vector<double>> matriz, const string archivo);

int main() {
    const string archivo_entrada = "SALIDABIN.bin";
    const string archivo_salida = "resultados.txt";
    vector<vector<double>> matriz;

    leer_desde_binario(archivo_entrada, matriz);
    calcular_suma_horizontal_vertical(matriz);
    guardar_resultados(matriz, archivo_salida);

    imprimir_matriz(matriz);

    cout << endl;
    cout << "Resultados guardados en: " << archivo_salida << endl;

    return 0;
}

void leer_desde_binario(const string& archivo, vector<vector<double>>& matriz) {
    ifstream entrada(archivo, ios::binary);

    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo de entrada" << endl;
        return;
    }

    double elemento;
    for (int i = 0; i < 3; i++) {
        vector<double> fila;
        for (int j = 0; j < 3; j++) {
            entrada.read(reinterpret_cast<char*>(&elemento), sizeof(double));
            fila.push_back(elemento);
        }
        matriz.push_back(fila);
    }

    entrada.close();
}

void calcular_suma_horizontal_vertical(vector<vector<double>>& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();

    for (int i = 0; i < filas; ++i) {
        double suma_horizontal = 0.0;
        for (int j = 0; j < columnas; ++j) {
            suma_horizontal += matriz[i][j];
        }
        matriz[i].push_back(suma_horizontal);
    }

    matriz.push_back(matriz[0]);

    for (int i = 0; i < columnas + 1; ++i) {
        double suma_vertical = 0.0;
        for (int j = 0; j < filas; ++j) {
            suma_vertical += matriz[j][i];
        }
        matriz[matriz.size() - 1][i] = suma_vertical;
    }
}

void imprimir_matriz(vector<vector<double>> matriz) {
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++)
            cout << matriz[i][j] << "  |";
        cout << "\n";
    }
}

void guardar_resultados(vector<vector<double>> matriz, const string archivo) {
    ofstream salida(archivo);

    if (!salida.is_open()) {
        cout << "No se pudo abrir el archivo de salida." << endl;
        return;
    }

    int filas = matriz.size();
    int columnas = matriz[0].size();

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            salida << matriz[i][j] << "\t";
        }
        salida << "\n";
    }

    salida.close();
}
