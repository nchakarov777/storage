#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include "product.h"

#ifndef STORAGE_H
#define STORAGE_H

class Storage
{
private:
    int storageSpace[10][10][10];
    bool availableSpace[10][10][10];
	map<string, vector<Product> > availableProducts;
    string getProductId(Product);
    StoragePlace getStoragePlace(string);

    /**
        Finds a new place for the given product.
        Product: the product
        string: the id of the product
        vector: the vector to which to add the product
        bool: to print feedback to the user
     */
    void findNewPlaceAndAdd(Product, string, vector<Product>&, bool);
    ///Sorts a given vector with products by their expiration date.
    void sortByExpiryDate(vector<Product>&);
    ///Getter for the quantity of given products.
    double getProductQuantity(vector<Product>&) const;
    ///Getter for the current date in the yyyy.mm.dd format.
    string getCurrentDate() const;

public:
	Storage();
	void addProduct(Product, bool);
	void listAvailableProducts();
    void removeProduct(string, double);
    void clearProducts();
    void clearOutdatedProducts();

};

#endif

