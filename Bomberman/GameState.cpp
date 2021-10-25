#include "GameState.h"
#include "Definitions.h"
#include "GameOverState.h"

using namespace sf;

namespace Simao
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
		CriaMatriz(matriz);
	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Parede", BLOCK_WALL_FILEPATH);
		_data->assets.LoadTexture("Bloco", BREAKABLE_WALL_FILEPATH);

		_data->assets.LoadTexture("PlayerRight", PLAYER_RIGHT_FILEPATH);
		_data->assets.LoadTexture("PlayerLeft", PLAYER_LEFT_FILEPATH);
		_data->assets.LoadTexture("PlayerUp", PLAYER_UP_FILEPATH);
		_data->assets.LoadTexture("PlayerDown", PLAYER_DOWN_FILEPATH);
		_data->assets.LoadTexture("PlayerDead", PLAYER_DEAD_FILEPATH);

		_data->assets.LoadTexture("NPCRight", NPC_RIGHT_FILEPATH);
		_data->assets.LoadTexture("NPCLeft", NPC_LEFT_FILEPATH);
		_data->assets.LoadTexture("NPCUp", NPC_UP_FILEPATH);
		_data->assets.LoadTexture("NPCDown", NPC_DOWN_FILEPATH);
		_data->assets.LoadTexture("NPCDead", NPC_DEAD_FILEPATH);

		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (matriz[i][j] == 1) //desenha bloco de parede
				{
					Bloco *newBloco = new Bloco();
					newBloco->_bloco.setTexture(this->_data->assets.GetTexture("Parede"));
					newBloco->id = i * 15 + j;
					newBloco->tipo = 1;
					newBloco->_bloco.setPosition((i * BLOCK_SIZE) + 210.0f, (j * BLOCK_SIZE) + 100.0f);
					_bloco.push_back(*newBloco);
				}

				if (matriz[i][j] == 2) //desenha bloco destrutível
				{
					Bloco *newBloco = new Bloco();
					newBloco->_bloco.setTexture(this->_data->assets.GetTexture("Bloco"));
					newBloco->id = i * 15 + j;
					newBloco->tipo = 2;
					newBloco->posx = i;
					newBloco->posy = j;
					newBloco->_bloco.setPosition((i * BLOCK_SIZE) + 210.0f, (j * BLOCK_SIZE) + 100.0f);
					_bloco.push_back(*newBloco);
				}

				if (matriz[i][j] == 3) //desenha player
				{
					_player[0].setTexture(this->_data->assets.GetTexture("PlayerRight"));
					_player[0].setPosition(player1.posx * 1.0f, player1.posy * 1.0f);
					_player[1].setTexture(this->_data->assets.GetTexture("PlayerLeft"));
					_player[1].setPosition(player1.posx * 1.0f, player1.posy * 1.0f);
					_player[2].setTexture(this->_data->assets.GetTexture("PlayerUp"));
					_player[2].setPosition(player1.posx * 1.0f, player1.posy * 1.0f);
					_player[3].setTexture(this->_data->assets.GetTexture("PlayerDown"));
					_player[3].setPosition(player1.posx * 1.0f, player1.posy * 1.0f);
					_player[4].setTexture(this->_data->assets.GetTexture("PlayerDead"));
					_player[4].setPosition(player1.posx * 1.0f, player1.posy * 1.0f);
				}

				if (matriz[i][j] == 4) //desenha bot
				{
					_NPC[0].setTexture(this->_data->assets.GetTexture("NPCRight"));
					_NPC[0].setPosition(Com.posx * 1.0f, Com.posy * 1.0f);
					_NPC[1].setTexture(this->_data->assets.GetTexture("NPCLeft"));
					_NPC[1].setPosition(Com.posx * 1.0f, Com.posy * 1.0f);
					_NPC[2].setTexture(this->_data->assets.GetTexture("NPCUp"));
					_NPC[2].setPosition(Com.posx * 1.0f, Com.posy * 1.0f);
					_NPC[3].setTexture(this->_data->assets.GetTexture("NPCDown"));
					_NPC[3].setPosition(Com.posx * 1.0f, Com.posy * 1.0f);
					_NPC[4].setTexture(this->_data->assets.GetTexture("NPCDead"));
					_NPC[4].setPosition(Com.posx * 1.0f, Com.posy * 1.0f);
				}
			}
		}
		
		_data->assets.LoadTexture("Bomb", BOMB_FILEPATH);
		_data->assets.LoadTexture("Explosion 1", EXPLOSION_ONE_FILEPATH);
		_data->assets.LoadTexture("Explosion 2", EXPLOSION_TWO_FILEPATH);
		
		Bomb *newBomb = new Bomb();
		newBomb->_bomb.setTexture(this->_data->assets.GetTexture("Bomb"));
		newBomb->_explosion[0].setTexture(this->_data->assets.GetTexture("Explosion 1"));
		newBomb->_explosion[1].setTexture(this->_data->assets.GetTexture("Explosion 2"));
		newBomb->_bomb.setPosition(100, 30);
		_bomb.push_back(*newBomb);

		Bomb *newBomb2 = new Bomb();
		newBomb2->_bomb.setTexture(this->_data->assets.GetTexture("Bomb"));
		newBomb2->_explosion[0].setTexture(this->_data->assets.GetTexture("Explosion 1"));
		newBomb2->_explosion[1].setTexture(this->_data->assets.GetTexture("Explosion 2"));
		newBomb2->_bomb.setPosition(670, 30);
		_bomb.push_back(*newBomb2);

		_data->assets.LoadTexture("Game State Background", GAME_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game State Background"));

	}

	void GameState::HandleInput()
	{
		Event evnt;
		while (_data->window.pollEvent(evnt))
		{
			if (Event::Closed == evnt.type)
			{
				_data->window.close();
			}
			
			//Movimentação do Player
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if ((int)_clock.getElapsedTime().asMilliseconds() / time)
				{
					time = (int)_clock.getElapsedTime().asMilliseconds() + 300;
					int i = 0;
					for (i = 1; i <= player1.speed; i++)
					{
						if (matriz[player1.posx][player1.posy + i] != 0)
						{
							i--;
							break;
						}
					}
					i--;
					desenhos.push_back(3);
					for (int j = 0; j < i; j++)
					{
						player1.MovePlayerDown();
						matriz[player1.posx][player1.posy - i] = 0;
					}
					matriz[player1.posx][player1.posy] = 3;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				if ((int)_clock.getElapsedTime().asMilliseconds() / time)
				{
					time = (int)_clock.getElapsedTime().asMilliseconds() + 300;
					int i = 0;
					for (i = 1; i <= player1.speed; i++)
					{
						if (matriz[player1.posx + i][player1.posy] != 0)
						{
							i--;
							break;
						}
					}
					i--;
					desenhos.push_back(0);
					for (int j = 0; j < i; j++)
					{
						player1.MovePlayerRight();
						matriz[player1.posx - i][player1.posy] = 0;
					}
					matriz[player1.posx][player1.posy] = 3;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if ((int)_clock.getElapsedTime().asMilliseconds() / time)
				{
					time = (int)_clock.getElapsedTime().asMilliseconds() + 300;
					int i = 0;
					for (i = 1; i <= player1.speed; i++)
					{
						if (matriz[player1.posx - i][player1.posy] != 0)
						{
							i--;
							break;
						}
					}
					i--;
					desenhos.push_back(1);
					for (int j = 0; j < i; j++)
					{
						player1.MovePlayerLeft();
						matriz[player1.posx + i][player1.posy] = 0;
					}
					matriz[player1.posx][player1.posy] = 3;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if ((int)_clock.getElapsedTime().asMilliseconds() / time)
				{
					time = (int)_clock.getElapsedTime().asMilliseconds() + 300;
					int i = 0;
					for (i = 1; i <= player1.speed; i++)
					{
						if (matriz[player1.posx][player1.posy - i] != 0)
						{
							i--;
							break;
						}
					}
					i--;
					desenhos.push_back(2);
					for (int j = 0; j < i; j++)
					{
						player1.MovePlayerUp();
						matriz[player1.posx][player1.posy + i] = 0;
					}
					matriz[player1.posx][player1.posy] = 3;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Z))
			{
				bomba.posx = player1.posx;
				bomba.posy = player1.posy;
				if (_bomb[0].natela == false)
				{
					_bomb[0]._bomb.setPosition((bomba.posx * BOMB_SIZE) + 210.0f, (bomba.posy * BOMB_SIZE) + 98.0f);
					_bomb[0]._explosion[0].setPosition((bomba.posx * BOMB_SIZE) + 210.0f, (bomba.posy * BOMB_SIZE) + 98.0f);
					_bomb[0]._explosion[1].setPosition((bomba.posx * BOMB_SIZE) + 210.0f, (bomba.posy * BOMB_SIZE) + 98.0f);
					_bomb[0].Dropbomb();
				}
			}		
		}
	}

	void GameState::Update(float dt)
	{
		
	}


	void GameState::Draw(float dt)
	{

		_data->window.clear();

		_data->window.draw(_background);

		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{

				if (matriz[i][j] == 3) //desenha player
				{
					_player[desenhospop].setPosition((i * BLOCK_SIZE) + 215.0f, (j * BLOCK_SIZE) + 100.0f);
				}

				if (matriz[i][j] == 4) //desenha bot
				{
					_NPC[desenhospop2].setPosition((i * BLOCK_SIZE) + 215.0f, (j * BLOCK_SIZE) + 100.0f);
				}
			}
		}
		
		//Desenha blocos
		for (auto parede : _bloco)
		{
			_data->window.draw(parede._bloco);
		}

		//Player
		if (desenhos.empty())
		{
			_data->window.draw(_player[desenhospop]);
		}
		while (!desenhos.empty())
		{
			desenhospop = desenhos.back();
			desenhos.pop_back();
			_data->window.draw(_player[desenhospop]);
		}

		

		//Move Bot
		if (((int)_clock.getElapsedTime().asMilliseconds() / time2))
		{
			int bot = Com.Minimax(matriz, _bomb[1]._bomb.getPosition());
			time2 = (int)_clock.getElapsedTime().asMilliseconds() + 300;
			if(bot == 0)
			{
				int i = 0;
				for (i = 1; i <= Com.speed; i++)
				{
					if (matriz[Com.posx + i][Com.posy] != 0)
					{
						i--;
						break;
					}
				}
				i--;
				desenhos2.push_back(0);
				for (int j = 0; j < i; j++)
				{
					Com.MoveNPCRight();
					matriz[Com.posx - i][Com.posy] = 0;
				}
				matriz[Com.posx][Com.posy] = 4;
			}

			if (bot == 1)
			{
				int i = 0;
				for (i = 1; i <= Com.speed; i++)
				{
					if (matriz[Com.posx - i][Com.posy] != 0)
					{
						i--;
						break;
					}
				}
				i--;
				desenhos2.push_back(1);
				for (int j = 0; j < i; j++)
				{
					Com.MoveNPCLeft();
					matriz[Com.posx + i][Com.posy] = 0;
				}
				matriz[Com.posx][Com.posy] = 4;
			}

			if (bot == 2)
			{
				int i = 0;
				for (i = 1; i <= Com.speed; i++)
				{
					if (matriz[Com.posx][Com.posy - i] != 0)
					{
						i--;
						break;
					}
				}
				i--;
				desenhos2.push_back(2);
				for (int j = 0; j < i; j++)
				{
					Com.MoveNPCUP();
					matriz[Com.posx][Com.posy + i] = 0;
				}
				matriz[Com.posx][Com.posy] = 4;
			}

			if (bot == 3)
			{
				bool livre = 0;
				if (matriz[Com.posx][Com.posy + 1] == 0)
				{
					livre = true;
				}
				desenhos2.push_back(3);
				if (livre == true) 
				{
					Com.MoveNPCDown();
					matriz[Com.posx][Com.posy - 1] = 0;
					matriz[Com.posx][Com.posy] = 4;
				}
			}

			if (bot == 4)
			{
				bomba.posx = Com.posx;
				bomba.posy = Com.posy;
				if (_bomb[1].natela == false)
				{
					_bomb[1]._bomb.setPosition((bomba.posx * BOMB_SIZE) + 200.0f, (bomba.posy * BLOCK_SIZE) + 100.0f);
					_bomb[1]._explosion[0].setPosition((bomba.posx * BOMB_SIZE) + 200.0f, (bomba.posy * BLOCK_SIZE) + 100.0f);
					_bomb[1]._explosion[1].setPosition((bomba.posx * BOMB_SIZE) + 200.0f, (bomba.posy * BLOCK_SIZE) + 100.0f);
					_bomb[1].Dropbomb();
					Com.ondetaX = bomba.posx;
					Com.ondetaY = bomba.posy;
				}
			}
		}

		//NPC
		if (desenhos2.empty())
		{
			_data->window.draw(_NPC[desenhospop2]);
		}
		while (!desenhos2.empty())
		{
			desenhospop2 = desenhos2.back();
			desenhos2.pop_back();
			_data->window.draw(_NPC[desenhospop2]);

		}

		//Bomba do Player
		_bomb[0].Explosion();
		_bomb[0].Explosion2();
		_bomb[0].Explosion3(0);
		if (_bomb[0].estado == 0)
			_data->window.draw(_bomb[0]._bomb);
		if (_bomb[0].estado == 1)
			_data->window.draw(_bomb[0]._bomb);
		if (_bomb[0].estado == 2)
			_data->window.draw(_bomb[0]._explosion[0]);
		if (_bomb[0].estado == 3)
			_data->window.draw(_bomb[0]._explosion[1]);
		if (_bomb[0].estado == 2 && _bomb[0].vaiexplodir == true)
		{
			_bomb[0].vaiexplodir = false;
			for (unsigned int i = 0; i < _bloco.size(); i++)
			{
				if (_bomb[0]._explosion[0].getGlobalBounds().intersects(_bloco[i]._bloco.getGlobalBounds()))
				{
					if (_bloco[i].tipo == 2)
					{
						matriz[_bloco[i].posx][_bloco[i].posy] = 0;
						_bloco.erase(_bloco.begin() + i);
					}
				}
				if (_bomb[0]._explosion[0].getGlobalBounds().intersects(_player[desenhospop].getGlobalBounds()))
				{
					_data->window.draw(_player[4]);
					_data->machine.AddState(StateRef(new GameOverState(this->_data)));
				}
				if (_bomb[0]._explosion[0].getGlobalBounds().intersects(_NPC[desenhospop2].getGlobalBounds()))
				{
					_NPC[4].setPosition(Com.posx * 1.0f, Com.posy * 1.0f);
					_data->window.draw(_NPC[4]);
					Com.~NPC();
					_data->machine.AddState(StateRef(new GameOverState(this->_data)));
				}
			}
		}

		//Bomba da Ai
		_bomb[1].Explosion();
		_bomb[1].Explosion2();
		_bomb[1].Explosion3(1);
		if (_bomb[1].estado == 0)
			_data->window.draw(_bomb[1]._bomb);
		if (_bomb[1].estado == 1)
			_data->window.draw(_bomb[1]._bomb);
		if (_bomb[1].estado == 2)
			_data->window.draw(_bomb[1]._explosion[0]);
		if (_bomb[1].estado == 3)
			_data->window.draw(_bomb[1]._explosion[1]);
		if (_bomb[1].estado == 2 && _bomb[1].vaiexplodir == true)
		{
			_bomb[1].vaiexplodir = false;

			for (unsigned int i = 0; i < _bloco.size(); i++)
			{
				if (_bomb[1]._explosion[0].getGlobalBounds().intersects(_bloco[i]._bloco.getGlobalBounds()))
				{
					if (_bloco[i].tipo == 2)
					{
						matriz[_bloco[i].posx][_bloco[i].posy] = 0;
						_bloco.erase(_bloco.begin() + i);
					}
				}
				if (_bomb[1]._explosion[0].getGlobalBounds().intersects(_player[desenhospop].getGlobalBounds()))
				{
					_player[4].setPosition(player1.posx * 1.0f, player1.posy * 1.0f);
					_data->window.draw(_player[4]);
					player1.~Player();
					_data->machine.AddState(StateRef(new GameOverState(this->_data)));
				}
				if (_bomb[1]._explosion[0].getGlobalBounds().intersects(_NPC[desenhospop2].getGlobalBounds()))
				{
					_NPC[4].setPosition(Com.posx * 1.0f, Com.posy * 1.0f);
					_data->window.draw(_NPC[4]);
					Com.~NPC();
					_data->machine.AddState(StateRef(new GameOverState(this->_data)));
				}
			}
		}

		_data->window.display();
	}
}