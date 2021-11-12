#include "SuperClaseVE.hpp"
#include <vector>
#include "ClaseBase.hpp"
#pragma once

using namespace std;

class SeqV : public ClaseBase{
	private:
		SuperClaseVE *x = new SuperClaseVE(); 
		SuperClaseVE *y = new SuperClaseVE();
	public:
		SeqV();
		string toString();
		SuperClaseVE *getX();
		SuperClaseVE *getY();
		void setX(SuperClaseVE *);
		void setY(SuperClaseVE *);
		SeqV(SuperClaseVE *, SuperClaseVE *);
};
