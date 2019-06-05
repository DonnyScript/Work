#ifndef CHECK_H
#define CHECK_H
#include <iostream>
using namespace std;
int checkInt(int& a)// To use set your int in main equal to this with that int as a parameter 
{
	while (cin.fail())
	{
		cout << "Put valid number: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> a;
	}
	return a;
}





#endif // !CHECK_H
