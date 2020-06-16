#pragma once
#include <vector>
#include <cstdlib>

#include "Card.h"

class Deck
{
public:
	Deck(int cards, int maxValue);
	~Deck();
	
	void push(Card c);
	Card pop(Card c);
    int size();
	bool isEmpty();
	void print();
	
private:
	std::vector<Card> deck_;
};

