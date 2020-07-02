#include "Deck.h"

#include <iostream>
#include <random>

#include "OutOfBoundsException.h"

Deck::Deck(int cards)
{
    std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 10);
	
	int minusCards = distr(gen);
	int plusCards = cards-minusCards-3-2;
	int stealCards = 3;
	int doubleCards = 2;

	
	
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
	for (int i = 0; i < doubleCards; i++)
	{
		Card card = Card(Card::Type::Double, 0);
		deck_.push_back(card);
	}
	auto rng = std::default_random_engine{};
	std::shuffle(begin(), end(), rng);
}

void Deck::push(Card c)
{
	deck_.push_back(c);
}

Card Deck::at(int i)
{
	int s = deck_.size();
	if (s >= --i && i>=0)
    {		
		return deck_.at(i);
    }
	else
	{
		throw OutOfBoundsException();
	}
	
		
	
	
}

Card Deck::pop(Card c) 
{

	
 
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
    
	return c;
}

Card Deck::back()
{
	return deck_.back();
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
	for (Card c : deck_)
	{
		std::cout << i << " ";
		c.printCard();
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
