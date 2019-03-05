#include "SFML\Graphics.hpp"
#include "State.h"
#include "Game.h"
#include <sstream>
#include <iostream>
#include "TestDef.h"

namespace slowStrike {
	class TestingState : public State
	{
	public:
		TestingState(GameDataRef data);
		void initialize();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;
		sf::View _view;
		sf::Vector2f _view_center;
		sf::Vector2f _view_size;
		sf::Sprite _backround;
		sf::Sprite _playButton;
	};
}