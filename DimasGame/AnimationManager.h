#pragma once
#include <map>
#include <iostream>
#include "Animation.h"
#include "TinyXML/tinyxml.h"

class AnimationManager
{
private:
	std::string currentAnim;
	std::map<std::string, Animation> animList;

public:
	AnimationManager();
	~AnimationManager();
	void create(std::string name, sf::Texture& texture, int x, int y, int w, int h, int count, float speed, int step = 0, bool Loop = true);
	void loadFromXML(std::string fileName, sf::Texture& t);
	void set(std::string name);
	void draw(sf::RenderWindow& window, int x = 0, int y = 0);
	void flip(bool b = 1) { animList[currentAnim].flip = b; }
	void tick(float time) { animList[currentAnim].tick(time); }
	void play() { animList[currentAnim].isPlaying = true; }
	void pause() { animList[currentAnim].isPlaying = false; }
	void play(std::string name) { animList[name].isPlaying = true; }
	bool isPlaying() { return animList[currentAnim].isPlaying; }
	float getH() { return animList[currentAnim].frames[0].height; }
	float getW() { return animList[currentAnim].frames[0].width; }
};
