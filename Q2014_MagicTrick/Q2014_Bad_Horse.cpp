// Q2014_MagicTrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Member function prototype.
string sNameSeparator(string sName1, string sName2);

//Global variables.
int nCase = 0;
int nNumberOfLines = 0;
int nPos = 0;
vector<string> vNames;
string sNames [100];
string sNameIn = "";


int _tmain(int argc, _TCHAR* argv[])
{
	cin >> nCase;
	//getline(cin, sNameIn);
	
	for (int i = 0; i < nCase; i++)
	{
		vNames.clear();
		sNames->clear();

		cin >> nNumberOfLines;
		for (int j = 0; j <= nNumberOfLines; j++)
		{
			//cin >> sNames[j];
			getline(cin, sNames[j]);
			vNames.push_back(sNames[j]);
		}
		nPos = sNames[0].find(" ");
		cout << "nPos=" << nPos <<endl;

		if ((vNames.size() % 2) == 0)
		{
			cout << "size (Yes): " << vNames.size() << endl;
			sNameIn = "Yes";
		}
		else
		{
			cout << "size (No): " << vNames.size() << endl;
			sNameIn = "No";
		}
		cout << "Case#" << i + 1 << ":" << sNameIn << endl;//sNameIn << endl;
	}
	return 0;
}

string sNameSeparator(string sName1, string sName2)
{


	return;
}
