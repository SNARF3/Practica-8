// Materia: Programación I, Paralelo 1

// Autor: MARVIN MOLLO RAMIREZ

// Fecha creación: 30/11/2023

// Fecha modificación: 30/11/2023

// Número de ejericio: 9

/* Problema planteado: Escriba un programa que tenga como entrada un fichero que contenga un texto y dé como
resultado una estadística del número de palabras.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;
void escribir() {
    ofstream archivoSalida("texto.txt");
    if (!archivoSalida.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return ; 
    }
    fflush(stdin);
    string texto;
    cout << "Ingrese el texto: ";
    getline(cin, texto);
    archivoSalida << texto;
    archivoSalida.close();
    cout << "Escritura en el archivo exitosa." << endl;
}
void palabras(){
    ifstream leer("texto.txt");
    string testo;
    getline(leer, testo);
    int contador=1;
    for (char letras:testo){
        if(letras==' '){
            contador++;
        }
    }
    cout<<"en total hay: "<<contador<<" palabras."<<endl;
    leer.close();
}
int main() {
    int entrada;
    do{
        cout<<" 1.ingresar texto\n 2.ver cantidad de palabras\n 3.salir "<<endl;
        cin>>entrada;
        switch(entrada){
            case 1:
                escribir();
                break;
            case 2:
                palabras();
        }
    }while(entrada!=3);
    return 0;
}
