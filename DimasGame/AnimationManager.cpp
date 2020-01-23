#include "AnimationManager.h"

AnimationManager::~AnimationManager()
{
	animList.clear();
}

void AnimationManager::create(std::string name, sf::Texture& texture, int x, int y, int w, int h, int count, float speed, int step, bool Loop)
{
	Animation a;
	a.speed = speed;
	a.loop = Loop;
	a.sprite.setTexture(texture);
	a.sprite.setOrigin(0, h);

	for (int i = 0; i < count; i++)
	{
		a.frames.push_back(sf::IntRect(x + i * step, y, w, h));
		a.frames_flip.push_back(sf::IntRect(x + i * step + w, y, -w, h));
	}
	animList[name] = a;
	currentAnim = name;
}

void AnimationManager::loadFromXML(std::string fileName, sf::Texture& t)
{
	TiXmlDocument animFile(fileName.c_str());

	animFile.LoadFile();

	TiXmlElement* head;
	head = animFile.FirstChildElement("sprites");

	TiXmlElement* animElement;
	animElement = head->FirstChildElement("animation");
	while (animElement)
	{
		Animation anim;
		currentAnim = animElement->Attribute("title");
		int delay = atoi(animElement->Attribute("delay"));
		anim.speed = 1.0 / delay; anim.sprite.setTexture(t);

		TiXmlElement* cut;
		cut = animElement->FirstChildElement("cut");
		while (cut)
		{
			int x = atoi(cut->Attribute("x"));
			int y = atoi(cut->Attribute("y"));
			int w = atoi(cut->Attribute("w"));
			int h = atoi(cut->Attribute("h"));

			anim.frames.push_back(sf::IntRect(x, y, w, h));
			anim.frames_flip.push_back(sf::IntRect(x + w, y, -w, h));
			cut = cut->NextSiblingElement("cut");
		}

		anim.sprite.setOrigin(0, anim.frames[0].height);

		animList[currentAnim] = anim;
		animElement = animElement->NextSiblingElement("animation");
	}
}

void AnimationManager::set(std::string name)
{
	currentAnim = name;
	animList[currentAnim].flip = 0;
}

void AnimationManager::draw(sf::RenderWindow& window, int x, int y)
{
	animList[currentAnim].sprite.setPosition(x, y);
	window.draw(animList[currentAnim].sprite);
}
