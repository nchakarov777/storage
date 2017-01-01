#include<iostream>
#include<string>
using namespace std;

#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
private:
	string product_name;
	string exp_date; // dd/mm/yyyy format
	string entry_date; // dd/mm/yyyy format
	string producer_name;
	string unit;
	double quantity;
	string in_storage_place //sektsiq.raft.nomer format
	string comment;
public:
	Product();
	void input();
	void output() const;

};

#endif
