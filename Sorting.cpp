#include <iostream>
#include "Sorting.h"

Sorting::Sorting()
{
  comparisons = 0;
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
	/*for (int i = 0; i < 10000; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Number of comparisons: " << comparisons << endl; */
} // ss

void Sorting::MS(int* array, int beg, int end)
{
	if (beg >= end)
		return;
	int mid = beg + (end - beg)/2;
	MS(array, beg, mid);
	MS(array, mid + 1, end);
	MSPT2(array, beg, mid, end);	
	
/*  for(int i =0; i<10000; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Number of comparisons: " << comparisons << endl;*/
} // MS

void Sorting::MSPT2(int* array, int left, int mid, int right)
{
	int length1 = mid - left + 1;
	int length2 = right - mid;

	int * leftArray = new int[length1];
	int * rightArray = new int[length2];

	for (int n = 0; n < length1; n++)
		leftArray[n] = array[left + n];
	for (int n = 0; n < length2; n++)
		rightArray[n] = array[mid + n + 1];
	int i = 0;
	int j = 0;
	int k = 1;
	while (i < length1 && j < length2)
	{
		comparisons++;
		if (leftArray[i] >= rightArray[j])
			array[k++] = rightArray[j++];
		else
			array[k++] = leftArray[i++];
	} // while
	while (i < length1)
		array[k++] = leftArray[i++];
	while (j < length2)
		array[k++] = rightArray[j++];

} // MSPT2

void Sorting::HS(int* array) //Heap
{
 
} // HS


int Sorting::QS1(int* arr, int start,int last) //QuickSort at first
{
  int i=start+1,j=last,temp;
  if(i>j)
  return comparisons;
  while(i<=j)
  {
    if(arr[i]<arr[start])
    {
      comparisons++;
      i++;
    }//if
    if(arr[j]>arr[start])
    {
      comparisons++;
      j--;                
    }//if
    if(i<=j)
    {
      comparisons++;
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
    }//if
  }//while
  temp=arr[start];
  arr[start]=arr[j];
  arr[j]=temp;
  QS1(arr,start,j-1);
  QS1(arr,j+1,last);     
  return comparisons;
} // QS1



void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int low, int high)
{
    // pivot
    int pivot = arr[high];
   
    // Index of smaller element
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
 
            // increment index of smaller element
            comparisons++;
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
// Generates Random Pivot, swaps pivot with end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
}

int Sorting::QS2(int* arr, int low,int high) //QuickSort at random
{
    if (low < high) 
    { 
        // pi is partitioning index, arr[p] is now at right place 
        int pi = partition_r(arr, low, high); 
  
        // Separately sort elements before partition and after partition 
        QS2(arr, low, pi - 1); 
        QS2(arr, pi + 1, high); 
    } 
    return comparisons;
} // QS2
