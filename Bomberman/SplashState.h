#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameLoop.h"
using namespace sf;

namespace Simao
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		Clock _clock;

		Sprite _background;

	};

}
