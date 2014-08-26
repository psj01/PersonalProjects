/***********************************************************************
Purpose: This program prompts the user to enter the lengths for 
		 the three sides of a triangle and the program will calculate the 
		 perimeter and area of the triangle, assuming the user enter valid 
		 lenghts for a triangle.
***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <conio.h>

using namespace std;

int main()
{
	    /*****************************************************************

		A		= length of side A
		B		= length of side B
		C		= length of side C
		P		= Perimeter of the triangle
		Phalf	= (Perimeter of the triangle) / 2
		Area	= Area of the triangle
		S		= (phalf)*(phalf-A)*(phalf-B)*(phalf-C)
		ans		= User's response for if they want to continue or not

		*****************************************************************/

	char ans;
	do
	{
		double  A,
				B,
				C,
				P,
				Phalf,
				Area,
				S;

		cout<<"\n***** Welcome! *****"<<endl<<endl;
		cout<<"         *          "<<endl;
		cout<<"        ***         "<<endl;
		cout<<"       *****        "<<endl;
		cout<<"      *******       "<<endl<<endl;

		cout<<"This program will calculate the perimeter and the area "
			<<"of \nany triangle given the lengths for all three sides (A, B & C)."<<endl<<endl;

		cout<<"Please enter length of side A : ";
		cin>>A;
		cout<<"Please enter length of side B : ";
		cin>>B;
		cout<<"Please enter length of side C : ";
		cin>>C;

		P=A+B+C;
		Phalf=P/2.0;
		S=(Phalf)*(Phalf-A)*(Phalf-B)*(Phalf-C);

		if(S>0)
		{
			std::cout<<std::fixed;
			std::cout<<std::setprecision(2);
			Area=sqrt(S);
			cout<<"\nThe perimeter of the triangle is : "<<setw(6)<<P<<endl;
			cout<<"The area of the triangle is      : "<<setw(6)<<Area<<endl<<endl;
			cout<<"\n***** Thank you! *****"<<endl;
		}
		else
		{
			cout<<"\nSorry you've entered invalid lenghts for a triangle."<<endl;
		}
		
		cout<<"\nWould you like to start over? (Y/N) : ";
		cin>>ans;
	}while(ans=='Y'||ans=='y');

	cout<<"Good Bye!"<<endl;
	_getch();
	return 0;
}