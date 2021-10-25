#include "MainMenuState.h"
#include "Definitions.h"
#include "InputManager.h"
#include "GameState.h"

using namespace sf;


namespace Simao
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		_data->assets.LoadTexture("Main Menu Background", MENU_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Exit Button", EXIT_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));

		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2)*2);
		_exitButton.setPosition((SCREEN_WIDTH / 2) - (_exitButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_exitButton.getGlobalBounds().height / 4)*1);
	}

	void MainMenuState::HandleInput()
	{
		Event evnt;
		while (_data->window.pollEvent(evnt))
		{
			if (Event::Closed == evnt.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_playButton, Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
			
			if (_data->input.IsSpriteClicked(_exitButton, Mouse::Left, _data->window))
			{
				_data->window.close();
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
		
	}

	void MainMenuState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_playButton);
		_data->window.draw(_exitButton);

		_data->window.display();
	}
}