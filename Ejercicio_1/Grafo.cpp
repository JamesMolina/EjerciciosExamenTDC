#include "Grafo.hpp"

Grafo::Grafo(){
	
}

void Grafo::setSecuencia(Seq *_secuencia){
	secuencia = _secuencia;
}

Seq *Grafo::getSecuencia(){
	return secuencia;	
}

string Grafo::toString(){
	return " G = " + secuencia->toString();
}
