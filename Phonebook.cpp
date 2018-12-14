 #include"Phonebook.h"

//Definition of the default constructor to Initialize the data members of the Class
Phonebook::Phonebook()
{
	numCongressmen = 0;
	maxCongressman = 5;
	congressmen = new PhoneBookEntry[maxCongressman];
}

//Definition of the constructor with the actual size of the array  
Phonebook::Phonebook(int num)
{
	numCongressmen = 0;
	maxCongressman = num;
	congressmen = new PhoneBookEntry[maxCongressman];
}

//Definition of the Copy constructor that will create a copy of the array 
Phonebook::Phonebook(const Phonebook & original)
{
	numCongressmen = original.numCongressmen;
	maxCongressman = original.maxCongressman;
	congressmen = new PhoneBookEntry[maxCongressman];
	for (int i = 0; i < maxCongressman; i++)
			congressmen[i] = original.congressmen[i];
	
}

//Definition of the destructor in order to delete or free the memory 
Phonebook::~Phonebook()
{	if(congressmen)
	{
	delete[]congressmen;
	congressmen = NULL;
	}
}

//this function adds the entries to the array and extends its length when the max is reached  
void Phonebook::add(PhoneBookEntry first)
{	
	if (numCongressmen >=maxCongressman)
	{
		resize();
	}
	congressmen[numCongressmen] = first;
	numCongressmen++;
}

//this function displays the array of entries  
void Phonebook::display() const
{
	for (int i = 0; i < numCongressmen; i++)
	{
		congressmen[i].display();
	}

}

/*this function sorts the array in ascending order
void Phonebook::sort(PhoneBookEntry list[], int maxCongressman)
{ 
	int smallest;
	PhoneBookEntry swap;
	for (int i = 0; i<maxCongressman-1; i++)
	{
		smallest = i;
		for (int j = i+1; j < maxCongressman; j++)
		{
			if (list[j].getHtownPhone() < list[smallest].getHtownPhone())
			{
				smallest = j;
				swap = list[smallest];
				list[smallest] = list[i];
				list[i] = swap;
			}
		}
		/*if (smallest != i)
		{	
			swap = congressmen[i];
			congressmen[i] = congressmen[smallest];
			congressmen[smallest] = swap;
		}
		
	}
}*/

void Phonebook::sort()
{
	int smallest = 0;
	PhoneBookEntry tmp;
	for (int i = 0; i < numCongressmen; i++)//loop through list
	{
		//cout << "up to " << i << endl;
		smallest = i;//smallest object position is set to the current position
		for (int j = i + 1; j < numCongressmen; j++)// loop through list from i+1 to numCongressmen
		{
			if (congressmen[j] < congressmen[smallest])//if we find a number that is smaller then smallest, set smallest to j
				smallest = j;
		}
		if (smallest != i)// if we find a smaller number swap entries
		{
			//cout << "swapping: " << congressmen[i].getHtownPhone() << " with " << congressmen[smallest].getHtownPhone() << endl;
			tmp = congressmen[i];
			congressmen[i] = congressmen[smallest];
			congressmen[smallest] = tmp;
		}
	}
}

//this function assigns the entry searched and returns true or false depending on weither the element was found or not  
//bool Phonebook::search(string searchVal, PhoneBookEntry & entry)
//{
//	for (int j = 0; j < numCongressmen; j++)
//	{
//		if (congressmen[j].getHtownPhone() == searchVal)
//		{
//			entry = congressmen[j];
//			return true;
//		}
//		
//	}
//	
//		return false;
//}
/*
DESC:	Searches through the input array and returns the index of Item if found.
Otherwise returns -1
*/
template<typename T>
static int binarysearch(T *Array, int nTop, int nBottom, T Item)
{
	if (nTop > nBottom)
		return -1;

	int nMiddle = (nTop + nBottom) / 2;

	if (Array[nMiddle] == Item)
		return nMiddle;
	else if (Array[nMiddle] < Item)
		nTop = nMiddle + 1;
	else if (Array[nMiddle] > Item)
		nBottom = nMiddle - 1;

	return binarysearch<T>(Array, nTop, nBottom, Item);
}

/*
DESC:	Searches through the input array and returns the index of Item if found.
Otherwise returns -1
*/
template<typename T>
static int binarysearch(T *Array, int nSize, T Item)
{
	return binarysearch(Array, 0, nSize - 1, Item);
}

/*
DESC:	Searches through the input array and returns a pointer to the Item,
if not found, will return NULL
*/
template<typename T>
static T *binarysearchItem(T *Array, int nSize, T Item)
{
	T *Ret = NULL;
	int nIndex = binarysearch(Array, 0, nSize - 1, Item);
	if (nIndex > -1)
		Ret = &Array[nIndex];

	return Ret;
}

bool Phonebook::search(string searchVal, PhoneBookEntry & entry)
{
	int nTop = 0,
		nBottom = numCongressmen - 1,
		nNumberSize;
	PhoneBookEntry searchRet;

	//Remove any illegal characters from the string.
	for (int i = 0; i<sizeof(IllegalCharacters) / sizeof(IllegalCharacters[0]); i++)
		searchVal.erase(remove(searchVal.begin(), searchVal.end(), IllegalCharacters[i]), searchVal.end());

	//Check if the string size is valid
	if ((nNumberSize = searchVal.size()) != 10)
		return false;

	//Check if string contains numbers
	for (int i = 0; i < nNumberSize; i++)
	{
		if (searchVal[i] < '0' || searchVal[i] > '9')// check if character contains numbers
			return false;
	}

	//We can now do a binary search for the number
	entry.setHtownPhone(searchVal);
	PhoneBookEntry *pItem = binarysearchItem<PhoneBookEntry>(congressmen, numCongressmen, entry);
	if (pItem != NULL)
	{
		entry = *pItem;
		return true;
	}
	return false;
}

//this function extends the length of the array by creating a new array and delete the previous one  
void Phonebook::resize()
{
	maxCongressman = maxCongressman + 1;
	PhoneBookEntry *temp = new PhoneBookEntry[maxCongressman];
	for (int i = 0; i < numCongressmen; i++)
		temp[i] = congressmen[i];
	delete[] congressmen;
	congressmen = temp;
}