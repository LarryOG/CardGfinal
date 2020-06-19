#pragma once
#include <string>
#include <vector>

#include "Card.h"

class Deck
{
public:
	Deck() {}
	Deck(int cards);
	~Deck() = default;
	
	void push(Card c);
	Card at(int i);
	Card pop(Card c);
    int size();
	bool isEmpty();
	void print();
	
private:
	//d::string name_;
	std::vector<Card> deck_;
};

