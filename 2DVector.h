#include <vector> 
#include <fstream> 
#include <string> 
#include <iostream>
using namespace std;

void fillVector(string filename, vector<vector<char>>& inputMaze)// Tun this into member function
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

	void printVector(vector<vector<char>> inputVector) 
	{
		for (int row = 0; row < inputVector.size(); row++)
		{
			for (int colum = 0; colum < inputVector.at(row).size(); colum++)
			{
				cout << inputVector.at(row).at(colum);
			}
			cout << endl;
		}
	}


	bool findPath(int x, int y)//Pathfinder that uses a 2D vector 
	{
		if((x < 0) || (y < 0) || (x >= Maze.size()) || (y >= Maze.at(x).size()) )
		{
			return false; 
		}
		if(Maze.at(x).at(y) == end)
		{
			return true;
		}

		if((Maze.at(x).at(y) != open) && (Maze.at(x).at(y) != start) )
		{
			return false;
		}

		Maze.at(x).at(y) = path;

		if(findPath(x-1,y) == true)
		{
			return true;
		}

		if(findPath(x,y + 1) == true)
		{
			return true;
		}

		if(findPath(x +1,y) == true)
		{
			return true;
		}

		if(findPath(x,y - 1 ) == true)
		{
			return true; 
		}

		Maze.at(x).at(y) = 'X';

		return false; 

	}
};