#pragma once
#include <SFML/Graphics.hpp>
#include "GameLoop.h"
#include "Definitions.h"

using namespace sf;

namespace Simao
{
	class Cenario
	{
	public:
		Cenario();

		void CriaMatriz(int matriz1[X][Y]);

	public:
		int matriz[X][Y];
	};
}