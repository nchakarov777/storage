#include "Storage.h"
#include "storage-place.h"
#include <stdlib.h>
#include <map>
#include <vector>

Storage::Storage(){
    for(int i = 0; i<10;i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                int volume = rand()%100 +10;
                if(volume % 5 == 0){
                    storageSpace[i][j][k] = -1;
                }else{
                    storageSpace[i][j][k] = volume;
                }
            }
        }
    }
}

string Storage::getProductId(Product product){
    string id = product.getProductName();
    id+="/";
    id+=product.getExpDate();
    return id;
}

bool Storage::findNewPlaceAndAdd(Product product, string id){
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            for(int k =0; k<10;k++){
                if(!availableSpace[i][j][k]){
                    if(storageSpace[i][j][k] >= product.getQuantity()){
                        product.setStoragePlace(i, j, k);
                        vector<Product> newVector;
                        newVector.push_back(product);
                        availableProducts.insert(pair<string, vector<Product>>(id, newVector));
                        availableSpace[i][j][k] = true;
                        storageSpace[i][j][k] -= product.getQuantity();
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Storage::addProduct(Product product){
    string id = getProductId(product);
    map<string, vector<Product>>::iterator it = availableProducts.find(id);
    vector<Product> products;
    if(it != availableProducts.end())
    {
        cout<<id<<endl;
        products = it->second;
        for (unsigned i=0; i < products.size(); i++) {
            products[i].output();
        }
    }else{
        if(findNewPlaceAndAdd(product, id)){
            cout<<"Your product was successfully stored. "<<endl;
        }else{
            cout<<"Sorry, either the storage is full, or the quantity you are trying to add is too big."<<endl;
        }
    }
}




