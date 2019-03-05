#include "MainMenuState.h"


namespace slowStrike {
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::initialize()
	{
		this->_data->assets.loadTexture("backroundmain", MAIN_MENU_BACKROUND_FILEPATH);
		this->_backround.setTexture(this->_data->assets.GetTexture("backroundmain"));

		this->_data->assets.loadTexture("startbutton", MAIN_MENU_START_FILEPATH);
		this->_playButton.setTexture(this->_data->assets.GetTexture("startbutton"));

		this->_playButton.setPosition((1920 / 2) - (this->_playButton.getGlobalBounds().width / 2),
			(1080 / 2) - (this->_playButton.getGlobalBounds().height / 2));


	}

	void MainMenuState::handleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				//_data->machine.addState(stateRef(new Level1AState(this->_data)));
			}
		}
	}

	void MainMenuState::update(float dt)
	{

	}

	void MainMenuState::draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_backround);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
}