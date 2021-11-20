#include <iostream>


using namespace std;

long comparisons = 0;

void SS(int* array, int size)
{
	int low = array[0];
	int swapper;
	int tracker;
	for (int i = 0; i < size; i++)
	{
		for (int j = size-1; j > i; j--)
		{
			if (array[j] < low)
			{
				tracker = j;
				low = array[j];
			} // if
		} // for
		swapper = array[i];
		array[i] = low;
		array[tracker] = swapper;
	} // for
	for (int i = 0; i < size; i++)
		cout << array[i] << " " << endl;
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
