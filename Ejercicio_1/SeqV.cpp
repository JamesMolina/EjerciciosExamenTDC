#include "SeqV.hpp"


SeqV::SeqV(){

}
		
SeqV::SeqV(SuperClaseVE *_x, SuperClaseVE *_y){
	x = _x;
	y = _y;	
}
		
void SeqV::setX(SuperClaseVE *_x){
	x = _x;			
}
		
void SeqV::setY(SuperClaseVE *_y){
	y = _y;			
}
		
SuperClaseVE *SeqV::getX(){
	return x;		
}
		
SuperClaseVE *SeqV::getY(){
	return y;		
}
		
string SeqV::toString(){
	return "( " + x->toString() + ", " + y->toString() + " )";
}

