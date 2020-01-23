#pragma once
#include "Entity.h"


class Bullet : public Entity
{
public:
	Bullet(AnimationManager& a, Level& lev, int x, int y, bool dir);
	void update(float time);


};

