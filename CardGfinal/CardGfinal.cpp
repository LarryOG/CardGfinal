// CardGfinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Deck.h"
#include "OutOfBoundsException.h"
#include "Player.h"
#include "Game.h"


int main()
{
	/*
	 *std::cout << "Creating mainDeck of 20 cards\n";
	Deck mainDeck = Deck(5);
	mainDeck.print();
	
	std::cout << "Creating empty sideDeck \n";

	Deck sideDeck = Deck();
	std::cout << "Is mainDeck empty?\n"<< mainDeck.isEmpty() << std::endl;
	std::cout << "Is sideDeck empty?\n"<< sideDeck.isEmpty() << std::endl;
	std::cout << "Size of mainDeck is: " << mainDeck.size() << std::endl;
	int cardNumber;
	std::cout << "select card to move" << std::endl;
	std::cin >> cardNumber;
	std::cout << "pushing card from main to side" << std::endl;
	sideDeck.push(mainDeck.pop(mainDeck.at(--cardNumber)));
	std::cout << "Size of mainDeck is: " << mainDeck.size() << std::endl;
	std::cout << "sideDeck consist of:" << std::endl;
	sideDeck.print();
	std::cout << "mainDeck consist of:" << std::endl;
	
	
	mainDeck.print();
	*/
	/*
	try {
		Player player1 = Player();
		Player player2 = Player();
		Deck deck = Deck(20);

		std::cout << "deck generated" << std::endl;
		deck.print();
		std::cout << "\n" << deck.size() << "\n";
		std::cout << "player1, pick a card" << std::endl;
		int cardNumber;
		std::cin >> cardNumber;
		player1.takeCard(deck, deck.at(cardNumber));
		std::cout << "player1 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << "\n" << deck.size() << "\n";

		std::cout << "player2, pick a card" << std::endl;
		std::cin >> cardNumber;
		player2.takeCard(deck, deck.at(cardNumber));
		std::cout << "player2 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << "\n" << deck.size() << "\n";

		std::cout << "player1, pick a card" << std::endl;
		std::cin >> cardNumber;
		player1.takeCard(deck, deck.at(cardNumber));
		std::cout << "player1 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << "\n" << deck.size() << "\n";

		std::cout << "player2, pick a card" << std::endl;
		std::cin >> cardNumber;
		player2.takeCard(deck, deck.at(cardNumber));
		std::cout << "player2 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << "\n" << deck.size() << "\n";

		std::cout << "player1, pick a card" << std::endl;
		std::cin >> cardNumber;
		player1.takeCard(deck, deck.at(cardNumber));
		std::cout << "player1 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << "player2, pick a card" << std::endl;
		std::cin >> cardNumber;
		player2.takeCard(deck, deck.at(cardNumber));
		std::cout << "player2 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << "player1, pick a card" << std::endl;
		std::cin >> cardNumber;
		player1.takeCard(deck, deck.at(cardNumber));
		std::cout << "player1 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << "player2, pick a card" << std::endl;
		std::cin >> cardNumber;
		player2.takeCard(deck, deck.at(cardNumber));
		std::cout << "player2 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << "player1, pick a card" << std::endl;
		std::cin >> cardNumber;
		player1.takeCard(deck, deck.at(cardNumber));
		std::cout << "player1 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << "player2, pick a card" << std::endl;
		std::cin >> cardNumber;
		player2.takeCard(deck, deck.at(cardNumber));
		std::cout << "player2 picked a card " << cardNumber << std::endl;
		deck.print();
		std::cout << std::endl << std::endl;

		std::cout << "player1 hand has " << player1.getHand().size() << " cards:" << std::endl;
		player1.getHand().print();
		std::cout << "player2 hand has " << player2.getHand().size() << " cards:" << std::endl;
		player2.getHand().print();

		std::cout << "player1 play a card. \n";
		std::cin >> cardNumber;
		player1.playCard(player2.getHand().at(cardNumber));
		std::cout << "player1 hand has \n";
		player1.getHand().print();
		std::cout << "player2 hand has \n";
		player2.getHand().print();
		std::cout << "player1 board has \n";
		player1.getBoard().print();
	}
	catch (OutOfBoundsException &)
	{
		std::cout << "\nCard number out of range\n";
	}

	*/
	
try
{
	std::cout << " Welcome to Card-G \n ";
	std::string name;
	while (std::cout << "Enter player name to start:\n " && !(std::cin >> name)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << " Invalid input; please re-enter.\n ";
	}

	Game g(name);
	g.prep();
	std::cout << "\n\n Prep finished.\n\n ";
	g.startGame();
	g.endGame();

}

catch (OutOfBoundsException &)
{
		std::cout << "\n\n Card number out of bounds.\n\n ";
}
/*
Player player2 = Player();
Deck deck = Deck(20);

std::cout << "deck generated" << std::endl;
deck.print();
std::cout << "Computer pick a card" << std::endl;
player2.takeCard(deck, deck.popSteal());
player2.getHand().print();
*/
}
