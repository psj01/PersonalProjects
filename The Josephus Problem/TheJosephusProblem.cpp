/***************************************************************************************************

								The Josephus Problem

The problem is known as the Josephus problem and postulates a group of soldiers of size 
N surrounded by an overwhelming enemy force. There is no hope for victory without 
reinforcements, but there is only a single horse available for escape. The soldiers agree to 
a pact to determine which of them is to escape and summon help. They form a circle and 
a number M is picked from a hat. One of their names is also picked from a hat. Beginning 
with the soldier whose name is picked, they begin to count clockwise around the circle. 
When the count reaches M, that soldier is removed from the circle, and the count begins 
again with the next soldier. The process continues so that each time the count reaches M, 
another soldier is removed from the circle. Any soldier removed from the circle is no 
longer counted. The last soldier remaining is to take the horse and escape. The problem 
is, given a number M, the ordering of the soldiers in the circle, and the soldier from whom 
the count begins, to determine the order in which soldiers are eliminated from the circle 
and which soldier escapes.


******************************************************************************************************/

#include "TheJosephusProblem.h"

/**************************************************************************************************************************************************

Object : SEQ

NOTES : This object class is used to store the names of the soliders.  

**************************************************************************************************************************************************/
class SEQ 
{ 

	private: 
	 string id; // name of soldier 

	public: 
	 SEQ ( const string& x = Init_Val) : id ( x ) { } // default constructor 

	 string operator ( ) ( )
	 { // overloaded function operator 
		 string tmp = id; 
		 if ( id [ 1 ] < '9' )
		 {
				 id [ 1 ]++;
		 }
		 else
		 {
			 id [ 0 ]++;
			 id [ 1 ] = '1';
		 } 

		 return tmp; // return next name in order 
	 } 
}; 

/**************************************************************************************************************************************************

FUNCTION : main()

NOTES : The main function for the program. main function includes the calls to the subroutine functions. main calls init_vals function to
read in the values of N and M and it also fills in the soldier names in vector V.

**************************************************************************************************************************************************/
int main()
{
	
	unsigned int x,y;
	vector<string> v;
	char ans;
	do
	{
		cout<<"\t\t\tThe Josephus Problem"<<endl<<endl;
		
cout<<"The problem is known as the Josephus problem and postulates a group of soldiers of size"
	<<" N surrounded by an overwhelming enemy force. There is no hope for \nvictory without"
	<<" reinforcements, but there is only a single horse available for  escape. The soldiers agree to"
	<<" a pact to determine which of them is to escape \nand summon help. \n\nThey form a circle and"
	<<" a number M is picked from a hat. One of their names is \nalso picked from a hat. Beginning"
	<<" with the soldier whose name is picked, they \nbegin to count clockwise around the circle."
	<<" \n\nWhen the count reaches M, that soldier is removed from the circle, and the \ncount begins "
	<<" again with the next soldier. The process continues so that each \ntime the count reaches M,"
	<<" another soldier is removed from the circle. Any \nsoldier removed from the circle is no"
	<<" longer counted. The last soldier \nremaining is to take the horse and escape. \n\nThe problem"
	<<" is, given a number M, the ordering of the soldiers in the circle, \nand the soldier from whom" 
	<<" the count begins, to determine the order in which \nsoldiers are eliminated from the circle"
	<<" and which soldier escapes."<<endl<<endl<<endl;


		init_vals(v,x,y); //calling init_vals function

		cout<<"\nNumber of people : "<<x<<endl;
		cout<<"Index for elimination : "<<y<<endl;

		cout<<"\nInitial group of people"<<endl;
		print_vector(v,x); //calling print_vector function

		cout<<endl<<endl;
	
		int cnt=0;
		int temp=x;
		int inival=0;
		while(cnt!=temp-1)
		{
			inival=(inival+y-1)%v.size();
			v.erase(v.begin()+inival);
			x--;
			cout<<"After elimination round No. "<<cnt+1<<endl<<endl; 
			print_vector(v,x);
			cout<<endl<<endl;
			cnt++;
		}

		cout<<"Restart ? (Y/N) : ";
		cin>>ans;
	
	}while(ans=='y'||ans=='Y');

	cout<<"\n\nBye! --press any key to exit."<<endl;

	_getch();
	return 0;
}

/**************************************************************************************************************************************************

FUNCTION : init_vals()

NOTES : This routine reads the values of N and M when the program prompts for prints out those values on stdout. 
		It also fills in the soldier names in vector v

**************************************************************************************************************************************************/
void init_vals(vector <string>& v, unsigned& N, unsigned& M)
{
	cout<<"Enter total number of soldiers (N) : ";
	cin>>N;
	cout<<"Enter the lucky number (M) : ";
	cin>>M;

	v.resize(N);
	SEQ names;
	generate(v.begin(),v.end(), names); //storing the soldier names in names

}


/**************************************************************************************************************************************************

FUNCTION : print_vector

NOTES : This routine prints out the contents of vector v at start and after removing a name from the vector until only one name remains 
		in the vector, where cnt has an initial value of 0 and simply indicates the total number of removals so far.   
		It prints only 12 names on a single line where the names are seperated by single spaces.

**************************************************************************************************************************************************/
void print_vector(const vector <string>& v, const unsigned& cnt)
{
	int No_ItemsPerLine=0;
	for(int i=0;i<cnt;i++)
	{
		if(No_ItemsPerLine!=No_Items)
		{
			cout<<" "<<v[i]<<" ";
			No_ItemsPerLine++;
		}
		else
		{
			cout<<endl<<" "<<v[i]<<" ";
			No_ItemsPerLine=1;
		}
	}
}