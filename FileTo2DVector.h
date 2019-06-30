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