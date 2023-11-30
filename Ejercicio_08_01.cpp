// Materia: Programación I, Paralelo 1

// Autor: MARVIN MOLLO RAMIREZ

// Fecha creación:26 /11/2023

// Fecha modificación: 30/11/2023

// Número de ejericio: 9

/* Problema planteado: Escribir un programa con la opción de encriptar y de desencriptar un fichero de texto.
La encriptación consiste en que dado un fichero de texto de entrada genere otro fichero de
salida de extensión <nombre>.COD donde el texto estará codificado (encriptado).
Esta codificación consiste en reemplazar cada carácter por el tercero siguiente según la tabla
ASCII.
La opción de desencriptado consiste en leer un fichero <nombre>.COD y recuperar la
información original. */

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
void encriptar(){
	ofstream e;
	e.open("pepito.COD");
	string texto;
	if(e.fail()){
		cout<<"NO se pudo crear";
		exit(1);
	}
	fflush(stdin);
	cout<<"escribe el texto que quieras encriptar"<<endl;
	getline(cin,texto);
	for(char encrip:texto){
		encrip=encrip+3;
		e<<encrip;
	}
	e.close();
	cout<<"texto encriptado correctamente"<<endl;
	
}
void desencripar(){
	ifstream o;
	o.open("pepito.COD");
	string texto;
	getline(o,texto);
	string testo;
	for(char letras:texto){
		letras=letras-3;
		testo+=letras;
	}
	o.close();
	cout<<"el texto desencriptado es el siguiente: "<<endl;
	cout<<"--------------------------------------\n";
	cout<<testo<<endl;
	cout<<"--------------------------------------\n";
}

int main() {
    int opcion;
	do{
		cout << "Seleccione una opcion:\n";
    	cout << "1. Encriptar\n";
    	cout << "2. Desencriptar\n";
    	cout<<"3. Salir\n";
    	cin >> opcion;
		switch (opcion) {
        case 1:
            encriptar();
            break;
        case 2:
            desencripar();
            break;
        default:
            break;
    }
	}while(opcion!=3);
    
    return 0;
}

