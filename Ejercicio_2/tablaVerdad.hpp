#include <string>
#pragma once

using namespace std;

class tablaVerdad{
	private:
		int matriz[5][5];
	public:
		tablaVerdad();
		void printTabla();
		bool cargarMatriz(string);
		int devolverGanador(int,int);
		void imprimirTipo(int);
};
