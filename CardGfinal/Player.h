#pragma once
#include "Deck.h"

class Player
{
public:
	Player() : power_(0) { }
	~Player();
	
	void takeCard(Deck& d, Card c);
	void playCard(Card c);

	Deck getHand() const;
	//void setHand();
	Deck getBoard() const;
	int getPower() const;

private:
	Deck hand_;
	Deck board_;
	int power_;
};

