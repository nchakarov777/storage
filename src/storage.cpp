#include "Storage.h"
#include "storage-place.h"

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
    for(int i = 0; i<10;i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++)
                availableSpace[i][j][k] = false;
        }
    }
}

string Storage::getProductId(Product product){
    string id = product.getProductName();
    id+="/";
    id+=product.getExpDate();
    return id;
}

void Storage::findNewPlaceAndAdd(Product product, string id, vector<Product>& products){
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            for(int k = 0;k<10;k++){
                if(!availableSpace[i][j][k]){
                    if(storageSpace[i][j][k] >= product.getQuantity()){
                        product.setStoragePlace(i, j, k);
                        products.push_back(product);
                        availableProducts.insert(pair<string, vector<Product>>(id, products));
                        availableSpace[i][j][k] = true;
                        system("CLS");
                        cout<<"Your product was successfully stored on place "<<i<<"/"<<j<<"/"<<k<<endl;
                        cout<<"There is "<<storageSpace[i][j][k]-product.getQuantity()<<" "<<product.getUnit()<<" free space in the same number."<<endl;
                        //TODO to file the addition
                        return ; ///return?
                    }
                }
            }
        }
    }
    system("CLS");
    cout<<"Sorry, either the storage is full, or the quantity you are trying to add is too much."<<endl;
    return ; ///return?
}

void Storage::addProduct(Product product){
    string id = getProductId(product);
    map<string, vector<Product>>::iterator it = availableProducts.find(id);
    vector<Product> products;
    if(it != availableProducts.end())
    {
        cout<<id<<endl;
        products = it->second;
        int filled = 0;
        cout<<products.size()<<endl;
        for (unsigned i=0; i < products.size(); i++) {
            StoragePlace currentPlace = products[i].getStoragePlace();

            double newQuantity = products[i].getQuantity() + product.getQuantity();
            if( newQuantity <= storageSpace[currentPlace.getSection()][currentPlace.getShelf()][currentPlace.getNumber()]){
                products[i].setQuantity(newQuantity);
                system("CLS");
                cout<<"The product "<<product.getProductName()<<" was stored on place "<<currentPlace.getSection()<<"/"<<currentPlace.getShelf()<<"/"<<currentPlace.getNumber()<<endl;
                cout<<"There is "<<storageSpace[currentPlace.getSection()][currentPlace.getShelf()][currentPlace.getNumber()]-newQuantity<<" "<<product.getUnit()<<" free space in the same number."<<endl;
                //TODO to file the addition
                return;
            }
        }
        findNewPlaceAndAdd(product, id, products);
    }else{
        vector<Product> newVector;
        findNewPlaceAndAdd(product, id, newVector);
    }
}

void Storage::listAvailableProducts(){
    for(map<string, vector<Product>>::iterator it = availableProducts.begin(); it!=availableProducts.end(); it++ ){
        vector<Product> products = it->second;
        for(unsigned i = 0;i<products.size(); i++ ){
            products[i].output();
        }
    }
}

void Storage::removeProduct(string name, double quantity){
    vector<Product> foundProducts;
    for(map<string, vector<Product>>::iterator it = availableProducts.begin(); it!=availableProducts.end(); it++ ){
        string id = it->first;
        if (id.find(name) != string::npos) {
            foundProducts.push_back(it->second);
        }
    }
}

void Storage::sortByExpiryDate(vector<Product>& products){
    vector<Product> Sortable;
    for(unsigned i=0; i<products.size(); i++)
        Sortable.push_back(products[i]);
    //for(unsigned i = 0; i<products.size(); i++){
    //}
}

