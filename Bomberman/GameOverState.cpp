#include <SFML/Graphics.hpp>
#include "GameOverState.h"
#include "Definitions.h"
#include "MainMenuState.h"

using namespace sf;


namespace Simao
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}

	void GameOverState::Init()
	{
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
	}

	void GameOverState::HandleInput()
	{
		Event evnt;
		while (_data->window.pollEvent(evnt))
		{
			if (Event::Closed == evnt.type)
			{
				_data->window.close();
			}
		}
	}

	void GameOverState::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void GameOverState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();
	}
}