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

void check(int& input)// To use set call with what you want to check at the parameter
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


#endif // !CHECK_H
