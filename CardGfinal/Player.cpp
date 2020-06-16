#include "Player.h"

void Player::takeCard(Deck d, Card c)
{
	hand_.push(d.pop(c));
}

void Player::playCard(Card c)
{
	board_.push(hand_.pop(c));
}

Deck Player::getHand() const
{
	return hand_;
}

Deck Player::getBoard() const
{
	return board_;
}

int Player::getPower() const
{
	return power_;
}
