#ifndef DEELER_H
#define DEELER_H
#include"Object.h"
class Deeler : public Object
{
public:
	Deeler();
	Deeler(int, int);
	void update(LK_TRANSITION);
protected:
	bool rise;
	int moveCount;
	int moveCountMax;
};


#endif	
