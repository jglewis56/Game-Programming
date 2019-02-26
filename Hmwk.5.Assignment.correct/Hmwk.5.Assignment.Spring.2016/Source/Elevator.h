#ifndef ELEVATOR_H
#define ELEVATOR_H

//System Headers
#include <string>

//Game Headers
#include "Object.h"

using namespace std;

class Elevator: public Object
{

public:

	Elevator(int,int,int);

	//Action methods
	void update(LK_TRANSITION, vector<Object*> &);

protected:
	

};

#endif	
