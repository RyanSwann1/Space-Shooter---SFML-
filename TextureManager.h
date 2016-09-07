#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include "ResourceManager.h"
#include <SFML\Graphics.hpp>
#include <iostream>
class TextureManager :
	public ResourceManager<sf::Texture>
{
public:
	TextureManager() 
	{
		loadInTextures();
	}
	~TextureManager() {}

	sf::Texture* loadFromFilePath(const std::string& id) override
	{
		//Search through existing file paths for each texture
		auto iter = m_filePath.find(id);
		if (iter != m_filePath.cend())
		{
			sf::Texture* texture = new sf::Texture;
			if (!texture->loadFromFile(iter->second)) 
			{
				delete texture;
				texture = nullptr;
				return nullptr;
			}
			return texture;
		}		
		return nullptr;
	}

private:
	void loadInTextures()
	{
		registerFilePath("Player", "Textures/Player_Ship.PNG");
		registerFilePath("Player_Laser", "Textures/Player_Laser.PNG");
		registerFilePath("Enemy", "Textures/Enemy_Ship.PNG");
		registerFilePath("Enemy_Laser", "Textures/Enemy_Laser.PNG");
		registerFilePath("Power_Up_Health", "Textures/Power_Up_Health.PNG");
	}

};
#endif // !TEXTURE_MANAGER_H

