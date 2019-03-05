#pragma once
#include "SFML\Graphics.hpp"
#include "State.h"
#include "Game.h"
#include <sstream>
#include <iostream>
#include "MainMenuDef.h"

namespace slowStrike {
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);
		void initialize();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _backround;
		sf::Sprite _playButton;
	};
}