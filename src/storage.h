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
    bool availableSpace[10][10][10];
	map<string, vector<Product>> availableProducts;
    string getProductId(Product product);
    StoragePlace getStoragePlace(string productId);

public:
	Storage();
	void addProduct(Product);
	void printAvailableProducts();
    void removeProducts();
    void clearProducts();
    bool findNewPlaceAndAdd(Product product, string id);
};

#endif

