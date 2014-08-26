/*******************************************************************
Purpose: This program prompts the user to enter a food/drink total
         and then calculates and displays the tip, the tax, and the 
         total bill.
********************************************************************/

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
	double bill,tip,total,tax;

	cout<<"******************************"<<endl;
	cout<<"**********          **********"<<endl;
	cout<<"********** Welcome! **********"<<endl;
	cout<<"**********          **********"<<endl;
	cout<<"******************************"<<endl<<endl;
	
	cout<<"Please enter the restaurent bill : ";
	cin>>bill;
	cout<<endl;
	
	tip=bill*.15;
	tax=bill*.10;
	total=bill+tip+tax;



	cout<<fixed;
	cout<<setprecision(2);
	
	cout<<"You entered : "<<bill<<endl;
	
	cout<<"***************************************************"<<endl;
	cout<<"***************************************************"<<endl;
	cout<<"*               Tip amount is    : $"<<setw(10)<<tip<<"    *"<<endl;
	cout<<"*               Tax amount is    : $"<<setw(10)<<tax<<"    *"<<endl;
	cout<<"*               Total amount due : $"<<setw(10)<<total<<"    *"<<endl;
	cout<<"***************************************************"<<endl;
	cout<<"***************************************************"<<endl<<endl;
	
	
	cout<<"Thank you!"<<endl;
	_getch(); 
	return 0;
}