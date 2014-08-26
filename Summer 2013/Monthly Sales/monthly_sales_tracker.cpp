/*****************************************************************************************************************
Purpose:	This program will track monthly sales data for a small company.
*****************************************************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;


class Seller
{
private:
	string fname;
	string lname;
	string sellerID;
	double salestotal;

public:
	Seller();
	Seller(string newFirstName, string newLastName, string newID, double newSalesTotal);
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setID(string newID);
	void setSalesTotal(double newSalesTotal);
	string getFirstName();
	string getLastName();
	string getID();
	double getSalesTotal();
	void print();

};

class SalesRegion 
{
private:
	string regionname;
	Seller sellerArray[30];
	int numofsellers;
	void sortSellersByID();
//	int findSellerID(string searchID); - this is the old search mehthod 
	int findSellerID(string searchID); // using Binary Search 

public:
	SalesRegion();
	SalesRegion(string newRegionName, string fileName);
	void setRegionName(string newRegionName);
	string getRegionName();
	void processSales(string filename);
	void print();

};

/*****************************************************************************************************************
Function: main

Use:      The Boss function

Arguments: none

Returns:   int (returns 0)
*****************************************************************************************************************/

int main()
{
	SalesRegion region("ILLINOIS","sellersIL.txt");
	region.print();
	region.processSales("salesILJuly.txt");
	region.print();
	_getch();
	return 0;
}

/*****************************************************************************************************************
Method: the default seller constructor.

Use:      this will set the first and last name to none and seller id to "ZZZ000" and sales total to zero if 
		  the user does not specify any values when declared.

Arguments: none

Returns:   nothing - this is a constructor
*****************************************************************************************************************/
Seller::Seller()
{
	fname="None";
	lname="None";
	sellerID="ZZZ000";
	salestotal=0.0;
}


/*****************************************************************************************************************
Method: Seller constructor with four arguments

Use:      this will set the initial values for first name, last name, seller id and sales total thats specified 
	      by the user.

Arguments: string first name, string last name, string ID, double sales total.

Returns:   nothing - this is a constructor
*****************************************************************************************************************/
Seller::Seller(string newFirstName, string newLastName, string newID, double newSalesTotal)
{
	setFirstName(newFirstName);
	setLastName(newLastName);
	setID(newID);
	setSalesTotal(newSalesTotal);
}


/*****************************************************************************************************************
Method: setter method for setting the first name.

Use:      this method will set the first name to the newFirstName thats entered by the user.

Arguments: string newFirstName

Returns:   nothing 
*****************************************************************************************************************/
void Seller::setFirstName(string newFirstName)
{
	fname=newFirstName;
}

/*****************************************************************************************************************
Method: setter method for setting the last name.

Use:      this method will set the last name to the newLastName thats entered by the user.

Arguments: string newLastName

Returns:   nothing - void
*****************************************************************************************************************/
void Seller::setLastName(string newLastName)
{
	lname=newLastName;
}

/*****************************************************************************************************************
Method: setter method for setting the user id.

Use:      this method will set the user id to newID thats entered by the user.

Arguments: string newID

Returns:   nothing - void
*****************************************************************************************************************/
void Seller::setID(string newID)
{
	if (newID.length()>0&&newID.length()<7)
	{
		sellerID=newID;
	}
	else
	{
		sellerID="ZZZ000";
	}
}

/*****************************************************************************************************************
Method: setter method for setting the sales total amount.

Use:      this method will set the sales total to the newSalesTotal thats entered by the user.

Arguments: double newSalesTotal

Returns:   nothing - this is a void function
*****************************************************************************************************************/
void Seller::setSalesTotal(double newSalesTotal)
{
	if (newSalesTotal>0)
	{
		salestotal=newSalesTotal;
	}
	else
	{
		salestotal=0.0;
	}
}

/*****************************************************************************************************************
Method: getter method to get the first name.

Use:      this method will give you back the first name

Arguments: none

Returns:   string first name
*****************************************************************************************************************/
string Seller::getFirstName()
{
	return fname;
}

/*****************************************************************************************************************
Method: getter method to get the last name.

Use:      this method will give you back the last name

Arguments: none

Returns:   string last name
*****************************************************************************************************************/
string Seller::getLastName()
{
	return lname;
}

/*****************************************************************************************************************
Method: getter method to get the user id.

Use:      this method will give you back the id

Arguments: none

Returns:   string user id
*****************************************************************************************************************/
string Seller::getID()
{
	return sellerID;
}

/*****************************************************************************************************************
Method: getter method to get sales amount total.

Use:      this method will give you back the number stored in sales total.

Arguments: none

Returns:   double sales total
*****************************************************************************************************************/
double Seller::getSalesTotal()
{
	return salestotal;
}

/*****************************************************************************************************************
Method: print method.

Use:       This method will print the data members of the Seller formatted into columns.

Arguments: none

Returns:   nothing - this is a void function
*****************************************************************************************************************/
void Seller::print()
{
		cout<<fixed<<setprecision(2);
		cout<<setw(35)<<left<<getLastName()+", "+getFirstName()<<setw(20)<<getID()<<setw(10)<<right<<getSalesTotal()<<endl;
}



/*****************************************************************************************************************
Method: the default sales region constructor.

Use:      This "default" constructor will simply set the number of sellers to 0.

Arguments: none

Returns:   nothing - this is a constructor
*****************************************************************************************************************/
SalesRegion::SalesRegion()
{
	numofsellers=0;
}

/*****************************************************************************************************************
Method: SalesRegion constructor with two arguments.

Use:      Constructor that will create a sales region with the name newRegionName and get data from the fileName 
		  given by the user.

Arguments: string newRegionName, string fileName

Returns:   nothing - this is a constructor
*****************************************************************************************************************/
SalesRegion::SalesRegion(string newRegionName, string fileName)
{
	ifstream infile;
	ofstream outfile;
	numofsellers=0;
	double salesTotal;
	string fname,lname,sellerID;

	infile.open(fileName);
	if (infile.fail())
	{
		cout<<"sellersIL.txt failed to open."<<endl;
		exit(1);
	}
	infile>>lname;
	while (infile)
	{
		infile>>fname;
		infile>>sellerID;
		infile>>salesTotal;
		Seller newSeller(fname,lname,sellerID,salesTotal);
		sellerArray[numofsellers]=newSeller;
		numofsellers++;

		infile>>lname;
	}
	infile.close();
	sortSellersByID();
}

/*****************************************************************************************************************
Method: sortSellersByID()

Use:      This method should sort the array of seller objects in ascending order by the seller ID using the 
	      selection sort algorithm covered in class.

Arguments: none

Returns:   nothing - void 
*****************************************************************************************************************/
void SalesRegion::sortSellersByID()
{
	int i, j, min;
	Seller temp;

	for (i=0;i<numofsellers;i++)
	{
		min = i;
		for (j=i+1;j<numofsellers;j++)
		{
			if (sellerArray[j].getID()<sellerArray[min].getID())
			{
				min=j;
			}
		}
			temp=sellerArray[i];
			sellerArray[i]=sellerArray[min];
			sellerArray[min]=temp;
	}	
}

/*****************************************************************************************************************
Method: findSellerID(string searchID)

Use:      This method will find the position of the seller array element with a seller ID that matches searchID. 
		  The algorithm used by this function is linear search.

Arguments: string

Returns:   int - returns the position of the seller array element with matching search id
*****************************************************************************************************************/
/*
int SalesRegion::findSellerID(string searchID)
{
	int i;
	for (int i=0;i<numofsellers;i++)
	{
		if(searchID==sellerArray[i].getID())
		{
			return i;
		}
	}
	return -1;
}
*/

/*****************************************************************************************************************
Method: findSellerID(string searchID)

Use:      This method will find the position of the seller array element with a seller ID that matches searchID. 
		  The algorithm used by this function is binary search.

Arguments: string

Returns:   int - returns the position of the seller array element with matching search id
*****************************************************************************************************************/
int SalesRegion::findSellerID(string searchID)
{
   int low = 0;
   int high = numofsellers - 1;
   int mid;

   while (low <= high)
      {
      mid = (low + high) / 2;

      if (searchID == sellerArray[mid].getID())
         return mid;

      if (searchID < sellerArray[mid].getID())
         high = mid - 1;
      else
         low = mid + 1;
      }
   return -1;
   }

/*****************************************************************************************************************
Method: setRegionName(string)

Use:      This method will check if the length of newRegionName is greater than 0. If it is, it will set 
		  the region name data member to newRegionName. Otherwise, it will set the region name data member 
		  to "None".

Arguments: none

Returns:   nothing - void 
*****************************************************************************************************************/

void SalesRegion::setRegionName(string newRegionName)
{
	regionname=newRegionName;
}

/*****************************************************************************************************************
Method: getRegionName()

Use:      This method will return the region name data member

Arguments: none

Returns:   string - region name 
*****************************************************************************************************************/
string SalesRegion::getRegionName()
{
	return regionname;
}

/*****************************************************************************************************************
Method: processSales(string)

Use:      This method will read a series of sales records, each containing a seller ID and a sales amount. For
		  each sales record, the method will search for the seller ID, if found, will add the sales 
		  amount to the sales total for that seller. If a seller ID is not found, an error message 
		  will be printed.

Arguments: string file name

Returns:   none - void
*****************************************************************************************************************/
void SalesRegion::processSales(string filename)
{
	ifstream infile;
	ofstream outfile;
	double saleAmt;
	string id;

	cout<<"\n\t  Sale Transcations\n"<<endl;
	cout<<"Seller ID\t\t"<<"Sale Amount"<<endl<<endl;
	infile.open(filename);
	if (infile.fail())
	{
		cout<<"salesILJuly.txt failed to open."<<endl;
		exit(1);
	}
	infile>>id;
	while (infile)
	{
		infile>>saleAmt;
		int index=findSellerID(id);
		if(index==-1)
		{
			cout<<id<<"\t\t\tERROR--ID not found"<<endl;
		}
		else
		{
			sellerArray[index].setSalesTotal(sellerArray[index].getSalesTotal() + saleAmt);
			cout<<id<<"\t\t\t"<<fixed<<setprecision(2)<<setw(7)<<saleAmt<<endl;
		}

		infile>>id;
	}
	infile.close();
}

/*****************************************************************************************************************
Method: print()

Use:      This method should print a page header (including the region name) and column headers and then loop 
		  through the seller array and call the method print() for each object in the array.

Arguments: none

Returns:   none - void
*****************************************************************************************************************/
void SalesRegion::print()
{
	cout<<endl<<"\t\t\tSeller Listing for Illinois"<<endl;
	cout<<endl<<"Name"<<"\t\t\t\t"<<"  Seller ID"<<"\t\t   Sales"<<endl<<endl;
	int i=0;
	for (i=0;i<numofsellers;i++)
	{
		sellerArray[i].print();
	}
}
