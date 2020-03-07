#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <iostream>
#include <SFML/Graphics.hpp>

class AssetMenager
{

	public:
			AssetMenager();
			static sf::Texture& GetTexture(std::string const &filename);
	private:
			std::map<std::string, sf::Texture> m_Textures;
			static AssetMenager* sInstance;

};


#endif
