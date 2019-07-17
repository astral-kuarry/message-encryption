#include <iostream>
#include <stdio.h>
#include "username.h"
#include "helpers.h"
#include "stdlib.h"
#include "password.h"
#include "monarch.h"
#include <string>
#include <array>
#include <sstream>


username usrnm;
helpers hlp = helpers(false);


monarch::monarch(string targetKey) {
    string monarchKey;
    string houseKey;
    string nationKey;
    string alphabeticKey;
    string numericKey;

	getDateKey(targetKey);
    cout << dateKey << endl;
	monarchKey = getMonarchString();
	houseKey = getHouseString();
	nationKey = getNationString();

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

}

string monarch::getMonarchString(){

}

string monarch::getHouseString(){

}

string monarch::getNationString(){

}
