#include <iostream>

#include <conio.h>

using namespace std;


void fillTable(int table[4][25]);


void displayTable(int table[4][25]);


int selection_sort(int numbers[], int size);


int main()
{
	
	int mins[4][25]; //creates a 4*25 matrix which will store the mins it will take for each job.
	
	fillTable(mins); // fill the matrix
	
	displayTable(mins);


	int m1jobs[25]={0};
	int m2jobs[25]={0};
	int m3jobs[25]={0};
	int m4jobs[25]={0};

	cout<<endl<<endl;
	cout<<"Enter jobs in order for machine #1"<<endl;
	cout<<"Job number should be between 1 and 25."<<endl;
	for(int i=0;i<25;i++)
	{
		
		int input;
		cout<<"Job #:"<<i+1<<" : ";
		cin>>input;
		while(input<0 || input>25)
		{
			cout<<"Error! Enter a valid job number."<<endl;
			cout<<"Job #:"<<i+1<<" : ";
			cin>>input;
		}
		if(input==0)
		{
			break;
		}
		m1jobs[i]=input;
		
	}
	
	cout<<endl<<endl;
	cout<<"Enter jobs in order for machine #2"<<endl;
	cout<<"Job number should be between 1 and 25."<<endl;
	for(int i=0;i<25;i++)
	{
		int input;
		cout<<"Job #:"<<i+1<<" : ";
		cin>>input;
		while(input<0 || input>25)
		{
			cout<<"Error! Enter a valid job number."<<endl;
			cout<<"Job #:"<<i+1<<" : ";
			cin>>input;
		}
		if(input==0)
		{
			break;
		}
		m2jobs[i]=input;
	}


	cout<<endl<<endl;
	cout<<"Enter jobs in order for machine #3"<<endl;
	cout<<"Job number should be between 1 and 25."<<endl;
	for(int i=0;i<25;i++)
	{
		int input;
		cout<<"Job #:"<<i+1<<" : ";
		cin>>input;
		while(input<0 || input>25)
		{
			cout<<"Error! Enter a valid job number."<<endl;
			cout<<"Job #:"<<i+1<<" : ";
			cin>>input;
		}
		if(input==0)
		{
			break;
		}
		m3jobs[i]=input;
	}


	cout<<endl<<endl;
	cout<<"Enter jobs in order for machine #4"<<endl;
	cout<<"Job number should be between 1 and 25."<<endl;
	for(int i=0;i<25;i++)
	{
		int input;
		cout<<"Job #:"<<i+1<<" : ";
		cin>>input;
		while(input<0 || input>25)
		{
			cout<<"Error! Enter a valid job number."<<endl;
			cout<<"Job #:"<<i+1<<" : ";
			cin>>input;
		}
		if(input==0)
		{
			break;
		}
		m4jobs[i]=input;
	}

	//----------------------------------------------------------------



	cout<<endl<<endl;
	int sum=0;
	int b=0;
	while(m1jobs[b]!=0)
	{
		int a=m1jobs[b];
		sum=sum+mins[0][a-1];
		b++;
	}
	cout<<"Total time for M1 is : "<<sum<<" mins."<<endl;
	int m1sum=sum;

	sum=0;
	b=0;
	while(m2jobs[b]!=0)
	{
		int a=m2jobs[b];
		sum=sum+mins[1][a-1];
		b++;
	}
	cout<<"Total time for M2 is : "<<sum<<" mins."<<endl;
	int m2sum=sum;


	sum=0;
	b=0;
	while(m3jobs[b]!=0)
	{
		int a=m3jobs[b];
		sum=sum+mins[2][a-1];
		b++;
	}
	cout<<"Total time for M3 is : "<<sum<<" mins."<<endl;
	int m3sum=sum;


	sum=0;
	b=0;
	while(m4jobs[b]!=0)
	{
		int a=m4jobs[b];
		sum=sum+mins[3][a-1];
		b++;
	}
	cout<<"Total time for M4 is : "<<sum<<" mins."<<endl;
	int m4sum=sum;
	
	int totalminsums[4];

	totalminsums[0]=m1sum;
	totalminsums[1]=m2sum;
	totalminsums[2]=m3sum;
	totalminsums[3]=m4sum;

	int abc=selection_sort(totalminsums, 4);

	cout<<endl<<endl;

	//-----------------------------------------------


	//now find m1 unfinished jobs
	int sum1=0;
	int b1=0;
	
	while(sum1<totalminsums[abc])
	{
		sum1=sum1+mins[0][m1jobs[b1]];
		b1++;
	}
	if(sum1!=totalminsums[abc])
	{
		cout<<endl;
		cout<<"m1 unfinished jobs are : ";
		while(m1jobs[b1]!=0)
		{
			cout<<m1jobs[b1]<<"  ";
			b1++;
		}
	}
	

	//-----------------------------------------------


	//now find m2 unfinished jobs
	int sum2=0;
	int b2=0;
	while(sum2<totalminsums[abc])
	{
		sum2=sum2+mins[0][m2jobs[b2]];
		b2++;
	}
	if(sum2!=totalminsums[abc])
	{
		cout<<endl;
		cout<<"m2 unfinished jobs are : ";
		while(m2jobs[b2]!=0)
		{
			cout<<m2jobs[b2]<<"  ";
			b2++;
		}
	}

	//-----------------------------------------------


	//now find m3 unfinished jobs
	int sum3=0;
	int b3=0;
	while(sum3<totalminsums[abc])
	{
		sum3=sum3+mins[0][m3jobs[b3]];
		b3++;
	}
	if(sum3!=totalminsums[abc])
	{
		cout<<endl;
		cout<<"m3 unfinished jobs are : ";
		while(m3jobs[b3]!=0)
		{
			cout<<m3jobs[b3]<<"  ";
			b3++;
		}
	}

	//-----------------------------------------------


	//now find m4 unfinished jobs
	int sum4=0;
	int b4=0;
	while(sum4<totalminsums[abc])
	{
		sum4=sum4+mins[0][m4jobs[b4]];
		b4++;
	}
	if(sum4!=totalminsums[abc])
	{
		cout<<endl;
		cout<<"m4 unfinished jobs are : ";
		while(m4jobs[b4]!=0)
		{
			cout<<m4jobs[b4]<<"  ";
			b4++;
		}
	}


	
	cout<<endl<<endl;
	_getch();
	return 0;
}


void fillTable(int table[4][25])
{
    for(int i = 0; i < 4; i++) { 
        for(int c = 0; c < 25; c++) { 
            table[i][c] = rand() % 120 + 10;
        }
    }
}


void displayTable(int table[4][25]) {
    for (int i = 0; i < 4; i++) {
		cout<<endl<<"Machine #"<<i+1<<endl<<endl;
        for ( int j = 0; j < 25; j++) {
            cout <<"     "<<table[i][j]<<"     ";
        }
    }
}


int selection_sort(int numbers[], int size)
{
	int a=1;
	int smallest = numbers[0];
	for(int i=1;i<size;i++)
	{
		if(numbers[i]<smallest)
		{
			//smallest=numbers[i];
			a=i;
		}
	}
	return a;
}