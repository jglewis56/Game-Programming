#ifndef BLOCK_H
#define BLOCK_H
#include "constants.h"
using namespace std;

class Block
{
private:
	float posX;
	float posY;
	float velY;
	bool reached;
public:
	Block(float,float);
	~Block();
	void update(float);
	int getPosX() const;
	int getPosY() const;
	bool getReached();
	void setPosX(float x);
	void setPosY(float y);
	void setReached(bool reached);

};

#endif	
