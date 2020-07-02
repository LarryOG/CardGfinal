#include "Game.h"
#include "Card.h"
#include <iostream>
#include <random>


#include "OutOfBoundsException.h"

void Game::prep()
{
	Deck deck(20);
	std::cout << "\nDeck generated.\n";
	while(opponent_->getHand().size()!=5 || player_->getHand().size()!=5)
	{
		try {
			std::cout << "\n Choose a card from main deck\n ";
			deck.print();
			std::cout << std::endl;
			if (turn_ & 1)
			{
				std::cout << opponent_->getName() << " choose a card. \n";
				opponent_->takeCard(deck, deck.at(1));
				std::cout << "\nCard chosen. Cards in "<<opponent_->getName();
				std::cout << " hand are now:\n";
				opponent_->getHand().print();
				nextTurn();
			}
			else
			{
				std::cout << player_->getName() << " choose a card. \n";
				int cardNumber;
				std::cin >> cardNumber;
				player_->takeCard(deck, deck.at(cardNumber));
				std::cout << "\nCard chosen. Cards in " << player_->getName();
				std::cout << " hand are now:\n";
				player_->getHand().print();
				nextTurn();
			}
		}catch (OutOfBoundsException &)
		{
			std::cout << "\n\n Exception occured. Card number out of range. Try again!\n\n "; 
		}
	}
}

void Game::startGame()
{
	try {
		turn_ = 1; activePlayer_ = opponent_; 
		std::cout << "\n Starting game, brace yourself!\n";
		while (!opponent_->getHand().isEmpty() || !player_->getHand().isEmpty())
		{
			if (this->getActivePlayer() == opponent_)
			{
				std::cout << "\n " << opponent_->getName() << " turn. Play card.\n";
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> distr(1, opponent_->getHand().size());
				int i = distr(gen);
				Card* card = &opponent_->getHand().at(i);
				this->cardPlayed(card);
				opponent_->playCard(opponent_->getHand().at(i));
				std::cout << "\n Card played. Cards on " << opponent_->getName();
				std::cout << " board are:\n ";
				opponent_->getBoard().print();
				this->printState();
				this->nextTurn();
			}
			else if (this->getActivePlayer() == player_)
			{
				std::cout << "\n " << player_->getName() << " turn. Play card.\n";
				int cardNumber;
				std::cout << " Choose a card to play:\n ";
				std::cin >> cardNumber;
				Card* card = &player_->getHand().at(cardNumber);
				this->cardPlayed(card);
				player_->playCard(player_->getHand().at(cardNumber));

				std::cout << "\n Card played. Cards on " << player_->getName();
				std::cout << " board are:\n ";
				player_->getBoard().print();
				this->printState();
				this->save();
				this->nextTurn();
			}

		}
	}
	catch (OutOfBoundsException&)
	{
		std::cout << "\n\n Exception occured. Card number out of range. Try again!\n\n ";
	}
}

void Game::nextTurn()
{
	++turn_;
	if (turn_ & 1 && !opponent_->getHand().isEmpty())
	{
		activePlayer_= opponent_;
	}
	else if (turn_ & 1 && opponent_->getHand().isEmpty())
	{
		activePlayer_ = player_;
	}
	if (!(turn_ & 1) && !player_->getHand().isEmpty())
	{
		activePlayer_ = player_;
	}
	if (!(turn_ & 1) && player_->getHand().isEmpty())
	{
		activePlayer_ = opponent_;
	}
}

void Game::cardPlayed(Card* c)
{
	try
	{
		
	
	if (c->getType() == Card::Type::Steal)
	{  //if power is odd
		if (c->getPower() & 1)
		{//Steal: steal random card
			if (this->getActivePlayer()==opponent_)
			{
				if (!this->get_player()->getHand().isEmpty())
				{
					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<> distr(1, this->get_player()->getHand().size());
					Deck d = this->get_opponent()->getHand();
					Card c = this->get_player()->getHand().at(distr(gen));
					this->get_player()->removeFromHand(c);
					d.push(c);
					this->get_opponent()->setHand(d);

				}
				else
				{
					c->setType(Card::Type::PowerPlus);
					c->setPower(1);
					this->cardPlayed(c);
				}
			}
			else
			{
				if (!this->get_opponent()->getHand().isEmpty())
				{
					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<> distr(1, this->get_opponent()->getHand().size());
					Deck d = this->get_player()->getHand();
					Card c = this->get_opponent()->getHand().at(distr(gen));
					this->get_opponent()->removeFromHand(c);
					d.push(c);
					this->get_player()->setHand(d);

				}
				else
				{
					c->setType(Card::Type::PowerPlus);
					c->setPower(1);
					this->cardPlayed(c);
				}
			}
		}

		else //if power is even
		{//Steal: choose a card to steal
			if (this->getActivePlayer() == opponent_)
			{
				if (!this->get_player()->getHand().isEmpty())
				{
					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<> distr(1, this->get_player()->getHand().size());
					Deck d = this->get_opponent()->getHand();
					Card c = this->get_player()->getHand().at(distr(gen));
					this->get_player()->removeFromHand(c);
					d.push(c);
					this->get_opponent()->setHand(d);

				}
				else
				{
					c->setType(Card::Type::PowerPlus);
					c->setPower(1);
					this->cardPlayed(c);
				}
			}
			else
			{
				if (!this->get_opponent()->getHand().isEmpty())
				{
					int cardnumber;
					std::cout << "\n Please choose a card to steal from opponents hand. \n";
					std::cin >> cardnumber;
					Deck d = this->get_player()->getHand();
					Card c = this->get_opponent()->getHand().at(cardnumber);
					this->get_opponent()->removeFromHand(c);
					d.push(c);
					this->get_player()->setHand(d);
				}
				else
				{
					c->setType(Card::Type::PowerPlus);
					c->setPower(1);
					this->cardPlayed(c);
				}

			}
		}
	}
	else if (c->getType() == Card::Type::PowerMinus)
	{
		if (this->getActivePlayer() == opponent_)
		{
			int p = this->get_player()->getPower();
			this->get_player()->setPower(p - c->getPower());
		}
		else
		{
			int p = this->get_opponent()->getPower();
			this->get_opponent()->setPower(p - c->getPower());
		}
	}
	else if (c->getType() == Card::Type::PowerPlus)
	{
		if (this->getActivePlayer() == opponent_)
		{
			int p = this->get_opponent()->getPower();
			this->get_opponent()->setPower(p + c->getPower());
		}
		else
		{
			int p = this->get_player()->getPower();
			this->get_player()->setPower(p + c->getPower());
		}
	}
	else if (c->getType()== Card::Type::Double)
	{
		if (this->getActivePlayer()==opponent_)
		{
			int p = this->get_opponent()->getPower();
			this->get_opponent()->setPower(p + p);
		}
		else
		{
			int p = this->get_player()->getPower();
			this->get_player()->setPower(p + p);
		}
	}
	}
	catch (OutOfBoundsException&)
	{
		std::cout << "\n\n Exception occured. Card number out of range. Try again!\n\n ";
	}
}

void Game::printState()
{
	std::cout << "\n Turn: \n "<<turn_<<"\n Player in charge: \n "<< getLeader();
	std::cout << "\n Card played this turn, ";
	if (this->getActivePlayer()==opponent_)
	{
		std::cout << "by " << opponent_->getName() << std::endl;
		opponent_->getBoard().back().printCard();
	} else if(this->getActivePlayer()==player_ && turn_==7)
	{
		std::cout << "by " << opponent_->getName() << std::endl;
		opponent_->getBoard().back().printCard();
	}
	else
	{
		std::cout << "by " << player_->getName() << std::endl;
		player_->getBoard().back().printCard();
	}
	if (getLeader()==opponent_->getName())
	{
		std::cout << opponent_->getName() << "'s power level: " << opponent_->getPower();
		std::cout << "\n " << player_->getName() << "'s power level: " << player_->getPower();
		std::cout << "\n " << opponent_->getName() << "'s card's still to be played: \n ";
		opponent_->getHand().print();
		std::cout << player_->getName() << "'s card's still to be played: \n ";
		player_->getHand().print();
	}else
	{
		std::cout << player_->getName() << "'s power level: " << player_->getPower();
		std::cout << "\n " << opponent_->getName() << "'s power level: " << opponent_->getPower();
		std::cout << "\n " << player_->getName() << "'s card's still to be played: \n ";
		player_->getHand().print();
		std::cout << opponent_->getName() << "'s card's still to be played: \n ";
		opponent_->getHand().print();
	}
}

void Game::save()
{
	//results.open("results.txt", std::ios_base::app);
	//results << this->printState();
	
}

std::string Game::getLeader()
{
	if (player_->getPower() > opponent_->getPower())
	{
		return player_->getName();
	}
	else return opponent_->getName();
}

Player* Game::getActivePlayer()
{
	return activePlayer_;
}

int Game::get_turn()
{
	return turn_;
}

Player* Game::get_player()
{
	return player_;
}

Player* Game::get_opponent()
{
	return opponent_;
}
