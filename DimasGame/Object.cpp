#include "Object.h"

Object::Object(int x, int y, bool type)
{
	this->x = x;
	this->y = y;
	this->type = type;
}

Object::~Object()
{
}

bool Object::isStatic()
{
	return !type;
}

bool Object::isDynamic()
{
	return type;
}

int Object::getX()
{
	return x;
}

int Object::getY()
{
	return y;
}

void Object::setX(int x)
{
	this->x = x;
}

void Object::setY(int y)
{
	this->y = y;
}
