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

	public:

		/* Card Functions */

		void DealCard(std::vector<int> *Deck);

		int GetDeckAmount(std::vector<int> Deck, bool TrueNumbers = false);
		int CheckDeck(std::vector<int> Deck, bool TrueNumbers = false);

		bool ResetDeck(std::vector<int> *Deck);

		/* Round Function */

		bool RunRound (std::vector<int> *PlayerDeck, std::vector<int> *DealerDeck, bool Player = true);

		/* Timer */

		void Wait(double Seconds);

		MainGame();

};