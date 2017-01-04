#include "storage-place.h"

StoragePlace::StoragePlace(){

}

StoragePlace::StoragePlace(int section, int shelf, int number){
    this->section = section;
    this->shelf = shelf;
    this->number = number;
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
