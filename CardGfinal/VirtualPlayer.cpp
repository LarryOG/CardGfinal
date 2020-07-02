#include "VirtualPlayer.h"
#include "Game.h"

void VirtualPlayer::takeCard(Deck& d, Card c)
{
	auto it = d.begin();
	auto size = this->getHand().size();
 		while (it != d.end())
		{
			if (it->getType() == Card::Type::Steal)
			{
				this->hand_.push(d.pop(*it));
				break;
			}
			++it;
		}
		if (size == this->getHand().size())
		{
			it = d.begin();
			while (it != d.end())
			{
				if (it->getType() == Card::Type::PowerPlus && it->getPower() > 7)
				{
					this->hand_.push(d.pop(*it));
					break;
				}
				++it;
			}
		}
		if (size == this->getHand().size())
		{
			it = d.begin();
			while (it != d.end())
			{
				if (it->getType() == Card::Type::Double)
				{
					this->hand_.push(d.pop(*it));
					break;
				}
				++it;
			}
		}
		if (size == this->getHand().size())
		{
			it = d.begin();
			while (it != d.end())
			{
				if (it->getType() == Card::Type::PowerMinus && it->getPower() > 7)
				{
					this->hand_.push(d.pop(*it));
					break;
				}
				++it;
			}
		}
		if (size == this->getHand().size())
		{
			it = d.begin();
			while (it != d.end())
			{
				if (it->getType() == Card::Type::PowerPlus && it->getPower() > 5)
				{
					this->hand_.push(d.pop(*it));
					break;
				}
				++it;
			}
		}
		if (size == this->getHand().size())
		{
			it = d.begin();
			while (it != d.end())
			{
				if (it->getType() == Card::Type::PowerMinus && it->getPower() > 5)
				{
					this->hand_.push(d.pop(*it));
					break;
				}
				++it;
			}
		}
		if (size == this->getHand().size())
		{
			it = d.begin();
			while (it != d.end())
			{
				if (it->getType() == Card::Type::PowerPlus && it->getPower() > 3)
				{
					this->hand_.push(d.pop(*it));
					break;
				}
				++it;
			}
		}
		if (size == this->getHand().size())
		{
			it = d.begin();
			while (it != d.end())
			{
				if (it->getType() == Card::Type::PowerMinus && it->getPower() > 3)
				{
					this->hand_.push(d.pop(*it));
					break;
				}
				++it;
			}
		}
		if (size == this->getHand().size())
		{
			it = d.begin();
			while (it != d.end())
			{
				if (it->getType() == Card::Type::PowerPlus && it->getPower() > 1)
				{
					this->hand_.push(d.pop(*it));
					break;
				}
				++it;
			}
		}
	    if (size == this->getHand().size())
		{
			it = d.begin();
			while (it != d.end())
			{
				if (it->getType() == Card::Type::PowerMinus && it->getPower() > 1)
				{
					this->hand_.push(d.pop(*it));
					break;
				}
				++it;
			}
		}
}

void VirtualPlayer::playCard(Card c)
{
	board_.push(hand_.pop(c));
	/*auto it = hand_.begin();
	auto size = this->getHand().size();
	while (it != hand_.end())
	{
		if (it->getType() == Card::Type::Steal)
		{
			this->board_.push(hand_.pop(*it));
			break;
		}
		++it;
	}
	if (size == this->getHand().size())
	{
		it = hand_.begin();
		while (it != hand_.end())
		{
			if (it->getType() == Card::Type::PowerPlus)
			{
				this->board_.push(hand_.pop(*it));
				break;
			}
			++it;
		}
	}
	if (size == this->getHand().size())
	{
		it = hand_.begin();
		while (it != hand_.end())
		{
			if (it->getType() == Card::Type::Double)
			{
				this->board_.push(hand_.pop(*it));
				break;
			}
			++it;
		}
	}
	if (size == this->getHand().size())
	{
		it = hand_.begin();
		while (it != hand_.end())
		{
			if (it->getType() == Card::Type::PowerMinus)
			{
				this->board_.push(hand_.pop(*it));
				break;
			}
			++it;
		}
	}*/
}
