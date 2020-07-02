#pragma once
#include <fstream>

#include "Player.h"
#include "VirtualPlayer.h"

class Game
{
public:
	Game(std::string name):
	player_(new Player(name,0)),opponent_(new VirtualPlayer()),turn_(0){}
	~Game() { delete player_; delete opponent_; }

	void prep();
	void startGame();
	void nextTurn();
	void cardPlayed(Card* c);
	void printState();
	void save();
	std::string getLeader();
	void endGame();

	int get_turn();
	Player* get_player();
	Player* get_opponent();
	Player* getActivePlayer();

private:
	std::ofstream results;
	Player* player_;
	Player* opponent_;
	Player* activePlayer_;

	int turn_;
};

