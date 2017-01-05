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
	string productName;
	string expDate; // dd.mm.yyyy format
	string entryDate; // dd.mm.yyyy format
	string producerName;
	string unit;
	double quantity;
	string ispInput; //sektsiq/raft/nomer format
	StoragePlace storagePlace;
	string comment;
	string section, shelf, number;
	void storage_place_processing();
	bool isValid(string);
public:
	Product();
	void input();
	void output() const;
	StoragePlace getStoragePlace();
};

#endif
