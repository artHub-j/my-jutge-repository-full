/*Write a program that, given a time expressed in hours, minutes and seconds, computes the time corresponding to add one second, and also the time corresponding to subtract one second.

Your program must use the definition

     struct Time {
         int hour, minute, second;
     };
and it must implement and use the precedure

     void one_second(const Time& t, Time& t1, Time& t2);
that leaves in t1 the time in t plus one second, and leaves in t2 the time in t minus one second. For instance, if t has 23 59 59, then t1 must be 0 0 0 and t2 must be 23 59 58.

Input
-------
Input consists of several cases, each with three numbers (hour, minute and second) that form a correct time. That is, the hour is between 0 and 23, and the minute and the second are between
0 and 59.

Output
-------
For every given time t, print two lines with t1 and t2.

Observation

You can implement auxiliary procedures.*/

#include<iostream>

using namespace std;

struct Time {
int hour, minute, second;
};

void one_second(const Time& t, Time& t1, Time& t2){
	
	t1.second = t.second + 1;
	t1.minute = t.minute;
	t1.hour = t.hour;
	
	if(t1.second == 60){
		t1.second = 0;
		t1.minute = t1.minute + 1;
		
		if(t1.minute == 60){
			t1.minute = 0;
			t1.hour = t1.hour +1;
		}
		if(t1.hour == 24) t1.hour = 0;
	}
	
	t2.second = t.second - 1;
	t2.minute = t.minute;
	t2.hour = t.hour;
	
	if(t2. second == -1){
		t2.second = 59;
		t2.minute = t2.minute - 1;
		
		if(t2.minute == -1){
			t2.minute = 59;
			t2.hour = t2.hour - 1;
		}
		if(t2.hour == -1) t2.hour = 23;
	} 
	
}

int main(){
	
	Time t, t1, t2; 
	
	while(cin>>t.hour>>t.minute>>t.second){
		
		one_second(t, t1, t2);
		
		cout<<t1.hour<<" "<<t1.minute<<" "<<t1.second<<endl;
		cout<<t2.hour<<" "<<t2.minute<<" "<<t2.second<<endl; 
	}
	
}

