#include "Game.h"
#include "Card.h"
#include <iostream>
#include <random>


#include "OutOfBoundsException.h"

void Game::prep()
{
	Deck deck(20);
	std::cout << "\n Main Deck generated.\n" << " Now choose 5 cards you wish to play with, one at a time.\n";
	std::cout << " Similarly, your opponent will select 1 card at a time, until both of you have 5 card to play.\n";
	while(opponent_->getHand().size()!=5 || player_->getHand().size()!=5)
	{
		try {
			std::cout << "\n There are "<<deck.size()<<" cards in main deck now.\n ";
			deck.print(std::cout);
			std::cout << "\n ";
			if (turn_ & 1)
			{
				std::cout << opponent_->getName() << " has " << opponent_->getHand().size();
				std::cout << " cards in hand now. \n ";
				std::cout << player_->getName() << " has " << player_->getHand().size() << " cards in hand now.\n ";
				std::cout << opponent_->getName() << ", choose a card now.\n ";
				opponent_->takeCard(deck, deck.at(1));
				std::cout << "\n Card chosen. Cards in "<<opponent_->getName();
				std::cout << " hand are now:\n ";
				opponent_->getHand().print(std::cout);
				nextTurn();
			}
			else
			{
				std::cout << player_->getName() << " has " << player_->getHand().size();
				std::cout << " cards in hand now.\n ";
				std::cout << opponent_->getName() << " has " << opponent_->getHand().size() << " cards in hand now.\n ";
				int cardNumber;
				while (std::cout << player_->getName() << ", choose a card now.\n " && !(std::cin >> cardNumber)) {
					std::cin.clear(); //clear bad input flag
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
					std::cout << "Invalid input; please re-enter.\n ";
				}
				
				player_->takeCard(deck, deck.at(cardNumber));
				std::cout << "\n Card chosen. Cards in " << player_->getName();
				std::cout << " hand are now:\n ";
				player_->getHand().print(std::cout);
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
		std::ofstream results;
		results.open("results.txt", std::ios_base::app);
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
				opponent_->getBoard().print(std::cout);
				this->printState(std::cout);
				this->printState(results);
				this->nextTurn();
			}
			else if (this->getActivePlayer() == player_)
			{
				std::cout << "\n " << player_->getName() << " turn. Play card.\n";
				int cardNumber;
				while (std::cout << " Choose a card to play:\n " && (!(std::cin >> cardNumber) || cardNumber > player_->getHand().size() || cardNumber < 1)) {
					std::cin.clear(); //clear bad input flag
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
					std::cout << " Invalid input; please re-enter.\n ";
				}
				Card* card = &player_->getHand().at(cardNumber);
				this->cardPlayed(card);
				player_->playCard(player_->getHand().at(cardNumber));

				std::cout << "\n Card played. Cards on " << player_->getName();
				std::cout << " board are:\n ";
				player_->getBoard().print(std::cout);
				this->printState(std::cout);
				this->printState(results);
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
					std::cout << "\n no cards to steal- transforming to PowerPlus: 1\n ";

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
					std::cout << "\n no cards to steal- transforming to PowerPlus: 1\n ";
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
					std::cout << "\n no cards to steal- transforming to PowerPlus: 1\n ";

				}
			}
			else
			{
				if (!this->get_opponent()->getHand().isEmpty())
				{
					int cardnumber;
					while (std::cout << "\n Please choose a card to steal from opponents hand. \n " && !(std::cin >> cardnumber)) {
						std::cin.clear(); //clear bad input flag
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
						std::cout << "Invalid input; please re-enter.\n ";
					}
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
					std::cout << "\n no cards to steal- transforming to PowerPlus: 1\n ";

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

void Game::printState(std::ostream& os)
{
	os << "\n Turn: \n "<<turn_<<"\n Player in charge: \n "<< getLeader();
	os << "\n Card played this turn, ";
	if (this->getActivePlayer()==opponent_)
	{
		os << "by " << opponent_->getName() << std::endl;
		opponent_->getBoard().back().printCard(os);
	} else if(this->getActivePlayer()==player_ && turn_==7)
	{
		os << "by " << opponent_->getName() << std::endl;
		opponent_->getBoard().back().printCard(os);
	}
	else
	{
		os << "by " << player_->getName() << std::endl;
		player_->getBoard().back().printCard(os);
	}
	if (getLeader()==opponent_->getName())
	{
		os << opponent_->getName() << "'s power level: " << opponent_->getPower();
		os << "\n " << player_->getName() << "'s power level: " << player_->getPower();
		os << "\n " << opponent_->getName() << "'s card's still to be played: \n ";
		opponent_->getHand().print(os);
		os << player_->getName() << "'s card's still to be played: \n ";
		player_->getHand().print(os);
	}else
	{
		os << player_->getName() << "'s power level: " << player_->getPower();
		os << "\n " << opponent_->getName() << "'s power level: " << opponent_->getPower();
		os << "\n " << player_->getName() << "'s card's still to be played: \n ";
		player_->getHand().print(os);
		os << opponent_->getName() << "'s card's still to be played: \n ";
		opponent_->getHand().print(os);
	}
}


std::string Game::getLeader()
{
	if (player_->getPower() > opponent_->getPower())
	{
		return player_->getName();
	}
	else return opponent_->getName();
}

void Game::endGame()
{

	std::cout << "\n Game finished!\n ";
	if (player_->getPower() > opponent_->getPower())
	{
		std::cout << "The winner is: " << player_->getName()<<"\n\n\n ";
	}
	else if (player_->getPower() == opponent_->getPower())
	{
		std::cout << "It's a draw!\n\n\n ";
	}else
	{
		std::cout << "The winner is: " << opponent_->getName()<<"\n\n\n ";
	}
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
