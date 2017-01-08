#include "storage-place.h"

StoragePlace::StoragePlace(){

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
