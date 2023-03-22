#pragma once
#include "PhoneBookEntry.h"
#include <algorithm>

//This program creates the default constructor, destructor, methods and member variables 
// (dynamically allocated array of phonebook, array's size) 

static char IllegalCharacters[] = { '(',')',' ','-',',','[',']',';' };// Illegal characters to be removed from string

class Phonebook 
{
public:
	Phonebook();
	Phonebook(int);
	Phonebook(const Phonebook & );
	~Phonebook();
	void display() const;
	void add(PhoneBookEntry);
	void sort();
        bool search(string, PhoneBookEntry &);
	void resize();

private:
	PhoneBookEntry * congressmen;
	int numCongressmen;
	int maxCongressman;
};
