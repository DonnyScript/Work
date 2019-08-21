#include "BlackJack.h"

int main()
{
	char continuePlay = 'Y';
	int playerNum = 0;
	cout << "How many players: ";
	cin >> playerNum;
	while (playerNum > 10 || playerNum < 0)
	{
		cout << "Invalid number of players. Try again." << endl;
		cout << "Enter the number of players between 0 and 10: ";
		cin >> playerNum;
	}

	vector<Player> players(playerNum + 1);
	Dealer dealer;

	do
	{

		for (int bet = 0; bet <= players.size() - 1 ; bet++)
		{
			int playerBet;


			if (bet != players.size() -1)
			{
				cout << "Player " << bet + 1 << " bet: ";
				cin >> playerBet;

				while (playerBet == 0 || players.at(bet).getCash() < playerBet)
				{
					if (players.at(bet).getCash() == 0)
					{
						cout << "You have no money" << endl;
						players.at(bet).setStandLeaveBust('B');
						playerBet = 0;
						break;
					}
					if (playerBet == 0)
					{
						cout << "You cannot bet $0.00. Try again." << endl;
						cout << "Player " << bet + 1 << " bet: ";
						cin >> playerBet;

					}
					else if (players.at(bet).getCash() < playerBet)
					{
						cout << "You cannot bet more money than you have. Try again." << endl;
						cout << "Player " << bet + 1 << " bet: ";
						cin >> playerBet;

					}

					cout << endl;

				}

				players.at(bet).bet(playerBet);
			}

			else
			{
				cout << "Computer bet: 1";
				players.at(bet).bet(1);
				cout << '\n' << '\n';
			}

		}
		if ((dealer.getShuffleDeckSize() <= 30) )
		{
			dealer.Shuffle();
		}
		dealer.Deal(players);
		PlayGame(players, dealer);
		HitorStand(players, dealer);
		dealer.turnOverCard();
		DealerHit(dealer);
		cout << '\n';
		cout << setw(12) << "Dealers hand: ";
		for (int player = 0; player < dealer.getHandSize(); player++)
		{

			cout << dealer.outputRankToString(player) << " of ";
			cout << dealer.outputSuitToString(player);


			if (player != dealer.getHandSize() - 1)
			{
				cout << " and  ";
			}
			else
			{
				
				dealer.handValue();
				cout << endl << setw(25) << "Total Points: " << dealer.getPlayerHandTotal() << '\n' << endl;
			}
		}
		Winners(players, dealer);

		for (int player = 0; player < players.size() - 1; player++)
		{
			cout << "Player " << player + 1 << "'s cash: ";
			cout << players.at(player).getCash();
			cout << '\n';
		}
		cout << "Computer's cash: " << players.at(players.size() - 1).getCash() << '\n';

		cout << '\n' << '\n';
		for (int player = players.size() - 1; player > 0; player--)
		{
			
			cout << "Player " << player << ", keep playing? (L for leave, Y for continue): ";
			cin >> continuePlay;
			if (players.at(player - 1).getCash() == 0)
			{
				players.erase(players.begin() + (player - 1));
			}
			if (continuePlay == 'L')
			{
				players.erase(players.begin() + (player - 1));
				continuePlay = 'Y';
			}

		}

		if (continuePlay == 'Y')
		{
			for (int player = 0; player < players.size(); player++)
			{
				players.at(player).clearHand();
			}
			dealer.clearHand();
		}

		if (players.size() == 1)
		{
			cout << "Allow the computer to keep playing? (L for leave, Y for continue) ";
			cin >> continuePlay;

			if (continuePlay == 'L')
			{
				players.erase(players.begin());
			}
		}

	} while (continuePlay == 'Y' || (players.size() - 1 == 0));

	return 0;
}
