#include "Vertice.hpp"

Vertice::Vertice(){

}


Vertice::Vertice(int valor){
	(*this).valor = valor;
}

int Vertice::getValor(){
	return valor;
}

void Vertice::setValor(int valor){
	(*this).valor = valor;
}

void Vertice::setEtiqueta(string _etiqueta){
	etiqueta = _etiqueta;
}

string Vertice::getEtiqueta(){
	return etiqueta;
}

string Vertice::toString(){
	return to_string(valor);
}
		
string Vertice::toStringConEtiqueta(){
	string retornar = to_string(valor);
	if(etiqueta != "")
		retornar += " etiqueta = { " + etiqueta +" } ";
	return retornar;
}

