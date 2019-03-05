#include "SplashState.h"

namespace slowStrike {
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::initialize()
	{
		this->_data->assets.loadTexture("splashback", SPLASH_BACKROUND_FILEPATH);
		_backround.setTexture(this->_data->assets.GetTexture("splashback"));

	}

	void SplashState::handleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->_data->window.close();
				break;
			case sf::Event::KeyPressed:
				_data->machine.addState(stateRef(new MainMenuState(this->_data)));
				break;
			}


		}
	}

	void SplashState::update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > 3)
		{
			_data->machine.addState(stateRef(new MainMenuState(this->_data))); //switch to main menu
		}
	}

	void SplashState::draw(float dt)
	{
		this->_data->window.clear(sf::Color::Blue);

		this->_data->window.draw(this->_backround);

		this->_data->window.display();
	}
}