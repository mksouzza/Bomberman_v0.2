#pragma once
#include "Humanoide.h"
#include "Cenario.h"

namespace Simao
{
	class Player : public Humanoide, Cenario
	{
	public:
		Player();
		~Player() {}
		void MovePlayerUp();
		void MovePlayerDown();
		void MovePlayerRight();
		void MovePlayerLeft();

		Sprite _player[5];
	};

}
