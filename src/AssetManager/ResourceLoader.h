#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H
#include <iostream>
#include <lua5.2/lua.hpp>
#include "Lua/luaLoader.h"
#include "ResourceType.hpp"

class ResourceLoader
{
	private:
		static ResourceLoader *sInstance;
		lua_State *L;
		luaLoader *luaLoad;
		bool isInit = false;
		bool CheckLua(lua_State *L, int r)
		{
			if(r != LUA_OK)
			{
				std::string errormsg = lua_tostring(L, -1);
				std::cout << errormsg << std::endl;
				return false;
			}

		return true;
		}


	public:
		ResourceLoader();
		bool LookForAsset(const char* filename);
		void PrintResourceData(const char* filename);
		void PrintResourceList(const char* filename);
		ResourceData getResourceData(const char* filename);

};

#endif
