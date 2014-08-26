/*****************************************************************************************************************
Purpose:	This program will monthly sales data from a file that you have opened for input. It will then assign 
			total monthly sales to the appropriate month and finds the total sales for the year, average sales 
			per month, best month and worst month based on the data the program got from the file.
*****************************************************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

const int NUM_MONTHS = 12;

const string MONTH_NAMES[NUM_MONTHS+1] = { "", "January", "Febuary", "March","April", "May", "June", "July", "August", "September", "October", "November","December" };

void buildSalesArray(double []);
void printSalesArray(double []);
double findSum(double []);
double findMean(double []);
int findLowMonth(double salesArray[]);
int findHighMonth(double salesArray[]);


/*****************************************************************************************************************
Function: main

Use:      The Boss function

Arguments: none

Returns:   int (returns 0)
*****************************************************************************************************************/

int main()
{
	double salesArray[NUM_MONTHS+1] = { 0 };

	buildSalesArray(salesArray);
	printSalesArray(salesArray);
	cout<<"\nThe total sales for the year : "<<findSum(salesArray)<<endl<<endl;
	cout<<"The average sales per month  : "<<findMean(salesArray)<<endl<<endl<<endl;

	int bestmonth=findHighMonth(salesArray);
	int worstmonth=findLowMonth(salesArray);
	cout<<"Best Month  : "<<MONTH_NAMES[bestmonth]<<endl;
	cout<<"Worst Month : "<<MONTH_NAMES[worstmonth]<<endl;
	

	_getch();
	return 0;
}


/*****************************************************************************************************************
Function: buildSalesArray

Use:      This function will accumulate sales data in the sales array from the text file

Arguments: double salesArray

Returns:   nothing
*****************************************************************************************************************/
void  buildSalesArray(double salesArray[])
{
	ifstream infile;
	ofstream outfile;
	int monthnumber;
	double saleamt;

	infile.open("sales.txt");
	if (infile.fail())
	{
		cout<<"sales.txt failed to open."<<endl;
	}

	infile>>monthnumber;
	while(infile)
		{
			infile>>saleamt;
			salesArray[monthnumber]=salesArray[monthnumber]+saleamt;
			infile>>monthnumber;
		}
	infile.close();

}


/*****************************************************************************************************************
Function: printSalesArray

Use:      This function will print the contents of elements 1 through 12 of the sales array. 
		  The total for each month should be preceded by the name of the month.

Arguments: double salesArray

Returns:   nothing
*****************************************************************************************************************/
void printSalesArray(double salesArray[])
{
	int i;
	cout<<"\t     SUMMARY"<<endl<<endl;
	for (i=1;i<13;i++)
	{
		cout<<setw(15)<<left<<MONTH_NAMES[i]<<" : "<<fixed<<setprecision(2)<<setw(15)<<right<<salesArray[i]<<endl;
	}
}


/*****************************************************************************************************************
Function: findSum

Use:      This function will calculate and return the sum of the numbers in 
	      elements 1 through 12 of the sales array.

Arguments: double salesArray

Returns:   the sum
*****************************************************************************************************************/

double findSum(double salesArray[])
{
	double sum=0;
	int i;
	for (i=1;i<13;i++)
	{
		sum=salesArray[i]+sum;
	}
	return sum;
}


/*****************************************************************************************************************
Function: findMean

Use:      This function will calculate and return the mean of the numbers in 
	      elements 1 through 12 of the sales array.

Arguments: double salesArray

Returns:   the mean
*****************************************************************************************************************/
double findMean(double salesArray[])
{
	double sum=findSum(salesArray);
	double mean=sum/12.0;
	return mean;
}


/*****************************************************************************************************************
Function: findLowMonth

Use:      This function will find and return the month number (subscript) of the lowest sales total 
		  in elements 1 through 12 of the sales array.

Arguments: double salesArray

Returns:   the subscript of the low month
*****************************************************************************************************************/
int findLowMonth(double salesArray[]) 
{
	int low=1;
	int i;
	for(i=2;i<=NUM_MONTHS;i++)
	{
		if(salesArray[i]<salesArray[low])
		{
			low=i;
		}
	}
	return low;
}


/*****************************************************************************************************************
Function: findHighMonth

Use:      This function will find and return the month number (subscript) of the highest sales total 
		  in elements 1 through 12 of the sales array.

Arguments: double salesArray

Returns:   the subscript of the high month
*****************************************************************************************************************/
int findHighMonth(double salesArray[])
{
	int high=1;
	int i;
	for (i=2;i<=NUM_MONTHS;i++)
	{
		if(salesArray[i]>salesArray[high])
		{
			high=i;
		}
	}
	return high;
}
