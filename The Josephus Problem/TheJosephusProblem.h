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


#ifndef PROG5_H
#define PROG5_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <conio.h>
#include <vector>
#include <algorithm> 

using namespace std;

const int No_Items=12; // const declaration for No_Items
const string Init_Val="A1"; // const declaration for Init_Val


void init_vals(vector <string>& v, unsigned& N, unsigned& M); 
void print_vector(const vector <string>& v, const unsigned& cnt); 


#endif
