#include "tablaVerdad.hpp"
#include <iostream>
#include <fstream>
#include<windows.h>

using namespace std;

tablaVerdad::tablaVerdad(){
}
		

bool tablaVerdad::cargarMatriz(string archivo){
	string lineas;
	int fila = 0, columna = 0;
	ifstream f( archivo );
 	if ( f.is_open() ) {
 		getline( f, lineas );
 		while( !f.eof() ) {
			for(int i = 0; i < lineas.size(); i++){
				if(lineas[i] != '|')
				if(lineas[i] == '0')
					matriz[fila][columna++] = 0;
				else if(lineas[i] == '1')
					matriz[fila][columna++] = 1;
				else if(lineas[i] == '2')
					matriz[fila][columna++] = 2;
			}
 			fila++;
 			columna = 0;
 			getline( f, lineas );
 		}
 		return true;
 	}
 	else{
 		cerr << "Error al abrir el archivo." << endl;
 		return false;
	} 
}

int tablaVerdad::devolverGanador(int jugador_1, int jugador_2){
	return matriz[jugador_1][jugador_2];
}

void tablaVerdad::printTabla(){
	HANDLE  consola;
	int color;
  	consola = GetStdHandle(STD_OUTPUT_HANDLE);
  	SetConsoleTextAttribute(consola, 7);
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|            |";
	SetConsoleTextAttribute(consola, 4);
	cout << "   Piedra   ";
	SetConsoleTextAttribute(consola, 7);
	cout << "|";
	SetConsoleTextAttribute(consola, 6);
	cout << "   Papel    ";
	SetConsoleTextAttribute(consola, 7);
	cout << "|";
	SetConsoleTextAttribute(consola, 5);
	cout << "  Tijera    ";
	SetConsoleTextAttribute(consola, 7);
	cout << "|";
	SetConsoleTextAttribute(consola, 2);
	cout << " Lagartija  ";
	SetConsoleTextAttribute(consola, 7);
	cout << "|";
	SetConsoleTextAttribute(consola, 3);
	cout << "   Spoke    ";
	SetConsoleTextAttribute(consola, 7);
	cout  << "|" << endl;	
	cout << "------------------------------------------------------------------------------" << endl;
	for(int i = 0; i < 5; i++){
		imprimirTipo(i);
		for(int j = 0; j < 5; j++){
			if(matriz[i][j] == 1){
				if(i == 0)
					SetConsoleTextAttribute(consola, 4);
				if(i == 1)
					SetConsoleTextAttribute(consola, 6);
				if(i == 2)
					SetConsoleTextAttribute(consola, 5);
				if(i == 3)
					SetConsoleTextAttribute(consola, 2);
				if(i == 4)
					SetConsoleTextAttribute(consola, 3);
				cout << "      V     ";
			}else if(matriz[i][j] == 0){
				if(j == 0)
					SetConsoleTextAttribute(consola, 4);
				if(j == 1)
					SetConsoleTextAttribute(consola, 6);
				if(j == 2)
					SetConsoleTextAttribute(consola, 5);
				if(j == 3)
					SetConsoleTextAttribute(consola, 2);
				if(j == 4)
					SetConsoleTextAttribute(consola, 3);
				cout << "      F     ";
			}else if(matriz[i][j] == 2){
				SetConsoleTextAttribute(consola, 7);
				cout << "      F     ";
			}
			SetConsoleTextAttribute(consola, 7);
			cout << "|";
		}	
		cout << endl;
	}
	cout << "------------------------------------------------------------------------------" << endl;
}


void tablaVerdad::imprimirTipo(int numero){
	HANDLE  consola;
	int color;
  	consola = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consola, 7);
	cout << "|";
	if( numero == 0){
		SetConsoleTextAttribute(consola, 4);
		cout << " Piedra     ";
	}else if( numero == 1){
		SetConsoleTextAttribute(consola, 6);
		cout << " Papel      ";
	}else if( numero == 2){
		SetConsoleTextAttribute(consola, 5);
		cout << " Tijera     ";
	}else if( numero == 3){
		SetConsoleTextAttribute(consola, 2);
		cout << " Lagartija  ";
	}else if( numero == 4){
		SetConsoleTextAttribute(consola, 3);
		cout << " Spoke      ";	
	}
	SetConsoleTextAttribute(consola, 7);
	cout << "|";
}


