// Q2014_MagicTrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Global variables.
int nCase = 0;
int nNumberOfLines = 0;
bool bIsNameIn = false;
string sNames[100];
string sNameIn = "";


int _tmain(int argc, _TCHAR* argv[])
{
	cin >> nCase;
	cin >> nNumberOfLines;
	
	for (int j = 0; j < nNumberOfLines; j++)
	{
		cin >> sNames[j];
	}
	for (int i = 0; i < nCase; i++)
	{
		cout << "Case#" << i + 1 << ":" << sNames[i] << endl;//sNameIn << endl;
	}

	return 0;
}

