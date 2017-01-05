#include "storage-controller.h"
#include <iostream>
#include "product.h"
#include "storage.h"

StorageController::StorageController(){

}

void StorageController::addProduct(){
    Product newProduct;
    newProduct.input();
    storage.addProduct(newProduct);
}

void StorageController::removeProduct(){

}

void StorageController::listAvailableProducts(){

}

void StorageController::referenceDataRangeWork(){

}

void StorageController::clearOutdatedProducts(){

}
