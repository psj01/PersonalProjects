/****************************************************************************************************************
Purpose:	This program will track monthly sales data for a small company.
*****************************************************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;


struct Seller
{
	string fname;
	string lname;
	string sellerid;
	double totalsales;
};


int buildSellerArray(Seller sellerArray[]);
void printSellerArray(Seller sellerArray[], int size);
void sortSellersByID(Seller sellerArray[], int size);
int findSellerID(Seller sellerArray[], int size, string searchID);
void processSales(Seller sellerArray[], int size);


/*****************************************************************************************************************
Function: main

Use:      The Boss function

Arguments: none

Returns:   int (returns 0)
*****************************************************************************************************************/
int main()
{
	Seller sellerArray[30];
	int size;

	size=buildSellerArray(sellerArray);
	sortSellersByID(sellerArray,size);
	printSellerArray(sellerArray,size);
	processSales(sellerArray,size);
	printSellerArray(sellerArray, size);

	_getch();
	return 0;
}

/*****************************************************************************************************************
Function: buildSellerArray

Use:      This function will read the seller data into the seller array.  It also keeps track of the number of 
		  seller records read into the array and returns it.

Arguments: double salesArray

Returns:   (int) the number of seller records read in to the seller array.
*****************************************************************************************************************/
int buildSellerArray(Seller sellerArray[])
{
	ifstream infile;
	ofstream outfile;
	int i=0;

	infile.open("sellers.txt");
	if (infile.fail())
	{
		cout<<"sellers.txt failed to open."<<endl;
		exit(1);
	}
	while (infile)
	{
		infile>>sellerArray[i].lname;
		infile>>sellerArray[i].fname;
		infile>>sellerArray[i].sellerid;
		infile>>sellerArray[i].totalsales;
		i++;
	}
	infile.close();
	return i-1;
}


/*****************************************************************************************************************
Function: sortSellersByID

Use:      This function will sort the seller array in ascending order by the seller ID using selection sort.

Arguments: Seller sellerArray and int size

Returns:   (void) Nothing.  the function simply sort the array.
*****************************************************************************************************************/
void sortSellersByID(Seller sellerArray[], int size)
{
	int i, j, min;
	Seller temp;

	for (i=0;i<size-1;i++)
	{
		min = i;
		for (j=i+1;j<size;j++)
		{
			if (sellerArray[j].sellerid<sellerArray[min].sellerid)
			{
				min=j;
			}
			temp=sellerArray[i];
			sellerArray[i]=sellerArray[min];
			sellerArray[min]=temp;
		}
	}	
}



/*****************************************************************************************************************
Function: printSellerArray

Use:      This function will print the contents of the seller array.

Arguments: Seller sellerArray and int size

Returns:   (void) Nothing.
*****************************************************************************************************************/
void printSellerArray(Seller sellerArray[],int size)
{
	int i;
	cout<<"\n\t\t\t      Seller Listing"<<endl<<endl;
	cout<<"      Name \t\t\t        Seller ID \t     Sales "<<endl<<endl;
	for (i=0;i<size;i++)
	{
		cout<<setw(25)<<left<<sellerArray[i].lname+", "+sellerArray[i].fname<<"\t\t "<<setw(7)<<sellerArray[i].sellerid<<"\t "<<setw(10)<<right<<fixed<<setprecision(2)<<sellerArray[i].totalsales<<endl;
	}
}



/*****************************************************************************************************************
Function: findSellerID

Use:	This function will be called to find the position of the seller array element with a seller ID that 
		matches searchID thats passed in.

Arguments: Seller sellerArray, int size and string searchID

Returns:   (int) It will return the position of the seller with the matching seller ID if 
		   the seller is not found it will return -1
*****************************************************************************************************************/
int findSellerID(Seller sellerArray[], int size, string searchID)
{
	int i;

   for (i = 0; i < size; i++)
      {
      if (searchID == sellerArray[i].sellerid)
         return i;
      }
   return -1;
}



/*****************************************************************************************************************
Function: processSales

Use:	This method will read a series of sales records, each containing a last name, a first name, 
		and a sales amount. For each sales record, the method should search for the seller name and, 
		once found, it will add the sales amount to the sales total for that particular seller. 
		If a seller name is not found, an error message saying "ERROR - ID not found." will be printed out.

Arguments: Seller sellerArray and int size

Returns:   (void) this function returns nothing.
*****************************************************************************************************************/
void processSales(Seller sellerArray[], int size)
{
	ifstream infile;
	ofstream outfile;
	string id;
	double salesamt;

	infile.open("sales.txt");
	if (infile.fail())
	{
		cout<<"sales.txt failed to open."<<endl;
		exit(1);
	}
	cout<<"\n\t\t\t Sales Transactions "<<endl<<endl;
	cout<<"Seller ID "<<"\t\t Sale Amount"<<endl<<endl;
	infile>>id;
	while(infile)
	{
		infile>>salesamt;
		int index=findSellerID(sellerArray,size,id);
		if (index==-1)
		{
			cout<<id;
			cout<<"\t\t\tERROR - ID not found."<<endl;
		}
		else
		{
			cout<<id<<"\t\t\t "<<fixed<<setprecision(2)<<setw(10)<<salesamt<<endl;
			sellerArray[index].totalsales+=salesamt;
		}
		infile>>id;
	}
	infile.close();
}

