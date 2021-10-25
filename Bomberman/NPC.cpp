#include "NPC.h"

namespace Simao
{
	NPC::NPC()
	{
		id = 002;
		speed = 1;
		bombs = 1;
		posx = 11;
		posy = 1;
	}
	void NPC::MoveNPCUP()
	{
		posy = posy - speed;
	}

	void NPC::MoveNPCDown()
	{
		posy = posy + speed;
	}

	void NPC::MoveNPCLeft()
	{
		posx = posx - speed;
	}

	void NPC::MoveNPCRight()
	{
		posx = posx + speed;
	}

	int NPC::Minimax(int matriz[X][Y], Vector2f bombX)
	{
		vector <int> moves0;
		vector <int> moves1;
		vector <int> moves2;
		vector <int> moves3;
		vector <int> moves4;
		return  Minimax2(matriz, bombX);
		for (int j = 0; j < 100; j++)
		{
			int move = Minimax2(matriz, bombX);
			if (move == 0)
				moves0.push_back(0);
			if (move == 1)
				moves1.push_back(1);
			if (move == 2)
				moves2.push_back(2);
			if (move == 3)
				moves3.push_back(3);
			if (move == 4)
				moves4.push_back(4);
		}

		if(moves0.size() > moves1.size() && moves0.size() > moves2.size() && moves0.size() > moves3.size() && moves0.size() > moves4.size())
			return 0;
		if (moves1.size() > moves0.size() && moves1.size() > moves2.size() && moves1.size() > moves3.size() && moves1.size() > moves4.size())
			return 1;
		if (moves2.size() > moves1.size() && moves2.size() > moves0.size() && moves2.size() > moves3.size() && moves2.size() > moves4.size())
			return 2;
		if (moves3.size() > moves1.size() && moves3.size() > moves2.size() && moves3.size() > moves0.size() && moves3.size() > moves4.size())
			return 3;
		if (moves4.size() > moves1.size() && moves4.size() > moves2.size() && moves4.size() > moves3.size() && moves4.size() > moves0.size())
			return 4;
	}

	int NPC::Minimax2(int matriz[X][Y], Vector2f bombX)
	{

		vector <int> moves;
		if (matriz[this->posx + 1][this->posy] == 0)
			moves.push_back(0);
		if (matriz[this->posx - 1][this->posy] == 0)
			moves.push_back(1);
		if (matriz[this->posx][this->posy - 1] == 0)
			moves.push_back(2);
		if (matriz[this->posx][this->posy + 1] == 0)
			moves.push_back(3);
		if (bombX.x == 670)
			moves.push_back(4);

		int afasta = rand() % moves.size();
		int movimenta = moves[afasta];
		if (bombX.x == 670)
			return 4;
		else
		{
			double antes = GA(this->posx, this->posy);
			if (movimenta == 0)
			{
				double depois = GA(this->posx + 1, this->posy);
				if (antes < depois)
					return 0;
				else
					return 5;
			}

			if (movimenta == 1)
			{
				double depois = GA(this->posx - 1, this->posy);
				
				if (antes < depois)
					return 1;
				else
					return 5;
			}

			if (movimenta == 2)
			{
				double depois = GA(this->posx, this->posy - 1);
				if (antes < depois)
					return 2;
				else
					return 5;
			}

			if (movimenta == 3)
			{
				double depois = GA(this->posx, this->posy + 1);
				if (antes < depois)
					return 3;
				else
					return 5;
			}

		}

	}

	double NPC::GA(int posX, int posY)
	{
		double vetor = 0;
		double vetorX = 0;
		double vetorY = 0;
		double vetorXY = 0;
		vetorX = pow((posX - this->ondetaX), 2);
		vetorY = (posY - this->ondetaY) * (posY - this->ondetaY);
		vetorXY = vetorX + vetorY;
		vetor = sqrt(vetorXY);
		return vetor;
	}
}


