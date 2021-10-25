#pragma once
#include "Humanoide.h"

namespace Simao
{
	class NPC : public Humanoide
	{
	public:
		NPC();
		~NPC() {}
		void MoveNPCUP();
		void MoveNPCDown();
		void MoveNPCLeft();
		void MoveNPCRight();
		int Minimax(int matriz[X][Y], Vector2f bombX);
		int Minimax2(int matriz[X][Y],  Vector2f bombX);
		double GA(int posX, int posY);

		int ondetaX;
		int ondetaY;
	};
}
