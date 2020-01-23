#pragma once
#include <SFML\Graphics.hpp>


class Animation
{
public:
	std::vector<sf::IntRect> frames, frames_flip;
	bool flip, isPlaying, loop; //�������, ����� �� ������ � �����
	float speed, currentFrame; //��������, ������� ����
	sf::Sprite sprite;


	Animation();
	~Animation() {};
	void tick(float time);

};

