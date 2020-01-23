#pragma once
class Object
{
private:
	int x, y;
	bool type; // 0 - static, 1 - dynamic
public:
	Object(int x, int y, bool type);
	~Object();
	bool isStatic();
	bool isDynamic();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};

