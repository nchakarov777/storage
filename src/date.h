#include<iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int day;
    int month;
    int year;

public:

	int getDay();
	int getMonth();
	int getYear();
};

#endif
