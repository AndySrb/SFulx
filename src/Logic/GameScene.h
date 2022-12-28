#ifndef GAMESCENE_H
#define GAMESCENE_H 

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <vector>


class GameScene : public sf::Drawable
{
	private:
     virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
     {
     }

	 bool f_multiplayer;
	 bool f_pause;
	public:
	 GameScene();
	 
};

#endif
