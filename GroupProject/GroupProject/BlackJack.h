#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <time.h>
#include <ctime>
#include <iomanip>

using namespace std;

class Player
{
private:
	int cash;
	int currentBet;
	int handTotal;
	int acesInHand;
	int acesUsed;
	char StandOrBustorLeave;

protected:
	enum Rank
	{
		Ace = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		King,
		Queen,
		Jack,
		DownCard = 1000
	};
	enum Suit
	{
		Hearts,
		Spades,
		Clubs,
		Diamonds,
	};


	struct Card
	{
		Rank value;
		Suit type;
	};


	vector<Card> Hand;
public:
	Player()
	{
		cash = 100;
		currentBet = 0;
		handTotal = 0;
		acesInHand = 0;
		acesUsed = 0;
		StandOrBustorLeave = 'N';
	}

	void bet(int amount)
	{
		cash = cash - amount;
		currentBet = amount;
	}

	void clearHand()
	{
		Hand.clear();
	}

	int getCash()
	{
		return this->cash;
	}

	int getBet()
	{
		return currentBet;
	}

	void setCashonWin(int amount)
	{
		cash = cash + amount;
	}


	void setStandLeaveBust(char action)
	{
		this->StandOrBustorLeave = action;
	}

	char getStandLeaveBustLeave()
	{
		return StandOrBustorLeave;
	}

	int getHandSize()
	{
		return Hand.size();
	}
	void setCard(Card Cards)
	{
		Hand.push_back(Cards);
	}

	void setPlayerHandTotal(int sum)
	{
		this->handTotal = sum;

	}

	int getPlayerHandTotal()
	{
		int total;

		total = this->handTotal;

		acesInHand = acesInHand - acesUsed;
		if (acesInHand > 0 && total > 21)
		{
			total -= 10;
			acesUsed++;
		}

		setPlayerHandTotal(total);
		return total;
	}

	string outputSuitToString(int position)
	{
		switch (this->Hand.at(position).type)
		{

		case 0:
			return "Hearts";

		case 1:
			return "Spades";

		case 2:
			return "Clubs";

		case 3:
			return "Diamonds";


		default:
			return "Not Recognized";

		}
	}

	string outputRankToString(int position)
	{
		switch (this->Hand.at(position).value)
		{
		case 1:
			return "Ace";

		case 2:
			return "Two";

		case 3:
			return "Three";

		case 4:
			return "Four";

		case 5:
			return "Five";

		case 6:
			return "Six";

		case 7:
			return "Seven";

		case 8:
			return "Eight";

		case 9:
			return "Nine";

		case 10:
			return "Ten";
		case 11:
			return "King";
		case 12:
			return "Queen";
		case 13:
			return "Jack";
		case 1000:
			return "FaceDown";

		default:
			return "Unknown Value";
		}
	}

	void handValue()
	{
		int sum = 0;
		acesInHand = 0;
		for (int hand = 0; hand < Hand.size(); hand++)
		{
			switch (Hand.at(hand).value)
			{
			case Ace:
				sum += 11;
				acesInHand++;
				break;
			case Two:
				sum += 2;
				break;
			case Three:
				sum += 3;
				break;
			case Four:
				sum += 4;
				break;
			case Five:
				sum += 5;
				break;
			case Six:
				sum += 6;
				break;
			case Seven:
				sum += 7;
				break;
			case Eight:
				sum += 8;
				break;
			case Nine:
				sum += 9;
				break;
			case Ten:
				sum += 10;
				break;
			case Jack:
				sum += 10;
				break;
			case Queen:
				sum += 10;
				break;
			case King:
				sum += 10;
				break;
			}

		}


		setPlayerHandTotal(sum);
	}

	bool strategy(int index)
	{
		Card topCard;
		topCard.value = static_cast<Rank>(index);
		bool isHitting = false;

		int hand = getPlayerHandTotal();

		
		if (hand >= 17 && hand <= 20)
		{
			isHitting = false;
		}
		else if (hand == 21)
		{
			isHitting = false;
		}
		else if (hand >= 5 && hand <= 11)
		{
			isHitting = true;
		}
		else if (hand == 12)
		{
			if (topCard.value == Four || topCard.value == Five || topCard.value == Six)
			{
				isHitting = false;
			}
			else
			{
				isHitting = true;
			}
		}
		else if (hand >= 13 && hand <= 14)
		{
			if (topCard.value == Two || topCard.value == Three || topCard.value == Four || topCard.value == Five || topCard.value == Six)
			{
				isHitting = false;
			}
			else
			{
				isHitting = true;
			}
		}
		else if (hand == 15)
		{
			if (topCard.value == Seven || topCard.value == Eight || topCard.value == Nine || topCard.value == Ace)
			{
				isHitting = true;
			}
			else
			{
				isHitting = false;
			}
		}
		else if(hand < 21)
		{
			if (topCard.value == Seven || topCard.value == Eight)
			{
				isHitting = true;
			}
			else
			{
				isHitting = false;
			}
		}

		return isHitting;
	}
};


class Dealer : public Player
{
private:
	stack<Card> Deck;
	stack<Card> ShuffleDeck;
	vector<Card> CardDeck;
	Card FaceDownCard;

public:
	bool CheckShuffle(vector<int>picked, int currentCard)
	{
		bool notPicked = true;

		for (int iterator = 0; iterator < picked.size(); iterator++)
		{
			if (currentCard == picked.at(iterator))
			{
				notPicked = false;
			}
		}
		return notPicked;
	}


	void Shuffle()
	{
		srand(time(0));
		vector<int> picked;
		int randCard;

		while (ShuffleDeck.size() != 312)
		{
			randCard = rand() % 312;

			if (CheckShuffle(picked, randCard))
			{
				ShuffleDeck.push(CardDeck.at(randCard));
			}
		}
	}

	Dealer()
	{
		vector<Card> Cards(312);
		FaceDownCard.value = DownCard;
		FaceDownCard.type = Diamonds;
		Rank ranks[13] = { Ace,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,King,Queen,Jack };
		Suit Suits[4] = { Hearts,Diamonds,Spades,Clubs };
		int iterator = 0;

		for (int deck = 0; deck < 6; deck++)
		{
			for (int suit = 0; suit < 4; suit++)
			{
				for (int rank = 0; rank < 13; rank++)
				{
					Cards.at(iterator).type = Suits[suit];
					Cards.at(iterator).value = ranks[rank];
					Deck.push(Cards.at(iterator));
					CardDeck.push_back(Cards.at(iterator));
					iterator++;
				}
			}
		}
	}


	void getCard(Card Cards)
	{
		Hand.push_back(Cards);
	}

	int getShuffleDeckSize()
	{
		return ShuffleDeck.size();
	}


	Card GiveCard()
	{
		Card giveCard;
		giveCard.type = ShuffleDeck.top().type;
		giveCard.value = ShuffleDeck.top().value;

		ShuffleDeck.pop();
		return giveCard;
	}

	void turnOverCard()
	{
		Card giveCard;
		giveCard.type = ShuffleDeck.top().type;
		giveCard.value = ShuffleDeck.top().value;
		ShuffleDeck.pop();
		Hand.at(1) = giveCard;
	}

	

	
	int getHand()
	{
		return Hand.at(0).value;
	}

	void Deal(vector<Player>& players)
	{
		for (int hand = 0; hand < 2; hand++)
		{
			for (int toplayers = 0; toplayers < players.size(); toplayers++)
			{
				players.at(toplayers).setCard(GiveCard());
			}
			if (hand == 0)
			{
				this->getCard(GiveCard());
			}
			if (hand == 1)
			{
				this->getCard(FaceDownCard);
			}
		}
	}
};

void DealerHit(Dealer& dealer)
{
	bool dealerHit = false;
	int dealerValue = 0;
	dealer.handValue();


	do
	{
		dealerValue = dealer.getPlayerHandTotal();

		if (dealerValue < 17)
		{
			dealerHit = 1;
		}
		else
		{
			dealerHit = 0;
		}

		if (dealerHit == 1)
		{
			cout << '\n' << "Dealer hits. " << endl;
			dealer.setCard(dealer.GiveCard());

			for (int handSize = 0; handSize < dealer.getHandSize(); handSize++)
			{
				cout << dealer.outputRankToString(handSize) << " of ";
				cout << dealer.outputSuitToString(handSize);


				if (handSize !=dealer.getHandSize() - 1)
				{
					cout << " and ";
				}
				else
				{
					dealer.handValue();
					dealerValue = dealer.getPlayerHandTotal();
					cout << endl << setw(25) << "Total Points: " << dealerValue << '\n' << endl;
				}

			}
		}


	} while (dealerHit == 1);

	if (dealerValue > 21)
	{

		cout << setw(20) << "DEALER BUSTED" << '\n';
		dealer.setStandLeaveBust('B');

	}
	else
	{
		cout << "Dealer stands." << endl;
		dealer.setStandLeaveBust('S');
	}
}

void HitorStand(vector<Player>& players, Dealer& dealer)
{
	char HitorStand = 'O';
	char canPlay = 'Y';
	for (int play = 0; play < players.size() - 1; play++)
	{
		if (players.at(play).getBet() == 0)
		{
			canPlay = 'N';
		}

		if (canPlay != 'N')
		{
			cout << "Player " << play + 1 << " hit or stand(H or S): ";
			cin >> HitorStand;
			if (HitorStand == 'S')
			{
				players.at(play).setStandLeaveBust('S');
			}

			if (HitorStand == 'H')
			{
				char BustorStand = 'O';
				do
				{
					players.at(play).setCard(dealer.GiveCard());
					for (int player = 0; player < players.at(play).getHandSize(); player++)
					{

						cout << players.at(play).outputRankToString(player) << " of ";
						cout << players.at(play).outputSuitToString(player);


						if (player != players.at(play).getHandSize() - 1)
						{
							cout << " and ";
						}
						else
						{
							players.at(play).handValue();
							cout << endl << setw(25) << "Total Points: " << players.at(play).getPlayerHandTotal() << '\n' << endl;
						}
					}

					if (players.at(play).getPlayerHandTotal() > 21)
					{

						cout << setw(20) << "BUSTED" << '\n';
						players.at(play).setStandLeaveBust('B');
						BustorStand = 'B';
					}

					if (BustorStand != 'B')
					{
						cout << "Would you like to hit or stand (H or S): ";
						cin >> BustorStand;
						players.at(play).setStandLeaveBust('S');
					}

				} while (BustorStand != 'B' && BustorStand != 'S');
			}

		}
		canPlay = 'Y';
	}
	bool cpuHit = false;
	do
	{

		cpuHit = players.at(players.size() - 1).strategy(dealer.getHand());

		if (cpuHit == 1)
		{
			cout << '\n' << "Computer hits. " << endl;

			players.at(players.size() - 1).setCard(dealer.GiveCard());


			for (int player = 0; player < players.at(players.size() - 1).getHandSize(); player++)
			{

				cout << players.at(players.size() - 1).outputRankToString(player) << " of ";
				cout << players.at(players.size() - 1).outputSuitToString(player);


				if (player != players.at(players.size() - 1).getHandSize() - 1)
				{
					cout << " and ";
				}
				else
				{
					players.at(players.size() - 1).handValue();
					cout << endl << setw(25) << "Total Points: " << players.at(players.size() - 1).getPlayerHandTotal() << '\n' << endl;
				}
			}
		}


	} while (cpuHit == 1);

	if (players.at(players.size() - 1).getPlayerHandTotal() > 21)
	{

		cout << setw(20) << "BUSTED" << '\n';
		players.at(players.size() - 1).setStandLeaveBust('B');

	}
	else
	{
		cout << "Computer stands." << endl;
		players.at(players.size() - 1).setStandLeaveBust('S');
	}
}




void Winners(vector<Player>& players, Dealer& dealer)
{
	for (int play = 0; play < players.size() - 1; play++)
	{

		if (players.at(play).getStandLeaveBustLeave() == 'S' || 'B')
		{

			int playerDistToWin = 21 - players.at(play).getPlayerHandTotal();
			int dealerDistToWin = 21 - dealer.getPlayerHandTotal();
			
			if (dealerDistToWin >= 0)
			{

				if ((dealerDistToWin < playerDistToWin) || (players.at(play).getStandLeaveBustLeave() == 'B'))
				{
					cout << "Player " << play + 1 << " sadly ";
					cout << "House wins" << '\n';
				}
				if (dealerDistToWin > playerDistToWin && (players.at(play).getStandLeaveBustLeave() != 'B'))
				{
					cout << "Player " << play + 1 << " beats the house!" << '\n';
					players.at(play).setCashonWin(players.at(play).getBet() * 2);
				}
				if (dealerDistToWin == playerDistToWin)
				{
					cout << "Player " << play + 1 << "Plunders" << '\n';
					players.at(play).setCashonWin(players.at(play).getBet());
				}
			}
			else if(players.at(play).getStandLeaveBustLeave() != 'B')
			{
				cout << "Player " << play + 1 << " beats the house!" << '\n';
				players.at(play).setCashonWin(players.at(play).getBet() * 2);
			}
			else if (players.at(play).getStandLeaveBustLeave() == 'B')
			{
				cout << "Player " << play + 1 << " sadly ";
				cout << "House wins" << '\n';
			}

		}

	}

	if (players.at(players.size() - 1).getStandLeaveBustLeave() == 'S' || 'B')
	{
		int playerDistToWin = 21 - players.at(players.size() - 1).getPlayerHandTotal();
		int dealerDistToWin = 21 - dealer.getPlayerHandTotal();

		if (dealerDistToWin >= 0)
		{
			if (dealerDistToWin < playerDistToWin)
			{
				cout << "Computer, sadly ";
				cout << "House wins" << '\n';
			}
			if (dealerDistToWin > playerDistToWin)
			{
				cout << "Computer beats the house!";
				players.at(players.size() - 1).setCashonWin(players.at(players.size() - 1).getBet() * 2);
			}
			if (dealerDistToWin == playerDistToWin)
			{
				cout << "Computer plunders";
				players.at(players.size() - 1).setCashonWin(players.at(players.size() - 1).getBet());
			}
		}
		else if(players.at(players.size() -1).getStandLeaveBustLeave() != 'B')
		{
			cout << "Computer beats the house!";
			players.at(players.size() - 1).setCashonWin(players.at(players.size() - 1).getBet() * 2);
		}
		else if (players.at(players.size() - 1).getStandLeaveBustLeave() == 'B')
		{
			cout << "Computer, sadly ";
			cout << "House wins" << '\n';
		}
		cout << '\n';

	}
}


void PlayGame(vector<Player>& players, Dealer& dealer)
{
	char action = 'O';
	bool computerTurn = false;

	cout << setw(20) << "Dealer's hand: ";
	for (int deal = 0; deal < dealer.getHandSize(); deal++)
	{
		if (deal != 1)
		{
			cout << dealer.outputRankToString(deal) << " of ";
			cout << dealer.outputSuitToString(deal);
		}
		else
		{
			cout << dealer.outputRankToString(deal) << " card";
		}
		if (deal != players.at(0).getHandSize() - 1)
		{
			cout << " and ";
		}
	}

	cout << '\n' << '\n';

	for (int switchPlayer = 0; switchPlayer < players.size(); switchPlayer++)
	{


		if (switchPlayer != players.size() - 1)
		{
			cout << setw(12) << "Player " << switchPlayer + 1 << "'s " << "hand: ";
		}
		else
		{
			cout << setw(22) << "Computer's hand: ";
			computerTurn = true;
		}

		for (int player = 0; player < players.at(switchPlayer).getHandSize(); player++)
		{

			cout << players.at(switchPlayer).outputRankToString(player) << " of ";
			cout << players.at(switchPlayer).outputSuitToString(player);

			if (player != players.at(0).getHandSize() - 1)
			{
				cout << " and ";
			}
			else
			{
				players.at(switchPlayer).handValue();
				cout << endl << setw(25) << "Total Points: " << players.at(switchPlayer).getPlayerHandTotal() << '\n' << endl;
			}
		}
		cout << '\n';
	}
}




#endif 