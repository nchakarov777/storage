#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;

#include "storage-controller.h"

StorageController controller;
int command;
bool stopMenu = false;

void printMenu(){
    cout<<"For adding new product press 1."<<endl;
    cout<<"For removing products press 2."<<endl;
    cout<<"For listing the available products press 3."<<endl;
    cout<<"For clearing the outdated products press 4."<<endl;
    cout<<"For reference of the work of given period press 5."<<endl;
    cout<<"For quitting the storage press 0."<<endl;
    cout<<"Your command: ";
}

void validateAndExecuteCommand(int command){
    switch(command){
        case 1: controller.addProduct();break;
        case 2: controller.removeProduct();break;
        case 3: controller.listAvailableProducts();break;
        case 4: controller.clearOutdatedProducts();break;
        case 5: controller.referenceDataRangeWork();break;
        case 0: stopMenu = true;break;
        default: cout<<"Please enter valid command"<<endl;
    }
}

int main(){

    while(!stopMenu){
        system("cls");
        printMenu();
        cin>>command; system("cls");
        validateAndExecuteCommand(command);
    }
}
