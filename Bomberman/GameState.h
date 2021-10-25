#pragma once
//#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameLoop.h"
#include "Cenario.h"
#include "Player.h"
#include "Bloco.h"
#include "Bomb.h"
#include "NPC.h"
#include <vector>
#include <list>

using namespace sf;

namespace Simao
{
	class GameState : public State, Cenario
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);



	private:
		GameDataRef _data;

		Clock _clock;

		Texture _backgroundTexture;
		Sprite _background;
		Sprite _parede;
		Sprite _speed;
		vector <Bomb> _bomb;
		vector <Bloco> _bloco;
		Sprite _player[5];
		Sprite _explosion[2];
		Sprite _NPC[5];
		list<int>desenhos;
		list<int>desenhos2;

		int desenhospop = 3;
		int desenhospop2 = 3;
		int random = 0;
		int time = 1; 
		int time2 = 1;

		Player player1;
		NPC Com;
		Bomb bomba;
		

	};

}
