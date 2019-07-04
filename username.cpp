#include "username.h"
#include <iostream>
#include <string>
#include <array>
#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <math.h>
#include <sstream>
#include <iomanip>
using namespace std;
username::username() {
	//constructor

}

username::~username() {
	// TODO Auto-generated destructor stub
}

bool username::checkPrime(int number){
    int flag = 1;
    for (int i = 2; i <= sqrt(number) / 2; i++) {  
        if (number % i == 0) { 
            flag = 0; 
            break; 
        } 
    } 
    if (flag == 1) { 
        return true;
    } 
    return false; 
}

// Check if a letter is a consonant
bool username::checkConsonant(char letter){
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int i;
    for (i = 0; i < 5; i++){
        if (letter == vowels[i] || letter == toupper(vowels[i])){
            return false;
        }
    }
    return true;
}

// Check if there is a series of four ascending numbers in the date key
bool username::checkAscending(string numString){
    char numStringArry[120];
    int numIntArry[120];
    int i,j;
    strcpy(numStringArry, numString.c_str());
    for (i = 0; i < 12; i++){
        numIntArry[i] = numStringArry[i] - '0';
    }
    for (j = 0; j < 9; j++){
        if ( ((numIntArry[j] + 1) == numIntArry[j+1]) && ((numIntArry[j] + 2) == numIntArry[j+2]) && ((numIntArry[j] + 3) == numIntArry[j+3])){
            return true;
        }
    }
    return false;
}

// count how many of certain characters exist in a string
// type is what type of count you want. 1 = 1 digit int, 2 = 3 digit int
void username::countInt(string input, int inputSize, int checkArry[], int checkArrysize, int countArry[], int type){
    int i,j,k,m;
    int count;
    int intInputArry[100];
    int threeDigNum[3];
    for (i = 0; i < inputSize; i++){
        intInputArry[i] = input[i] - '0';
    }
    if (type == 1){
        for (j = 0; j < checkArrysize; j++){
            count = 0;
            for (k = 0; k < inputSize; k++){
                if (checkArry[j] == intInputArry[k]){
                    count++;
                }
            }
            countArry[j] = count;
        }
    } else if (type == 2){
        for (j = 0; j < checkArrysize; j++){
            count = 0;
            for (m = 2; m >= 0; m--) {
                threeDigNum[m] = checkArry[j] % 10;
                checkArry[j] /= 10;
            }
            for (k = 0; k < inputSize; k++){
                if (intInputArry[k] == threeDigNum[0] && intInputArry[k+1] == threeDigNum[1] && intInputArry[k+2] == threeDigNum[2]){
                    count++;
                }
            }
            countArry[j] = count;
        }
    }
    return; 
}

void username::countChar(string input, int inputSize, char checkArry[], int checkArrysize, int countArry[]){
    int i,j,k,m;
    int count;
    char charInputArry[inputSize+1];
    strcpy(charInputArry, input.c_str());
    for (j = 0; j < checkArrysize; j++){
            count = 0;
            for (k = 0; k < inputSize; k++){
                if (checkArry[j] == charInputArry[k]){
                    count++;
                }
            }
            countArry[j] = count;
        }
}

string username::invertLetToNum(string input) {
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());
    int numArry [input.size()];

    for (int i = 0; i < sizeof(inputArry)-1; i++) {
        numArry[i] = (int) inputArry[i] - 64;
    }
    int size = sizeof(numArry)/sizeof(numArry[0]);
    string str = intToString(numArry,size);

    return str;
}


string username::invertOrder(string input) {
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());
    char dupArry [input.size()+1];

    for (int i = 0; i < sizeof(inputArry); i++) {
        dupArry[i] = inputArry[input.size()-1-i];
    }
    string str(dupArry);
    return str;
}


string username::digitLetShift(string input, int numDigits){
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());

    for (int i = 0; i < sizeof(inputArry)-1; i++){
        inputArry[i] = ((((inputArry[i] - 65) + numDigits) % 26 + 26) % 26) + 65;
    }
    string str(inputArry);
    return str;
}


string username::digitNumShift(string input, int numDigits){
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());

    for (int i = 0; i < sizeof(inputArry)-1; i++){
        inputArry[i] = ((((inputArry[i] - 48) + numDigits) % 10 + 10) % 10) + 48;
    }
    string str(inputArry);
    return str;
}


string username::intToString (int arry[], int size){
    string outputString = "";
    for (int i = 0; i < size; i++){
        std::string str = std::to_string(arry[i]);
        outputString = outputString + str;
        }
    return outputString;
}

string username::deleteDig (string input, int numDigits){
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());
    char newArry[] = {0};
    int size = sizeof(inputArry)/sizeof(inputArry[0]) - abs(numDigits) - 1;

    if (numDigits > 0) {
        for (int i = 0; i < size; i++) {
            newArry[i] = inputArry[i];
        }
    } else {
        for (int j = 0; j < size; j++) {
            newArry[j] = inputArry[j+abs(numDigits)];
        }
    }
    string str(newArry);
    return str;
}

string username::invertNumToLet(string input){
    //printf("Input: %s\n",input.c_str());
    char inputArry[100];
    strcpy(inputArry, input.c_str());
    char newArry[] = {0};
    int size = sizeof(inputArry)/sizeof(inputArry[0]) - 1;
    int i = 0;
    int j = 0;
    //printf("size: %d\n",size);

    while (i < size) {
       // printf("%d value: %c\n",i,inputArry[i]);
        if (inputArry[i] == 0) {
            i++;
        } else if ((inputArry[i] == '1') && (i != size - 1)){
            //printf("check1\n");
            switch(inputArry[i+1]) {
                case '0' :
                    newArry[j] = 'J';
                    j++;
                    //printf("check1111:%c at j value: %d\n",newArry[j],j);
                    break;
                case '1' :
                    newArry[j] = 'K';
                    j++;
                    break;
                case '2' :
                    newArry[j] = 'L';
                    j++;
                    break;
                case '3' :
                    newArry[j] = 'M';
                    j++;
                    break;
                case '4' :
                    newArry[j] = 'N';
                    j++;
                    break;
                case '5' :
                    newArry[j] = 'O';
                    j++;
                    break;
                case '6' :
                    newArry[j] = 'P';
                    j++;
                    break;
                case '7' :
                    newArry[j] = 'Q';
                    j++;
                    break;
                case '8' :
                    newArry[j] = 'R';
                    j++;
                    break;
                case '9' :
                    newArry[j] = 'S';
                    j++;
                    break;
            }
            i += 2;
        } else if ((inputArry[i] == '2') && (inputArry[i+1] != '\0') && (inputArry[i+1] != '7' || inputArry[i+1] != '8' || inputArry[i+1] != '9')){
            //printf("check2\n");
            switch(inputArry[i+1]) {
                case '0' :
                    newArry[j] = 'T';
                    j++;
                    break;
                case '1' :
                    newArry[j] = 'U';
                    j++;
                    break;
                case '2' :
                    newArry[j] = 'V';
                    j++;
                    break;
                case '3' :
                    newArry[j] = 'W';
                    j++;
                    break;
                case '4' :
                    newArry[j] = 'X';
                    j++;
                    break;
                case '5' :
                    newArry[j] = 'Y';
                    j++;
                    break;
                case '6' :
                    newArry[j] = 'Z';
                    j++;
                    break;
            }
            i += 2;

        } else {
            //printf("check0\n");
            switch(inputArry[i]) {
                case '1' :
                    newArry[j] = 'A';
                    j++;
                    break;
                case '2' :
                    newArry[j] = 'B';
                    j++;
                    break;
                case '3' :
                    newArry[j] = 'C';
                    j++;
                    break;
                case '4' :
                    newArry[j] = 'D';
                    j++;
                    break;
                case '5' :
                    newArry[j] = 'E';
                    j++;
                    break;
                case '6' :
                    newArry[j] = 'F';
                    j++;
                    break;
                case '7' :
                    newArry[j] = 'G';
                    j++;
                    break;
                case '8' :
                    newArry[j] = 'H';
                    j++;
                    break;
                case '9' :
                    newArry[j] = 'I';
                    j++;
                    break;
            }
            i++;
        }
    }
    //printf("checkkkk: %c\n",newArry[0]);
    string str(newArry);
    return str;
}

string username::excise(string input, string excise){
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());
    char exArry[excise.size()+1];
    strcpy(exArry, excise.c_str());


    int size = sizeof(inputArry)/sizeof(inputArry[0]) - 1;
    int sizeEx = sizeof(exArry)/sizeof(exArry[0]) - 1;
    //printf("sizeEx: %d\n",sizeEx);
    int j = 0;
    int k = 0;
    char newArry [30] = {'0'};
    int check = 0;

    for (int i = 0; i < size; i++) {
       // printf("checkI: %d\n",i);
        for (int j = 0; j < sizeEx; j++){
          //  printf("J:%d\n",j);
            if (inputArry[i] == exArry[j]) {
              //  printf("inputArry[%d]:%c exArry[%d]:%c\n",i,inputArry[i],j,exArry[j]);
                //newArry[k] = inputArry[i];
                //printf("newArry[%d]:%c\n",k,newArry[k]);
                //k++;
                check = 1;

            }
        }
        /*
        while ((j < sizeEx) || (check == 0)) {
            printf("inputArry[%d]:%c exArry[%d]:%c\n",i,inputArry[i],j,exArry[j]);
            if (inputArry[i] == exArry[j]) {
                check = 1;
                printf("I hate C\n");
            }
            j++;
        }
        */
        
        if (check == 0) {
            newArry[k] = inputArry[i];
            k++;
        }
        check = 0;
        //j = 0;
        
        
    }
    
    string str(newArry);
    return str;
}

int username::intToNum(int arry[], int size){
    int finalNumber = 0;
    for (int i = 0; i < size; i++) {
        int num = arry[i];
        if (num != 0) {
            while (num > 0) {
                finalNumber *= 10;
                num /= 10;
            }
            finalNumber += arry[i];
        } else {
            finalNumber *= 10;
        }
        
    }
    return finalNumber;
}

//Checks if a 3 digit number in the date key is prime
bool username::checkOdd1(string date){
    return true;
}

bool username::checkOdd2(string date){
    return true;
}

bool username::checkOdd3(string date){
    return true;
}

bool username::checkOddA(string text){
    return true;
}

bool username::checkOddB(string text){
    return true;
}

bool username::checkOddC(string text){
    return true;
}

//If any three successive numbers of the date key form a 3-digit prime
bool username::checkEven1(string date){
    int dateIntArry[100];
    int threeDigArry[10];
    int threeDigInt;
    int i,j,k;
    for (i = 0; i < 12; i++){
        dateIntArry[i] = date[i] - '0';
    }
    for (j = 0; j < 10; j++){
        threeDigArry[0] = dateIntArry[j];
        threeDigArry[1] = dateIntArry[j+1]; 
        threeDigArry[2] = dateIntArry[j+2]; 
        threeDigInt = intToNum(threeDigArry, 3);
        if (checkPrime(threeDigInt)){
            return true;
        }
    }
    return false;
}

//If at least one date key digit is repeated at least three times
bool username::checkEven2(string date){
    int dateIntArry[100];
    int i,j,k;
    int count;
    for (i = 0; i < 12; i++){
        dateIntArry[i] = date[i] - '0';
    }
    for (j = 0; j < 12; j++){
        count = 0;
        for (k = 0; k < 12; k++){
            if (dateIntArry[j] == dateIntArry[k]){
                count++;
            }
        }
        if (count >= 3){
            return true;
        }
    }
    return false;
}

bool username::checkEven3(string date){
    return true;
}

bool username::checkEvenA(string text){
    return true;
}

bool username::checkEvenB(string text){
    return true;
}

bool username::checkEvenC(string text){
    return true;
}