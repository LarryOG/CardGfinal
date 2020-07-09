 #pragma once
#include <string>
#include <vector>

#include "Card.h"

class Deck
{
	using Container = std::vector<Card>;
public:
	using iterator = Container::iterator;
	using const_iterator = Container::const_iterator;
	
	Deck() {};
	Deck(int cards);
	~Deck() = default;

	iterator begin() { return deck_.begin(); }
	iterator end() { return deck_.end(); }
	const_iterator begin() const { return deck_.begin(); }
	const_iterator end() const { return deck_.end(); }
	const_iterator cbegin() const { return deck_.cbegin(); }
	const_iterator cend() const { return deck_.cend(); }
	
	void push(Card c);
	Card at(int i);
	Card pop(Card c);
	Card back();
    int size();
	bool isEmpty();
	void print(std::ostream& os);
	

	Card popSteal();
	
private:
	Container deck_;
};

