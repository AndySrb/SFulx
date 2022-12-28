#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	m_ResourceLoader = new ResourceLoader();
}

void ResourceManager::addResource(const char* filename)
{
	ResourceData tmp = m_ResourceLoader->getResourceData(filename);

	m_rdata.insert(std::pair<const char*,ResourceInfo>(tmp.name.c_str(),ResourceInfo()));
	m_rdataKey.push_back(filename);
}

ResourceData ResourceManager::getResource(const char* filename)
{
	return m_rdata.at(filename).m_data;
}

ResourceManager::ResourceInfo ResourceManager::getResourceInfo(const char* filename)
{
	return m_rdata.at(filename);
}

//std::vector<std::string> ResourceManager::getResourceListNames() {}

void ResourceManager::PrintResourceListNames() // May not work
{
	std::cout << this;
}
