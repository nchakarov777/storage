#include "Storage.h"
#include "storage-place.h"
#include <stdlib.h>

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

void Storage::addProduct(Product product){
    if(1){

    }
}

StoragePlace Storage::getStoragePlace(string productId){
    map<string, Product>::iterator it = availableProducts.find(productId);
    Product product;
    if(it != availableProducts.end())
    {
        //element found;
        cout<<"namerih";
        product = it->second;
        return product.getStoragePlace();
    }
}
