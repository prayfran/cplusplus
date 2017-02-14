
#include "Calendar.h"
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){

Calendar c;
int y = 2013;
int m = 12;
int d = 31;
int h = 24;
int tm = 00;
string name2 = "New Year's Eve!";
try{
c.insert(y,m,d,h,tm,name2);
}catch(const char* ss){
	
}

try{
string s = "2000-7-4T0/PT24H Bicentennial";
c.insert(s);
}catch(double ss){
     
}

int ys = 2000;
int ms = 13;
int ds = 03;
int hs = 13;
int tms = 01;

string name2s = "CS156";
try{
c.insert(ys,ms,ds,hs,tms,name2s);
}catch(const char* ss){
		
}

for(int i =0; i< c.size(); i++){

cout<< c.events[i]<<endl;

}
Calendar b;
b|=c;

c.clear();
return 0;
}
