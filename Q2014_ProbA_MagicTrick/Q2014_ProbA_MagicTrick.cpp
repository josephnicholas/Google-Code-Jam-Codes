// Q2014_ProbA_MagicTrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Containers.
vector<string> vCardArrangement;

//variables.
int nNumberOfCases{ 0 };
int nRowNumber{ 0 };
string sCardNumbers;

//function prototype.
string sFoundInRow(vector<string>, int);


int _tmain(int argc, _TCHAR* argv[])
{
	cin >> nNumberOfCases;
	for (int i = 0; i < nNumberOfCases; i++)
	{
		cin >> nRowNumber;
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
		for (int j = 0; j < 4; j++)
		{
			getline(cin, sCardNumbers);
			vCardArrangement.push_back(sCardNumbers);
		}
		//Find specific card number by inputted row position.
		for (int k = 0; k < vCardArrangement.size(); k++)
		{
			if ((vCardArrangement.size() % 4) == 0)
			{
				cout << "\n";

			}
			cout << vCardArrangement[k] << " ";
		}
		

		cout << "Case #"<<i + 1<<":"<<vCardArrangement.size() << endl;
	}

	return 0;
}

//Implementation.
string sFoundInRow(vector<string> vNumberContainer, int nRow)
{
	string sFoundNumber;

	return sFoundNumber;
}