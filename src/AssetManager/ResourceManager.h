#ifndef RESOURCEMANAGER_H 
#define RESOURCEMANAGER_H
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <map>
#include "ResourceLoader.h"
#include "AssetManager.h"


class ResourceManager
{

	private:

		struct ResourceInfo
		{
			bool isLoaded;
			bool ERROR = false;
			const char* mapID;
			ResourceData m_data;
		};

		std::map<const char*,ResourceInfo> m_rdata;
		std::vector<const char*> m_rdataKey;
		ResourceLoader *m_ResourceLoader;
		AssetMenager m_AssetMenager;


	public:
		ResourceManager();


		void addResource(const char* filename);
		void addResourceList(const char* filename);
		ResourceData getResource(const char* filename);
		ResourceInfo getResourceInfo(const char* filename);
		//
		void PrintResourceListNames();
		std::vector<std::string> getResourceListNames();


		std::ostream&  operator<<(std::ostream& os) //May not work
		{
		std::vector<const char*>::iterator iter = m_rdataKey.begin();
		while (iter != m_rdataKey.end())
		{
			os << m_rdataKey.data() << '\n';
			iter++;
		}
		return os;
		}


};

#endif
