#include "ResourceLoader.h"
#include <cwctype>
#include <iostream>
#include <string>

ResourceLoader* ResourceLoader::sInstance = nullptr;

ResourceLoader::ResourceLoader()
{
	//Only allow one ResourceLoader to exist
	//Otherwise throw an exception
	std::cout << "ResourceLoader::ResourceLoader()" << std::endl;
	if (sInstance == nullptr) 
	{
		sInstance = this;
		if (!isInit)
			L = luaL_newstate();
			luaL_openlibs(L);
			luaLoad = new luaLoader(L);
			isInit = true;
	}

}

bool ResourceLoader::LookForAsset(const char* filename)
{

	if (CheckLua(L,luaL_dofile(L,filename)))
	{
		std::cout<< "ResourceLoader::LookForAsset() lua file is OK: " << filename << std::endl;
		return true;
	} else 
		return false;

	return false;
}

void ResourceLoader::PrintResourceData(const char* filename)
{
	std::string name;
	std::string desc;
	int type;
	std::string sprite_filename;
	std::string settings_filename;
	std::string function_filename;

	if (CheckLua(L,luaL_dofile(L,filename)))
	{
		luaLoad->readFromTable("Asset","Name");
		name = std::string(*luaLoad);
		luaLoad->readFromTable("Asset","Desc");
		desc = std::string(*luaLoad);
		luaLoad->readFromTable("Asset", "Type");
		type = *luaLoad;
		luaLoad->readFromTable("Asset","SpriteFile");
		sprite_filename = std::string(*luaLoad);
		luaLoad->readFromTable("Asset","SettingsFile");
		settings_filename = std::string(*luaLoad);
		luaLoad->readFromTable("Asset","FunctionFile");
		function_filename = std::string(*luaLoad);
	}

	std::cout << "Name: " << name << std::endl;
	std::cout << "Type: " << type << std::endl;
	std::cout << "SpriteLocation: " << sprite_filename << std::endl;
	std::cout << "SettingFile: " << settings_filename << std::endl;
	std::cout << "function_filename: " << function_filename << std::endl;
}

void ResourceLoader::PrintResourceList(const char *filename)
{
	if (CheckLua(L,luaL_dofile(L,filename)))
	{
		size_t j = luaLoad->getArrayLen("AssetList");
			for (int i=1;i <= j ; i++)
			{
				luaLoad->readFromTable("AssetList", i);
				std::string val = *luaLoad;
				std::cout << "AssetList" << '[' << i << ']' << "= " << val << std::endl;
			}
	}
}


