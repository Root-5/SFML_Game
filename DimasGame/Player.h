#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	enum { stay, walk, duck, jump, climb, swim } STATE;
	bool onLadder, shoot, hit;
	std::map<std::string, bool> key;
	Player(AnimationManager& a, Level& lev, int x, int y);
	void Keyboard();
	void Animation(float time);
	void update(float time);
	void Collision(int num);
};

