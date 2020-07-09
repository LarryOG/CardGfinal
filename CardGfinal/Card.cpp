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

void Card::printCard(std::ostream& os) const
{
	if (this->getType() == Type::Steal)
	{  //if power is odd
		if (this->power_ & 1)
			os << " Steal: steal random card" << "\n ";
		else //if power is even
			os << " Steal: choose a card to steal" << "\n ";
	} else if (this->getType() == Type::PowerMinus)
	{
		os << " Power Minus: " << this->power_ << "\n ";
	}else if (this->getType() == Type::PowerPlus)
	{
		os << " Power Plus: " << this->power_ << "\n ";
	}else if (this->getType()==Type::Double)
	{
		os << " Double: double your power\n ";
	}
}
