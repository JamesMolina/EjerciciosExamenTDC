#include "Seq.hpp"

Seq::Seq(){

}
		
vector<Set*> Seq::getConjuntos(){
	return conjuntos;
}


void Seq::setConjuntos(vector<Set*> conjuntos){
	(*this).conjuntos = conjuntos;
}

void Seq::setConjunto(Set *conjunto){
	conjuntos.push_back(conjunto);
}
		
void Seq::setConjuntoV(Set *conjunto){
	conjuntos[0] = conjunto;
}
		
void Seq::setConjuntoE(Set *conjunto){
	conjuntos[1] = conjunto;
}
		
string Seq::toString(){	
	string retornar = "( ";
	for(int i = 0; i < conjuntos.size(); i++){
		retornar += conjuntos[i]->toString();
		if(i < conjuntos.size()-1)
			retornar += ", ";
	}
	retornar += " )";
	return retornar;
}
