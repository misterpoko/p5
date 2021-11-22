#ifndef SORTING_H
#define SORTING_H
using namespace std;

class Sorting 
{
  public:
    Sorting();
    ~Sorting();
    void SS(int * array);
    void MS(int* array, int beg, int end);
    void MSPT2(int* array, int left, int mid, int right);
    void HS(int* array);
    int QS1(int* arr, int start,int last);
    int QS2(int* arr, int start,int last);
    
    long comparisons;
    
};


#endif


