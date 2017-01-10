#include "storage-controller.h"
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
    cout<<"Enter the name of the product you want to remove: ";
    string name;
    cin>>name;
    cout<<"Enter the quantity you want to remove: ";
    double quantity;
    cin>>quantity;
    storage.removeProduct(name, quantity);
}

void StorageController::listAvailableProducts(){
    storage.listAvailableProducts();
}

void StorageController::referenceDataRangeWork(){

}

void StorageController::clearOutdatedProducts(){

}

void StorageController::sortIt(){
    storage.sortByExpiryDate();
}
