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
    void QS1(int* array);
    void QS2(int* array);
    
    long comparisons;
    
};


#endif


