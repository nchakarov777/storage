#include "product.h"
#include "storage-place.h"

Product::Product(){
	productName = "";
	expDate = ""; // dd.mm.yyyy format
	entryDate = ""; // dd.mm.yyyy format
	producerName = "";
	unit = "";
	quantity = 0.0;
	ispInput = ""; //sektsiq/raft/nomer format
	comment = "";
}

void Product::storage_place_processing(){
    if(ispInput[1] == '/'){
        section = ispInput.substr(0,1);
        if(ispInput[3] == '/'){
            shelf = ispInput.substr(2,1);
            if(ispInput[5] == '\0')
                number = ispInput.substr(4,1);
            else
                number = ispInput.substr(4,2);
        }
        else{
            shelf = ispInput.substr(2,2);
            if(ispInput[6] == '\0')
                number = ispInput.substr(5,1);
            else
                number = ispInput.substr(5,2);
        }
    }
    else{
        section = ispInput.substr(0,2);
        if(ispInput[4] == '/'){
            shelf = ispInput.substr(3,1);
            if(ispInput[6] == '\0')
                number = ispInput.substr(5,1);
            else
                number = ispInput.substr(5,2);
        }
        else{
            shelf = ispInput.substr(3,2);
            if(ispInput[7] == '\0')
                number = ispInput.substr(6,1);
            else
                number = ispInput.substr(6,2);
        }
    }
}

void Product::input() {
	cout << "Enter product name: ";
	cin >> productName;
	cout << "Enter expiration date (dd.mm.yyyy format): ";
	cin >> expDate;
	cout << "Enter date of product's entry (dd.mm.yyyy format): ";
	cin >> entryDate;
	cout << "Enter producer name: ";
	cin >> producerName;
	cout << "Enter quantity and units of the product(e.g. 10 kilograms): ";
	cin >> quantity >> unit;
}

void Product::output() const{
    cout << "Product name: " << productName << endl;
    cout << "Expiration date: " << expDate << endl;
    //validate date
    cout << "Entry date: " << entryDate << endl;
    //validate date
    cout << "Producer name: " << producerName << endl;
    cout << "Quantity available : " << quantity << " " << unit << endl;
    cout << "Product's place in store:\n" << "section " << section << "; shelf " << shelf << "; number " << number << endl;
}

StoragePlace Product::getStoragePlace(){
    return storagePlace;
}
