#pragma once
#include "TestingState.h"

namespace slowStrike {
	TestingState::TestingState(GameDataRef data) : _data(data)
	{

	}

	void TestingState::initialize()
	{
		_view_center = sf::Vector2f(this->_data->window.getPosition().x, this->_data->window.getPosition().y);
		_view_size = sf::Vector2f(this->_data->window.getSize().x, this->_data->window.getSize().y);
		this->_data->assets.loadTexture("splashback", SPLASH_BACKROUND_FILEPATH);
		_backround.setTexture(this->_data->assets.GetTexture("splashback"));

	}

	void TestingState::handleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->_data->window.close();
				break;
			case sf::Event::MouseWheelMoved:
				if (event.mouseWheel.delta > 0)
					_view_size.x += 50, _view_size.y += 50;
				else if (event.mouseWheel.delta < 0)
					_view_size.x -= 50, _view_size.y -= 50;

				
				break;
			}


		}
	}

	void TestingState::update(float dt)
	{
		_view.setCenter(_view_center);
		_view.setSize(_view_size);
		_data->window.setView(_view);
	}

	void TestingState::draw(float dt)
	{
		this->_data->window.clear(sf::Color::Blue);

		this->_data->window.draw(this->_backround);

		this->_data->window.display();
	}
}