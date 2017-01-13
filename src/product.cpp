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
}

bool Product::isValid(string fullDate){
    int date, month, year;
    int len=0, i=0;
    date = 10*(fullDate[8]-'0') + fullDate[9] - '0';
    month = 10*(fullDate[5]-'0') + fullDate[6] - '0';
    year = 1000*(fullDate[0]-'0') + 100*(fullDate[1]-'0') + 10*(fullDate[2] - '0') + fullDate[3] - '0';
    while(fullDate[i] != '\0'){
        len++;
        i++;
    }
    if(len>10 || year>2017 || month>12 || date>31 || (((month==4) || (month==6) || (month==9) || (month==11)) && date>30) || (month==2 && date>28) || (fullDate[4]!='.' && fullDate[7]!='.')) return false;
    else return true;
}

void Product::input() {
	cout << "Enter product name: ";
	cin >> productName;
	do{
        system("CLS");
        cout << "Enter product name: " << productName << endl;
        cout << "Enter expiration date (yyyy.mm.dd format): ";
        cin >> expDate;
        if(!isValid(expDate)){
            cout << "The expiration date you've input is in bad format. Please enter again!\n";
            system("PAUSE");
        }
	}while(!isValid(expDate));
	do{
        system("CLS");
        cout << "Enter product name: " << productName << endl;
        cout << "Enter expiration date (yyyy.mm.dd format): " << expDate << endl;
        cout << "Enter date of product's entry (yyyy.mm.dd format): ";
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
    cout << "Product's place in store:\n" << "section " << storagePlace.getSection() << "; shelf " << storagePlace.getShelf()
         << "; number " << storagePlace.getNumber() << ";" << endl;
}
///Not sure if this getter is properly written, might not work or not work the way we want
StoragePlace Product::getStoragePlace(){
    return storagePlace;
}

string Product::getProductName(){
    return productName;
}

string Product::getExpDate(){
    return expDate;
}

double Product::getQuantity(){
    return quantity;
}

void Product::setStoragePlace(int Section, int Shelf, int Number){
    storagePlace.setNumber(Number);
    storagePlace.setShelf(Shelf);
    storagePlace.setSection(Section);
}

void Product::setQuantity(double quantity){
    this->quantity = quantity;
}

string Product::getUnit(){
    return unit;
}

