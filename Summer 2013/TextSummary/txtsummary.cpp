/*************************************************************************************************************
Purpose:	This program will reads characters from a file that you have opened for input. It will count several 
			categories of characters (vowels, digits, etc. etc.) and present summary totals after it has read 
			the input file along with the input file itself.
*****************************************************************************************************************/

#include <iostream>

#include <conio.h>

#include <iomanip>

#include <fstream>

bool isVowel(char ch);

bool isConsonant(char ch);

using namespace std;

int main()
{
	char ch;
	int vowel=0,
		consonant=0,
		letter=0,
		digit=0,
		character=0,
		lparenthesis=0,
		rparenthesis=0,
		squote=0,
		dquote=0,
		other=0;

	ifstream infile;
	ofstream outfile;

	infile.open("hopper.txt");

	if (infile.fail())
	{
		cout<<"hopper.txt failed to open."<<endl;
	}

	else
	{
		infile.get(ch);
		while (infile)
		{
		   cout << ch;

		   if (isalpha(ch)||isdigit(ch))
		   {

			   if (isalpha(ch))
			   {
				   letter++;
				   character++;
			   }
			   if (isdigit(ch))
			   {
				   digit++;
				   character++;
			   }
			   if (isVowel(ch))
			   {
				   vowel++;
			   }
			   if (isConsonant(ch))
			   {
				   consonant++;
			   }
		   }

		   else
		   {
			   switch (ch)
			   {
			   case '(':
					 {
						 lparenthesis++;
						 character++;
						 break;
					 }
			   case ')' :
					{
						rparenthesis++;
						character++;
						break;
					}
			   case '"':
				   {
					   dquote++;
					   character++;
					   break;
				   }
			   case '\'':
				   {
					   squote++;
					   character++;
					   break;
				   }
			   default :
				   {
					   other++;
					   character++;
				   }
			   }
		   }

		   infile.get(ch);
		}

		cout<<endl<<endl;
		cout<<"\tSUMMARY\n"<<endl;

		if(vowel+consonant==letter)
		{
			cout<<"Total Characters  : "<<setw(2)<<character<<endl;
			cout<<"Vowels            : "<<setw(2)<<vowel<<endl;
			cout<<"Consonant         : "<<setw(2)<<consonant<<endl;
			cout<<"Letter            : "<<setw(2)<<letter<<endl;
			cout<<"Digits            : "<<setw(2)<<digit<<endl;
			cout<<"Left Parenthesis  : "<<setw(2)<<lparenthesis<<endl;
			cout<<"Right Parenthesis : "<<setw(2)<<rparenthesis<<endl;
			cout<<"Single Quotes     : "<<setw(2)<<squote<<endl;
			cout<<"Double Quotes     : "<<setw(2)<<dquote<<endl;
			cout<<"Others            : "<<setw(2)<<other<<endl;
		}
		else
		{
			cout<<"WARNING!"<<endl;
		}
	}

	infile.close();

	_getch();
	return 0;
}


bool isVowel(char ch)
{
	if (toupper(ch)=='A'||toupper(ch)=='E'||toupper(ch)=='I'||toupper(ch)=='O'||toupper(ch)=='U')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isConsonant(char ch)
{
	if (isalpha(ch))
	{

		if (!(isVowel(ch)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else 
	{
		return false;
	}
}