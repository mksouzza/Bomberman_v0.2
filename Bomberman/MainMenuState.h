//#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameLoop.h"

using namespace sf;

namespace Simao
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Sprite _background;
		Sprite _playButton;
		Sprite _exitButton;

	};

}
