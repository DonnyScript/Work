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
#include <string>
using namespace std;

void checkInt(int& input)// To use set call with what you want to check at the parameter
{
	while (cin.fail())
	{
		cout << "Put valid number: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> input;
	}
}

void checkDouble(double& input)
{
	while (cin.fail())
	{
		cout << "Put valid number: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> input;
	}

}

void checkString(string& input)
{
	while (cin.fail())
	{
		cout << "Put valid number: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> input;
	}

}

void checkChar(string& input)
{
	while (cin.fail())
	{
		cout << "Put valid number: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> input;
	}
}



#endif // !CHECK_H
