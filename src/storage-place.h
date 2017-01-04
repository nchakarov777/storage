#include<iostream>
using namespace std;

#ifndef STORAGEPLACE_H
#define STORAGEPLACE_H

class StoragePlace
{
private:
    int section;
    int shelf;
    int number;

public:
    StoragePlace();
	StoragePlace(int section, int shelf, int number);
	int getSection();
	int getShelf();
	int getNumber();
};

#endif
