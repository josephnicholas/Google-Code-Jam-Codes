// Q2014_MagicTrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Member function prototype.
void sNameSeparator(string sName, vector<string> &);

//Global variables.
int nCase = 0;
int nNumberOfLines = 0;
int nPos = 0;
vector<string> vNames;
string sNames;// [100];
string sNameIn = "";


int _tmain(int argc, _TCHAR* argv[])
{
	cin >> nCase;
	
	for (int i = 0; i < nCase; i++)
	{
		vNames.clear();
		sNames.clear();

		cin >> nNumberOfLines;

		/***************************************************************

		Stack overflow:
		You have a different problem than the one described in the faq. 
		You are mixing formatted and unformatted input. formatted input 
		leaves trailing newlines in the stream. Your unformatted input, 
		getline, stops when it encounters a newline.

		***************************************************************/

		if (cin.peek() == '\n')
			cin.ignore();

		/***
		-end-
		***/

		for (int j = 0; j < nNumberOfLines; j++)
		{
			getline(cin, sNames);
			sNameSeparator(sNames, vNames);
			//vNames.push_back(sNames);
		}

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

void sNameSeparator(string sName, vector<string> &vNameContainer)
{
	int found = sName.find(" ");
	int rFound = sName.rfind(" ");
	sName = sName.substr(found);

	//First find.
	cout << "first:" << sName << endl;
	vNameContainer.push_back(sName);

	sName = sName.substr(rFound);
	//Second find.
	cout << "second:" << sName << endl;
	vNameContainer.push_back(sName);

	cout << "vector size:" << vNameContainer.size() << endl;

}
