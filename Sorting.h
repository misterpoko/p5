#ifndef SORTING_H
#define SORTING_H
using namespace std;

class Sorting 
{
  public:
    Sorting();
    ~Sorting();
    void SS(int* array);
    void MS(int* array, int const begin, int const end);
    void MSPT2(int* array, int left, int mid, int right);
    void HS(int* array,int n);
    int QS1(int* arr, int start,int last);
    int QS2(int* arr, int start,int last);
    
    //Need to say in the class so that they can have access to the comparison variable
    void merge(int array[], int const left, int const mid, int const right);
    
    void heapify(int arr[], int n, int i);
    
    int partition_r(int arr[], int low, int high);
    int partition(int arr[], int low, int high);
    
    
    
    long comparisons;
    
};


#endif


