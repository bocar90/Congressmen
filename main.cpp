// CSC 211 Spring 2018
// Dr. Sturm
// Bocar Sock
//bocar.sock@cix.csi.cuny.edu

#include"Phonebook.h"
#include"PhoneBookEntry.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<algorithm>
using namespace std;
//This program reads entries from a file, adds them to an array and displays the array
//it also sorts the data and returns a message based on the user search's entry 


int main(int argc, char* argv[])
{
	ifstream inData;
	int numEntries= 0, numLines = 0, max = 0;
	char rep;
	string lineCongress;
	
	//inData.open("congressContacts.txt");
	inData.open(argv[1]); //opens the files by using the command line argument
	if (!inData)
	{
		cout << "Error opening file!";
	}
	
	while (!inData.eof())
	{
		getline(inData, lineCongress);
		numLines++;
	}
	numEntries= numLines/6;
	cout << numEntries << endl;
	Phonebook myPhonebook(numEntries);
	inData.clear();
	inData.seekg(0, ios::beg);
	PhoneBookEntry entry;
	while (!inData.eof())
	{	
		getline(inData, lineCongress, '(');
		entry.setName(lineCongress);
		getline(inData, lineCongress, '-');
		entry.setParty(lineCongress);
		getline(inData, lineCongress, ')');
		entry.setDistrict(lineCongress);
		getline(inData, lineCongress); // reads to the end of line or empty line
		getline(inData, lineCongress);
		entry.setAddress(lineCongress);
		getline(inData, lineCongress, ';');
		entry.setPhone(lineCongress);
		getline(inData, lineCongress);
		entry.setPhone2(lineCongress);
		getline(inData, lineCongress, ':');
		entry.setHtownDistrict(lineCongress);
		getline(inData, lineCongress);
		//Remove any illegal characters from the string.
		for (int i = 0; i<sizeof(IllegalCharacters) / sizeof(IllegalCharacters[0]); i++)
			lineCongress.erase(remove(lineCongress.begin(), lineCongress.end(), IllegalCharacters[i]), lineCongress.end());
	
		entry.setHtownPhone(lineCongress);
		getline(inData, lineCongress);
		getline(inData, lineCongress);
	
		myPhonebook.add(entry);
		
	}
	inData.close();
	//inData.open();
	inData.open(argv[1]); // opens the files by using the command line argument
	PhoneBookEntry congressEntry;
	myPhonebook.sort();
	cout << "Phone book sorted:" << endl;
	myPhonebook.display();	
	//cout << myPhonebook.congressmen[149].getParty()<<endl;
	cout << "There are "<<numEntries<<" congressmen in the data base";
	string searchElement;
	// repeats the search until the user enters N for No
	do
	{
		cin.ignore();
		cout << "\nEnter the person's number: ";
		getline(cin, searchElement);
		if (myPhonebook.search(searchElement, congressEntry))
		{
		cout << "Search successful!!!" << endl;
		congressEntry.display();
		}
		else
		cout << "The person is not in the phone book !!" << endl;
	cout << "Do you want to search another entry (Y/N)? ";
	cin >> rep;
	} while (rep=='Y'||rep=='y');
	
	system("PAUSE");
	return 0;
}

