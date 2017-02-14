/*
Parker Franks
CS253 Problem Solving with C++
HW4: Calendar Class
March 24, 2014
*/

#include "Calendar.h"
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

//Default ctor creates an empty calendar.
Calendar::Calendar(){
events.clear();
}

//Copies a Calendar
Calendar::Calendar(const Calendar &){
this->s_year = s_year; 
this->s_month = s_month; 
this->s_day = s_day; 
this->s_hour = s_hour;
this->s_timespan = s_timespan;
this->name = name;
}

//Calendar Destructor 
Calendar::~Calendar(){}

//Sets the error messages for the different variables in an event stored in the Calendar
void Calendar::set_error(){
YearArg = "bad year: ";
MonthArg = "bad month: ";
DayArg = "bad day: ";
HourArg = "bad hour: ";
TimeSpanArg = "bad length: ";
EventArg = 2.71828;
}

//converts the different integer parts of an event into one 
//string pushes that string as an event on the back of the events vector then sorts.
void Calendar::string_to_int(){
	  string event;
	  stringstream ss;
	  ss << s_year;
	  string year = ss.str();
	  stringstream aa;
	  aa << s_month;
	  string month = aa.str();
	  stringstream dd;
	  dd << s_day;
	  string day = dd.str();
	  stringstream ff;
	  ff << s_hour;
	  string hour = ff.str();
	  stringstream gg;
	  gg << s_timespan;
	  string timespan = gg.str();
	
	
		if(timespan.length() == 1)
		{
		   timespan = "0" + timespan;
		}
		if(month.length() == 1)
		{
		   month = "0" + month;	
		}
		if(day.length() == 1)
		{
		   day = "0" + day;	
		}
		if(hour.length() == 1)
		{
		   hour = "0" + hour;	
		}
	
	  event = year + '-' + month + '-' + day + 'T'+ hour + "/PT" + timespan + 'H' + ' ' + name;
	  events.push_back(event);
          sort(events.begin(), events.end());
	  
}

//Checks the parts of the event for errors and checks for overlapping events than it calls the event creator string_to_int
bool Calendar::insert(int year, int mon, int day, int hour, int length_in_hours, const string &title){
	set_error();
	eventcount =0;
	
	if(validyear(year) == 0 |validmonth(mon) == 0 |validday(day)==0|validhour(hour) == 0 |validtimespan(length_in_hours) == 0)
	{
		cout << "wtf"<<endl;
		return 0;
	} 
	name = title;
	
	if(events.size() == 0)
	{ string_to_int();
	  
	}
	else{

	for(int i =0; i < events.size(); i++)
	{
	  validevent(events[i]);
	  eventcount =0;	
          if(s_year = year){
			
		      if(s_month = mon){
				
				if(s_day = day){
				  
					if(hour > s_hour && hour < (s_hour + s_timespan)){
						string_to_int();
					
						return true;
					}else{
					string_to_int();
					
					return false;	
					}
				}else{
				string_to_int();	
				
				return false;		
				}
			}else{
			string_to_int();
			
			return false;	
			}		
		}else{
		string_to_int();
		
		return false;
		}
	}

	}
	
	
	return 0;
	}



//Prints out the events for a calendar that calls this method
void Calendar::print(std::ostream &os) const{

	for(int i =0 ; i< this->events.size();i++){
	os <<this->events[i];
	}
	

}

//Breaks an event string into the interger parts and checks them for errors
bool Calendar::insert(const string &specification){
	eventcount =0;
	set_error();
	
	std::vector<string>::iterator it;
	const char* c = specification.c_str();

	sscanf(c, "%d-%d-%dT%d/PT%d", &t_year,&t_mon,&t_day,&t_hour,&t_timespan);
	
	if(validevent(specification)==0)
	{
		
		return 0;
	} 
	int n = specification.find("H");
	string title = specification.substr(n+1,n+1);
	name = title;
		
	if(events.size() == 0)
	{ 
	string_to_int();
	
	
	}
	else{

	for(int i =0; i < events.size(); i++)
	{
	  validevent(events[i]);
	  eventcount =0;
          if(s_year = t_year){

		      if(s_month = t_mon){
				
				if(s_day = t_day){
				  
					if(t_hour > s_hour && t_hour < (s_hour + s_timespan)){
						string_to_int();
					
						return true;
					}else{
					string_to_int();
				
					return false;	
					}
				}else{
				string_to_int();
				
				return false;		
				}
			}else{
			string_to_int();
			
			return false;	
			}		
		}else{
		string_to_int();
		
		return false;
		}
	}
	
	}
	
}

//returns the number of events in the calender that called it
int Calendar::size() const{
return this->events.size();
}

//clears the calendar of events
void Calendar::clear(){
this->events.clear();
}

//checks to see if the year given for a new event is valid
bool Calendar::validyear(int year){
	
	stringstream tt;
	tt << year;
	string t = tt.str();
	if(year > 2100){
		if(eventcount == 1)
		{
		return false;
		}else{
		string yearargg = YearArg + "The Year is greater than 2100 " + t;
		throw yearargg.c_str();
		return false;
		}
	}else if(year < 1900)
		{
		if(eventcount == 1)
		{
		return false;
		}else{
		string yearargl = YearArg + "The Year is less than 1900 " + t;
		throw yearargl.c_str();
		return false;
		}
	}else{
		s_year = year;
	        return true;
	}
		return false;
}

//checks to see if the month given for a new event is valid
bool Calendar::validmonth(int month)
{	
	stringstream tt;
	tt << month;
	string t = tt.str();
	if(month > 12){
		if(eventcount == 1)
		{
		return false;
		}else{
		string monthargg = MonthArg + "The Month is greater than 12 " + t;
		throw monthargg.c_str();		
		return false;
		}
	}else if(month < 1)
			{
		if(eventcount == 1)
		{
		return false;
		}else{
		string monthargl = MonthArg + "The Month is less than 1 " + t;
		throw monthargl.c_str();
		return false;
		}
	}else{
		s_month = month;
	        return true;
	}
		return false;
}

//checks to see if the day given for a new event is valid
bool Calendar::validday(int day)
{	
	bool leap;
	if (s_year % 400 == 0 || s_year % 4 == 0)
		leap = true;
	else if (s_year % 100 == 0)
		leap = false;
	stringstream tt;
	tt << day;
	string t = tt.str();
if(s_month == 1 | s_month == 3 | s_month == 5 | s_month == 7| s_month == 8| s_month == 10| s_month == 12){
	if(day > 31){
		if(eventcount ==1)
		{
		return false;
		}else{
		string dayargg = DayArg + "The Day is greater than 31 " + t;
		throw dayargg.c_str();
		return false;
		}
	}else if(day < 1)
			{
		string dayargl = DayArg + "The Day is less than 1 " + t;
		throw dayargl.c_str();
	}else{
		s_day = day;
	        return true;
	}

}else if(s_month == 4 | s_month == 6| s_month == 9| s_month == 11){
	if(day > 30){
		if(eventcount == 1)
		{
		return false;
		}else{
		string dayargg = DayArg + "The Day is greater than 30 " + t;
		throw dayargg.c_str();
		return false;
		}
	}else if(day < 1)
			{
		if(eventcount ==1)
		{
		return false;
		}else{
		string dayargl = DayArg + "The Day is less than 1 " + t;
		throw dayargl.c_str();
		return false;
		}
	}else{
		s_day = day;
	        return true;
	}
	}else{
	if(leap == false){
	if(day > 28){
		if(eventcount == 1)
		{
		return false;
		}else{
		string dayargg = DayArg + "The Day is greater than 28 " + t;
		throw dayargg.c_str();
		return false;
		}
	}else if(day < 1)
			{
		if(eventcount == 1)
		{
		return false;
		}else{
		string dayargl = DayArg + "The Day is less than 1 " + t;
		throw dayargl.c_str();
		return false;
		}
	}else{
		s_day = day;
	        return true;
	}
	}else if(leap == true){
	if(day > 29){
		if(eventcount == 1)
		{
		return false;
		}else{
		string dayargg = DayArg + "The Day is greater than 29 " + t;
		throw dayargg.c_str();
		return false;
		}
	}else if(day < 1)
			{
		if(eventcount == 1)
		{
		return false;
		}else{
		string dayargl = DayArg + "The Day is less than 1 " + t;
		throw dayargl.c_str();
		return false;
		}
	}else{
		s_day = day;
		
	        return true;
		}
	}
	}
		return false;
}

//checks to see if the hour given for a new event is valid
bool Calendar::validhour(int hour){
	
	stringstream tt;
	tt << hour;
	string t = tt.str();
	if(hour > 23){
		if(eventcount == 1)
		{
		 return false;	
		}else{
		string hourargg = HourArg + "The Hour is greater than 23 " + t;
		throw hourargg.c_str();
		return false;
		}
	}else if(hour < 0){
		if(eventcount == 1)
		{
		return false;
		}else{
		string hourargl = HourArg + "The Hour is less than 1 " + t;
		throw hourargl.c_str();
		return false;
		}
	}else{
		s_hour = hour;
		return true;
	}
		return false;
}

//checks to see if the timespan given for a new event is valid
bool Calendar::validtimespan(int timespan){

	stringstream tt;
	tt << timespan;
	string t = tt.str();
	if(s_hour + timespan > 24){
		if(eventcount == 1){
		return false;	
		}else{
		string timespanargg = TimeSpanArg + "The Length goes past midnight " + t;
		throw timespanargg.c_str();
		return false;
		}
	}else if(timespan < 0){
		if(eventcount == 1){
		return false;
		}else{
		string timespanargl = TimeSpanArg + "The Length can't be less than 0 " + t;
		throw timespanargl.c_str();

		return false;
		}
	}else{
		s_timespan = timespan;
		return true;
	}
	return false;
}

//checks to see if a new event is valid
bool Calendar::validevent(string event){
	eventcount = 1;
	const char* c = event.c_str();
	sscanf(c, "%d-%d-%dT%d/PT%d", &s_year,&s_month,&s_day,&s_hour,&s_timespan);

		if(validyear(s_year) == 0 | validmonth(s_month) == 0 |validday(s_day) == 0 |validhour(s_hour) == 0|validtimespan(s_timespan) ==0){
		
			throw EventArg;
			eventcount =0;
			return false;
		}
			eventcount = 0;
			return true;			
}

//combines and stores two calendars events into the calendar calling the operator
Calendar &Calendar::operator|=(const Calendar &rhs){
std::vector<std::string>::iterator it;
	it = this->events.begin();
	for(int i =0 ;i < rhs.events.size(); i++)
	{
	  it = this->events.insert(it, rhs.events[i]);
	}	
}

//changes the equals operator for a calendar so that the calendar calling it will change to the right hand side calendar
Calendar &Calendar::operator=(const Calendar &rhs){
	s_year = rhs.s_year; 
	s_month = rhs.s_month; 
	s_day = rhs.s_day; 
	s_hour = rhs.s_hour;
	s_timespan = rhs.s_timespan;
	name = rhs.name;
	events = rhs.events;
	return *this;
}

//basically made to compare two events
bool operator<(const string &lhs, const string &rhs){
return lhs.compare(rhs);
}

//returns a calendar that is the combination of the left hand side calendar and the right hand side calendar without changing either calendar
Calendar operator|(const Calendar &lhs, const Calendar &rhs){
	Calendar a = lhs;
	std::vector<std::string>::iterator it;
	it = a.events.begin();
	for(int i =0 ;i < rhs.events.size(); i++)
	{
	  it = a.events.insert(it, rhs.events[i]);

	}
	return a;

}
