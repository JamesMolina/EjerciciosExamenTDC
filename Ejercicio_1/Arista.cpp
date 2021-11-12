#include "Arista.hpp"

Arista::Arista(){

}

Arista::Arista(SeqV *_secuencia){
	secuencia = _secuencia;
}
		
void Arista::setSecuencia(SeqV *_secuencia){
	secuencia = _secuencia;	
}

SeqV *Arista::getSecuencia(){
	return secuencia;
}
		
string Arista::toString(){
	return secuencia->toString();
};
