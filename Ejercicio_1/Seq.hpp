#include "Set.hpp"
#include "ClaseBase.hpp"
#pragma once

using namespace std;

class Seq :public ClaseBase{
	private:
		vector<Set*> conjuntos;
		
	public:
		Seq();
		string toString();
		void setConjunto(Set *);
		void setConjuntoV(Set *);
		void setConjuntoE(Set *);
		vector<Set*> getConjuntos();
		void setConjuntos(vector<Set*>);
};
