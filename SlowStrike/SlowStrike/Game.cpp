#include "Game.h"
#include "SplashState.h"
#include "TestingState.h"
namespace slowStrike {
	Game::Game(std::string title)
	{
		_data->window.create(sf::VideoMode(1920, 1080), title, sf::Style::Fullscreen); //sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize
		_data->machine.addState(stateRef(new TestingState(this->_data)));
		this->Run();
	}

	void Game::Run()
	{
		float new_Time, frameTime, interpolation;
		float currentTime = this->clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.processStateChanges();
			new_Time = this->clock.getElapsedTime().asSeconds();
			frameTime = new_Time - currentTime;
			if (frameTime > .25f)
			{
				frameTime = .25f;
			}

			currentTime = new_Time;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.getActiveState()->handleInput();
				this->_data->machine.getActiveState()->update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.getActiveState()->draw(interpolation);
		}
	}
}