// Materia: Programación I, Paralelo 1

// Autor: MARVIN MOLLO RAMIREZ

// Fecha creación: 26/11/2023

// Fecha modificación: 30/11/2023

// Número de ejericio: 9

/* Problema planteado: Escriba un programa que cree un fichero de texto llamado "PERSONAS.BIN" en el que se
guarde la información de un número indeterminado de personas.
La información que se guardará por cada persona será:
• Nombre: De 1 a 30 caracteres.
• Edad numérico (>= 1 y <=100)
• Sexo CHAR (M/F).
• FechaNacimiento CHAR(10) (formato dd/mm/yyyy)
La información correspondiente a cada persona se leerá del teclado.
El proceso finalizará cuando se teclee un campo "Nombre" que esté solamente con el carácter
de espacio. */

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct personas{
    char nombre[30];
    int edad;
    char sexo[2];
    char fecha[10];
};
void escritura(){
    ofstream xd;
    xd.open("Personas.BIN", ios::app | ios::binary);
    if(xd.fail()){
		cout<<"NO se pudo crear";
		exit(1);
	}
    personas personitas;
    int edad;
    cout<<"Nombre: "<<endl;
    fflush(stdin);
    cin.getline(personitas.nombre, 30);
    if (personitas.nombre[0] == ' ') {
        cerr << "Nombre no valido." << endl;
        exit(1);
    }
    cout<<"Ingrese su edad"<<endl;
    cin>>personitas.edad;
    if(personitas.edad>100||personitas.edad<1){
    	cout<<"ingrese su edad nuevamente: "<<endl;
    	cin>>personitas.edad;
    }
	cin.ignore();  // Limpiar el buffer de entrada antes de getline

	cout << "Sexo (M/F): ";
	cin.ignore();
	cin.getline(personitas.sexo, 2);
	
	if (personitas.sexo[0] != 'M' || personitas.sexo[0] != 'F') {
    	cout << "Sexo no valido. Por favor, ingrese 'M' o 'F': " << endl;
    	cin.getline(personitas.sexo, 2);  // Aseg�rate de tener suficiente espacio para '\0'
	}
    cout<<"fecha de nacimiento (dd/mm/yyyy): "<<endl;
    cin.ignore();
    cin.getline(personitas.fecha, 10);
    xd.write(reinterpret_cast<char*>(&personitas), sizeof(personas));
    xd.close();
    cout<<"datos guardados correctamente"<<endl;
}
int main() {
    int n;
    cout<<"ingrese la cantidad de personas que desea ingresar: "<<endl;
    cin>>n;
    for (int i=0;i<n; i++){
        escritura();
    }
    return 0;
}

