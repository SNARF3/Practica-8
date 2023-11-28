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

