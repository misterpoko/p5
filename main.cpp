#include <iostream>
#include "Sorting.h"

using namespace std;
int main (int argc, char **argv)
{
	int j = 5;
	int array[j];
	for (int i = 0; i < j; i++)
	{
		array[i] = rand() %100;
	} // for
	/*for (int i = 0; i < 10000; i++)
		cout << array[i] << " ";
	cout << endl << endl;*/
	SS(array, j);
	
	return 0;
} // main
