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

	int TrueDeckAmount = GetDeckAmount(Deck, true);
	int SoftDeckAmount = GetDeckAmount(Deck);

	if (TrueDeckAmount >= 22)
	{

		if (TrueNumbers)
		{
			return 1;
		}
		else
		{

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

std::string MainGame::PrintDeckCards(std::vector<int> Deck, bool TrueNumbers, bool Dealer, int SpecificCard)
{
   
	if (SpecificCard != -1)
	{

		if (SpecificCard > Deck.size() - 1)
		{
			return "[Error MG::PDC-SC-DS: Too Big]" + std::to_string(Deck.size() - 1) + " " + std::to_string(SpecificCard) + "]";
		}
		else
		{
			return "[" + std::to_string(Deck[SpecificCard]) + "]";
		}

	}

	// [1][9]
	std::string Cards = "";

	int TrueNumber = GetDeckAmount(Deck, true);
	int SoftNumber = GetDeckAmount(Deck);

	if (TrueNumber == SoftNumber || TrueNumber < 22 || TrueNumbers)
	{
		for (int i = 0; i < Deck.size(); i++)
		{
			if (Dealer && i != 0)
			{
				Cards += "[X]";
			}
			else
			{
				Cards += "[" + std::to_string(Deck[i]) + "]";
			}
		}
	}
	else
	{
		for (int i = 0; i < Deck.size(); i++)
		{

			if (Dealer && i != 0)
			{
				Cards += "[X]";
			}
			else
			{
				int number = 0;

				if (Deck[i] == 11)
				{
					number = 1;
				}
				else
				{
					number += Deck[i];
				}

				Cards += "[" + std::to_string(Deck[i]) + "]";
			}
		}
	}

	return Cards;

}

bool MainGame::ResetDeck(std::vector<int> *Deck)
{

	Deck->clear();

	if (Deck->size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

// Round Functions

bool MainGame::RunRound(std::vector<int> *PlayerDeck, std::vector<int> *DealerDeck, bool Player)
{

	if (Round == 0)
	{

		/* Check Decks */

		if (GetDeckAmount(*PlayerDeck, true) >= 1)
		{
			if (!ResetDeck(PlayerDeck))
			{
				return false;
			}
		}

		if (GetDeckAmount(*PlayerDeck, true) >= 1)
		{
			if (!ResetDeck(DealerDeck))
			{
				return false;
			}
		}

		/* Deal First Cards */

		Wait(1.5);
		DealCard(PlayerDeck);
		std::cout << "Player Deck: " << PrintDeckCards(*PlayerDeck);
		Wait(1);
		DealCard(PlayerDeck);
		std::cout << PrintDeckCards(*PlayerDeck, true, false, 1) << std::endl;

		Wait(1.5);
		std::cout << std::endl;

		DealCard(DealerDeck);
		std::cout << "Dealer First Card: " << PrintDeckCards(*DealerDeck, true, true);
		Wait(1);
		DealCard(DealerDeck);
		std::cout << PrintDeckCards(*DealerDeck, false, true, 1) << std::endl;

		Round += 1;
	}
	else
	{

		/* Display Total */

		std::cout << "Player Deck: " << PrintDeckCards(*PlayerDeck) << std::endl;
		std::cout << "Dealer Deck: " << PrintDeckCards(*DealerDeck, false, false) << std::endl;

		std::cout << std::endl;
		switch(CheckDeck(*PlayerDeck))
		{

			case 1: // Fumble

				std::cout << "Fumble!" << std::endl;
				Playing = false;

			break;
			case 2: // Playing
			{
				std::cout << "Hit or Stand?: ";
				std::string choice;
				std::cin >> choice;
				std::cin.ignore();



				break;
			}
			case 3: // Winner

				std::cout << "Winner!" << std::endl;
				Playing = false;

			break;
			default: // Error
				std::cout << "[Error: RRSC-CD-PD]" << std::endl;
			break;

		};

	}

};

/* Wait Functions */

void MainGame::Wait(double Seconds)
{

	std::this_thread::sleep_for(std::chrono::duration<double>(Seconds));

}

/* String Functions */

int CheckString(std::string StringToCheck)
{



}


MainGame::MainGame(){};

int main(){

	MainGame Game;

	std::vector<int> PlayerDeck = {};
	std::vector<int> DealerDeck = {};

	Game.RunRound(&PlayerDeck, &DealerDeck);

	/*switch(Game.CheckDeck(PlayerDeck, true))
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

	}; */

	return 0;
};