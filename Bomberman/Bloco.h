#pragma once
#include <SFML/Graphics.hpp>
#include "GameLoop.h"
#include "Entity.h"

namespace Simao
{
	class Bloco : public Entity
	{
	public:
		Bloco();
		~Bloco() {}

		int tipo;

		Sprite _bloco;

	};
}

