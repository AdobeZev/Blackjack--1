#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

/* Class */

class MainGame
{

	protected:

		/* Cards */

		std::vector<int> CardAmounts = {11,2,3,4,5,6,7,8,9,10,10,10,10};

		int Round = 0;
		bool Playing = false;

	public:

		/* Card Functions */

		void DealCard(std::vector<int> *Deck);

		int GetDeckAmount(std::vector<int> Deck, bool TrueNumbers = false);
		int CheckDeck(std::vector<int> Deck, bool TrueNumbers = false);
		std::string PrintDeckCards(std::vector<int> Deck, bool TrueNumbers = false, bool Dealer = false, int SpecificCard = -1);

		bool ResetDeck(std::vector<int> *Deck);

		/* Round Function */

		bool RunRound (std::vector<int> *PlayerDeck, std::vector<int> *DealerDeck, bool Player = true);

		/* Timer */

		void Wait(double Seconds);

		/* String Functions */

		int CheckString(std::string StringToCheck);

		MainGame();

};