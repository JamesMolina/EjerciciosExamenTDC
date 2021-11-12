#include "SuperClaseVE.hpp"

#pragma once

using namespace std;

class Vertice : public SuperClaseVE{
	private:
		int valor;
		string etiqueta = "";
	public:
		Vertice();
		Vertice(int);
		int getValor();
		string toString();
		void setValor(int);
		string getEtiqueta();
		void setEtiqueta(string);
		string toStringConEtiqueta();
};
