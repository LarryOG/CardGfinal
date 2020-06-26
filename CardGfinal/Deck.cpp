#include "Deck.h"

#include <iostream>
#include <random>

Deck::Deck(int cards)
{
	int plusCards = 3*(cards / 6) + cards % 6;
	int minusCards = 2*(cards / 6);
	int stealCards = cards / 6;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 10);
	
	for(int i=0; i<plusCards; i++)
	{
		Card card = Card(Card::Type::PowerPlus, distr(gen));
			deck_.push_back(card);
	}
	for (int i = 0; i < minusCards; i++)
	{
		Card card = Card(Card::Type::PowerMinus, distr(gen));
		deck_.push_back(card);
	}
	for (int i = 0; i < stealCards; i++)
	{
		Card card = Card(Card::Type::Steal, distr(gen));
		deck_.push_back(card);
	}
	
}

void Deck::push(Card c)
{
	deck_.push_back(c);
}

Card Deck::at(int i)
{
	return deck_.at(i);
}

Card Deck::pop(Card c) 
{

	int a = 0;
 
	auto i = std::begin(deck_);
	while(i != std::end(deck_))
	{
		if(i->equals(c))
		{
			deck_.erase(i);
			break;
		}
		++i;
	}
    
	//deck_.erase(std::remove(deck_.begin(), deck_.end(), c), deck_.end());
	return c;
}

int Deck::size()
{
	return deck_.size();
}

bool Deck::isEmpty()
{
	if (deck_.empty()) 
		return true;
	else return false;
	
}

void Deck::print()
{
	int i = 1;
	//std::cout << "Cards in deck are: " << std::endl;
	for (Card c : deck_)
	{
		std::cout << i << " ";
		c.printCard();
		std::cout << std::endl;
		i++;
	}
}

Card Deck::popSteal()
{
	for (Card c : deck_)
	{
		if (c.getType()==Card::Type::Steal)
		{
			return c;
		}
	}
}
 
Card Deck::popPowerPlus()
{
	
}

Card Deck::popPowerMinus()
{
}
