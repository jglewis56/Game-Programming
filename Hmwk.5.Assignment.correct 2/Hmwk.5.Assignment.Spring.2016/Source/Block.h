#ifndef BLOCK_H
#define BLOCK_H

//System Headers
#include <string>

//Game Headers
#include "Object.h"

using namespace std;

class Block: public Object
{

public:

	Block(int,int,int);

	//Action methods
	void update(LK_TRANSITION, vector<Object*> &);

protected:
	

};

#endif	
