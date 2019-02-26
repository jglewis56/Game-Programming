#include "constants.h"
#include "Object.h"

using namespace std;

Object::Object(int posX, int posY, int velY){
	
	//Convert to floating point internal representation
	this->posX = (float)posX;
	this->posY = (float)posY;
	this->velY = (float)velY;
	
	//Assign graphics properties
	width = -1;
	height = -1;

	//Assign base object type
	objectID = OBJECT;

	//No base art asset
	spriteID = -1;
}
	
//Get Methods
float Object::getPosX() const{
	return(posX);
}

float Object::getPosY() const{
	return(posY);
}

float Object::getVelY() const {
	return(velY);
}

int Object::getWidth() const {
	return(width);
}

int Object::getHeight() const {
	return(height);
}

int Object::getObjectID() const{
	return(objectID);
}


int Object::getSpriteID() const{
	return(spriteID);
}

//Set Methods
void Object::setPosX(float posX){
	this->posX = posX;
}

void Object::setPosY(float posY){
	this->posY = posY;
}

void Object::setVelY(float velY) {
	this->velY = velY;
}

void Object::setWidth(int width) {
	this->width = width;
}

void Object::setHeight(int height) {
	this->width = height;
}

void Object::setObjectID(OBJECT_ID objectID){
	this->objectID = objectID;
}

void Object::setSpriteID(int spriteID){
	this->spriteID = spriteID;
}

//Plotting Methods
int Object::plotX(){
	return((int)posX);
}

int Object::plotY(){
	return((int)posY);
}