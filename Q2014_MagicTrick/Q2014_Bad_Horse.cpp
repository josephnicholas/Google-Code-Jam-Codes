// Q2014_MagicTrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

//Member function prototype.
void sNameSeparator(string sName, vector<string> &);

//Global variables.
int nCase = 0;
int nNumberOfLines = 0;
int nPos = 0;

vector<string> vNames;
string::iterator iterFoundName;

string sNames;// [100];
string sNameIn = "";

int _tmain(int argc, _TCHAR* argv[])
{
	cin >> nCase;
	
	for (int i = 0; i < nCase; i++)
	{
		vNames.empty();
		sNames.empty();

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
		}

		if ((vNames.size() % 2) == 0)
		{
			sNameIn = "Yes";
		}
		else
		{
			sNameIn = "No";
		}
		cout << "Case#" << i + 1 << ":" << sNameIn << endl;//sNameIn << endl;
	}
	return 0;
}

void sNameSeparator(string sName, vector<string> &vNameContainer)
{
	iterFoundName = find(sName.begin(), sName.end(), ' ');
	string sNameCopy = sName;
	string temp;
	
	temp.empty();
	vNameContainer.empty();
	vNameContainer.clear();

	for (string::iterator it = sNameCopy.begin(); it != sNameCopy.end(); ++it)
	{
		//First find.
		if (*it == ' ')
		{
			break;
		}
		//cout << *it;
		temp += *it;
	}
	vNameContainer.push_back(temp);
		
	//cout << " ";
	temp.empty();
	for (string::iterator it = iterFoundName; it != sName.end(); ++it)
	{
		//First find.
		if (*it == ' ')
		{
			sName.erase(it);
		}
		//cout << *it;
		temp += *it;
	}
	vNameContainer.push_back(temp);
}
