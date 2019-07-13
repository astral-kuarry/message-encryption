#include "username.h"
#include "helpers.h"
#include <iostream>
#include <stdlib.h>
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
#include <vector>
#include <ctype.h>



using namespace std;
helpers console; 

username::username(string text, string date) {
	string tableKey = invertNumToLet(getTableKey(text, date));
    //cout << tableKey << endl;
    char tableKeyArry[tableKey.size()+1];
    strcpy(tableKeyArry, tableKey.c_str());
    int midPoint = tableKey.size()/2;
    char keywordArry[100];
    char plaintextArry[100];
    int index = 0;
    for (int i = 0; i < midPoint; i++){
        keywordArry[i] = tableKeyArry[i];
    }
    keywordArry[midPoint] = '\0';
    for (int j = midPoint; j < tableKey.size(); j++){
        plaintextArry[index] = tableKeyArry[j];
        index++;
    }
    plaintextArry[tableKey.size() - midPoint] = '\0';
    string str(keywordArry);
    string str1(plaintextArry);
    username::keyword = str;
    username::plaintext = str1;
    username::ciphertext = Encipher(keyword, plaintext);
    //cout << "keyword: " << keyword << endl << "plaintext: " << plaintext << endl << "ciphertext: " << ciphertext << endl;
    
}
username::username(){

}
username::~username() {
	// TODO Auto-generated destructor stub
}

bool username::checkPrime(long long number){
    console.log("Check Prime");
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
    console.log("Check Consonant");
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int i;
    //cout << letter << endl;
    for (i = 0; i < 5; i++){
        if (letter == vowels[i] || letter == toupper(vowels[i])){
            return false;
        }
    }
    return true;
}

// Check if there is a series of four ascending numbers in the date key
bool username::checkAscending(string numString){
    console.log("Check Ascending");
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
    console.log("Count Int");
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
    console.log("Count Char");
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
    console.log("Invert Let to Num");
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());
    int numArry [input.size()];

    for (int i = 0; i < sizeof(inputArry)-1; i++) {
        numArry[i] = abs((int) inputArry[i] - 64);
        //cout << abs(numArry[i]) << endl;
    }
    int size = sizeof(numArry)/sizeof(numArry[0]);

    string str = intToString(numArry,size);

    return str;
}


string username::invertOrder(string input) {
    console.log("Invert Order");
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());
    char dupArry [input.size()+1];

    for (int i = 0; i < sizeof(inputArry); i++) {
        dupArry[i] = inputArry[input.size()-1-i];
    }
    string str(dupArry);
    console.log(str);
    return str;
}


string username::digitLetShift(string input, int numDigits){
    console.log("digit let shift");
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());

    for (int i = 0; i < sizeof(inputArry)-1; i++){
        inputArry[i] = ((((inputArry[i] - 65) + numDigits) % 26 + 26) % 26) + 65;
    }
    string str(inputArry);
    return str;
}

string username::digitNumShift(string input, int numDigits){
    console.log("digit num shift");
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());

    for (int i = 0; i < sizeof(inputArry)-1; i++){
        inputArry[i] = ((((inputArry[i] - 48) + numDigits) % 10 + 10) % 10) + 48;
    }
    string str(inputArry);
    return str;
}


string username::intToString (int arry[], int size){
    console.log("int to string");
    string outputString = "";
    for (int i = 0; i < size; i++){
        string str = to_string(arry[i]);
        outputString = outputString + str;
        //cout << outputString << endl;
    }
    //cout << outputString << endl;
    return outputString;
}

string username::deleteDig (string input, int numDigits){
        console.log("Delete Dig");
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
        newArry[size] = '\0';
        string str(newArry);
        console.log(str);
        return str;
}

string username::invertNumToLet(string input){
    console.log("invert num to let");
    int i,j,k;
    j = 0;
    char inputArry[input.size()];
    int num;
    int inputDig;
    int inputDigPlusOne;
    strcpy(inputArry, input.c_str());
    int size = sizeof(inputArry)/sizeof(inputArry[0]);
    char outputArry[100];
    for (i = 0; i < size; i++){
        if (!isdigit(inputArry[i])) {
            outputArry[j] = inputArry[i];
            j++;
        } else{
            inputDig = inputArry[i] - '0';
            inputDigPlusOne = inputArry[i+1] - '0';
            num = inputDig * 10 + inputDigPlusOne;
            //cout << num << " " << inputDig << " " << inputDigPlusOne << endl;
            //cout << size << endl;
            if (inputDig != 0){
                if (num > 26 || i == size-1){
                    if (inputDig == 1){
                        outputArry[j] = 'A';
                        j++;
                    }
                    if (inputDig == 2){
                        outputArry[j] = 'B';
                        j++;
                    }
                    if (inputDig == 3){
                        outputArry[j] = 'C';
                        j++;
                    }
                    if (inputDig == 4){
                        outputArry[j] = 'D';
                        j++;
                    }
                    if (inputDig == 5){
                        outputArry[j] = 'E';
                        j++;
                    }
                    if (inputDig == 6){
                        outputArry[j] = 'F';
                        j++;
                    }
                    if (inputDig == 7){
                        outputArry[j] = 'G';
                        j++;
                    }
                    if (inputDig == 8){
                        outputArry[j] = 'H';
                        j++;
                    }
                    if (inputDig == 9) {
                        outputArry[j] = 'I';
                        j++;
                    }
                } else{
                    if (num == 10){
                        outputArry[j] = 'J';
                        j++;
                    }
                    if (num == 11){
                        outputArry[j] = 'K';
                        j++;
                    }
                    if (num == 12){
                        outputArry[j] = 'L';
                        j++;
                    }
                    if (num == 13){
                        outputArry[j] = 'M';
                        j++;
                    }
                    if (num == 14){
                        outputArry[j] = 'N';
                        j++;
                    }
                    if (num == 15){
                        outputArry[j] = 'O';
                        j++;
                    }
                    if (num== 16){
                        outputArry[j] = 'P';
                        j++;
                    }
                    if (num == 17){
                        outputArry[j] = 'Q';
                        j++;
                    }
                    if (num == 18) {
                        outputArry[j] = 'R';
                        j++;
                    }
                    if (num == 19) {
                        outputArry[j] = 'S';
                        j++;
                    }
                    if (num == 20) {
                        outputArry[j] = 'T';
                        j++;
                    }
                    if (num == 21) {
                        outputArry[j] = 'U';
                        j++;
                    }
                    if (num == 22) {
                        outputArry[j] = 'V';
                        j++;
                    }
                    if (num == 23) {
                        outputArry[j] = 'W';
                        j++;
                    }
                    if (num == 24) {
                        outputArry[j] = 'X';
                        j++;
                    }
                    if (num == 25) {
                        outputArry[j] = 'Y';
                        j++;
                    }
                    if (num == 26) {
                        outputArry[j] = 'Z';
                        j++;
                    }
                    i++;
                }
            }
        }
    }

    outputArry[j] = '\0';
    //cout << i << " " << j << endl;
    string str(outputArry);
    return str;
}

string username::excise(string input, string excise){
    console.log("excise");
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
    console.log("checkOdd1");
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
    console.log("checkOdd2");
    stringstream changeThis(date); 
    long long dateNum = 0; 
    changeThis >> dateNum;

    return checkPrime(dateNum);
}

bool username::checkOdd3(string date){
    console.log("checkOdd3");
    char dateArr[date.size()+1];
    strcpy(dateArr, date.c_str());
    int sum = 0;

    for (int i = 0; i < 12; i++){
        sum += (dateArr[i] - 48);
    }
    //printf("sum: %f\n",sum/12.0);
    if (((double) (sum/12.0)) > 5.5){
        return true;
    } else {
        return false;
    }
}

bool username::checkOddA(string text){
    console.log("checkOddA");
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
    console.log("checkOddB");
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
    console.log("checkOddC");
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
    console.log("checkEven1");
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
    console.log("checkEven2");
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
    console.log("checkEven3");
    return checkAscending(date);
}

//If the third, fourth, and fifth letters are consonants
bool username::checkEvenA(string text){
    console.log("checkEvenA");
    //cout << text << endl;
    return checkConsonant(text[2]) && checkConsonant(text[3]) && checkConsonant(text[4]);
}

//If there are less than or equal to four letters in the text key from the first half of the alphabet
bool username::checkEvenB(string text){
    console.log("checkEvenB");
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
    console.log("checkEvenC");
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
        //cout << checkEvenB(text) << checkEvenC(text) << endl;
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

int username::Mod(int a, int b)
{
    return (a % b + b) % b;
}

char** username::Create2DArray(int rowCount, int colCount) {
    char** arr = new char*[rowCount];

    for (int i = 0; i < rowCount; ++i)
        arr[i] = new char[colCount];

    return arr;
}

string username::ToUpper(string str) {
    string output = str;
    int strLen = str.size();

    for (int i = 0; i < strLen; ++i)
        output[i] = toupper(output[i]);

    return output;
}

 string username::RemoveChar(string str, char ch) {
    string output = str;

    for (int i = 0; i < output.size(); ++i)
        if (output[i] == ch)
            output = output.erase(i, 1);

    return output;
}

 vector<int> username::FindAllOccurrences(string str, char value)
{
    vector<int> indexes;

    int index = 0;
    while ((index = str.find(value, index)) != -1)
        indexes.push_back(index++);

    return indexes;
}

 string username::RemoveAllDuplicates(string str, vector<int> indexes)
{
    string retVal = str;

    for (int i = indexes.size() - 1; i >= 1; i--)
        retVal = retVal.erase(indexes[i], 1);

    return retVal;
}

 char** username::GenerateKeySquare(string key)
{
    char** keySquare = Create2DArray(5, 5);
    string defaultKeySquare = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    string tempKey = key.empty() ? "CIPHER" : ToUpper(key);

    tempKey = RemoveChar(tempKey, 'J');
    tempKey += defaultKeySquare;

    for (int i = 0; i < 25; ++i)
    {
        vector<int> indexes = FindAllOccurrences(tempKey, defaultKeySquare[i]);
        tempKey = RemoveAllDuplicates(tempKey, indexes);
    }

    tempKey = tempKey.substr(0, 25);

    for (int i = 0; i < 25; ++i)
        keySquare[(i / 5)][(i % 5)] = tempKey[i];

    return keySquare;
}

 void username::GetPosition(char** keySquare, char ch, int* row, int* col)
{
    if (ch == 'J')
        GetPosition(keySquare, 'I', row, col);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (keySquare[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
}

 char* username::SameRow(char** keySquare, int row, int col1, int col2, int encipher)
{
    return new char[2] { keySquare[row][Mod((col1 + encipher), 5)], keySquare[row][Mod((col2 + encipher), 5)] };
}

 char* username::SameColumn(char** keySquare, int col, int row1, int row2, int encipher)
{
    return new char[2] { keySquare[Mod((row1 + encipher), 5)][col], keySquare[Mod((row2 + encipher), 5)][col] };
}

 char* username::SameRowColumn(char** keySquare, int row, int col, int encipher)
{
    return new char[2] { keySquare[Mod((row + encipher), 5)][Mod((col + encipher), 5)], keySquare[Mod((row + encipher), 5)][Mod((col + encipher), 5)] };
}

 char* username::DifferentRowColumn(char** keySquare, int row1, int col1, int row2, int col2)
{
    return new char[2] { keySquare[row1][col2], keySquare[row2][col1] };
}

 string username::RemoveOtherChars(string input)
{
    string output = input;
    int strLen = input.size();

    for (int i = 0; i < strLen; ++i)
        if (!isalpha(output[i]))
            output = output.erase(i, 1);

    return output;
}

 string username::AdjustOutput(string input, string output)
{
    string retVal = output;
    int strLen = input.size();

    for (int i = 0; i < strLen; ++i)
    {
        if (!isalpha(input[i]))
            retVal = retVal.insert(i, 1, input[i]);

        if (islower(input[i]))
            retVal[i] = tolower(retVal[i]);
    }

    return retVal;
}

 string username::Cipher(string input, string key, bool encipher)
{
    string retVal = "";
    char** keySquare = GenerateKeySquare(key);
    string tempInput = RemoveOtherChars(input);
    int e = encipher ? 1 : -1;
    int tempInputLen = tempInput.size();

    if ((tempInputLen % 2) != 0)
        tempInput += "X";

    for (int i = 0; i < tempInputLen; i += 2)
    {
        int row1 = 0;
        int col1 = 0;
        int row2 = 0;
        int col2 = 0;

        GetPosition(keySquare, toupper(tempInput[i]), &row1, &col1);
        GetPosition(keySquare, toupper(tempInput[i + 1]), &row2, &col2);

        if (row1 == row2 && col1 == col2)
        {
            retVal += string(SameRowColumn(keySquare, row1, col1, e), 2);
        }
        else if (row1 == row2)
        {
            retVal += string(SameRow(keySquare, row1, col1, col2, e), 2);
        }
        else if (col1 == col2)
        {
            retVal += string(SameColumn(keySquare, col1, row1, row2, e), 2);
        }
        else
        {
            retVal += string(DifferentRowColumn(keySquare, row1, col1, row2, col2), 2);
        }
    }

    retVal = AdjustOutput(input, retVal);

    return retVal;
}

 string username::Encipher(string input, string key)
{
    return Cipher(input, key, true);
}

 string username::Decipher(string input, string key)
{
    return Cipher(input, key, false);
}
