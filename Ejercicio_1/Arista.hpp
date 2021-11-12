#include "SeqV.hpp"
#include "SuperClaseVE.hpp"
#pragma once

using namespace std;

class Arista : public SuperClaseVE{
	private:
		SeqV *secuencia = new SeqV();
	public:
		Arista();
		Arista(SeqV *);
		string toString();
		SeqV *getSecuencia();
		void setSecuencia(SeqV *);
};
