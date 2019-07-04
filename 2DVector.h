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


void printVector()//Currently setup to print a 2D vector called Maze
	{
		for (int row = 0; row < 9; row++)
		{
			for (int colum = 0; colum < 9; colum++)
			{
				cout << Maze.at(row).at(colum);
			}
			cout << endl;
		}
	}