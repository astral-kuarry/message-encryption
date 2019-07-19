#include <iostream>
#include <stdio.h>
#include "headers/username.h"
#include "headers/helpers.h"
#include "stdlib.h"
#include "headers/password.h"
#include "headers/monarch.h"
#include <string>
#include <array>
#include <sstream>
#include <iostream>


username usrnm;
helpers hlp = helpers(false);


monarch::monarch(string targetKey) {
    string alphabeticKey;
    string numericKey;
    int index;
    int i, j, k;
	getDateKey(targetKey);
    index = searchMonarch();
    alphabeticKey = getAlphabeticKey(index);
    numericKey = getNumericKey( targetKey);
    if ((numericKey.at(0) - '0') % 2){
        password = alphabeticKey.at(0);
        j = 0;
        k = 1;
        for (i = 1; i < 12; i++){
            if (i % 2){
                password = password + numericKey.at(j++);
            } else {
                password = password + alphabeticKey.at(k++);
            }

        }
    } else{
        password = numericKey.at(0);
        j = 0;
        k = 1;
        for (i = 1; i < 12; i++){
            if (i % 2){
                password = password + alphabeticKey.at(j++);
            } else {
                password = password + numericKey.at(k++);
            }

        }
    }
    //cout << "Date Key: " << dateKey << endl << "Alphabetic Key: " << alphabeticKey << endl << "Numeric Key: " << numericKey << endl << "Password: " << password << endl;
}

monarch::~monarch() {

}

void monarch::getDateKey(string targetKey){
    int targetArray[10];
    int i, j, k;
    for (i = 0; i < targetKey.length(); i++) {
        targetArray[i] = targetKey.at(i) - '0';
    }
    for (i = targetKey.length(); i < 8; i++) { //Safety Check
        targetArray[i] = 0;
    }
    if (targetArray[0] % 2 && targetArray[1] % 2){
        targetArray[0] = 1;
        targetArray[1] = targetArray[6] % 3;
    } else{
        targetArray[0] = 0;
        if (targetArray[1] == 0){
            targetArray[1] = 1;
        }
    }

    targetArray[2] = targetArray[7] % 3;
    if (targetArray[2] == 0 && targetArray[3] == 0){
        targetArray[2] = 1;
    }
    targetArray[4] = 1;
    //hlp.printIntArray(targetArray, 8);
    std::stringstream strstream;
    strstream << usrnm.intToNum(targetArray, 8);
    strstream >> dateKey;
    if (targetArray[0] == 0){
        string first = "0";
        dateKey = first + dateKey;
    }
}

int monarch::searchMonarch(){
    int i, j, k;
    bool searching = true;
    int year, month, day;
    int targetYear = 0;
    int targetMonth = 0;
    int targetDay = 0;
    int yeardiff = 1000;
    int monthdiff = 1000;
    int daydiff = 1000;

    int index = 0;
    string targetYearS, targetMonthS, targetDayS;

    bool days, months, years;
    int slash;
    int size = sizeof(monarchArray)/sizeof(monarchArray[0]);
    //dateKey = "11121064";
    year = (((dateKey.at(4) - '0') * 10 + (dateKey.at(5) - '0')) * 10 + (dateKey.at(6) - '0')) * 10 + (dateKey.at(7)- '0');
    month = (dateKey.at(0) - '0') * 10 + (dateKey.at(1) - '0');
    day = (dateKey.at(2) - '0') * 10 + (dateKey.at(3) - '0');

    //cout << year << " " << month << " " << day << endl;
    for (i = 1; i < size-16; i+=4){
        months = true;
        days = false;
        years = false;
        slash = 0;
        targetDayS = "0";
        targetMonthS = "0";
        targetYearS = "0";

        for (j = 0; j < monarchArray[i].length(); j++){
            if (monarchArray[i].at(j) == '/' && slash == 0){
                months = false;
                days = true;
                j++;
                slash++;
            }
            if (monarchArray[i].at(j) == '/' && slash == 1){
                days = false;
                years = true;
                j++;
                slash++;
            }
            if (months){
                targetMonthS = targetMonthS + monarchArray[i].at(j);
            }else if (days){
                targetDayS = targetDayS + monarchArray[i].at(j);
            }else if (years){
                targetYearS = targetYearS + monarchArray[i].at(j);
            }
        }
        stringstream convertyear(targetYearS);
        convertyear >> targetYear;
        stringstream convertmonth(targetMonthS);
        convertmonth >> targetMonth;
        stringstream convertday(targetDayS);
        convertday >> targetDay;
        //cout << targetMonth << " " << targetDay << " " << targetYear << endl;
        if (abs(year - targetYear) <= yeardiff){
            if (yeardiff){
                yeardiff = abs(year - targetYear);
                index = i;
                monthdiff = abs(month - targetMonth);
            } else {
                if (abs(month - targetMonth) <= monthdiff){
                    if (monthdiff){
                        monthdiff = abs(month - targetMonth);
                        index = i;
                        daydiff = abs(day - targetDay);
                    } else{
                        if (abs(day - targetDay) <= daydiff){
                            if (daydiff){
                                daydiff = abs(day - targetDay);
                                index = i;
                            }
                        }
                    }
                }
            }
        }

    }
    //cout << monarchArray[index];
    return index;

}


string monarch::getAlphabeticKey(int index){
    int i,j,k;
    string concatonated;
    string alphabeticKey;
    char monarchChar[50];
    char houseChar[50];
    char nationChar[50];
    int monarchSize, houseSize, nationSize;
    strcpy(monarchChar, monarchArray[index - 1].c_str());
    strcpy(houseChar, monarchArray[index + 2].c_str());
    strcpy(nationChar, monarchArray[index + 1].c_str());
    hlp.stringRemoveNonAlphaNum(monarchChar);
    hlp.stringRemoveNonAlphaNum(houseChar);
    hlp.stringRemoveNonAlphaNum(nationChar);
    string monarch(monarchChar);
    string house(houseChar);
    string nation(nationChar);
    string keys[3] = {monarch, house, nation};
    monarchSize = monarch.length();
    houseSize = house.length();
    nationSize = nation.length();
    int lengths[3] = {monarchSize, houseSize, nationSize};

    int temp;
    string tempString;
    for (i = 0; i < 2; i++){
        for (j = 0;j<2-i; j++){
            if (lengths[j] > lengths[j+1]){
                temp = lengths[j];
                lengths[j] = lengths[j+1];
                lengths[j+1] = temp;
                tempString = keys[j];
                keys[j] = keys[j+1];
                keys[j+1] = tempString;
            }
        }
    }
    concatonated = keys[0] + keys[1] + keys[2];
    //concatonated = "ABCD";
    //cout << concatonated << endl;
    i = 2;
    alphabeticKey = concatonated.at(0);
    while (alphabeticKey.length() <= 5){
        alphabeticKey = alphabeticKey + concatonated.at(i);
        i += 3;
        if (i >= concatonated.length()){
            i = i - (concatonated.length() - 1);
             i--;
        }
        //cout << i <<  " " << concatonated.length() << endl;
    }
    return alphabeticKey;
}

string monarch::getNumericKey(string targetKey){
    string numericKey;
    int i = 2;
    numericKey = targetKey.at(0);
    while (numericKey.length() <= 5){
        numericKey = numericKey + targetKey.at(i);
        i += 3;
        if (i >= targetKey.length()){
            i = i - (targetKey.length() - 1);
            i--;
        }
        //cout << i <<  " " << targetKey.length() << endl;
    }
    //cout << numericKey << endl;
    return numericKey;

}