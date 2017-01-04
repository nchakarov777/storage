#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;

#include "Product.h"
#include "storage.h"

int main(){
    Storage storage;
    Product newProduct;
    newProduct.input();
    storage.addProduct(newProduct);
    cout << endl; system("pause"); system("CLS");
    newProduct.output();
    cout << endl; system("pause");
}
