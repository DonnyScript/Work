#include <iostream>
#include <string>
#include "PowerBallTicket.h"

using namespace std; 

int main()
{
	srand(time(0));
	char choice;
	int num[5];
	int redchoice;
	int totalWin = 0;
	int ticketPri = 0;
	


	do
	{

		
		PowerBallTicket WinTicket;
		cout << "'p' for pick your own: "<<endl;
		cout << "'r' for random: " << endl;
		cout << "'q' to quit: " << endl; 

		
		

		cin >> choice;
		checkChoice(&choice);




		switch (choice)
		{


		case 'p':
		{
			
			for (int i = 0; i < 5; i++)
			{
				cout << "Choose number 1-69 and no duplicates: ";
				cin >> num[i];
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (j != i)
					{
						while (num[i] == num[j])
						{
							cout << "Re-enter number: ";
							cin >> num[j];
						}
					}
				}
			}

			cout << "Now pick your red ball number only 1-26 and no duplicates: ";
			cin >> redchoice;

			PowerBallTicket ticket1(num[0], num[1], num[2], num[3], num[4], redchoice);
			ticketPri = ticketPri + 2;
			totalWin = totalWin + ticket1.WinningTicket(WinTicket);
			break;
			
		}



		case 'r':
		{
			char option = 'a';
			int ticketnum = 0;
			cout << "How many tickets would you like?: ";
			cin >> ticketnum;
			cout << "do you want to see all tickets or just winning tickets(input a or j): ";
			cin >> option;

			vector<PowerBallTicket> randTicket(ticketnum);
			
			for (int i = 0; i < ticketnum; i++)
			{
				totalWin = totalWin + randTicket.at(i).WinningTicket(WinTicket);
				ticketPri = ticketPri + 2;
				if (option == 'a')
				{
					cout << "Ticket # is : ";
					for (int j = 0; j < 5; j++)
					{
						cout << randTicket.at(i).getwhiteBall(j) << '-';
					}
					cout << "Red: " << randTicket.at(i).getredBall() << endl;
				}
				else if (option == 'j')
				{
					if (randTicket.at(i).WinningTicket(WinTicket) != 0)
					{
						cout << "Winning ticket is:";
						for (int j = 0; j < 5; j++)
						{
							cout << randTicket.at(i).getwhiteBall(j) << '-';
						}
						cout << " Red:" << randTicket.at(i).getredBall() << " and Amount: ";
						cout << randTicket.at(i).WinningTicket(WinTicket) << endl;
					}
				}
			}
			break;
		  }
		

		}
	} while (choice != 'q');
		cout << "You won: " << totalWin << "$" << endl;
		cout << "You spent: " << ticketPri << endl;
		cout << "Net loss or win: " << totalWin - ticketPri << endl;
		 
		PowerBallTicket demonstrate;
		cout << "Overload the <<: " << demonstrate << endl; 




		system("pause");
		return 0;
	}
