#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	
	char ans1;
	
	do
	{
		long int num;
		cout<<"\n\nEnter your integer : ";
		cin>>num;
		int digits=1;
		while( (num/10)!=0 )
		{
			num=num/10;
			digits++;
		}
		cout<<"\n# of digits digits : "<<digits<<endl;
		cout<<"\nWould you like to start over? (Y/N) : ";
		cin>>ans1;	
	}while(ans1=='Y'||ans1=='y');

	cout<<"\nBye - press any key to exit."<<endl;
	_getch();
	return 0;
}
		

