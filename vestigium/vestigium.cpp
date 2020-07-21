/**
 *	Vestigium.cpp
 *	Jarrett Tang
 */

#include <iostream>
#include <vector>

using namespace std;

int check_row();

int main()
{
	int numTestCases = 0;

	cin >> numTestCases;

	/* main loop */
	for (int caseNum = 0; caseNum < numTestCases; caseNum++)
	{
		int size = 0;
		int traceCount = 0;
		int inputNum = 0;
		int rowCount = 0;
		int colCount = 0;

		cin >> size;

		int matrix[size][size];

		// filling matrix
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++) 
			{
				cin >> inputNum;
				matrix[j][k] = inputNum;
			}
		}

		/* test matrix */
		// for (int j = 0; j < size; j++)
		// {
		// 	for (int k = 0; k < size; k++) 
		// 	{
		// 		cout << matrix[j][k] << " ";
		// 	}
		// 	cout << "\n";
		// }

		// check trace
		for (int iTrace = 0; iTrace < size; iTrace++)
		{
			traceCount += matrix[iTrace][iTrace];
			// cout << iTrace << " " << matrix[1][1] << endl;
		}

		// row counter
		for (int j = 0; j < size; j++) 
		{
			for (int k = 0; k < size; k++)
			{
				int selected = matrix[j][k];
				for (int l = k+1; l < size; l++)
				{
					if (matrix[j][k] == matrix[j][l])
					{
						rowCount++;
						l = size;
						k = size;
					}
				}
			}
		}

		/* column counter */
		for (int j = 0; j < size; j++) 
		{
			for (int k = 0; k < size; k++)
			{
				int selected = matrix[j][k];
				for (int l = k+1; l < size; l++)
				{
					if (matrix[k][j] == matrix[l][j])
					{
						colCount++;
						l = size;
						k = size;
					}
				}
			}
		}

		/* output */
		cout << "Case #" << caseNum + 1 << ": " << traceCount << " "
				<< rowCount << " " << colCount << endl;
		
	}


	return 0;
}