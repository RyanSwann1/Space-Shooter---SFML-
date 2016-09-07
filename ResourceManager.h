#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <unordered_map>
#include <string>
#include <iostream>

template <class T>
class ResourceManager
{
public:
	ResourceManager() {}
	virtual ~ResourceManager() 
	{
		destroyAllResources();
	}

	T* getResource(const std::string& id)
	{
		auto res = find(id);
		return (res ? res->first : nullptr);
	}

	bool requireResource(const std::string& id)
	{
		auto res = find(id);
		if (res)
		{
			res->second++;
			return true;
			
		}
		T* resource = loadFromFilePath(id);
		if (resource)
		{
			m_resources.emplace(id, std::make_pair(resource, 1));
			return true;
		}
		return false;
	}

	void unloadResource(const std::string& id)
	{
		auto res = find(id);
		if (res)
		{
			if (res->second) {
				res->second--;
			}
			else
			{
				destroyResource(id);
			}
		}
	}

	/*unsigned int resourceCount(const std::string& id) const
	{
		auto res = find(id);
		if (res) {
			res->second;
		}
		else {
			return 0;
		}
	}*/

protected:
	std::unordered_map<std::string, std::string> m_filePath; //name of file, file path
	virtual T* loadFromFilePath(const std::string& id) = 0;

	bool registerFilePath(const std::string& fileName, const std::string& filePath)
	{
		return m_filePath.emplace(fileName, filePath).second;
	}

private:
	std::unordered_map<std::string, std::pair<T*, unsigned int>> m_resources; //Name of resource, resource and how many times resource is in use
	
	std::pair<T*, unsigned int>* find(const std::string& id)
	{
		auto iter = m_resources.find(id);
		return (iter != m_resources.end() ? &iter->second : nullptr);	
	}


	void destroyResource(const std::string& id)
	{
		m_resources.erase(id);
	}

	void destroyAllResources()
	{
		
	}

};
#endif // !RESOURCE_MANAGER_H
