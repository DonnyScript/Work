#ifndef  TOKEEP_H
#define TOKEEP_H
#include <iostream> 
using namespace std;

void print()//using the same one as class example, credit Eric Charnesky
	{
		for (int dash = 0; dash < 8; dash++)
		{
			cout << "--";
		}
		cout << "-" << endl;
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				cout << "|";
				//cout << board[row][column];// Make an char with board[][] to fill with pieces 
			}
			cout << "|" << endl;
			for (int dash = 0; dash < 8; dash++)
			{
				cout << "--";
			}
			cout << "-" << endl;
		}
	}







#endif