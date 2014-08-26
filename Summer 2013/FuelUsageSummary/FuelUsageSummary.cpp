/****************************************************************************************************************
Purpose:	This program will accept fuel usage information from the user about a series of trips. 
			After each set of information (for one trip or fueling) is entered, summary information about 
			that trip will be displayed, and then the user will be asked if there is another set. Multiple 
			sets can be entered. 
			After the user has indicated there are no more sets, certain summary information about all the 
			trips will be displayed.
*****************************************************************************************************************/

#include <iostream>

#include <conio.h>

#include <cmath>

#include <string>

#include <iomanip>

using namespace std;

double getGallons();
double getMiles();
double getPricePerGallon();
double calcTripMilage(double miles, double gallons);
double calcTripCost(double PricePerGallon, double gallons);
double calcTripCostPerMile(double tripCost, double miles);
double calcOverallMPG(double totalMiles, double totalGallons);
void showOneTrip(double tripMileage, double tripCost, double tripCostPerMile);
void showTotals(double totalMiles, double totalGallons, double totalCost, double overallMPG);
void showMilageComparison(double overallMPG);

const double FLEET_AVERAGE = 25.00; // constant 

/*****************************************************************************************************************
Function: main

Use:      The Boss function

Arguments: none

Returns:   int (returns 0)
*****************************************************************************************************************/
int main()

{
	string ans;

	double totalMiles=0.0;
	double totalGallons=0.0;
	double totalCost=0.0;
	double overallMPG;

	
	cout<<"****************************************"<<endl;
	cout<<"*****                              *****"<<endl;
	cout<<"*****      Fuel Usage Analysis     *****"<<endl;
	cout<<"*****                              *****"<<endl;
	cout<<"****************************************"<<endl<<endl;
	
	do
	{

		double gallons=getGallons();
		double miles=getMiles();
		double PricePerGallon=getPricePerGallon();
		double TripMilage=calcTripMilage(miles,gallons);
		double TripCost=calcTripCost(PricePerGallon,gallons);
		double TripCostPerMile=calcTripCostPerMile(TripCost,miles);

		cout<<fixed;
		cout<<setprecision(2);

		showOneTrip(TripMilage, TripCost, TripCostPerMile);

		totalMiles=totalMiles+miles;
		totalGallons=totalGallons+gallons;
		totalCost=totalCost+TripCost;

		cout<<"Would you like to enter another trip information? (Y/N) : ";
		cin>>ans;

	}while(ans=="Y" || ans=="y"|| ans=="yes" || ans=="Yes" || ans=="YES");


	overallMPG=calcOverallMPG(totalMiles, totalGallons);
	showTotals(totalMiles, totalGallons, totalCost, overallMPG);
	showMilageComparison(overallMPG);

	cout<<"\n*****     Thank you!     *****"<<endl;
	
	

	_getch();
	return 0;
}

/*****************************************************************************************************************
Function: getGallons

Use:      Get gallons from the user

Arguments: none

Returns:   double [ the get gallons function returns the value of gallons thats entered by the user. ]
*****************************************************************************************************************/
double getGallons()
{
	double gallons;
	cout<<endl;
	cout<<"Please enter the number of Gallons : ";
	cin>>gallons;
	while(gallons>40.0 || gallons<0.0)
	{
		cout<<"Out of range: must be between 0 and 40 gallons. Re-enter : ";
		cin>>gallons;
	}
	return gallons;
}

/*****************************************************************************************************************
Function: getMiles

Use:      Get miles from the user

Arguments: none

Returns:   double [ the get miles function returns the value of miles thats entered by the user. ] 
*****************************************************************************************************************/
double getMiles()
{
	double miles;
	cout<<"Please enter the number of Miles : ";
	cin>>miles;
	while(miles >800.00 || miles <0.0)
	{
		cout<<"Out of range: must be between 0 and 800 miles. Re-enter : ";
		cin>>miles;
	}
	return miles;
}

/*****************************************************************************************************************
Function: getPricePerGallon

Use:      Get price per gallon from the user

Arguments: none

Returns:   double [ the get price per gallon function returns the price per gallon entered by the user. ] 
*****************************************************************************************************************/
double getPricePerGallon()
{
	double price;
	cout<<"Please enter the gas price per gallon : ";
	cin>>price;
	while(price>7 || price <2)
	{
		cout<<"Out of range: must be between 2 and 7 dollars. Re-enter : ";
		cin>>price;
	}
	return price;
}

/*****************************************************************************************************************
Function: calcTripMilage

Use:      Calculate the trip milage for the current trip

Arguments: double miles and double gallons

Returns:   double [This function will take the miles and gallons entered by the user and calculates and returns
		   the trip milage.]
*****************************************************************************************************************/
double calcTripMilage(double miles, double gallons)
{
	double TripMilage;
	if (gallons<=0)
	{
		TripMilage=0;
		return TripMilage;
	}
	else
	{
		TripMilage=miles/gallons;
		return TripMilage;
	}
}

/*****************************************************************************************************************
Function: calcTripCost

Use:      Calculate the trip cost for the current trip

Arguments: double price per gallon and double gallons

Returns:   double [This function will take the price per gallon and number of gallons and returns the trip 
		   cost for the trip.]
*****************************************************************************************************************/
double calcTripCost(double PricePerGallon, double gallons)
{
	return PricePerGallon*gallons;
}

/*****************************************************************************************************************
Function: calcTripCostPerMile

Use:      Calculate the trip cost per mile for the current trip

Arguments: double trip cost and double gallons

Returns:   double [ This function returns the cost per mile for the trip ]
*****************************************************************************************************************/
double calcTripCostPerMile(double TripCost, double miles)
{
	double TripCostPerMile;

	if (miles==0)
	{
		TripCostPerMile=0;
		return TripCostPerMile;
	}
	else
	{
		TripCostPerMile=TripCost/miles;
		return TripCostPerMile;
	}
}

/*****************************************************************************************************************
Function: calcOverallMPG

Use:      Calculate the overall milage for the users vechicle

Arguments: double total miles and double total gallons

Returns:   double [This function calculate and returns the overall milage of the user's vechicle. ]
*****************************************************************************************************************/
double calcOverallMPG(double totalMiles, double totalGallons)
{
	return totalMiles/totalGallons;
}

/*****************************************************************************************************************
Function: showOneTrip

Use:      Display the information on to the screen

Arguments: trip milage, trip cost and the trip cost per mile

Returns:   nothing [This function simply display information about the trip on the screen.  It returns nothing]
*****************************************************************************************************************/
void showOneTrip(double TripMilage, double TripCost, double TripCostPerMile)
{
	setw(6);
	cout<<fixed;
	cout<<setprecision(2);
	cout<<endl;
	cout<<"Trip Milage is     :  "<<setw(6)<<TripMilage<<" mpg"<<endl;
	cout<<"Trip cost is       : $"<<setw(6)<<TripCost<<endl;
	cout<<"Trip cost per mile : $"<<setw(6)<<setprecision(3)<<TripCostPerMile<<endl<<endl;
}

/*****************************************************************************************************************
Function: showTotals

Use:      Display the information on to the screen

Arguments: total miles, total gallons, total cost and the overall MPG

Returns:   nothing [This function displays information about all the trips on the screen.  It returns nothing]
*****************************************************************************************************************/
void showTotals(double totalMiles, double totalGallons, double totalCost, double overallMPG)
{
	cout<<endl;
	cout<<fixed;
	cout<<setprecision(2);
	cout<<"Total Miles   :  "<<setw(6)<<totalMiles<<endl;
	cout<<"Total Gallons :  "<<setw(6)<<totalGallons<<endl;
	cout<<"Total Cost    : $"<<setw(6)<<totalCost<<endl;
	cout<<"Overall MPG   :  "<<setw(6)<<overallMPG<<endl<<endl;
}

/*****************************************************************************************************************
Function: showMilageComparison

Use:      Display the difference between overall milage and the fleet average

Arguments: overall MPG

Returns:   nothing [ This function simply displays the difference in your overall milage from the fleet average.
		   It doesn't return any value. ]
*****************************************************************************************************************/
void showMilageComparison(double overallMPG)
{
	double overallMPGdiff;
	overallMPGdiff=overallMPG-FLEET_AVERAGE;
	if (overallMPGdiff>0)
	{
		cout<<"Your vehicle's mileage is greater than fleet average by "<<overallMPGdiff<<" mpg."<<endl;
	}
	else if (overallMPGdiff<0)
	{
		overallMPGdiff=overallMPGdiff*(-1);
		cout<<"Your vehicle's mileage is less than fleet average by "<<overallMPGdiff<<" mpg."<<endl;
	}
	else
	{
		cout<<"Your vehicle's mileage is the same as the fleet average."<<endl;
	}
}
