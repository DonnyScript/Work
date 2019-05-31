#include "PowerBallTicket.h"

using namespace std;



void PowerBallTicket::setwhiteBall(int setNum, int loop)
{
	whiteBall[loop] = setNum;
}

void PowerBallTicket::setredBall(int setNum)
{
	redBall = setNum;
}

int PowerBallTicket::getredBall()
{
	return redBall;
}

int PowerBallTicket::WinningTicket(PowerBallTicket& newTicket)
{
	int numMatch = 0;
	bool redMatch = false;
	int winAmount = 0; 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
				if(this->getwhiteBall(i) == newTicket.getwhiteBall(j))
				{
					numMatch++;
				}
		}
	}
	if (newTicket.getredBall() == this->redBall) {
		redMatch = true; 
	}
	if (redMatch)
	{
		winAmount = 4; 
	}
	 if ((numMatch == 1) && (redMatch))
	{
		winAmount = 4; 
	}
	 if ((numMatch == 2) && (redMatch))
	{
		winAmount = 7;
	}
	 if (numMatch == 3)
	{
		winAmount = 7;
	}
 	 if (numMatch == 4)
	{
		winAmount = 100;
	}
	 if ((numMatch == 4) && (redMatch))
	{
		winAmount = 50000;
	}
	 if (numMatch == 5)
	{
		winAmount = 1000000;
	}
	 if ((numMatch == 5) && (redMatch))
	{
		winAmount = 100000000;
	}
	return winAmount;
}

PowerBallTicket::PowerBallTicket(int wBall1, int wBall2, int wBall3, int wBall4, int wBall5, int redBall)
{
	whiteBall[0] = wBall1;
	whiteBall[1] = wBall2;
	whiteBall[2] = wBall3;
	whiteBall[3] = wBall4;
	whiteBall[4] = wBall5;
	this->redBall = redBall;
	
	
}

PowerBallTicket::PowerBallTicket()
{
	whiteBall[0] = (rand() % 69) + 1;
	whiteBall[1] = (rand() % 69) + 1; 
	whiteBall[2] = (rand() % 69) + 1;
	whiteBall[3] = (rand() % 69) + 1;
	whiteBall[4] = (rand() % 69) + 1;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j != i)
			{
				while (whiteBall[i] == whiteBall[j])
				{
					whiteBall[j] = (rand() % 69) + 1; 
				}
			}
		}
	}
	redBall = (rand() % 26) + 1;
	
	
}

int PowerBallTicket::getwhiteBall(int getNum)
{

	return whiteBall[getNum];
}

char checkChoice(char* input)
{
	char corrinput = *input;

	while ((corrinput != 'p') && (corrinput != 'r')&&(corrinput != 'q'))
	{
		cout << "Please input p or r or c or q: ";
		cin >> corrinput;
	}

	*input = corrinput;
	

	return *input;
}
ostream& operator<<(ostream& os, const PowerBallTicket& ticket)
{
	os << ticket.whiteBall[0]<<'-'<< ticket.whiteBall[1]<< '-' << ticket.whiteBall[2];
	os << '-' << ticket.whiteBall[3] << '-' << ticket.whiteBall[4];
	os << " red: " << ticket.redBall<< endl;

		return os;
	}

