/*
Parker Franks
CS253 Problem Solving with C++
HW4: Calendar Class
March 24, 2014
*/
#ifndef Calendar_h_included
#define Calendar_h_included

#include <string.h>
#include <string>
#include <vector>
#include "CalendarBase.h"
class Calendar : public CalendarBase {
public:

Calendar();
Calendar(const Calendar &);
~Calendar();
bool insert(int year, int mon, int day, int hour, int length_in_hours, const std::string &title);
virtual void print(std::ostream &os) const;
bool insert(const std::string &specification);
int size() const;
void clear();
Calendar &operator|=(const Calendar &rhs);
Calendar &operator=(const Calendar &rhs);
bool validyear(int year);
bool validmonth(int month);
bool validday(int day);
bool validhour(int hour);
bool validtimespan(int timespan);
bool validevent(std::string event);
void set_error();
void string_to_int();
std::vector<std::string> events;

private:

std::string YearArg;
std::string MonthArg;
std::string DayArg;
std::string HourArg;
std::string TimeSpanArg;
double EventArg;
int s_year, s_month, s_day, s_hour ,s_timespan;
int t_year;
int t_mon;
int t_day;
int t_hour;
int t_length_in_hours;
int t_timespan;
int eventcount;
std::string name;


};
bool operator<(const std::string &lhs, const std::string &rhs);
Calendar operator|(const Calendar &lhs, const Calendar &rhs);

#endif /* PNum_h_included */
