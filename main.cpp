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
int n , arrayTypeSelect;
int index =0;
char userSelectChar, listType;
bool check = true;
int valuesSize = 0;
Node * head = new Node;
Node * curr = head;
Sorting listy;
	ifstream inFile;

cout << "Random values (1) File Input (2). \nEnter a command: ";
cin >> userSelect;
arrayTypeSelect = stoi(userSelect);
while(arrayTypeSelect != 1 && arrayTypeSelect!= 2)
{
cout << "Invalid command please try again: ";
cin >>  userSelect;
arrayTypeSelect = stoi(userSelect);
}
if (arrayTypeSelect == 1 ) 
{
cout << "Enter a number of elements wanted: ";
cin >> userSelect;
bool inputCheck = true;
while(inputCheck == true)
{
try 
		  {
		    valuesSize = stof(userSelect);
inputCheck = false;
		  }//try
		  catch(std::invalid_argument) //Catches error if user tries to store strings into a float
      {
        cout << "Invalid input. Try again : ";
        cin >> userSelect;
		  }//catch
    }
int valuesRandom[valuesSize];
	  for (int i = 0; i < valuesSize; i++)
	  {
		  valuesRandom[i] = rand() %valuesSize;
	  } // for
printArray(valuesRandom,valuesSize);
cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp(q) quick-sort-rp (r) " << endl;
cout << "Enter the algorithm: ";
	  cin >> userSelect;
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
listy.SS(valuesRandom, (sizeof(valuesRandom)/sizeof(valuesRandom[0])));
				printArray(valuesRandom, (sizeof(valuesRandom)/sizeof(valuesRandom[0])));
cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			case 'm': // Merge Sort
listy.MS(valuesRandom,0 , (sizeof(valuesRandom)/sizeof(valuesRandom[0]))- 1);
				printArray(valuesRandom, (sizeof(valuesRandom)/sizeof(valuesRandom[0])));
cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			case 'h': // Heap Sort
n = sizeof(valuesRandom) / sizeof(valuesRandom[0]);
listy.HS(valuesRandom,n);
printArray(valuesRandom, (sizeof(valuesRandom)/sizeof(valuesRandom[0])));
cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			case 'q': // Quick Sort FP
listy.QS1(valuesRandom,0,valuesSize-1); 
printArray(valuesRandom, (sizeof(valuesRandom)/sizeof(valuesRandom[0])));
	      cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			case 'r': //Quick Sort RP
listy.QS2(valuesRandom,0,valuesSize-1);
	printArray(valuesRandom, (sizeof(valuesRandom)/sizeof(valuesRandom[0])));
cout << "Number of comparisons: " << listy.comparisons << endl;
				break;
			default:
				cout << "Command not recognized. Try again" << endl;
				break;
			}//switch
}
else
{ 
valuesSize = 0;
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
}//while
int values[valuesSize];
curr = head;
int i = 0;
while(curr != null) 
{
values[i] = curr->data;
curr = curr->next;
delete head;
head = curr;
i++;
}//while
	int values2[valuesSize];
	for (int i = valuesSize-1, j = 0; i >= 0; i--,j++)
		values2[j] = values[i];
	for (int i = 0; i < valuesSize; i++)
		values[i] = values2[i];
head = null;
curr = null;
cout << endl;
inFile.close();
printArray(values,valuesSize);
cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp(q) quick-sort-rp (r) " << endl;
cout << "Enter the algorithm: ";
	cin >> userSelect;
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
listy.SS(values, (sizeof(values)/sizeof(values[0])));
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
}

	return 0;
} // main

void printArray(int * array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
} // printArray
