/** nesting_depth.cpp 
 *	Jarrett Tang
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
	int numTestCases;
	string inputStr;
	vector<int> inputArr;
	vector<char> outArr;
	int prevNumIndex;
	int jumpAmt;

	getline(cin, inputStr);
	stringstream(inputStr) >> numTestCases;

	/* main loop */
	for (int testCaseItr = 0; testCaseItr < numTestCases; testCaseItr++)
	{
		inputStr = "";
		getline(cin, inputStr);
		prevNumIndex = 0;

		for (int i = 0; i < inputStr.length(); i++)
		{
			inputArr.push_back((int)inputStr[i] - 48);
		}

		/* First number */
		if (inputArr.at(0) == 0) 
		{
			outArr.push_back('0');
			prevNumIndex += 0;
		}
		else
		{
			for (int i = 0; i < inputArr.at(0); i++)
			{
				outArr.push_back('(');
				prevNumIndex++;
			}

			outArr.push_back((char)(inputArr[0] + 48));

			for (int i = 0; i < inputArr.at(0); i++)
			{
				outArr.push_back(')');
			}
		}

		/* Next Numbers */
		for (int i = 1; i < inputArr.size(); i++)
		{
			/* if the next number is greater than prev number */
			if (inputArr[i] > inputArr[i - 1])
			{
				// bump up one index 
				// use vector::insert
				// insert parts backwards ie: first:')' second:'x' third:'('
				jumpAmt = abs(inputArr[i] - inputArr[i-1]);
				for (int j = 0; j < jumpAmt; j++)
				{
					outArr.insert(outArr.begin() + prevNumIndex + 1, ')');
				}
				outArr.insert(outArr.begin() + prevNumIndex + 1,
								(char)(inputArr[i] + 48));
				for (int j = 0; j < jumpAmt; j++)
				{
					outArr.insert(outArr.begin() + prevNumIndex + 1, '(');
				}
				prevNumIndex += jumpAmt + 1;
			}

			/* if next number is less than or equal to prev number */
			else
			{
				// bump up index based on abs(prevNum - nextNum) + 1
				// vector::insert nextNum
				jumpAmt = abs(inputArr[i] - inputArr[i-1]);
				if (jumpAmt >= outArr.size() - prevNumIndex - 1)
				{
					outArr.push_back((char)(inputArr[i] + 48));
					prevNumIndex += jumpAmt + 1;
				}
				else
				{
					outArr.insert(outArr.begin() + jumpAmt + prevNumIndex 
									+ 1, (char)(inputArr[i] + 48));
					prevNumIndex += jumpAmt + 1;
				}

			}
		}

		/* output */
		// cout << "size: " << outArr.size() << endl;
		cout << "Case #" << testCaseItr + 1 << ": ";
		for (int i = 0; i < outArr.size(); i++)
		{
			cout << outArr.at(i);
		}
		cout << endl;

		outArr.clear();
		inputArr.clear();

	}
	

	return 0;
}