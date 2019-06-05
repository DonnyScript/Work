//
//  CheckingFunction's.h
//  Work       
//
//  Created by Donovan McCarthy on 5/6/19  
//  Copyright © 2019 Donovan Mccarthy. All rights reserved.
//


#ifndef CHECK_H
#define CHECK_H
#include <iostream>
using namespace std;
int checkInt(int& input)// To use set your int in main equal to this with that int as inputa parameter 
{
	while (cin.fail())
	{
		cout << "Put valid number: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> input;
	}
	return input;
}
double checkDouble(double input)
{
	while (cin.fail())
	{
		cout << "Put valid number: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> input;
	}
return input;
}


#endif // !CHECK_H
