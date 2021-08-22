#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <chrono>

/* Class */

class MainGame
{

	protected:

		/* Cards */

		std::vector<int> CardAmounts = {11,2,3,4,5,6,7,8,9,10,10,10,10};

	public:

		/* Card Functions */

		void DealCard(std::vector<int> *Deck);
		int GetDeckAmount(std::vector<int> Deck, bool TrueNumbers = false);
		int CheckDeck(std::vector<int> Deck, bool TrueNumbers = false);

		MainGame();

};