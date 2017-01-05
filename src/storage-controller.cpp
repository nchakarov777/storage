#include "storage-controller.h"
#include <iostream>
#include "product.h"
#include "storage.h"

StorageController::addProduct(){
    Product newProduct;
    newProduct.input();
    storage.addProduct(newProduct);
}

StorageController::removeProduct(){

}
