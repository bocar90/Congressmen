#include"PhoneBookEntry.h"

//Definition of the default constructor to Initialize the data members of the Class
PhoneBookEntry::PhoneBookEntry() : mName(""),mParty(""),mDistrict(""),mAddress(""),mPhone(""),mPhone2(""),mHtownPhone(""), mHtownDistrict("")
{

}

//Definition of the parameterized constructor to Initialize the data members of the Class
PhoneBookEntry::PhoneBookEntry(string inName, string inParty, string inDistrict,string inAddress, string inPhone, string inPhone2, string inHtownPhone, string inHtownDistrict): mName(inName),	mParty(inParty), mDistrict(inDistrict), mAddress(inAddress), mPhone(inPhone), mPhone2(inPhone2), mHtownPhone(inHtownPhone), mHtownDistrict(inHtownDistrict)
{

}

//this function displays the data members 
void PhoneBookEntry::display() const
{
	//cout << mName << " " << mPhone << " " << mAddress << endl;
	cout << mName << " (" << mParty << '-' << mDistrict << ')' << endl << mAddress << endl << mPhone << "; " << mPhone2 << endl << mHtownDistrict <<": "<<mHtownPhone << endl << endl;
	
}

//this function is used to obtain the value of the data member while using the default constructor
string PhoneBookEntry::getName() const
{
	return mName;
}

//this function is used to assign a value to the data member while using the default constructor
void PhoneBookEntry::setName(string inName) 
{
	mName = inName;
}

string PhoneBookEntry::getPhone() const
{
	return mPhone;
}

void PhoneBookEntry::setPhone(string inPhone)
{
	mPhone = inPhone;
}

string PhoneBookEntry::getAddress() const
{
	return mAddress;
}

void PhoneBookEntry::setAddress(string inAddress)
{
	mAddress = inAddress;
}

string PhoneBookEntry::getParty() const
{
	return mParty;
}

void PhoneBookEntry::setParty(string inParty)
{
	mParty = inParty;
}

string PhoneBookEntry::getDistrict() const
{
	return mDistrict;
}

void PhoneBookEntry::setDistrict(string inDistrict)
{
	mDistrict = inDistrict;
}

string PhoneBookEntry::getPhone2() const
{
	return mPhone2;
}

void PhoneBookEntry::setPhone2(string inPhone2)
{
	mPhone2 = inPhone2;
}


string PhoneBookEntry::getHtownDistrict() const
{
	return mHtownDistrict;
}

void PhoneBookEntry::setHtownDistrict(string inHtownDistrict)
{
	mHtownDistrict = inHtownDistrict;
}

string PhoneBookEntry::getHtownPhone() const
{
	return mHtownPhone;
}

void PhoneBookEntry::setHtownPhone(string inHtownPhone)
{
	mHtownPhone = inHtownPhone;
}

bool PhoneBookEntry::operator==(const PhoneBookEntry & phonebook)
{
	return (mHtownPhone == phonebook.mHtownPhone) ? true : false;
}
bool PhoneBookEntry::operator<=(const PhoneBookEntry &phonebook)
{
	return (mHtownPhone <= phonebook.mHtownPhone) ? true : false;
}
bool PhoneBookEntry::operator>=(const PhoneBookEntry &phonebook)
{
	return (mHtownPhone >= phonebook.mHtownPhone) ? true : false;
}
bool PhoneBookEntry::operator<(const PhoneBookEntry &phonebook)
{
	return (mHtownPhone < phonebook.mHtownPhone) ? true : false;
}
bool PhoneBookEntry::operator>(const PhoneBookEntry &phonebook)
{
	return (mHtownPhone > phonebook.mHtownPhone) ? true : false;
}
bool PhoneBookEntry::operator=(const PhoneBookEntry &phonebook)
{
	mName = phonebook.mName;
	mParty = phonebook.mParty;
	mDistrict = phonebook.mDistrict;
	mAddress = phonebook.mAddress;
	mPhone = phonebook.mPhone;
	mPhone2 = phonebook.mPhone2;
	mHtownPhone = phonebook.mHtownPhone;
	mHtownDistrict = phonebook.mHtownDistrict;
	
	return true;
}