#include "InputManager.h"

namespace Simao
{
	bool InputManager::IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow &window)
	{
		if (Mouse::isButtonPressed(button))
		{
			IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (playButtonRect.contains(Mouse::getPosition(window)))
			{
				return true;
			}
		}

		return false;
	}

	Vector2i GetMousePosition(RenderWindow &window)
	{
		return Mouse::getPosition(window);
	}
}