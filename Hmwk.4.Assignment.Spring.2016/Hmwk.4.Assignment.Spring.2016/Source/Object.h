#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
	Object();
	Object(int,int);
	//Get Methods
	float getPosX() const;
	float getPosY() const;
	int getObjectID()const;
	int getSpriteID() const;
	//Set Methods
	void setPosX(float);
	void setPosY(float);
	int setObjectID(OBJECT_ID);
	void setSpriteID(int);
	int plotX();
	int plotY();
	virtual void update(LK_TRANSITION)=0;
protected:
	float posX;
	float posY;
	OBJECT_ID objectID;
	int spriteID;
};


#endif