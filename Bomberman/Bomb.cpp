#include "Bomb.h"
#include "Definitions.h"


using namespace std;

namespace Simao
{
	Bomb::Bomb()
	{
		range = 1;
	}

	int Bomb::Dropbomb()
	{
		if (natela == false)
		{
			estado = 1;
			time = (int)_clock.getElapsedTime().asSeconds() + 3;
			natela = true;
			return 1;
		}
		else
			return 0;
	}

	int Bomb::Explosion()
	{
		if ((int)_clock.getElapsedTime().asSeconds() / time && estado == 1) 
		{
			estado = 2;
			vaiexplodir = true;
			time = (int)_clock.getElapsedTime().asSeconds() + 1;
			return 1;
		}
		else
			return 0;
	}

	int Bomb::Explosion2()
	{
		if ((int)_clock.getElapsedTime().asSeconds() / time && estado == 2)
		{
			estado = 3;
			time = (int)_clock.getElapsedTime().asSeconds() + 1;
			return 1;
		}
		else
			return 0;
	}

	int Bomb::Explosion3(int tipo)
	{
		if ((int)_clock.getElapsedTime().asSeconds() / time && estado == 3)
		{
			estado = 0;
			if(tipo == 1)
				_bomb.setPosition(670, 30);
			else
				_bomb.setPosition(100, 30);
			natela = false;
			return 1;
		}
		else
			return 0;
	}
}