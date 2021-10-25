#include "Player.h"
#include "Bomb.h"
#include "Definitions.h"
#include <SFML/Window/Keyboard.hpp>

using namespace sf;

namespace Simao
{
	Player::Player()
	{
		id = 001;
		speed = 1;
		bombs = 1;
		posx = 1;
		posy = 1;
	}

	void Player::MovePlayerUp()
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			posy = posy - speed;
		}
	}

	void Player::MovePlayerDown()
	{
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			posy = posy + speed;
		}
	}

	void Player::MovePlayerRight()
	{
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			posx = posx + speed;
		}
	}

	void Player::MovePlayerLeft()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			posx = posx - speed;
		}
	}
}


