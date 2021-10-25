#include <SFML/Graphics.hpp>
#include "GameLoop.h"
#include "Definitions.h"

int main()
{
	srand((unsigned)time(NULL));
	Simao::GameLoop(SCREEN_WIDTH, SCREEN_HEIGHT, "Super Bomberman");

	return EXIT_SUCCESS;
}