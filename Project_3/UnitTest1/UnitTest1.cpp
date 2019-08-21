#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project_3/MazeSolver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestBasic)
		{
			//Arrange 
			vector<vector<char>> inputMaze = { {'W','W','S','W'},{'W','W','O','W'},{'W','W','O','W'},{'W','W','E','W'} };
			MazeSolver mazesolver(inputMaze);
			int expX = 1;
			int expY = 2;
			int expDis = 34;
			
			//Act 
			mazesolver.setX(expX);
			int actX = mazesolver.getX();
			mazesolver.setY(expY);
			int actY = mazesolver.getY();
			mazesolver.setDis(expDis);
			int actDis = mazesolver.getDist();
			

			//Assert 
			Assert::AreEqual(expX, actX);
			Assert::AreEqual(expY, actY);
			Assert::AreEqual(expDis, actDis);
		}

		TEST_METHOD(TestFindS)
		{
			//Arrange
			vector<vector<char>> expmaze = { {'W','S','W','W','W','W'},
											 {'W','O','O','O','O','W'},
											 {'W','W','O','O','O','W'},
											 {'W','W','W','W','E','W' } };
		
			/*string filename = "AnotherMaze.txt";
			fillVector(filename, inputMaze);*///could not get to test 
			int expX = 0;
			int expY = 1;

			MazeSolver mazesolver(expmaze);
			//Act 
			mazesolver.findS();
			int actX = mazesolver.getX();
			int actY = mazesolver.getY();
			 
			//Assert
			Assert::AreEqual(expX, actX);
			Assert::AreEqual(expY, actY);
		}

		TEST_METHOD(TestSampleMaze)
		{
			//Arrange 
			int x, y;
			vector<vector<char>> SampleMaze = {
				{'W','O','W','W','O','W','W','W','W','W'},
				{'O','S','O','O','O','W','O','O','O','W'},
				{'O','W','O','W','O','W','O','W','O','W'},
				{'O','W','O','W','O','O','O','W','O','W'},
				{'O','O','O','W','O','W','W','O','O','W'},
				{'W','W','O','W','O','O','W','O','W','W'},
				{'W','O','O','O','W','O','W','O','O','O'},
				{'W','O','W','O','O','O','W','O','W','O'},
				{'W','O','W','W','O','W','W','O','W','O'},
				{'W','O','O','O','O','W','W','O','W','E'} };
			MazeSolver mazesolver(SampleMaze);
			int expDis = 23;

			//Act 
			mazesolver.findS();
			x = mazesolver.getX();
			y = mazesolver.getY();
			mazesolver.solve(x, y);
			int actDis = mazesolver.getDist();

			//Assert
			Assert::AreEqual(expDis, actDis);

		}


		TEST_METHOD(TestaltMaze)
		{
			//Arrange 
			int x, y;
			vector<vector<char>> SampleMaze = {
				{'W','O','W','W','O','W','W','W','W','W'},
				{'O','O','S','O','O','W','O','O','O','W'},
				{'O','W','O','W','O','W','O','W','O','W'},
				{'O','W','O','W','O','O','O','W','O','W'},
				{'O','O','O','W','O','W','W','O','O','W'},
				{'W','W','O','W','O','O','W','O','W','W'},
				{'W','O','O','O','W','O','W','O','O','O'},
				{'W','O','W','O','O','O','W','O','W','O'},
				{'W','O','W','W','O','W','W','O','W','O'},
				{'W','O','O','O','O','W','W','O','W','E'} };
			MazeSolver mazesolver(SampleMaze);
			int expDis = 22;

			//Act 
			mazesolver.findS();
			x = mazesolver.getX();
			y = mazesolver.getY();
			mazesolver.solve(x, y);
			int actDis = mazesolver.getDist();

			//Assert
			Assert::AreEqual(expDis, actDis);
		}
		TEST_METHOD(testPyr)
		{
			//Arrange 
			int x, y;
			vector<vector<char>> inputMaze ={ 
								{'W'},
							{'W','S','W'},
						{'W','O','O','O','W'},
					{'W','W','W','O','O','O','W'},
				{'W','W','W','W','W','E','W','W','W'} };
			MazeSolver mazesolver(inputMaze);
			int expDis = 8;

			//Act 
			mazesolver.findS();
			x = mazesolver.getX();
			y = mazesolver.getY();
			mazesolver.solve(x, y);
			int actDis = mazesolver.getDist();


			//Assert 
			
			Assert::AreEqual(expDis, actDis);


		}

		TEST_METHOD(testPyrReverse)
		{
			//Arrange 
			int x, y;
			vector<vector<char>> inputMaze = {
								{'W'},
							{'W','E','W'},
						{'W','O','O','O','W'},
					{'W','W','W','O','O','O','W'},
				{'W','W','W','W','W','S','W','W','W'} };
			MazeSolver mazesolver(inputMaze);
			int expDis = 8;

			//Act 
			mazesolver.findS();
			x = mazesolver.getX();
			y = mazesolver.getY();
			mazesolver.solve(x, y);
			int actDis = mazesolver.getDist();


			//Assert 
			Assert::AreEqual(expDis, actDis);

		}
		TEST_METHOD(testReturn0_for_no_solution)
		{
			//Arrange 
			int x, y;
			vector<vector<char>> inputMaze = {
								{'W'},
							{'W','S','W'},
						{'W','W','O','W','W'},
					{'W','W','W','W','E','W','W'} };
				
			MazeSolver mazesolver(inputMaze);
			int expDis = 0;

			//Act 
			mazesolver.findS();
			x = mazesolver.getX();
			y = mazesolver.getY();
			mazesolver.solve(x, y);
			int actDis = mazesolver.getDist();


			//Assert 
			Assert::AreEqual(expDis, actDis);

		}
		TEST_METHOD(shortesTest)
		{
			//Arrange 
			int x, y;
			vector<vector<char>> inputMaze = {
								{'W','W','W','S','W','W','W','W','W'},
								{'W','W','W','O','O','O','O','O','W'},
								{'W','W','W','O','O','W','W','E','W'},
								{'W','W','W','O','O','O','O','O','W'},
								{'W','W','W','O','O','O','O','O','W'} };

			MazeSolver mazesolver(inputMaze);
			int expDis = 7;

			//Act 
			mazesolver.findS();
			x = mazesolver.getX();
			y = mazesolver.getY();
			mazesolver.solve(x, y);
			int actDis = mazesolver.getDist();


			//Assert 
			Assert::AreEqual(expDis, actDis);

		}


		TEST_METHOD(spiralTest)
		{
			//Arrange 
			int x, y;
			vector<vector<char>> inputMaze = {
											{'W','W','W','W','W','W','W','W','W'},
											{'W','S','W','W','W','W','W','W','W'},
											{'W','O','W','O','O','O','O','O','W'},
											{'W','O','W','O','W','W','W','O','W'},
											{'W','O','W','O','W','E','W','O','W'},
											{'W','O','W','O','O','O','W','O','W'},
											{'W','O','W','W','W','W','W','O','W'},
											{'W','O','O','O','O','O','O','O','W'},
											{'W','W','W','W','W','W','W','W','W'} };

			MazeSolver mazesolver(inputMaze);
			int expDis = 28;

			//Act 
			mazesolver.findS();
			x = mazesolver.getX();
			y = mazesolver.getY();
			mazesolver.solve(x, y);
			int actDis = mazesolver.getDist();


			//Assert 
			Assert::AreEqual(expDis, actDis);

		}

		TEST_METHOD(ReverseSpiralTest)
		{
			//Arrange 
			int x, y;
			vector<vector<char>> inputMaze = {
											{'W','W','W','W','W','W','W','W','W'},
											{'W','E','W','W','W','W','W','W','W'},
											{'W','O','W','O','O','O','O','O','W'},
											{'W','O','W','O','W','W','W','O','W'},
											{'W','O','W','O','W','S','W','O','W'},
											{'W','O','W','O','O','O','W','O','W'},
											{'W','O','W','W','W','W','W','O','W'},
											{'W','O','O','O','O','O','O','O','W'},
											{'W','W','W','W','W','W','W','W','W'} };

			MazeSolver mazesolver(inputMaze);
			int expDis = 28;

			//Act 
			mazesolver.findS();
			x = mazesolver.getX();
			y = mazesolver.getY();
			mazesolver.solve(x, y);
			int actDis = mazesolver.getDist();


			//Assert 
			Assert::AreEqual(expDis, actDis);

		}




	};
}
