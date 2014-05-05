// Q2014_ProbA_MagicTrick.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

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
		vCardArrangement1.clear();
		vCardArrangement2.clear();
		for (int l = 0; l < 2; l++)
		{
			if (!isFinshedArr1)
			{
				//cout << "nRowNumber1:";
				cin >> nRowNumber1;
			}
			else
			{
				//cout << "nRowNumber2:";
				cin >> nRowNumber2;
			}


			if (cin.peek() == '\n')
				cin.ignore();

			if (isFinshedArr1)
			{
				//cout << "Set2:\n";
				sCardNumbers.clear();
				for (int k = 0; k < 4; k++)
				{
					getline(cin, sCardNumbers);
					vCardArrangement2.push_back(sCardNumbers);
				}
			}

			if (!isFinshedArr1)
			{
				//cout << "Set1:\n";
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
				
		//cout << "Output:" <<  << endl;
		cout << "Case #" << i + 1 << ":" << sFoundInRow(vCardArrangement1, vCardArrangement2, nRowNumber1, nRowNumber2) << endl;
	}

	return 0;
}

//Implementation.
string sFoundInRow(vector<string> vNumberContainer1, vector<string> vNumberContainer2, int nRowArr1, int nRowArr2)
{
	string sFoundItems, sTemp1, sTemp2, sTemp;
	string sDelimeter = ",";
	int nFoundItems = 0;

	int current;
	int next = -1;

	sTemp1 = vNumberContainer1[nRowArr1 - 1];
	sTemp2 = vNumberContainer2[nRowArr2 - 1];

	replace_if(sTemp1.begin(), sTemp1.end(), isspace, ',');
	replace_if(sTemp2.begin(), sTemp2.end(), isspace, ',');

	cout << "\n";
	
	vNumberContainer1.clear();
	vNumberContainer2.clear();
	
	do
	{
		current = next + 1;
		next = sTemp1.find_first_of(sDelimeter, current);
		sTemp = sTemp1.substr(current, next - current);
		vNumberContainer1.push_back(sTemp);

	} while (next != string::npos);
	
	//reinitialize
	current = 0;
	next = -1;
	sTemp.clear();

	do
	{
		current = next + 1;
		next = sTemp2.find_first_of(sDelimeter, current);
		sTemp = sTemp2.substr(current, next - current);
		vNumberContainer2.push_back(sTemp);

	} while (next != string::npos);

	for (unsigned int i = 0; i < vNumberContainer1.size(); i++)
	{
		if (vNumberContainer1[i] == vNumberContainer2[i])
		{
			nFoundItems++;
			sFoundItems = vNumberContainer1[i];
		}
		
	}

	if (nFoundItems > 1)
	{
		sFoundItems = "Bad magician!";
	}
	else if (nFoundItems == 0)
	{
		sFoundItems = "Volunteer cheated!";
	}


	return sFoundItems;
}


