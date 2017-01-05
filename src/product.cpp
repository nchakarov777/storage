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
            cout << "The date you've input is in bad format. Please enter again!\n";
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
            cout << "The date you've input is in bad format. Please enter again!\n";
            system("PAUSE");
        }
	}while(!isValid(entryDate));
	cout << "Enter producer name: ";
	cin >> producerName;
	cout << "Enter quantity and units of the product(e.g. 10 kilograms): ";
	cin >> quantity >> unit;
}

void Product::output() const{
    cout << "Product name: " << productName << endl;
    cout << "Expiration date: " << expDate << endl;
    cout << "Entry date: " << entryDate << endl;
    cout << "Producer name: " << producerName << endl;
    cout << "Quantity available : " << quantity << " " << unit << endl;
    cout << "Product's place in store:\n" << "section " << section << "; shelf " << shelf << "; number " << number << endl;
}

StoragePlace Product::getStoragePlace(){
    return storagePlace;
}
