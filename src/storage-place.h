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
	StoragePlace(int, int, int);
	int getSection();
	int getShelf();
	int getNumber();
	void setSection(int);
	void setShelf(int);
	void setNumber(int);
};

#endif
