#include "main.h"

/* Main Game Class */

/* Card Functions */

void MainGame::DealCard(std::vector<int> *Deck)
{

	srand(time(NULL));
	Deck->push_back(CardAmounts[rand() % CardAmounts.size()]);

};

int MainGame::GetDeckAmount(std::vector<int> Deck, bool TrueNumbers)
{

	int TrueNumber = 0;
	int FalseNumber = 0;

	for (int i = 0; i < Deck.size(); i++)
	{

		int CurrentNumber = Deck[i];
		TrueNumber += CurrentNumber;

	}

	if (TrueNumber >= 22)
	{

		if (TrueNumbers)
		{
			return TrueNumber;
		}
		else
		{

			for (int i = 0; i < Deck.size(); i++)
			{

				int CurrentNumber = Deck[i];

				if (CurrentNumber == 11)
				{
					CurrentNumber = 1;
				}

				FalseNumber += CurrentNumber;

			}

			return FalseNumber;

		}	

	}
	else
	{

		return TrueNumber;

	}

};

int MainGame::CheckDeck(std::vector<int> Deck, bool TrueNumbers)
{

	if (Deck.size() == 0) { return 2; }

	int TrueDeckAmount = 0;
	int SoftDeckAmount = 0;

	for (int i = 0; i < Deck.size(); i++)
	{
		TrueDeckAmount += Deck[i];
	};

	if (TrueDeckAmount >= 22)
	{

		if (TrueNumbers)
		{
			return 1;
		}
		else
		{

			for (int i = 0; i < Deck.size(); i++)
			{

				if (Deck[i] == 11)
				{
					SoftDeckAmount += 1;
				}
				else
				{
					SoftDeckAmount += Deck[i];
				}
			};

			if (SoftDeckAmount >= 22)
			{
				return 1;
			}
			else if (SoftDeckAmount <= 20)
			{
				return 2;
			}
			else
			{
				return 3;
			}

		}

	}
	else if (TrueDeckAmount <= 20)
	{
		return 2;
	}
	else if (TrueDeckAmount == 21)
	{
		return 3;
	}
	else
	{
		return 1;
	}

};

bool MainGame::ResetDeck(std::vector<int> Deck)
{

	Deck.clear();

	if (Deck.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

// Round Functions

bool MainGame::RunRound(std::vector<int> PlayerDeck, std::vector<int> DealerDeck, bool Player)
{

	if (Round == 0)
	{

		/* Check Decks */

		if (GetDeckAmount(PlayerDeck, true) >= 1)
		{
			if (!ResetDeck(PlayerDeck))
			{
				return false;
			}
		}

		if (GetDeckAmount(PlayerDeck, true) >= 1)
		{
			if (!ResetDeck(DealerDeck))
			{
				return false;
			}
		}

		/* Deal First Cards */

	}
	else
	{

		/* Display Total */

	}

};

void MainGame::Wait(double Seconds)
{

	std::this_thread::sleep_for(std::chrono::duration<double>(Seconds));

}


MainGame::MainGame(){};

int main(){

	MainGame Game;

	std::vector<int> PlayerDeck = {11};
	Game.DealCard(&PlayerDeck);

	std::cout << Game.GetDeckAmount(PlayerDeck, true) << std::endl;

	switch(Game.CheckDeck(PlayerDeck, true))
	{

		case 1:
			std::cout << "Fumble" << std::endl;
		break;

		case 2:
			std::cout << "Hit or Stand?" << std::endl;
		break;

		case 3:
			std::cout << "Winner" << std::endl;
		break;

		default:
			std::cout << "Error" << std::endl;
		break;

	};

	return 0;
};