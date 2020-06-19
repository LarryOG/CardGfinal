#include "Card.h"

#include <iostream>

bool Card::equals(const Card& c) const 
{
	if (type_ ==c.getType() && power_ == c.getPower())
		return true;
	else return false;

}

void Card::printCard() const
{
	if (this->getType() == Type::Steal)
	{
		if (this->power_ & 1)
			std::cout << "Steal: steal random card";
		else
			std::cout << "Steal: choose a card to steal";
	} else if (this->getType() == Type::PowerMinus)
	{
		std::cout << "Power Minus: " << this->power_;
	}else if (this->getType() == Type::PowerPlus)
	{
		std::cout << "Power Plus: " << this->power_;
	}
}
