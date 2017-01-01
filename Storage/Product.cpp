#include "Product.h"

Product::Product(){
	product_name = "";
	exp_date = ""; // dd/mm/yyyy format
	entry_date = ""; // dd/mm/yyyy format
	producer_name = "";
	unit = "";
	quantity = 0.0;
	in_storage_place = "" //sektsiq.raft.nomer format
	comment = "";
}

void Product::input() {
	cout << "Enter product's name: ";
	cin >> producer_name;
	cout << "Enter expiration date (dd/mm/yyyy format): ";
	cin >> exp_date;
	cout << "Enter date of product's entry (dd/mm/yyyy format): ";
	cin >> entry_date;
	cout << "Enter producer's name: ";
	cin >> producer_name;
	cout << "Enter quantity and units of the product(e.g. 10 kilograma): ";
	cin >> quantity >> unit;
	cout << "Enter in storage place of the product (section.shelf.number format): ";
	cin >> in_storage_place;
}