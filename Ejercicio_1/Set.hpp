#include "ClaseBase.hpp"
#include "SuperClaseVE.hpp"
#include <vector>
#include <string>

#pragma once

using namespace std;

class Set : public ClaseBase{
	private:
		vector<SuperClaseVE*> VE;
	public:
		Set();
		string toString();
		void setVE(SuperClaseVE *);
		SuperClaseVE *getUnVE(int);
		vector<SuperClaseVE*> getVE();
};

