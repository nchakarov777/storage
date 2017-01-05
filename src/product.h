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
	// dd.mm.yyyy format
	string expDate;
	string entryDate;
	string producerName;
	string unit;
	double quantity;
	StoragePlace storagePlace;
	string comment;
	bool isValid(string);
public:
	Product();
	void input();
	void output();
	StoragePlace getStoragePlace();
	string getProductName();
	string getExpDate();
	double getQuantity();
	void setStoragePlace(int, int, int);

};

#endif
