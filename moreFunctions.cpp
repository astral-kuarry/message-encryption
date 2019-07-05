//============================================================================
// Name        : message-encryption
// Author      : Dante Sanaei and Alec Leven
// Version     : pre-release
// Description : An algorithm to generate an encrypted username and password for a messaging service
//============================================================================

#include <iostream>
#include <stdio.h>
#include "username.h"
#include "stdlib.h"
#include <math.h>
#include <string>
#include <sstream>

using namespace std;


//functions
long long int getFrac(long double input, int numDigits);
string invertLetToNum(string input);
string invertOrder(string input);
string digitLetShift(string input, int numDigits);
string digitNumShift(string input, int numDigits);
string intToString (int arry[], int size);
string deleteDig (string input, int numDigits);
string getTextKey(string message);
int stringRemoveNonAlphaNum(char *str);
string getDateKey();
string invertNumToLet(string input);
string excise(string input, string excise);
bool checkPrime(int number);
bool checkConsonant(char letter);
bool checkAscending(string numString);
bool checkOdd1(string date);
bool checkOdd2(string date);
bool checkOdd3(string date);
bool checkOddA(string text);
bool checkOddB(string text);
bool checkOddC(string text);
void countInt(string input, int inputSize, int checkArry[], int checkArrysize, int countArry[], int type);
void countChar(string input, int inputSize, char checkArry[], int checkArrysize, int countArry[]);


int main() {

    //string letters = "CURBATM";
    //string letterscheck = invertNumToLet("398472023");
    //string check = excise(letters,letterscheck);
    //printf("ans: %s\n",check.c_str());
	//              123456789012
    string check = "YEAEBBOUBBBF";
    bool bcheck = checkOddC(check);
    printf("bcheck: %d\n",bcheck);
    //printf("check:%d",check1);
    return 0;
}

long long int getFrac(long double input, int numDigits) {
    long double result;
    long double intpart;
    long double fractpart;

    fractpart = modf(input , &intpart);
    if (fractpart != 0.0) {
        while (fractpart < 0.1) {
            fractpart *= 10;
        }
    }
        
    for (int i = 1; i <= numDigits; i++) {
        fractpart *= 10;
    }
    return round(fractpart);
}
string invertLetToNum(string input) {
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
string invertOrder(string input) {
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());
    char dupArry [input.size()+1];

    for (int i = 0; i < sizeof(inputArry); i++) {
        dupArry[i] = inputArry[input.size()-1-i];
    }
    string str(dupArry);
    return str;
}
string digitLetShift(string input, int numDigits){
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());

    for (int i = 0; i < sizeof(inputArry)-1; i++){
        inputArry[i] = ((((inputArry[i] - 65) + numDigits) % 26 + 26) % 26) + 65;
    }
    string str(inputArry);
    return str;
}
string digitNumShift(string input, int numDigits){
    char inputArry[input.size()+1];
    strcpy(inputArry, input.c_str());

    for (int i = 0; i < sizeof(inputArry)-1; i++){
        inputArry[i] = ((((inputArry[i] - 48) + numDigits) % 10 + 10) % 10) + 48;
    }
    string str(inputArry);
    return str;
}
string intToString (int arry[], int size){
    string outputString = "";
    for (int i = 0; i < size; i++){
        std::string str = std::to_string(arry[i]);
        outputString = outputString + str;
        }
    return outputString;
}
string deleteDig (string input, int numDigits){
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
string getTextKey(string message){ 
    int i, j, k, l, m;
    char messageArry[message.size()+1];
    strcpy(messageArry, message.c_str());
    int size = sizeof(messageArry)/sizeof(*messageArry);
    int spaces = 0;
    for(unsigned int iLoop = 0; iLoop < size; iLoop++ )
        if(messageArry [iLoop] == ' ' )
            spaces++;
    char finalArry[11];
    int count = 0; 
    for (i = 0; messageArry[i]; i++) 
        if (messageArry[i] != ' ') 
            messageArry[count++] = messageArry[i];                    
    messageArry[count] = '\0'; 
    if (count > 10){
        for (l= 0; l < 10; l++){
            finalArry[l] = messageArry[l];
            finalArry[l] = toupper(finalArry[l]);
        }
        finalArry[10] = '\0';
    }
    if (count < 10){
        for ( k = 0; k < count; k++){
            finalArry[k] = messageArry[k];
            finalArry[k] = toupper(finalArry[k]);
        }
        for (l = k; l < 10; l++){
            finalArry[l] ='X';
        }
    } else {
        for (m = 0; m < 10; m++){
            finalArry[m] = toupper(finalArry[m]);
        }
    }
    

    finalArry[10] = '\0';
    int loops = stringRemoveNonAlphaNum(finalArry);
    //cout << loops;
    if (loops > 0){
        for (int t = 9-loops; t < 10; t++){
            finalArry[t] = 'X';
        }
        
    }
    string finalString = string(finalArry);
    return finalString;
}
int stringRemoveNonAlphaNum(char *str){
    unsigned long i = 0;
    unsigned long j = 0;
    char c;
    int loops = 0;

    while ((c = str[i++]) != '\0')
    {
        if (isalnum(c) && !isdigit(c))
        {
            str[j++] = c;
        }else{
            loops++;
        }
        //str[j++] = 'X';
        
    }
   // str[j] = '\0';
    return loops;
}
string getDateKey(){
    std::time_t rawtime;
    std::tm* timeinfo;
    char datestring [80];
    int dateInt[14];
    int firstSeven[7];
    int lastSeven[7];
    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);
    std::strftime(datestring,80,"%Y%m%d%H%M%S",timeinfo);
    datestring[14] = '\0';
    for (int i = 0; i < 14;i++){
        //cout << datestring[i];
        dateInt[i] = datestring[i] - '0';
        //cout << dateInt[i] << endl;
    }
    //printArray(dateInt, 14);
    for (int j = 0; j < 7; j++){
        firstSeven[j] = dateInt[j];
    }
    for (int k = 0; k < 7; k++){
        lastSeven[k] = dateInt[k + 7];
    }
    //printArray(firstSeven, 7);
    //printArray(lastSeven, 7);
    int firstSevenInt = 0;
    int lastSevenInt = 0;
    for (int j = 0; j < 7; j++) {
        firstSevenInt *= 10;
        firstSevenInt += firstSeven[j];
        lastSevenInt *= 10;
        lastSevenInt += lastSeven[j];
    }
    cout << "\n" << firstSevenInt << "\n" << lastSevenInt << endl;
    long double getFracInput = (long double) firstSevenInt / lastSevenInt;
    printf("input: %.12Lf\n",getFracInput);
    int dateKeyInt = getFrac(getFracInput, 12);
    printf("ans:%d\n",dateKeyInt);

    return "s";
}
string invertNumToLet(string input){
    //printf("Input: %s\n",input.c_str());
    char inputArry[input.size()+1];
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
string excise(string input, string excise){
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
// Check if a number is prime
bool checkPrime(int number){
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
bool checkConsonant(char letter){
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
bool checkAscending(string numString){
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
void countInt(string input, int inputSize, int checkArry[], int checkArrysize, int countArry[], int type){
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

void countChar(string input, int inputSize, char checkArry[], int checkArrysize, int countArry[]){
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
//If more even numbers appear than odd
bool checkOdd1(string date){
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
//If the date key is a prime number
bool checkOdd2(string date){
    stringstream changeThis(date); 
    int dateNum = 0; 
    changeThis >> dateNum;

    return checkPrime(dateNum);
}
//If the average value of the sum of the elements of the date key is greater than 5.5
bool checkOdd3(string date){
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
//If text key has at least three occurrences any of: B,F,J,S,V
bool checkOddA(string text){
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
//If the text key contains an even number of vowels
bool checkOddB(string text){
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
//Using A=1, ... Z=26, if the sum of first two letters of the text key is less than or equal to 30
bool checkOddC(string text){
    char textArr[text.size()+1];
    strcpy(textArr, text.c_str());
    int sum = (textArr[0]-64) + (textArr[1]-64);
    if (sum <= 30){
        return true;
    } else {
        return false;
    }
}



/*
string getTableKey(string date, string text){
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
    int dateNum = stoi(date);
    string line1 = "";
    string line2 = "";
    string temp = "";
    string result = "";

    if (dateNum % 2 != 0){
        //ODD
        if ((checkOdd1(date) && checkOdd2(date) || (checkOdd1(date) && checkOdd3(date)) || (checkOdd1(date) && checkOdd3(date))){
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //4E
                line1 = strcat(excise(text,vowels),text);
                line2 = invertOrder(date);
                result = strcat(line1,line2);
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //4D
                line1 = excise(text,vowels);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddA(text)){
                //4A
                line1 = excise(text,vowels);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddB(text)){
                //4B
                line1 = invertNumToLet(date);
                line2 = invertLetToNum(text);
                result = strcat(line1,line2);
            } else if (checkOddC(text)){
                //4C
                line1 = deleteDig(date,-5);
                line2 = digitLetShift(text,2);
                result = strcat(line1,line2);
            } else {
                //4F
                line1 = excise(date,nums01234);
                line2 = digitLetShift(text,4);
                result = strcat(line1,line2);
            }
        } else if (checkOdd1(date){
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //1E
                line1 = excise(text,letsRSTE);
                line2 = date;
                result = strcat(line1,line2);
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //1D
                line1 = digitNumShift(date,1);
                line2 = text;
                result = strcat(line1,line2); 
            } else if (checkOddA(text)){
                //1A
                line1 = strcat(invertOrder(text),text);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddB(text)){
                //1B
                line1 = text;
                line2 = excise(date,nums1345);
                result = strcat(line1,line2);
            } else if (checkOddC(text)){
                //1C
                line1 = invertOrder(date);
                line2 = deleteDig(digitLetShift(text,4),-2);
                result = strcat(line1,line2);
            } else {
                //1F
                line1 = deleteDig(date,4);
                line2 = invertOrder(text);
                result = strcat(line1,line2);
            }
        } else if (checkOdd2(date)){
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //2E
                line1 = strcat(invertNumToLet(date),date);
                line2 = text;
                result = strcat(line1,line2);
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //2D
                line1 = deleteDig(invertOrder(text),-3);
                line2 = digitNumShift(date,2);
                result = strcat(line1,line2);
            } else if (checkOddA(text)){
                //2A
                line1 = digitNumShift(date,3);
                line2 = digitLetShift(text,-2);
                result = strcat(line1,line2);
            } else if (checkOddB(text)){
                //2B
                line1 = invertOrder(text);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddC(text)){
                //2C
                line1 = excise(date,oddNums);
                line2 = digitLetShift(text,1);
                result = strcat(line1,line2);
            } else {
                //2F
                line1 = strcat(date,invertOrder(text));
                line2 = invertLetToNum(text);
                result = strcat(line1,line2);
            }
        } else if (checkOdd3(date)){
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //3E
                line1 = date;
                line2 = text;
                result = strcat(line1,line2);
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //3D
                line1 = text;
                line2 = excise(date,primeNums);
                result = strcat(line1,line2);
            } else if (checkOddA(text)){
                //3A
                line1 = deleteDig(text,-3);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddB(text)){
                //3B
                line1 = text;
                line2 = strcat(invertOrder(date),excise(date,evenNums));
                result = strcat(line1,line2);
            } else if (checkOddC(text)){
                //3C
                line1 = digitLetShift(text,4);
                line2 = strcat(date,text)
                result = strcat(line1,line2);
            } else {
                //3F
                line1 = text;
                line2 = strcat(date,date);
                result = strcat(line1,line2);
            }
        } else {
            if (checkOddA(text) && checkOddB(text) && checkOddC(text)){
                //5E
                line1 = deleteDig(date,-3);
                line2 = invertOrder(digitLetShift(text,3));
                result = strcat(line1,line2);
            } else if ((checkOddA(text) && checkOddB(text)) || (checkOddB(text) && checkOddC(text)) || (checkOddA(text) && checkOddC(text))) {
                //5D
                line1 = invertNumToLet(date);
                line2 = invertLetToNum(excise(text,vowels));
                result = strcat(line1,line2);
            } else if (checkOddA(text)){
                //5A
                line1 = invertLetToNum(strcat(text,invertNumToLet(date)));
                line2 = text;
                result = strcat(line1,line2);
            } else if (checkOddB(text)){
                //5B
                line1 = excise(date,nums7890);
                line2 = excise(text,letsAEIJLOU);
                result = strcat(line1,line2);
            } else if (checkOddC(text)){
                //5C
                line1 = deleteDig(date,-3);
                line2 = digitLetShift(text,-3);
                result = strcat(line1,line2);
            } else {
                //5F
                line1 = excise(text,invertNumToLet(date));
                line2 = digitNumShift(date,-4);
                result = strcat(line1,line2);
            }
        }
    } else {
        //EVEN
        if ((checkEven1(date) && checkEven2(date)) || (checkEven2(date) && checkEven3(date)) || (checkEven1(date) && checkEven3(date))){
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //4E
                line1 = excise(text,invertNumToLet(date));
                line2 = digitNumShift(date,-4);
                result = strcat(line1,line2);
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //4D
                line1 = excise(date,nums0128);
                line2 = digitLetShift(text,4);
                result = strcat(line1,line2);
            } else if (checkEvenA(text)){
                //4A
                line1 = strcat(excise(text,vowels),text);
                line2 = invertOrder(date);
                result = strcat(line1,line2);
            } else if (checkEvenB(text)){
                //4B
                line1 = deleteDig(text,3);
                line2 = invertOrder(date);
                result = strcat(line1,line2);
            } else if (checkEvenC(text)){
                //4C
                line1 = deleteDig(date,3);
                line2 = invertOrder(digitLetShift(text,3));
                result = strcat(line1,line2);
            } else {
                //4F
                line1 = deleteDig(date,-1);
                line2 = invertOrder(deleteDig(text,-1));
                result = strcat(line1,line2);
            }
        } else if (checkEven1(date)){
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //1E
                line1 = text;
                line2 = excise(date,nums014689);
                result = strcat(line1,line2);
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //1D
                line1 = excise(text,letsMNOP);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkEvenA(text)){
                //1A
                line1 = invertOrder(text);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkEvenB(text)){
                //1B
                line1 = digitNumShift(date,-3);
                line2 = digitLetShift(text,-3);
                result = strcat(line1,line2);
            } else if (checkEvenC(text)){
                //1C
                line1 = invertOrder(date);
                line2 = invertOrder(text);
                result = strcat(line1,line2);
            } else {
                //1F
                line1 = excise(text,letA);
                line2 = excise(date,evenNums);
                result = strcat(line1,line2);
            }
        } else if (checkEven2(date)){
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //2E
                line1 = digitNumShift(date,1);
                line2 = digitLetShift(text,-2);
                result = strcat(line1,line2);
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //2D
                line1 = strcat(invertOrder(text),text);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkEvenA(text)){
                //2A
                line1 = deleteDig(invertOrder(text),-3);
                line2 = digitNumShift(date,2);
                result = strcat(line1,line2);
            } else if (checkEvenB(text)){
                //2B
                line1 = excise(date,evenNums);
                line2 = digitLetShift(text,3);
                result = strcat(line1,line2);
            } else if (checkEvenC(text)){
                //2C
                line1 = text;
                line2 = excise(date,primeNums);
                result = strcat(line1,line2);
            } else {
                //2F
                line1 = date;
                line2 = text;
                result = strcat(line1,line2);
            }
        } else if (checkEven3(date)){
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //3E
                line1 = deleteDig(date,3);
                line2 = digitLetShift(text,-1);
                result = strcat(line1,line2);
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //3D
                line1 = excise(date,nums01694);
                line2 = digitLetShift(text,4);
                result = strcat(line1,line2);
            } else if (checkEvenA(text)){
                //3A
                line1 = excise(text,vowels);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkEvenB(text)){
                //3B
                line1 = text;
                line2 = excise(date,primeNums);
                result = strcat(line1,line2);
            } else if (checkEvenC(text)){
                //3C
                line1 = text;
                line2 = strcat(invertOrder(date),excise(date,oddNums));
                result = strcat(line1,line2);
            } else {
                //3F
                line1 = excise(date,nums149);
                line2 = digitLetShift(text,-2);
                result = strcat(line1,line2);
            }
        } else {
            if (checkEvenA(text) && checkEvenB(text) && checkEvenC(text)){
                //5E
                line1 = invertOrder(invertLetToNum(text));
                line2 = invertNumToLet(invertOrder(date));
                result = strcat(line1,line2);
            } else if ((checkEvenA(text) && checkEvenB(text)) || (checkEvenB(text) && checkEvenC(text)) || (checkEvenA(text) && checkEvenC(text))) {
                //5D
                line1 = deleteDig(date,2);
                line2 = digitLetShift(text,6);
                result = strcat(line1,line2);
            } else if (checkEvenA(text)){
                //5A
                line1 = excise(date,nums01234);
                line2 = digitLetShift(text,4);
                result = strcat(line1,line2);
            } else if (checkEvenB(text)){
                //5B
                line1 = strcat(invertOrder(text),text);
                line2 = strcat(date,invertOrder(date));
                result = strcat(line1,line2);
            } else if (checkEvenC(text)){
                //5C
                line1 = strcat(invertOrder(text),text);
                line2 = date;
                result = strcat(line1,line2);
            } else {
                //5F
                line1 = digitLetShift(text,4);
                line2 = strcat(invertNumToLet(date),invertOrder(text));
                result = strcat(line1,line2);
            }
        }
    }

    return result;

}
*/