#include "username.h"
#include "helpers.h"
#include <iostream>
#include <sstream> 
#include <string>
#include <array>
#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <string.h>

using namespace std;
username::username(string date, string text) {
	cout << getTableKey(date, text) << endl;

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
    int j = 0;
    int k = 0;
    char newArry [30] = {'0'};
    int check = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < sizeEx; j++){
            if (inputArry[i] == exArry[j]) {
                check = 1;
            }
        }  
        if (check == 0) {
            newArry[k] = inputArry[i];
            k++;
        }
        check = 0;             
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
    int sumOdd = 0;
    int sumEven = 0;
    int countArryEven[100];
    int checkArryEven[6]= {0,2,4,6,8};
    int countArryOdd[100];
    int checkArryOdd[6] = {1,3,5,7,9};

    countInt(date, 12, checkArryEven, 5, countArryEven, 1);
    countInt(date, 12, checkArryOdd, 5, countArryOdd, 1);

    for (int i = 0; i < 5; i++){
        sumOdd += countArryOdd[i];
        sumEven += countArryEven[i];
    }
    if (sumEven > sumOdd){
        return true;
    } else {
        return false;
    }
}

bool username::checkOdd2(string date){
    stringstream changeThis(date); 
    int dateNum = 0; 
    changeThis >> dateNum;

    return checkPrime(dateNum);
}

bool username::checkOdd3(string date){
    char dateArr[date.size()+1];
    strcpy(dateArr, date.c_str());
    int sum = 0;

    for (int i = 0; i < 12; i++){
        sum += (dateArr[i] - 48);
    }
    printf("sum: %f\n",sum/12.0);
    if (((double) (sum/12.0)) > 5.5){
        return true;
    } else {
        return false;
    }
}

bool username::checkOddA(string text){
    char checkArr[6]= {'B','F','J','S','V'};
    int countArrChar[100];
    countChar(text, 12, checkArr, 5, countArrChar);
    for (int i = 0; i < 5; i++){
        if (countArrChar[i] >= 3){
            return true;
        }
    }
    return false;
}

bool username::checkOddB(string text){
    char checkArr[6]= {'A','E','I','O','U'};
    int countArrChar[100];
    countChar(text, 12, checkArr, 5, countArrChar); 
    int count = 0;
    for (int i = 0; i < 5; i++){
        count += countArrChar[i];
    }
    if ((count % 2) == 0){
        return true;
    } else {
        return false;
    }
}

bool username::checkOddC(string text){
    char textArr[text.size()+1];
    strcpy(textArr, text.c_str());
    int sum = (textArr[0]-64) + (textArr[1]-64);
    if (sum <= 30){
        return true;
    } else {
        return false;
    }
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

//If at least three successive numbers in the date key are ordered ascendingly
bool username::checkEven3(string date){
    return checkAscending(date);
}

//If the third, fourth, and fifth letters are consonants
bool username::checkEvenA(string text){
    return checkConsonant(text[2]) && checkConsonant(text[3]) && checkConsonant(text[4]);
}

//If there are less than or equal to four letters in the text key from the first half of the alphabet
bool username::checkEvenB(string text){
    char firstHalf[100] = {'A', 'B', 'C', 'D', 'E', 'F', 'G' ,'H', 'I', 'J', 'K', 'L', 'M'};
    int countArry[100];
    int sum = 0;
    countChar(text, 10, firstHalf, 13, countArry);
    for (int i = 0; i < 13; i++){
        sum = sum + countArry[i];
    }
    //cout << sum << endl;
    if (sum <= 4){
        return true;
    }
    return false;
}

//If less than half of the letters from the text key have at least one line of symmetry 
bool username::checkEvenC(string text){
    char symmetry[100] = {'A','B','C','D','E','H','I','M','O','T','U','V','W','X','Y'};
    int countArry[100];
    int sum = 0;
    countChar(text, 10, symmetry, 15, countArry);
    for (int i = 0; i < 15; i++){
        sum = sum + countArry[i];
    }
    //cout << sum << endl;
    if (sum <= 5){
        return true;
    }
    return false;
}

string username::getTableKey(string text, string date){
    helpers console;
    string vowels = "AEIOU";
    string oddNums = "13579";
    string evenNums = "02468";
    string primeNums = "2357";
    string nums1345 = "1345";
    string letsAEIJLOU = "AEIJLOU";
    string nums2357 = "2357";
    string letsRSTE = "RSTE";
    string nums01234 = "01234";
    string letsMNOP = "MNOP";
    string nums014689 = "014689";
    string nums01694 = "01694";
    string nums0128 = "0128";
    string nums0124689 = "0124689";
    string nums149 = "149";
    string nums7890 = "7890";
    string letA = "A";
    //int dateNum = stoi(date);
    stringstream geek(date); 
    long long dateNum = 0; 
    geek >> dateNum; 
    string line1 = "";
    string line2 = "";
    string temp = "";
    string result = "";
   // cout << "test2" << endl;
    if (dateNum % 2 != 0){
        //ODD
        console.log("ODD");
        if ((checkOdd1(date) && checkOdd2(date)) || (checkOdd1(date) && checkOdd3(date)) || (checkOdd1(date) && checkOdd3(date))){
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //4E
                line1 = excise(text,vowels) + text;
                line2 = invertOrder(date);
                result = line1 + line2;
                console.log("4E");
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //4D
                line1 = excise(text,vowels);
                line2 = date;
                result = line1 + line2;
                console.log("4D");
            } else if (checkOddA(text)){
                //4A
                line1 = excise(text,vowels);
                line2 = date;
                result = line1 + line2; 
                console.log("4A");
            } else if (checkOddB(text)){
                //4B
                line1 = invertNumToLet(date);
                line2 = invertLetToNum(text);
                result = line1 + line2; 
                console.log("4B");
            } else if (checkOddC(text)){
                //4C
                line1 = deleteDig(date,-5);
                line2 = digitLetShift(text,2);
                result = line1 + line2; 
                console.log("4C");
            } else {
                //4F
                line1 = excise(date,nums01234);
                line2 = digitLetShift(text,4);
                result = line1 + line2; 
                console.log("4F");
            }
        } else if (checkOdd1(date)) {
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //1E
                line1 = excise(text,letsRSTE);
                line2 = date;
                result = line1 + line2; 
                console.log("1E");
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //1D
                line1 = digitNumShift(date,1);
                line2 = text;
                result = line1 + line2; 
                console.log("1D");
            } else if (checkOddA(text)){
                //1A
                line1 = invertOrder(text) + text;
                line2 = date;
                result = line1 + line2; 
                console.log("1A");
            } else if (checkOddB(text)){
                //1B
                line1 = text;
                line2 = excise(date,nums1345);
                result = line1 + line2; 
                console.log("1B");
            } else if (checkOddC(text)){
                //1C
                line1 = invertOrder(date);
                line2 = deleteDig(digitLetShift(text,4),-2);
                result = line1 + line2; 
                console.log("1C");
            } else {
                //1F
                line1 = deleteDig(date,4);
                line2 = invertOrder(text);
                result = line1 + line2; 
                console.log("1F");
            }
        } else if (checkOdd2(date)){
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //2E
                line1 = invertNumToLet(date) + date;
                line2 = text;
                result = line1 + line2; 
                console.log("2E");
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //2D
                line1 = deleteDig(invertOrder(text),-3);
                line2 = digitNumShift(date,2);
                result = line1 + line2; 
                console.log("2D");
            } else if (checkOddA(text)){
                //2A
                line1 = digitNumShift(date,3);
                line2 = digitLetShift(text,-2);
                result = line1 + line2; 
                console.log("2A");
            } else if (checkOddB(text)){
                //2B
                line1 = invertOrder(text);
                line2 = date;
                result = line1 + line2; 
                console.log("2B");
            } else if (checkOddC(text)){
                //2C
                line1 = excise(date,oddNums);
                line2 = digitLetShift(text,1);
                result = line1 + line2; 
                console.log("2C");
            } else {
                //2F
                line1 = date + invertOrder(text);
                line2 = invertLetToNum(text);
                result = line1 + line2; 
                console.log("2F");
            }
        } else if (checkOdd3(date)){
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //3E
                line1 = date;
                line2 = text;
                result = line1 + line2; 
                console.log("3E");
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //3D
                line1 = text;
                line2 = excise(date,primeNums);
                result = line1 + line2; 
                console.log("3D");
            } else if (checkOddA(text)){
                //3A
                line1 = deleteDig(text,-3);
                line2 = date;
                result = line1 + line2; 
                console.log("3A");
            } else if (checkOddB(text)){
                //3B
                line1 = text;
                line2 = invertOrder(date) + excise(date,evenNums);
                result = line1 + line2; 
                console.log("3B");
            } else if (checkOddC(text)){
                //3C
                line1 = digitLetShift(text,4);
                line2 = date + text;
                result = line1 + line2; 
                console.log("3C");
            } else {
                //3F
                line1 = text;
                line2 = date + date;
                result = line1 + line2; 
                console.log("3F");
            }
        } else {
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //5E
                line1 = deleteDig(date,-3);
                line2 = invertOrder(digitLetShift(text,3));
                result = line1 + line2; 
                console.log("5E");
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //5D
                line1 = invertNumToLet(date);
                line2 = invertLetToNum(excise(text,vowels));
                result = line1 + line2; 
                console.log("5D");
            } else if (checkOddA(text)){
                //5A
                line1 = invertLetToNum(text + invertNumToLet(date));
                line2 = text;
                result = line1 + line2; 
                console.log("5A");
            } else if (checkOddB(text)){
                //5B
                line1 = excise(date,nums7890);
                line2 = excise(text,letsAEIJLOU);
                result = line1 + line2; 
                console.log("5B");
            } else if (checkOddC(text)){
                //5C
                line1 = deleteDig(date,-3);
                line2 = digitLetShift(text,-3);
                result = line1 + line2; 
                console.log("5C");
            } else {
                //5F
                line1 = excise(text,invertNumToLet(date));
                line2 = digitNumShift(date,-4);
                result = line1 + line2; 
                console.log("5F");
            }
        }
    } else {
        //EVEN
        console.log("EVEN");
        if ((checkEven1(date) && checkEven2(date)) || (checkEven2(date) && checkEven3(date)) || (checkEven1(date) && checkEven3(date))){
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //4E
                line1 = excise(text,invertNumToLet(date));
                line2 = digitNumShift(date,-4);
                result = line1 + line2; 
                console.log("4E");
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //4D
                line1 = excise(date,nums0128);
                line2 = digitLetShift(text,4);
                result = line1 + line2; 
                console.log("4D");
            } else if (checkEvenA(text)){
                //4A
                line1 = excise(text,vowels) + text;
                line2 = invertOrder(date);
                result = line1 + line2; 
                console.log("4A");
            } else if (checkEvenB(text)){
                //4B
                line1 = deleteDig(text,3);
                line2 = invertOrder(date);
                result = line1 + line2; 
                console.log("4B");
            } else if (checkEvenC(text)){
                //4C
                line1 = deleteDig(date,3);
                line2 = invertOrder(digitLetShift(text,3));
                result = line1 + line2; 
                console.log("4C");
            } else {
                //4F
                line1 = deleteDig(date,-1);
                line2 = invertOrder(deleteDig(text,-1));
                result = line1 + line2; 
                console.log("4F");
            }
        } else if (checkEven1(date)){
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //1E
                line1 = text;
                line2 = excise(date,nums014689);
                result = line1 + line2; 
                console.log("1E");
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //1D
                line1 = excise(text,letsMNOP);
                line2 = date;
                result = line1 + line2; 
                console.log("1D");
            } else if (checkEvenA(text)){
                //1A
                line1 = invertOrder(text);
                line2 = date;
                result = line1 + line2; 
                console.log("1A");
            } else if (checkEvenB(text)){
                //1B
                line1 = digitNumShift(date,-3);
                line2 = digitLetShift(text,-3);
                result = line1 + line2; 
                console.log("1B");
            } else if (checkEvenC(text)){
                //1C
                line1 = invertOrder(date);
                line2 = invertOrder(text);
                result = line1 + line2; 
                console.log("1C");
            } else {
                //1F
                line1 = excise(text,letA);
                line2 = excise(date,evenNums);
                result = line1 + line2; 
                console.log("1F");
            }
        } else if (checkEven2(date)){
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //2E
                line1 = digitNumShift(date,1);
                line2 = digitLetShift(text,-2);
                result = line1 + line2; 
                console.log("2E");
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //2D
                line1 = invertOrder(text) + text;
                line2 = date;
                result = line1 + line2; 
                console.log("2D");
            } else if (checkEvenA(text)){
                //2A
                line1 = deleteDig(invertOrder(text),-3);
                line2 = digitNumShift(date,2);
                result = line1 + line2; 
                console.log("2A");
            } else if (checkEvenB(text)){
                //2B
                line1 = excise(date,evenNums);
                line2 = digitLetShift(text,3);
                result = line1 + line2; 
                console.log("2B");
            } else if (checkEvenC(text)){
                //2C
                line1 = text;
                line2 = excise(date,primeNums);
                result = line1 + line2; 
                console.log("2C");
            } else {
                //2F
                line1 = date;
                line2 = text;
                result = line1 + line2; 
                console.log("2F");
            }
        } else if (checkEven3(date)){
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //3E
                line1 = deleteDig(date,3);
                line2 = digitLetShift(text,-1);
                result = line1 + line2; 
                console.log("3E");
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //3D
                line1 = excise(date,nums01694);
                line2 = digitLetShift(text,4);
                result = line1 + line2; 
                console.log("3D");
            } else if (checkEvenA(text)){
                //3A
                line1 = excise(text,vowels);
                line2 = date;
                result = line1 + line2; 
                console.log("3A");
            } else if (checkEvenB(text)){
                //3B
                line1 = text;
                line2 = excise(date,primeNums);
                result = line1 + line2; 
                console.log("3B");
            } else if (checkEvenC(text)){
                //3C
                line1 = text;
                line2 = invertOrder(date) + excise(date,oddNums);
                result = line1 + line2; 
                console.log("3C");
            } else {
                //3F
                line1 = excise(date,nums149);
                line2 = digitLetShift(text,-2);
                result = line1 + line2; 
                console.log("3F");
            }
        } else {
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //5E
                line1 = invertOrder(invertLetToNum(text));
                line2 = invertNumToLet(invertOrder(date));
                result = line1 + line2; 
                console.log("5E");
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //5D
                line1 = deleteDig(date,2);
                line2 = digitLetShift(text,6);
                result = line1 + line2; 
                console.log("5D");
            } else if (checkEvenA(text)){
                //5A
                line1 = excise(date,nums01234);
                line2 = digitLetShift(text,4);
                result = line1 + line2; 
                console.log("5A");
            } else if (checkEvenB(text)){
                //5B
                line1 = invertOrder(text) + text;
                line2 = date + invertOrder(date);
                result = line1 + line2; 
                console.log("5B");
            } else if (checkEvenC(text)){
                //5C
                line1 = invertOrder(text) + text;
                line2 = date;
                result = line1 + line2; 
                console.log("5C");
            } else {
                //5F
                line1 = digitLetShift(text,4);
                line2 = invertNumToLet(date) + invertOrder(text);
                result = line1 + line2; 
                console.log("5F");
            }
        }
    }

    return result;

}