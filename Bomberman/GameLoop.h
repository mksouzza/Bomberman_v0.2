#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
using namespace std;
using namespace sf;

namespace Simao
{
	struct GameData
	{
		StateMachine machine;
		RenderWindow window;
		AssetManager assets;
		InputManager input;
	};
	
	typedef shared_ptr<GameData> GameDataRef;

	class GameLoop
	{
	public:
		GameLoop(int width, int height, string title);
		~GameLoop() {}

	private:
		const float dt = 1.0f / 60.0f;
		Clock _clock;
		GameDataRef _data = make_shared<GameData>();

		void Run();
	};

}
