#pragma once
#include "SFML\Graphics.hpp"
#include "State.h"
#include "Game.h"
#include "MainMenuState.h"
#include "SplashDef.h"

namespace slowStrike {
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);
		void initialize();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _backround;
	};
}