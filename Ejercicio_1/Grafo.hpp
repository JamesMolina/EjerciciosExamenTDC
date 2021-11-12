#include "Seq.hpp"
#pragma once

using namespace std;

class Grafo{
	private:
		Seq *secuencia = new Seq();
	public:
		Grafo();
		string toString();
		Seq *getSecuencia();
		void setSecuencia(Seq *);
};
