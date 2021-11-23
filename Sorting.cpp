#include <iostream>
#include "Sorting.h"


/**
 * Constructor that creates a sorting object meant to keep track of comparisons
 */
Sorting::Sorting()
{
	comparisons = 0;
} // Sorting

/**
 * Default destructor
 */ 
Sorting::~Sorting()
{ 
} // ~Sorting

/**
 * This is the selection sort method. It is a simple sorting method.
 * @param array is the array being sorted
 * @param size is the size of the array being sorted
 */
void Sorting::SS(int* array, int size)
{
	int low;
	int tracker;
	//traversing array and finding min to swap with current element
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
} // SS

/**
 * This is the merge part of the mergesort method. This is where the actual sorting takes place. It is not a simple sort and uses lots of temporary arrays.
 * @param array the temp array to be sorted
 * @param left the leftmost part of the array
 * @param mid the middle of the array
 * @param right the rightmost part of the array
 */
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
     	 	} // if
		indexOfMergedArray++;
	} // while
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) 
	{
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	} // while
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) 
	{
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	} // while
} // merge

/**
 * This is the recursive part of the mergesort. It is where it calls the merge after breaking up the array into small pieces
 * @param array the array being sorted
 * @param begin the index of the first element
 * @param end the index of the last element
 */
void Sorting::MS(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively 
	auto mid = begin + (end - begin) / 2;
	MS(array, begin, mid);
	MS(array, mid + 1, end);
	merge(array, begin, mid, end);
} // MS

/**
 * This is the sorting part of heapsort. It turns the data into a heap and then promptly sorts it.
 * The heap is still array based.
 * @param arr the array to be sorted.
 * @param n index of smallest element
 * @param i index of largest element
 */
void Sorting::heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
 
	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
	} // if
	if (l < n) 
	{
		comparisons++;
	} // if 
        // If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
	{
		largest = r;
	} // if
      	if (r < n) 
	{
		comparisons++;
	} // if
	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
    		// Recursively heapify the affected sub-tree
    		heapify(arr, n, largest);
	} // if
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


int Sorting::partition1(int *arr,int start,int last)
{
int pivot=arr[start],p1=start+1,i,temp;
for(i=start+1;i<=last;i++)
{
comparisons++;
if(arr[i]<pivot)
{
if(i!=p1)
{  
temp=arr[p1];
arr[p1]=arr[i];
arr[i]=temp;
}   
p1++;
}
}
arr[start]=arr[p1-1];
arr[p1-1]=pivot;
return p1-1;
}


void Sorting::QS1(int* arr, int start,int last) //QuickSort at first
{
int p1;
if(start<last)
{
p1=partition1(arr,start,last);
QS1(arr,start,p1-1);
QS1(arr,p1+1,last);
}
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
i++;
swap(arr[i], arr[j]);
}
comparisons++;
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
