#include<iostream>
using namespace std;
#include "storage.h";

#ifndef STORAGECONTROLLER_H
#define STORAGECONTROLLER_H

class StorageController
{
private:
    Storage storage;


public:
    StorageController();
	void addProduct();
	void removeProduct();
	void clearOutdatedProducts();
	void listAvailableProducts();
	void referenceDataRangeWork();
};

#endif
