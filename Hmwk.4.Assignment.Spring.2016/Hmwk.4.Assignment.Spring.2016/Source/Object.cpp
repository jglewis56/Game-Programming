#include "constants.h"
#include "Object.h"
using namespace std;
Object::Object()
{

}
Object::Object(int posX, int posY)
{
	this->posX = (float)posX;
	this->posY = (float)posY;
	objectID = OBJECT;
	spriteID = -1;
};
float Object::getPosX() const
{
	return(posX);
}
float Object::getPosY() const
{
	return(posY);
}
int Object::getObjectID() const
{
	return(objectID);
}
int Object::getSpriteID() const
{
	return(spriteID);
}
//Set Methods
void Object::setPosX(float posX)
{
	this->posX = posX;
}
void Object::setPosY(float posY)
{
	this->posY = posY;
}
int Object::setObjectID(OBJECT_ID objectID)
{
	this->objectID = objectID;
	return(objectID);
}
void Object::setSpriteID(int spriteID)
{
	this->spriteID = spriteID;
}
//Plotting Methods 
int Object::plotX()
{
	return((int)posX);
}
int Object ::plotY()
{
	return((int)posY);
}