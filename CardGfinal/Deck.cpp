#include "Deck.h"
#include <random>

Deck::Deck(int cards, int maxValue)
{
	int plusCards = 3*(cards / 6) + cards % 6;
	int minusCards = 2*(cards / 6);
	int stealCards = cards / 6;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, maxValue);
	
	for(int i=0; i<plusCards; i++)
	{
		Card card = new Card(Card::Type::PowerPlus, distr(gen));
			deck_.push_back(card);
	}
	for (int i = 0; i < minusCards; i++)
	{
		Card card = new Card(Card::Type::PowerMinus, distr(gen));
		deck_.push_back(card);
	}
	for (int i = 0; i < stealCards; i++)
	{
		Card card = new Card(Card::Type::Steal, distr(gen));
		deck_.push_back(card);
	}
	
}

void Deck::push(Card c)
{
	deck_.push_back(c);
}

Card Deck::pop(Card c)
{
	deck_.erase(std::remove(deck_.begin(), deck_.end(), c), deck_.end());
	return c;
}

int Deck::size()
{
	return deck_.size();
}

bool Deck::isEmpty()
{
	if (deck_.size() > 0)
		return false;
	
}

void Deck::print()
{
}
