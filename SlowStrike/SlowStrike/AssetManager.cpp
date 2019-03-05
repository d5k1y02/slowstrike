#include "AssetManager.h"

namespace slowStrike {
	void AssetManager::loadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void AssetManager::loadTileMap(std::string name, const std::string& tileset,
		sf::Vector2u tileSize, int* tiles, unsigned int width, unsigned int height)
	{
		TileMap map;
		if (map.load(tileset, tileSize, tiles, width, height))
		{
			this->_tileMaps[name] = map;
		}
	}

	TileMap& AssetManager::GetTileMap(std::string name)
	{
		return this->_tileMaps.at(name);
	}

	void AssetManager::loadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}