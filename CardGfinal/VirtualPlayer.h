#pragma once
#include "Player.h"
class VirtualPlayer :
    public Player
{
public:
	VirtualPlayer():
	Player("Computer", 0){}

	virtual void takeCard(Deck& d, Card c) override;
	virtual void playCard(Card c) override;
};

