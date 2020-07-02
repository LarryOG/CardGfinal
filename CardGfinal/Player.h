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
	//void setName() const;
	Deck getHand() const;
	void setHand(Deck d);
	Deck getBoard() const;
	//void setBoard() const;
	int getPower() const;
	void setPower(int p);
	void removeFromHand(Card c);

private:
	std::string name_;
	int power_;
protected:
	Deck hand_; 
	Deck board_;
};

