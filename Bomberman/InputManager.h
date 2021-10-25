#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

namespace Simao
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(Sprite objetct, Mouse::Button, RenderWindow &window);

		Vector2i GetMousePosition(RenderWindow &window);
	};
}

