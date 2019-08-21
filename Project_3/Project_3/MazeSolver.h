#ifndef MAZESOLVER_H
#define MAZESOLVER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;



void fillVector(string filename, vector<vector<char>>& inputMaze)
{
	string tempLn;
	ifstream Maze(filename);
	while (!Maze.eof())
	{
		getline(Maze, tempLn);
		vector<char> rowChar(tempLn.begin(), tempLn.end());
		inputMaze.push_back(rowChar);
	}
}

class MazeSolver 
{
private:
	vector<vector<char>> Maze;
	int x = 0;
	int y = 0;
	int moveCounter = 0;
	int minDis = 1000000;
	static char const start = 'S';
	static char const end = 'E';
	static char const wall = 'W';
	static char const open = 'O';
	static char const path = 'P';
	static char const badpath = 'X';


public:
	MazeSolver(vector<vector<char>> Maze) : Maze(Maze)
	{
		
	}
	void setX(int x)
	{
		this->x = x;
	}
	int getX()
	{
		return x;
	}

	void setY(int y)
	{
		this->y = y;
	}
	int getY()
	{
		return y;
	}

	void setDis(int dis)
	{
		this->minDis = dis;
	}
	int getDist()
	{
		if (minDis == 1000000)
		{
			return 0;
		}
		return this->minDis;
	}

	void findS() 
	{
		for (int rowIndex = 0; rowIndex < this->Maze.size(); rowIndex++)
		{
			for (int index = 0; index < Maze.at(rowIndex).size(); index++)
			{
				if (Maze.at(rowIndex).at(index) == start)
				{
					this->x = rowIndex;
					this->y = index;
				}
			}
		}
	}
	
	bool isOpen(int x, int y)
	{
		if (Maze.at(x).at(y) == open)
		{
			return true;
		}

		if (Maze.at(x).at(y) == end)
		{
			return true;
		}

		return false;
	}

	bool validMove(int x, int y)
	{
		if (x > 0 && y > 0 && x < Maze.size() && y < Maze.at(x).size())
		{
			return true;
		}
		return false;
	}

	void solve(int x, int y)
	{
		if (Maze.at(x).at(y) == end)
		{
			if (moveCounter < minDis)
			{
				minDis = moveCounter;
			}
			
			cout << moveCounter << endl;
			moveCounter++;
		}

		if (Maze.at(x).at(y) == start)
		{
			
			moveCounter++;
		}

		if( validMove(x - 1, y) && isOpen(x -1, y))
		{
			if(Maze.at(x -1).at(y) != end)
			{
				Maze.at(x - 1).at(y) = path;
			}
			moveCounter++;
			solve(x-1,y);
			moveCounter--;
			Maze.at(x).at(y) = open;
		}

		if(validMove(x, y + 1) && isOpen(x,y + 1))
		{
			if(Maze.at(x).at(y + 1) != end)
			{
				Maze.at(x).at(y + 1) = path;
			}
			moveCounter++;
			solve(x,y + 1);
			moveCounter--;
			Maze.at(x).at(y) = open;	
		}


		if (validMove(x + 1, y) && isOpen(x + 1, y))
		{
			if (Maze.at(x + 1).at(y) != end)
			{
				Maze.at(x + 1).at(y) = path;
			}
			moveCounter++;
			solve(x + 1, y);
			moveCounter--;
			Maze.at(x).at(y) = open;
		}

		if(validMove(x, y - 1) && isOpen(x,y - 1))
		{
			if(Maze.at(x).at(y - 1) != end)
			{
				Maze.at(x).at(y - 1) = path;
			}
			moveCounter++;
			solve(x,y - 1);
			moveCounter--;
			Maze.at(x).at(y) = open;	
		}

		
		
	}

};






#endif 

