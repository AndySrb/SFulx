#ifndef PLAYER_H
#define PLAYER_H 

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Time.hpp>
#include "../Input/InputHandler.h"

//TODO: Implement InputHandling Player class

class Player : public sf::Drawable
{
	private:
     virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
     {
         // You can draw other high-level objects
         target.draw(m_sprite, states);
     }
	 


     //sf::Sprite m_sprite;
	 sf::CircleShape m_sprite;
     sf::Texture *m_texture;
	 InputHandler m_InputHandler; //InputHandler is already initilized in Window.cpp
	
	 bool m_toggle = true;

	public:
	 Player();
	 void ToggleColor();
	 void Update(sf::Time time);

	 sf::CircleShape* getSprite()
	 {
		 return &m_sprite;
	 }

	 sf::Texture* getTexture()
	 {
		 return m_texture;
	 }
	 
};


#endif
