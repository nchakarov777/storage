#include "storage-place.h"

StoragePlace::StoragePlace(){
    section = 0;
    shelf = 0;
    number = 0;
}

StoragePlace::StoragePlace(int se, int sh, int nu){
    section = se;
    shelf = sh;
    number = nu;
}


int StoragePlace::getNumber(){
    return number;
}

int StoragePlace::getShelf(){
    return shelf;
}

int StoragePlace::getSection(){
    return section;
}

void StoragePlace::setNumber(int number){
    this->number = number;
}

void StoragePlace::setShelf(int shelf){
    this->shelf = shelf;
}

void StoragePlace::setSection(int section){
    this->section = section;
}
