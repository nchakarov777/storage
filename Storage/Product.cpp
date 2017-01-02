#include "Product.h"

Product::Product(){
	product_name = "";
	exp_date = ""; // dd.mm.yyyy format
	entry_date = ""; // dd.mm.yyyy format
	producer_name = "";
	unit = "";
	quantity = 0.0;
	isp_input = ""; //sektsiq/raft/nomer format
	comment = "";
}

void Product::storage_place_processing(){
    if(isp_input[1] == '/'){
        section = isp_input.substr(0,1);
        if(isp_input[3] == '/'){
            shelf = isp_input.substr(2,1);
            if(isp_input[5] == '\0')
                number = isp_input.substr(4,1);
            else
                number = isp_input.substr(4,2);
        }
        else{
            shelf = isp_input.substr(2,2);
            if(isp_input[6] == '\0')
                number = isp_input.substr(5,1);
            else
                number = isp_input.substr(5,2);
        }
    }
    else{
        section = isp_input.substr(0,2);
        if(isp_input[4] == '/'){
            shelf = isp_input.substr(3,1);
            if(isp_input[6] == '\0')
                number = isp_input.substr(5,1);
            else
                number = isp_input.substr(5,2);
        }
        else{
            shelf = isp_input.substr(3,2);
            if(isp_input[7] == '\0')
                number = isp_input.substr(6,1);
            else
                number = isp_input.substr(6,2);
        }
    }
}

void Product::input() {
	cout << "Enter product name: ";
	cin >> product_name;
	cout << "Enter expiration date (dd.mm.yyyy format): ";
	cin >> exp_date;
	cout << "Enter date of product's entry (dd.mm.yyyy format): ";
	cin >> entry_date;
	cout << "Enter producer name: ";
	cin >> producer_name;
	cout << "Enter quantity and units of the product(e.g. 10 kilograms): ";
	cin >> quantity >> unit;
	cout << "Enter in storage place of the product (section/shelf/number format): ";
	cin >> isp_input;
	storage_place_processing();
}

void Product::output() const{
    cout << "Product name: " << product_name << endl;
    cout << "Expiration date: " << exp_date << endl;
    cout << "Entry date: " << entry_date << endl;
    cout << "Producer name: " << producer_name << endl;
    cout << "Quantity available : " << quantity << " " << unit << endl;
    cout << "Product's place in store:\n" << "section " << section << "; shelf " << shelf << "; number " << number << endl;
}
