#include <iostream>
#include "DoublyLinkedList.h"
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

void commandList() {  //basically the menu
	cout << "Commands - " ;
	cout << "insert (i), " ;
	cout << "delete (d), ";
	cout << "length (l), " ;
	cout << "print (p), ";
	cout << "additivepair (a), ";
	cout << "quit (q) " << endl;
}

int main(int argc, char *argv[]) {
	if(argc > 2 ) { //case for too many files ,exits
		cout << "Sorry! Too many files inputted, quitting..." << endl;
		return EXIT_SUCCESS;
	}
	if(argc == 1) { //checks if no files inputted, exit
		cout << "Sorry! No file inputted, quitting..." << endl;
		return EXIT_SUCCESS;
	}
	ifstream workingFile; 
	workingFile.open(argv[1], ios::in); //opens file to read from
	commandList();
	int singleNumber;  //placeholder for getting each int in list
	DoublyLinkedList currentList = DoublyLinkedList();	//intilizes list
	ItemType item;
	while(workingFile >> singleNumber) {//iterates to null
		item.initialize(singleNumber);//creates object for values, can go out of scope after loop 
		currentList.insertItem(item); //inputs data objects into the sortedLinkedList
	}
	
	bool keepLooping = true;  //inifinite menu screen until q
	
	while (keepLooping) {//only leave when q is inputted
		
		string command; //tried char, but couldn't figure out how to look at too long of input
		cout << "Enter a command: ";
		cin >> command;
		while(!cin.good()) {
					
					cin.ignore(2147483647, '\n');			//command = input
					cin.clear();
		}
		if(command.length() > 1) {
			cout << "Extracting first character in given string one moment..." << endl;
			int temp = time(NULL) + 1; //pause for 1 second, adds glitter to code.
			while(temp > time(NULL));  
		}
		switch(command.at(0)) { //takes the first character of the string, fixes the infinite loop when char more than 2 was inputted
			
			case 'i' : {
				
				cout << "Enter a number: " ; 
				
				int number;
				cin >> number;
				
					ItemType allData;
					allData.initialize(number);
					currentList.insertItem(allData);
					
				
				cin.clear();
				currentList.print();
			}
					break;
				
				
				
			
				break;
			case 'd' :	{
				
				cout << "Enter a value to delete: ";
				
				int number;
				cin >> number;
					ItemType allData;
					allData.initialize(number);
					
					currentList.deleteItem(allData);
					currentList.print();
					cin.clear();
			}
				break;
		
			
		
			case 'p' : currentList.print();
				break;
			case 'l' : {
				cout << "List length is: " << currentList.lengthIs();
				cout <<endl;
			}
				break;
			case 'a' :  {
					cout << "Get the additive sum of:";
				
				int number;
					cin >> number;
					ItemType allData;
					allData.initialize(number);
					currentList.print();
					currentList.additivePairs(allData);
			}
			break;
					
			case 'q' : {
				keepLooping = false; //quits
				cout << "Quitting program..."  << endl;
			}
				break;
				default: {
					cout << endl;
					cout << "Command not recognized.  Try again." <<  endl;
					commandList();
					cout << endl;
				}
				break;
		}
}
	return EXIT_SUCCESS;
}

