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

void Player::setName() const
{
}

Deck Player::getHand() const
{
	return hand_;
}

void Player::setHand() const
{
}

Deck Player::getBoard() const
{
	return board_;
}

void Player::setBoard() const
{
}

int Player::getPower() const
{
	return power_;
}

void Player::setPower() const
{
}
 