#include <iostream>
#include "Sorting.h"

Sorting::Sorting()
{
  comparisons=0;
} 
Sorting::~Sorting()
{
  
}

void Sorting::SS(int* array)
{
	int low;
	int tracker;
	for (int i = 0; i < 10000; i++)
	{
		tracker = i;
		for (int j = 10000-1; j > i; j--)
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
	for (int i = 0; i < 10000; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Number of comparisons: " << comparisons << endl;
} // ss

void Sorting::MS(int* array)
{
  for(int i =0; i<10000; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Number of comparisons: " << comparisons << endl;
} // MS

void Sorting::MSPT2(int* array)
{
  for(int i =0; i<10000; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Number of comparisons: " << comparisons << endl;
} // MSPT2

void Sorting::HS(int* array)
{
  for(int i =0; i<10000; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Number of comparisons: " << comparisons << endl;
} // HS


void Sorting::QS1(int* array)
{
  for(int i =0; i<10000; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Number of comparisons: " << comparisons << endl;
} // QS1

void Sorting::QS2(int* array)
{
  for(int i =0; i<10000; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Number of comparisons: " << comparisons << endl;
} // QS2
