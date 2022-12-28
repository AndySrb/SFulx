#ifndef OBJECT_H
#define OBJECT_H 

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

class Object : public sf::Drawable
{
	private:
     virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
     {
         target.draw(m_sprite, states);
     }


     sf::Sprite m_sprite;
     sf::Texture *m_texture;
	 sf::Time m_uptime;
	
	public:
	 Object();
	 //Object(const sf::IntRect &size,const sf::IntRect &texturePos,sf::Texture *texture);
     virtual void update(const sf::Time &deltaTime) {
	 m_uptime += deltaTime;
	 }

	 sf::Sprite* getSprite()
	 {
		 return &m_sprite;
	 }

	 sf::Texture* getTexture()
	 {
		 return m_texture;
	 }

 	 void setTextureSprite(sf::Texture *texture,const sf::IntRect &textureRect);

	 //void setSize(const int &x,const int &y);
	 //void setSize(const sf::IntRect &intRectSize);


	 
};
#endif
