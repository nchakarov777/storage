#include<iostream>
#include<string>
using namespace std;

void convertDate(string& wholeDate, int& day, int& month, int& year){
    int posF = wholeDate.find(".");
    int posS = wholeDate.find(".",3);


    if(posF == 1){
        day = wholeDate[0] - '0';                         //10.8.2016 -- 10.10.2016
        if(posS == 3){
            month = wholeDate[2] - '0';
            year = 1000*(wholeDate[4] - '0') + 100*(wholeDate[5] - '0') + 10*(wholeDate[6] - '0') + wholeDate[7] - '0';
        }
        else if(posS == 4){
            month = 10*(wholeDate[2] - '0') + wholeDate[3] - '0';
            year = 1000*(wholeDate[5] - '0') + 100*(wholeDate[6] - '0') + 10*(wholeDate[7] - '0') + wholeDate[8] - '0';
        }
    }
    if(posF == 2){
        day = 10*(wholeDate[0] - '0') + wholeDate[1] - '0';
        if(posS == 4){
            month = wholeDate[3] - '0';
            year = 1000*(wholeDate[5] - '0') + 100*(wholeDate[6] - '0') + 10*(wholeDate[7] - '0') + wholeDate[8] - '0';
        }
        else if(posS == 5){
            month = 10*(wholeDate[3] - '0') + wholeDate[4] - '0';
            year = 1000*(wholeDate[6] - '0') + 100*(wholeDate[7] - '0') + 10*(wholeDate[8] - '0') + wholeDate[9] - '0';
        }
    }
}

int main(){
    string first = "1.10.2017";
    string second = "13.10.2017";

    int dayFirst, monthFirst, yearFirst;
    convertDate(first, dayFirst, monthFirst, yearFirst);

    int daySecond, monthSecond, yearSecond;
    convertDate(second, daySecond, monthSecond, yearSecond);

    if(yearFirst < yearSecond)
        cout << first;
    if(yearFirst > yearSecond)
        cout << second;
    if(yearFirst == yearSecond){
        if(monthFirst < monthSecond)
            cout << first;
        if(monthFirst > monthSecond)
            cout << second;
        if(monthFirst == monthSecond){
            if(dayFirst < daySecond)
                cout << first;
            if(dayFirst > daySecond)
                cout << second;
            if(dayFirst == daySecond)
                cout << "Equal dates." << endl;
        }
    }
}
