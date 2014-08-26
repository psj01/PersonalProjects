#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>
#include "Hash.h"


hash::hash()
{
	for(int i=0;i<tablesize;i++)
	{
		hashtable[i]= new item;
		hashtable[i]->name="None assigned";
		hashtable[i]->drink="None assigned";
		hashtable[i]->next=NULL;
	}
}


	
void hash::AddItem(std::string name, std::string drink)
{
	int index=Hash(name);
	if(hashtable[index]->name=="None assigned")
	{
		hashtable[index]->name=name;
		hashtable[index]->drink=drink;
	}
	else
	{
		item* ptr=hashtable[index];
		item* n=new item;
		n->name=name;
		n->drink=drink;
		n->next=NULL;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=n;
	}
}


int hash::Hash(std::string key)
{
	int hash=0;
	int index;

	index=key.length();

	for(unsigned int i=0;i<key.length();i++)
	{
		hash+=(int)key[i];
	}	

	index=hash%tablesize;

	return index;

}

int hash::numofitemsinindex(int index)
{
	int count=0;
	if(hashtable[index]->name=="None assigned")
	{
		return count;
	}
	else
	{
		count++;
		item* ptr=hashtable[index];
		while(ptr->next!=NULL)
		{
			count++;
			ptr=ptr->next;
		}
		return count;
	}
}

void hash::printtable()
{
	int number;
	for(int i=0;i<tablesize;i++)
	{
		number=numofitemsinindex(i);
		std::cout<<"Index #"<<i<<std::endl;
		std::cout<<"**************************\n";
		printitemsinindex(i);
		std::cout<<"**************************\n";
		std::cout<<std::endl<<std::endl;
	}

}

void hash::printitemsinindex(int index)
{
	item* ptr=hashtable[index];
	if(ptr->name=="None assigned")
	{
		std::cout<<"Nothing here!"<<std::endl;
	}
	else
	{
		std::cout<<"index : "<<index<<" contains the following items :"<<std::endl;
		while(ptr!=NULL)
		{
			std::cout<<"--------------------------\n";
			std::cout<<ptr->name<<std::endl;
			std::cout<<ptr->drink<<std::endl;
			std::cout<<"--------------------------\n";
			ptr=ptr->next;
		}
	}
}


void hash::finddrink(std::string name)
{
	int index=Hash(name);
	bool foundname=false;
	std::string drink;
	item* ptr=hashtable[index];
	while(ptr!=NULL)
	{
		if(ptr->name==name)
		{
			foundname=true;
			drink=ptr->drink;
		}
		ptr=ptr->next;
	}
	if(foundname==true)
	{
		std::cout<<name<<"'s Fav drink = "<<drink<<std::endl;
	}
	else
	{
		std::cout<<name<<"'s info not found."<<std::endl;
	}
}


void hash::removeitem(std::string name)
{
	int index=Hash(name);
	item* delptr;
	item* p1;
	item* p2;
	//there is going to be different cases depending on where the item is located.

	//case 0 - the index where the name should be is empty!
	if(hashtable[index]->name=="None assigned")
	{
		std::cout<<name<<", not found!"<<std::endl;
	}

	//case 1 - only one item contains in that index location and that the name matches!
	else if(hashtable[index]->name==name && hashtable[index]->next==NULL)
	{
		hashtable[index]->name="None assigned";
		hashtable[index]->drink="None assigned";
		hashtable[index]->next=NULL;
		std::cout<<name<<" removed."<<std::endl;
	}

	//case 2 - we have a match and its located at the first item in the index , but there are more items after that.
	else if(hashtable[index]->name==name)
	{
		delptr=hashtable[index];
		hashtable[index]=hashtable[index]->next;
		delete delptr;
		std::cout<<name<<" removed."<<std::endl;
	}
	

	//case 3 - the index contains some itmes , but the first item is not the match!! case 3 has two diff cases
	else
	{
		p1=hashtable[index]->next;
		p2=hashtable[index];
		while(p1!=NULL && p1->name!=name)
		{
			p2=p1;
			p1=p1->next;
		}
		//case 3.1 - no match
		if(p1==NULL)
		{
			std::cout<<name<<", not found!"<<std::endl;
		}
		//case 3.2 - found a match! 
		else
		{
			delptr=p1;
			p1=p1->next;
			p2->next=p1;
			delete delptr;
			std::cout<<name<<" removed."<<std::endl;
		}
	}
}