#pragma once
#include "Deck.h"

class Player
{
public:
	Player():power_(0) {};
	Player(std::string name, int power) :
	name_(name), power_(power) {}
	~Player()=default;
	
	virtual void takeCard(Deck& d, Card c);
	virtual void playCard(Card c);

	std::string getName() const;
	void setName() const;
	Deck getHand() const;
	void setHand() const;
	Deck getBoard() const;
	void setBoard() const;
	int getPower() const;
	void setPower() const;

private:
	std::string name_;
	Deck hand_;
	Deck board_;
	int power_;
};

