#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameLoop.h"
using namespace sf;

namespace Simao
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Sprite _background;

		Clock _clock;

	};

}
