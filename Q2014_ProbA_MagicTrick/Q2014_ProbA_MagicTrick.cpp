// Q2014_ProbA_MagicTrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Containers.
vector<string> vCardArrangement1;
vector<string> vCardArrangement2;


//variables.
int nNumberOfCases{ 0 };
int nRowNumber1{ 0 };
int nRowNumber2{ 0 };
string sCardNumbers;

//function prototype.
string sFoundInRow(vector<string>, vector<string>, int, int);


int _tmain(int argc, _TCHAR* argv[])
{
	bool isFinshedArr1 = false;
	cin >> nNumberOfCases;
	for (int i = 0; i < nNumberOfCases; i++)
	{
		for (int l = 0; l < 2; l++)
		{
			if (!isFinshedArr1)
			{
				cout << "nRowNumber1:";
				cin >> nRowNumber1;
			}
			else
			{
				cout << "nRowNumber2:";
				cin >> nRowNumber2;
			}


			if (cin.peek() == '\n')
				cin.ignore();

			if (isFinshedArr1)
			{
				cout << "Set2:\n";
				sCardNumbers.clear();
				for (int k = 0; k < 4; k++)
				{
					getline(cin, sCardNumbers);
					vCardArrangement2.push_back(sCardNumbers);
				}
			}

			if (!isFinshedArr1)
			{
				cout << "Set1:\n";
				for (int j = 0; j < 4; j++)
				{
					if (j == 3) //4th cycle.
					{
						isFinshedArr1 = true;
					}
					getline(cin, sCardNumbers);
					vCardArrangement1.push_back(sCardNumbers);
				}
			}

			


		}
				
		cout << "Output:" << sFoundInRow(vCardArrangement1, vCardArrangement2, nRowNumber1, nRowNumber2) << endl;
		//cout << "Case #"<<i + 1<<":"<<vCardArrangement1.size() << endl;
	}

	return 0;
}

//Implementation.
string sFoundInRow(vector<string> vNumberContainer1, vector<string> vNumberContainer2, int nRowArr1, int nRowArr2)
{
	string sFoundNumber, sTemp1, sTemp2;
	
	sTemp1 = vNumberContainer1[nRowArr1 - 1];
	sTemp2 = vNumberContainer2[nRowArr2 - 1];

	sTemp1.erase(remove_if(sTemp1.begin(), sTemp1.end(), isspace), sTemp1.end());
	sTemp2.erase(remove_if(sTemp2.begin(), sTemp2.end(), isspace), sTemp2.end());

	cout << "\n";

	cout << sTemp1 << endl;
	cout << sTemp2 << endl;

	sFoundNumber = sTemp1.compare(sTemp2);
	sTemp1.

	return sFoundNumber;
}

//Find specific card number by inputted row position.
//for (int k = 0; k < vCardArrangement1.size(); k++)
//{
//	if ((vCardArrangement1.size() % 4) == 0)
//	{
//		cout << "\n";
//
//	}
//	cout << vCardArrangement1[k] << " ";
//}

