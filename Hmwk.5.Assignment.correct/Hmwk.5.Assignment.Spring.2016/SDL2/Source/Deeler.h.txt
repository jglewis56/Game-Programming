#ifndef DEELER_H
#define DEELER_H

//System Headers
#include <string>

//Game Headers
#include "Object.h"

using namespace std;

class Deeler: public Object
{

public:

	Deeler(int,int, int);

	//Action methods
	void update(LK_TRANSITION, vector<Object*> &);

protected:

	bool rise;
	int moveCount;
	int moveCountMax;
	
};

#endif	
