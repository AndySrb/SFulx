#include <iostream>
#include "AssetManager/ResourceLoader.h"


int main()
{
	ResourceLoader loader;
	std::cout << "PrintResourceData():" << std::endl;
	loader.PrintResourceData("asset.lua");
	std::cout << "PrintResourceList():" << std::endl;
	loader.PrintResourceList("asset.lua");
} 
