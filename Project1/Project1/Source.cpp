#include <iostream>
#include "trekwar.h"
using namespace std;

int main()
{
	Ship* newShip = nullptr;
	newShip = new Ship("don", 1, 2, them, 100, 50, 50);
	cout << newShip->getAlign() << endl; 
	newShip->changeAlign();
	cout << newShip->getAlign() << endl;



	return 0; 
}