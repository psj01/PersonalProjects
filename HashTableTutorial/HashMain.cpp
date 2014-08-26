#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>
#include "Hash.h"


int main()
{
	hash hashobj1;
	hashobj1.AddItem("jobin", "cocacola");
	hashobj1.AddItem("zac", "soda");
	hashobj1.AddItem("niboj", "rc cola");
	hashobj1.printtable();
	std::cout<<std::endl<<std::endl;
	hashobj1.finddrink("jobin");
	hashobj1.removeitem("niboj");
	hashobj1.removeitem("faet");
	_getch();
	return 0;
}
