#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h> 
#include "tablaVerdad.hpp"

using namespace std;
tablaVerdad *tabla = new tablaVerdad();

string cargarArchivo(){
	string nombreArchivo = "tabla.txt";
	//cout << "Ingrese el nombre del archivo [Unit Test: tabla.txt]: ";
	//cin >> nombreArchivo;
	return nombreArchivo;
}

bool obtenerMatriz(string archivo){
	return tabla->cargarMatriz(archivo);
}

void imprimir(){
	tabla->printTabla();
}

bool EsUnNumero(string cadena){
  for(int i = 0 ; i < cadena.size(); i++ )
    if( !isdigit(cadena[i]) )
      return false;
  return true;
}

int obtenerOpcion(int num){
	int opcion = -1;
	string opcionAux;
	cout << endl << "0. Piedra" << endl;
	cout << "1. Papel" << endl;
	cout << "2. Tijera" << endl;
	cout << "3. Lagartija" << endl;
	cout << "4. Spoke" << endl;
	do{
		cout << "Jugador " << num << ": ";
		cin >> opcionAux;
		if(EsUnNumero(opcionAux))
			opcion = stoi(opcionAux);
	}while(opcion < 0 || opcion > 5);
	return opcion;
}

void ganador(int jugador_1, int jugador_2){
	int gano_1 = tabla->devolverGanador(jugador_1, jugador_2);
	cout << endl;
	if(gano_1 == 1)
		cout << "Ha ganado el jugador #1" << endl;
	else if(gano_1 == 0)
		cout << "Ha ganado el jugador #2" << endl;
	else
		cout << "Ha quedado en empate" << endl;
}

void jugar(){
	int seguir, jugador_1, jugador_2;
	string seguirAux;
	do{
		jugador_1 = obtenerOpcion(1);
		jugador_2 = obtenerOpcion(2);
		ganador(jugador_1, jugador_2);
		cout << endl << "Desea continuar[No = 0]: ";
		cin >> seguirAux;
		if(EsUnNumero(seguirAux))
			seguir = stoi(seguirAux);
		else
			seguir = 1;
	}while(seguir);
}

void inicio(){
	int opcion;
	string opcionAux;
	do{
		cout << endl << endl;
		cout << "0. Salir" << endl;
		cout << "1. Imprimir Tabla" << endl;
		cout << "2. Jugar" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcionAux;
		if(EsUnNumero(opcionAux)){
			opcion = stoi(opcionAux);
			if(opcion == 1)
				imprimir();
			else if(opcion == 2)
				jugar();
		}
	}while(opcion);
}

int main(int argc, char** argv) {
	if( obtenerMatriz(cargarArchivo()) )
		inicio();
	delete tabla;
	return 0;
}


