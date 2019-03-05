#pragma once

#include <map>
#include <SFML\Graphics.hpp>
#include "TileMap.h"

namespace slowStrike {
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		void loadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		void loadTileMap(std::string name, const std::string& tileset, sf::Vector2u tileSize, int* tiles, unsigned int width, unsigned int height);
		TileMap &GetTileMap(std::string name);

		void loadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		std::map < std::string, sf::Texture> _textures;
		std::map < std::string, TileMap> _tileMaps;
		std::map < std::string, sf::Font> _fonts;

	};
}