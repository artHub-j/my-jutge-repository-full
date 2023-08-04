/*Write a function that returns the absolute value of an integer n.*/

#include<iostream>
using namespace std;
int absolute(int n);

int absolute(int n){

	if(n<0){

		return -(n);
	}
	else return n;

}
