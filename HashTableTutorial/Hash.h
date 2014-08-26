#ifndef HASH_H
#define HASH_H

#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>

class hash
{
private:
	static const int tablesize=10;
	struct item
	{
		std::string name;
		std::string drink;
		item* next;
	};

	item* hashtable[tablesize];

public:
	hash();
	int Hash(std::string key);
	void AddItem(std::string name,std::string drink);
	int numofitemsinindex(int index);
	void printtable();
	void printitemsinindex(int index);
	void finddrink(std::string drink);
	void removeitem(std::string name);
};

#endif
