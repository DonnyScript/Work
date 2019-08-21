#include "MazeSolver.h"


int main()
{
	//Create Variables 
	vector<vector<char>> inputMaze = {
								{'W','S','W','W','W','W','W'},
							    {'W','O','O','O','O','O','W'},
							    {'W','W','O','O','O','O','W'},
							    {'W','W','W','W','E','W','W'} };
	int x, y;
	
	
	
	//Some testing 
	MazeSolver mazesolver(inputMaze);
	mazesolver.findS();
	x = mazesolver.getX();
	y = mazesolver.getY();
	mazesolver.solve(x,y);
	cout << mazesolver.getDist() << "\n";
	
	
	system("pause");
	return 0; 
}