#ifndef BLOCK_H
#define BLOCK_H
#include"Object.h"
#include <string> 

using namespace std;
class Block : public Object
{
public:
	Block(int,int);
	void update(LK_TRANSITION);
};

#endif	
