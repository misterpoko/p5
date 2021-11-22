#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <fstream>
#include <string.h>
#include <sstream>
#include <string>
#include "Sorting.h"
#define null NULL

struct Node {
    int data;
    Node * next;
};

void printArray(int * array,int size);
using namespace std;
int main (int argc, char **argv)
{
  string userSelect;
  string subLine;
  int valueOfInt;
  int n;
  char userSelectChar, listType;
  bool check = true;
	char caseS = 's';
  char caseM = 'm';
  char caseH = 'h';
  char caseQ = 'q';
  char caseR = 'r';
  int valuesSize = 0;
  Node * head = new Node;
  Node * curr = head;
  int index =0;
  Sorting listy;
	ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile.is_open()) //Error checking for if the file can be opened
	{
	  cout << "Unable to open int file" << endl;
  }//if
	while (getline(inFile, subLine,' ')) //Gets each variable until it hits a space or EOF
	{
        valueOfInt = stoi(subLine);
        if(valuesSize == 0) 
        {
          head->data = valueOfInt;
        }//if
        else 
        {
          Node * n = new Node;
          n->data = valueOfInt;
          n->next = head;
          head = n;
        }//else
        valuesSize++;
        //valueOfInt = stoi(subLine);
        //values[index] = valueOfInt;
        //index++;
     //cout << subLine << " ";
  }//while
    int values[valuesSize];
    curr = head;
    int i = 0;
    while(curr != null) {
        values[i] = curr->data;
        curr = curr->next;
        delete head;
        head = curr;
        i++;
    }//while
	for (int i = 0; i < valuesSize; i++)
	{
		cout << values[i] << " ";
	} // for
	cout << endl;
    head = null;
    curr = null;
  cout << endl;
  inFile.close();
  cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp(q) quick-sort-rp (r) " << endl;
  cout << "Enter the algorithm: ";
	cin >> userSelect;
	//Lines 114 - 120 make sure input us a 1 char string
	while(userSelect.size()!=1)
	{
	  cout << "Invalid command, try again!" <<endl;
	  cout << "Enter a command: ";
	  cin >> userSelect;
	}//while
	userSelectChar = userSelect[0];
	switch (userSelectChar)
			{
			case 's': //Selestion Sort
        listy.SS(values);
				printArray(values, (sizeof(values)/sizeof(values[0])));
        cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			case 'm': // Merge Sort
        listy.MS(values,0 , (sizeof(values)/sizeof(values[0]))- 1);
				printArray(values, (sizeof(values)/sizeof(values[0])));
        cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			case 'h': // Heap Sort
        n = sizeof(values) / sizeof(values[0]);
        listy.HS(values,n);
        printArray(values, (sizeof(values)/sizeof(values[0])));
        cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			case 'q': // Quick Sort FP
        listy.QS1(values,0,valuesSize-1); 
        printArray(values, (sizeof(values)/sizeof(values[0])));
	      cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			case 'r': //Quick Sort RP
        listy.QS2(values,0,valuesSize-1);
       	printArray(values, (sizeof(values)/sizeof(values[0])));
        cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			default:
				cout << "Command not recognized. Try again" << endl;
				break;
			}//switch

	return 0;
} // main

void printArray(int * array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
} // printArray
