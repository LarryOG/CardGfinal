#include "Card.h"

#include <iostream>
#include <random>


#include "Game.h"



bool Card::equals(const Card& c) const 
{
	if (type_ ==c.getType() && power_ == c.getPower())
		return true;
	else return false;

}

void Card::printCard() const
{
	if (this->getType() == Type::Steal)
	{  //if power is odd
		if (this->power_ & 1)
			std::cout << " Steal: steal random card" << "\n ";
		else //if power is even
			std::cout << " Steal: choose a card to steal" << "\n ";
	} else if (this->getType() == Type::PowerMinus)
	{
		std::cout << " Power Minus: " << this->power_ << "\n ";
	}else if (this->getType() == Type::PowerPlus)
	{
		std::cout << " Power Plus: " << this->power_ << "\n ";
	}else if (this->getType()==Type::Double)
	{
		std::cout << " Double: double your power\n ";
	}
}
