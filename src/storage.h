#include<iostream>
#include<map>
#include<vector>
using namespace std;

#include "Product.h"

#ifndef STORAGE_H
#define STORAGE_H

class Storage
{
private:

    int storageSpace[10][10][10];
	map<string, Product> availableProducts;
    string getProcuctId(Product);
    string getProcuctPlaceId(Product);
    StoragePlace getStoragePlace(string productId);

public:
	Storage();
	void addProduct(Product product);
	void printAvailableProducts();
    void removeProducts();
    void clearProducts();
};

#endif

