#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include "storage-place.h"
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
	StoragePlace storagePlace;
	string comment;
	string section, shelf, number;
	void storage_place_processing();
public:
	Product();
	void input();
	void output() const;
	StoragePlace getStoragePlace();
};

#endif
