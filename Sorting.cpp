#include <iostream>
#include "Sorting.h"


long comparisons = 0;

void SS(int* array, int size)
{
	int low;
	int tracker;
	for (int i = 0; i < size; i++)
	{
		tracker = i;
		for (int j = size-1; j > i; j--)
		{
			if (array[j] < array[tracker])
			{
				tracker = j;
			} // if
			comparisons++;
		} // for
		low = array[i];
		array[i] = array[tracker];
		array[tracker] = low;
	} // for
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Number of comparisons: " << comparisons << endl;
} // ss

void MS()
{
} // MS

void MSPT2()
{
} // MSPT2

void HS()
{
} // HS

void QS1()
{
} // QS1

void QS2()
{
} // QS2
