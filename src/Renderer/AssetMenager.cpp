#include "AssetMenager.h"

AssetMenager* AssetMenager::sInstance = nullptr;

AssetMenager::AssetMenager()
{
	//Only allow one AssetMenager to exist
	//Otherwise throw an exception
	std::cout << "AssetMenager::AssetMenager()" << std::endl;
	if (sInstance == nullptr) 
		sInstance = this;
}

sf::Texture& AssetMenager::GetTexture( const std::string &filename )
{
	auto& texMap = sInstance->m_Textures;


	//If texture is already loaded, return sf::Texture
	std::map<std::string, sf::Texture>::iterator pairFound = texMap.find(filename);
	if(pairFound != texMap.end())
		return pairFound->second;
	else 
	{
		sf::Texture &texture = texMap[filename];
		texture.loadFromFile(filename);
		texMap.insert(std::pair<std::string,sf::Texture>(filename,texture));
		return texture;
	}
}
