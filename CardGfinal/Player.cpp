#include "Player.h"

void Player::takeCard(Deck& d, Card c)
{
	hand_.push(d.pop(c));
}

void Player::playCard(Card c)
{
	board_.push(hand_.pop(c));
}

std::string Player::getName() const
{
	return name_;
}


Deck Player::getHand() const
{
	return hand_;
}

void Player::setHand(Deck d)
{
	hand_ = d;
}


Deck Player::getBoard() const
{
	return board_;
}


int Player::getPower() const
{
	return power_;
}

void Player::setPower(int p) 
{
	power_ = p;
}
 
void Player::removeFromHand(Card c)
{
	hand_.pop(c);
}
