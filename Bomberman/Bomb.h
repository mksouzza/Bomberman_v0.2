#pragma once
#include "Entity.h"
#include "GameLoop.h"
#include <SFML/Graphics.hpp>


namespace Simao
{
	class Bomb : public Entity
	{
	public:
		Bomb();
		~Bomb() {}

		int Explosion();
		int Dropbomb();
		int Explosion2();
		int Explosion3(int tipo);

		Sprite _bomb;
		Sprite _explosion[2];

		Clock _clock;

		int range;
		int estado = 0;
		int time;
		bool vaiexplodir = false;
		bool natela = false;
	};
}
