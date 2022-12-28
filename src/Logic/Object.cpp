#include "Object.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

Object::Object(): m_uptime()
{
	m_texture = new sf::Texture();
}

void Object::setTextureSprite(sf::Texture *texture,const sf::IntRect &textureRect)
{
	m_texture = texture;
	m_sprite.setTexture(*m_texture);
	m_sprite.setTextureRect(textureRect);
}
