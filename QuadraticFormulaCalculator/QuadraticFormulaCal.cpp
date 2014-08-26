#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

int main()
{
	double A,B,C;
	char ans;
	do
	{

		cout<<"\n\t\t>>>>> Welcome <<<<<"<<endl<<endl;

		cout<<"Quadratic equation in the form : Ax^2 + Bx + C "<<endl;

		cout<<"\n\nPlease enter values for A, B and C below : "<<endl<<endl;
		cout<<"Enter A : ";
		cin>>A;
		cout<<"Enter B : ";
		cin>>B;
		cout<<"Enter C : ";
		cin>>C;

		double undersqrt;

		undersqrt=(B*B - 4*A*C);

		if(undersqrt>0)
		{
			double ans1, ans2;

			ans1=(-B + sqrt(undersqrt))/2*A;
		
			ans2=(-B - sqrt(undersqrt))/2*A;

			cout<<"\nSolutions/Roots are : "<<endl<<endl;
			cout<<"x is : "<<ans1<<" or "<<ans2<<endl<<endl;
		}
		else
		{
			cout<<endl;
			cout<<"No Solutions!"<<endl<<endl;
		}
		cout<<"\n\nWould you like to try again? (Y/N) : ";
		cin>>ans;

	}while(ans=='Y'||ans=='y');

	_getch();
	return 0;
}




