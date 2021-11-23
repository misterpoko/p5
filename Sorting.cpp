#include <iostream>
#include "Sorting.h"

Sorting::Sorting()
{
  comparisons = 0;
} 
Sorting::~Sorting()
{
  
}

void Sorting::SS(int* array, int size)
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
} // ss

void Sorting::merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
    {
      if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
      {
        comparisons++;
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
      }
      else 
      {
        comparisons++;
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
      }
      indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) 
    {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
      indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) 
    {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
      indexOfMergedArray++;
    }
} // merge


void Sorting::MS(int array[], int const begin, int const end)
{
  if (begin >= end)
    return; // Returns recursively
  
  auto mid = begin + (end - begin) / 2;
  MS(array, begin, mid);
  MS(array, mid + 1, end);
  merge(array, begin, mid, end);
}


/*void Sorting::MS(int* array, int beg, int end)
{
	if (beg >= end)
		return;
	int mid = beg + (end - beg)/2;
	MS(array, beg, mid);
	MS(array, mid + 1, end);
	MSPT2(array, beg, mid, end);	
	
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

} // MSPT2*/


void Sorting::heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
      largest = l;
    }
      if (l < n) 
	{
	comparisons++;
  //    if (arr[l] > arr[largest]) comparisons++;
	} 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    {
      largest = r;
    }
      if (r < n) 
	{
	comparisons++;
//      if (arr[r] > arr[largest]) comparisons++;
	}
    // If largest is not root
    if (largest != i) {
    {
       swap(arr[i], arr[largest]);
    }
    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
    }
} // heapify 

void Sorting::HS(int* arr, int n) //Heap
{
   // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
    // call max heapify on the reduced heap
    heapify(arr, i, 0);
    }
} // HS


int Sorting::QS1(int* arr, int start,int last) //QuickSort at first
{
  int i=start+1,j=last,temp;
  if(i>j)
    return 0;
  while(i<=j)
  {
    if(arr[i]<arr[start])
    {
      i++;
    }//if
      comparisons++;
    if(arr[j]>arr[start])
    {
      j--;                
    }//if
      comparisons++;
    if(i<=j)
    {
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

int Sorting::partition(int arr[], int low, int high)
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
int Sorting::partition_r(int arr[], int low, int high)
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
