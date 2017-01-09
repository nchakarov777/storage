#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
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
    void findNewPlaceAndAdd(Product, string, vector<Product>&);
    vector<Product> sortByExpiryDate(vector<Product>&);
    double getAllSize(vector<Product>&);
    bool compareDates(string, string) const;

public:
	Storage();
	void addProduct(Product);
	void listAvailableProducts();
    void removeProduct(string, double);
    void clearProducts();

};

#endif

