/** 
 *	2parent_scheduler.cpp
 *	Jarret Tang
 */

#include <iostream>

using namespace std;

bool inRange(int sRange, int eRange, int inputNum);

int main()
{
	int numTestCases;
	int numActivities;
	int inputInt;
	bool isImpossible;

	cin >> numTestCases;

	/* main loop */
	for (int testCase = 0; testCase < numTestCases; testCase++)
	{
		numActivities = 0;
		inputInt = 0;
		cin >> numActivities;
		int actArr[numActivities][3];	// activities array. Start/ End/ Who
										//					  int/ int/ 0 or 1
		isImpossible = false;
		/* read in activities */
		for (int act = 0; act < numActivities; act++)
		{
			for (int i = 0; i < 2; i++)
			{
				cin >> inputInt;
				actArr[act][i] = inputInt;
				actArr[act][2] = 0;
				inputInt = 0;
			}
		}

		/*
		 *	compare and assign activities
		 *	
		 * 	if: act overlaps -> nextAct to J
		 *
		 *	edit: changing so it will check j vector
		 *
		 *	it not overlap -> nextAct stay C
		 *	go to next act
		 */
		for (int act = 0; act < numActivities; act++)
		{
			for (int nextAct = act + 1; nextAct < numActivities; nextAct++)
			{
				if (actArr[act][0] == actArr[act][1] || actArr[nextAct][0] == actArr[nextAct][1])
				{
					nextAct = numActivities;
					act = numActivities;
					isImpossible = true;
				}

				if (actArr[act][1] < actArr[act][0])
				{
					nextAct = numActivities;
					act = numActivities;
					isImpossible = true;
				}

				//	if current act is 'J' then skip over cross check with 'C'
				if (actArr[act][2] == 1)
				{
					if (actArr[nextAct][2] == 1) {
						if (inRange(actArr[nextAct][0], actArr[nextAct][1], actArr[act][0]) 
							|| inRange(actArr[nextAct][0], actArr[nextAct][1], actArr[act][1])
							|| inRange(actArr[act][0], actArr[act][1], actArr[nextAct][0])
							|| inRange(actArr[act][0], actArr[act][1], actArr[nextAct][1])

							|| actArr[act][0] == actArr[nextAct][0] 
							|| actArr[act][1] == actArr[nextAct][1])
						{
							// if it intersects and its 'J' -> IMPOSSIBLE
							nextAct = numActivities;
							act = numActivities;
							isImpossible = true;
						}
					}
				}

				// crosscheck with 'C'
				else
				{
					if (inRange(actArr[nextAct][0], actArr[nextAct][1], actArr[act][0]) 
					|| inRange(actArr[nextAct][0], actArr[nextAct][1], actArr[act][1])
					|| inRange(actArr[act][0], actArr[act][1], actArr[nextAct][0])
					|| inRange(actArr[act][0], actArr[act][1], actArr[nextAct][1])

					|| actArr[act][0] == actArr[nextAct][0] 
					|| actArr[act][1] == actArr[nextAct][1])
					{
						//	if currentAct is 'C' and nextAct is 'C' and intersect => 
						//	nextAct has to be 'J'
						actArr[nextAct][2] = 1;
					}
				}
			}
		}

		/* output */
		cout << "Case #" << testCase + 1 << ": ";
		if (isImpossible)
		{
			cout << "IMPOSSIBLE";
		}
		else
		{
			for (int act = 0; act < numActivities; act++)
			{
				if (actArr[act][2] == 0)
				{
					cout << 'C';
				}
				else
				{
					cout << 'J';
				}
			}
		}
		cout << endl;

	}
	return 0;
}

bool inRange(int firstNum, int lastNum, int inputNum) 
{
	if (inputNum > firstNum && inputNum < lastNum) 
	{
		return true;
	}

	return false;
}