#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"
#include "Level.h"
#include "AnimationManager.h"


class Entity
{
public:
	float x, y, dx, dy, w, h; //x,y - левый верхний угол спрайта, dx, dy - скорость, w, h - ширина, высота спрайта
	AnimationManager anim;
	std::vector<Object> obj;
	bool life, dir;
	float timer, timer_end;
	std::string Name;
	int Health;
	Entity(AnimationManager& A, int X, int Y);
	virtual void update(float time) = 0;
	void draw(sf::RenderWindow& window);
	sf::FloatRect getRect();
	void option(std::string NAME, float SPEED = 0, int HEALTH = 10, std::string FIRST_ANIM = "");


};

