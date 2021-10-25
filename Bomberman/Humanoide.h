#pragma once
#include "Entity.h"
#include "Cenario.h"

namespace Simao
{
	class Humanoide : public Entity
	{
	public:
		int speed;
		int bombs;

		int isDead();
	};
}

