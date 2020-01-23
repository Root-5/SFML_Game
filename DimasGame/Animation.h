#pragma once
#include <SFML\Graphics.hpp>


class Animation
{
public:
	std::vector<sf::IntRect> frames, frames_flip;
	bool flip, isPlaying, loop; //поворот, живой ли объект и петля
	float speed, currentFrame; //скорость, текущий кадр
	sf::Sprite sprite;


	Animation();
	~Animation() {};
	void tick(float time);

};

