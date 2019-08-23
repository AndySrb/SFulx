#ifndef ASSETMENAGER_HPP
#define ASSETMENAGER_HPP
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
