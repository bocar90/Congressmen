#pragma once
#include <iostream>
#include<string>
using namespace std;

//This program creates the constructors (default and parameterized), methods and member variables for the entries

class PhoneBookEntry
{
public:
	PhoneBookEntry();
	PhoneBookEntry(string, string, string, string, string, string, string, string);
	void display() const;
	string getName() const;
	string getParty() const;
	string getDistrict() const;
	string getAddress() const;
	string getPhone() const;
	string getPhone2() const;
	string getHtownPhone() const;
	string getHtownDistrict() const;
	void setName(string);
	void setParty(string);
	void setDistrict(string);
	void setAddress(string);
	void setPhone(string);
	void setPhone2(string);
	void setHtownPhone(string);
	void setHtownDistrict(string);
	//overloaded operators
	bool operator==(const PhoneBookEntry &phonebook);
	bool operator<=(const PhoneBookEntry &phonebook);
	bool operator>=(const PhoneBookEntry &phonebook);
	bool operator<(const PhoneBookEntry &phonebook);
	bool operator>(const PhoneBookEntry &phonebook);
	bool operator=(const PhoneBookEntry &phonebook);

private:
	string mName;
	string mParty;
	string mDistrict;
	string mAddress;
	string mPhone;
	string mPhone2;
	string mHtownPhone;
	string mHtownDistrict;	
};