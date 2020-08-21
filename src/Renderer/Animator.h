#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <list>

#include "../AssetManager/AssetManager.h"


class Animator
{
//** Struct Animation
	public:
	struct Animation
	{
	std::string m_Name;
	std::string m_TextureName;
	std::vector<sf::IntRect> m_Frames;
	sf::Time m_Duration;
	bool f_IsLooping;

	Animation(const std::string &name,const std::string &textureName,
			const sf::Time &duration,bool looping) :
		m_Name(name), m_TextureName(textureName),
		m_Duration(duration),f_IsLooping(looping)
	{}

	void addFrames(const sf::Vector2i &startForm,
			const sf::Vector2i &frameSize, unsigned int frames)
	{
		sf::Vector2i current = startForm;
		for (unsigned int i = 0; i < frames; i++)
		{
			//add current frame from position and frame size
			m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
			//Advance current frame horizontally
			current.x += frameSize.x;
		}
	}
	};
//** /Struct Animation

	private:
		//Animator() {} //Disabling default constructor 
		//Animator(const Animator &obj) {}  //Disabling copy constructor
		//Animator(Animator&& obj) {} // Disabling move constructor

		//Returns the animation with the passed name
		//Returns nullptr if no such animation is found
		Animator::Animation* FindAnimation(const std::string &name);


		void SwitchAnimation(Animator::Animation* animation);

		//Refrence to the sprite
		sf::Sprite &m_Sprite;
		sf::Time m_CurrentTime;
		std::list<Animator::Animation> m_Animations;
		Animator::Animation *m_CurrentAnimation;


	public:

		Animator(sf::Sprite &sprite);

		Animator::Animation& CrateAnimation(const std::string &name, const std::string &textureName, sf::Time duration,bool looping = false);
		void Update(const sf::Time &deltaTime);
		bool switchAnimation(const std::string &name);
		std::string GetCurrentAnimationName() const;


		



};

#endif
