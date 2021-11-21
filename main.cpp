#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <fstream> 
#include <string.h>
#include <sstream>
#include <string>
#include "Sorting.h"

using namespace std;
int main (int argc, char **argv)
{
  string userSelect;
  string subLine; 
  int valueOfInt;
  char userSelectChar, listType;
  bool check = true;
	char caseS = 's';
  char caseM = 'm';
  char caseH = 'h';
  char caseQ = 'q';
  char caseR = 'r';
  int values [10000];
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
     values[index] = valueOfInt;
     index++;
     //cout << subLine << " ";
  }//while
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
				cout << "selection-sort" << endl; 
        listy.SS(values);
				break;
			case 'm': // Merge Sort
				cout << "merge-sort" << endl; 
        listy.MS(values);
				break;
			case 'h': // Heap Sort
        cout << "heap-sort" << endl; 
				break;
			case 'q': // Quick Sort FP
				cout << "quick-sort-fp(q)" << endl; 
				break;
			case 'r': //Quick Sort RP
			  cout << "quick-sort-rp (r)" << endl; 
				break;
			default:
				cout << "Command not recognized. Try again" << endl;
				break;
			}//switch

	return 0;
} // main
