#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
private:
	string product_name;
	string exp_date; // dd.mm.yyyy format
	string entry_date; // dd.mm.yyyy format
	string producer_name;
	string unit;
	double quantity;
	string isp_input; //sektsiq/raft/nomer format
	string comment;
	string section, shelf, number;
	void storage_place_processing();
public:
	Product();
	void input();
	void output() const;
};

#endif
