#include "Set.hpp"
#include "Vertice.hpp"
Set::Set(){

}
		
void Set::setVE(SuperClaseVE *_VE){
	bool guardar = true;
	for(int i = 0; i < VE.size(); i++){
		if( ((Vertice *)VE[i])->getValor() == ((Vertice *)_VE)->getValor())
			guardar = false;
	}
	if(guardar)
		VE.push_back(_VE);
}
		
SuperClaseVE *Set::getUnVE(int index){
	return VE[index];
}
		
vector<SuperClaseVE*> Set::getVE(){
	return VE;
}
		
string Set::toString(){
	string retornar = "{ ";
	for(int i = 0; i < VE.size(); i++){
		retornar += VE[i]->toString();
		if(i < VE.size()-1)
			retornar += ", ";
	}
	retornar += " }";
	return retornar;
}

