#include "product.h"
#include "storage-place.h"

Product::Product(){
	productName = "";
	expDate = "";
	entryDate = "";
    producerName = "";
	unit = "";
	quantity = 0.0;
	comment = "";
	StoragePlace storagePlace();
}

bool Product::isValid(string fullDate){
    int date, month, year;
    int len=0, i=0;
    date = 10*(fullDate[0]-'0') + fullDate[1] - '0';
    month = 10*(fullDate[3]-'0') + fullDate[4] - '0';
    year = 1000*(fullDate[6]-'0') + 100*(fullDate[7]-'0') + 10*(fullDate[8] - '0') + fullDate[9] - '0';
    while(fullDate[i] != '\0'){
        len++;
        i++;
    }
    if(len>10 || year>2017 || month>12 || date>31 || (((month==4) || (month==6) || (month==9) || (month==11)) && date>30) || (month==2 && date>28) || (fullDate[2]!='.' && fullDate[5]!='.')) return false;
    else return true;
}

void Product::input() {
	cout << "Enter product name: ";
	cin >> productName;
	do{
        system("CLS");
        cout << "Enter product name: " << productName << endl;
        cout << "Enter expiration date (dd.mm.yyyy format): ";
        cin >> expDate;
        if(!isValid(expDate)){
            cout << "The exp date you've input is in bad format. Please enter again!\n";
            system("PAUSE");
        }
	}while(!isValid(expDate));
	do{
        system("CLS");
        cout << "Enter product name: " << productName << endl;
        cout << "Enter expiration date (dd.mm.yyyy format): " << expDate << endl;
        cout << "Enter date of product's entry (dd.mm.yyyy format): ";
        cin >> entryDate;
        if(!isValid(entryDate)){
            cout << "The entry date you've input is in bad format. Please enter again!\n";
            system("PAUSE");
        }
	}while(!isValid(entryDate));
	cout << "Enter producer name: ";
	cin >> producerName;
	cout << "Enter quantity and units of the product(e.g. 10 kilograms): ";
	cin >> quantity >> unit;
}

void Product::output() {
    cout << "Product name: " << productName << endl;
    cout << "Expiration date: " << expDate << endl;
    cout << "Entry date: " << entryDate << endl;
    cout << "Producer name: " << producerName << endl;
    cout << "Quantity available : " << quantity << " " << unit << endl;
<<<<<<< HEAD
    //cout << "Product's place in store:\n" << "section " << section << "; shelf " << shelf << "; number " << number << endl;
=======
    cout << "Product's place in store:\n" << "section " << storagePlace.getSection() << "; shelf " << storagePlace.getShelf() << "; number " << storagePlace.getNumber() << endl;
>>>>>>> master
}

StoragePlace Product::getStoragePlace(){
    return storagePlace;
}

string Product::getProductName(){
    return producerName;
}

string Product::getExpDate(){
    return expDate;
}

double Product::getQuantity(){
    return quantity;
}

void Product::setStoragePlace(int section, int shelf, int number){
    StoragePlace newStoragePlace(section, shelf, number);
    storagePlace = newStoragePlace;
}

void Product::setQuantity(double quantity){
    this->quantity = quantity;
}

string Product::getUnit(){
    return unit;
}

