#pragma once

class Player;
class World;

class GameLogic
{
	Player& m_player;
	World& m_world;
public:
	GameLogic(World& world, Player& player);
	~GameLogic();

	bool processInput();
};

