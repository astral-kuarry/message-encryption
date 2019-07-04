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
string getTableKey(string date, string text);
bool checkOdd1(string date);
bool checkOdd2(string date);
bool checkOdd3(string date);
bool checkOddA(string text);
bool checkOddB(string text);
bool checkOddC(string text);
bool checkEven1(string date);
bool checkEven2(string date);
bool checkEven3(string date);
bool checkEvenA(string text);
bool checkEvenB(string text);
bool checkEvenC(string text);












int test();


int main() {

    //printf("CCCB:   %s\n",invertNumToLet("3332").c_str());
    //string letters = "CURBATM";
    //string letterscheck = invertNumToLet("398472023");
    //string check = excise(letters,letterscheck);
    //printf("ans: %s\n",check.c_str());
	
    string check = "1111";
    int check1 = stoi(check);
    //printf("check:%d",check1);
    string checkk = getTableKey("10055554","blah");
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
bool checkOdd1(string date){
    return;
}
bool checkOdd2(string date){
    return;
}
bool checkOdd3(string date){
    return;
}
bool checkOddA(string text){
    return;
}
bool checkOddB(string text){
    return;
}
bool checkOddC(string text){
    return;
}
bool checkEven1(string date){
    return;
}
bool checkEven2(string date){
    return;
}
bool checkEven3(string date){
    return;
}
bool checkEvenA(string text){
    return;
}
bool checkEvenB(string text){
    return;
}
bool checkEvenC(string text){
    return;
}

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
    string result = ""

    if (dateNum % 2 != 0){
        //ODD
        if ((checkOdd1() && checkOdd2()) || (checkOdd2() && checkOdd3()) || (checkOdd1() && checkOdd3())){
            if (checkOddA() && checkOddB() && checkOddC()){
                //4E
                line1 = strcat(excise(text,vowels),text);
                line2 = invertOrder(date);
                result = strcat(line1,line2);
            } else if ((checkOddA() && checkOddB()) || (checkOddB() && checkOddC()) || (checkOddA() && checkOddC())) {
                //4D
                line1 = excise(text,vowels);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddA()){
                //4A
                line1 = excise(text,vowels);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddB()){
                //4B
                line1 = invertNumToLet(date);
                line2 = invertLetToNum(text);
                result = strcat(line1,line2);
            } else if (checkOddC()){
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
        } else if (checkOdd1()){
            if (checkOddA() && checkOddB() && checkOddC()){
                //1E
                line1 = excise(text,letsRSTE);
                line2 = date;
                result = strcat(line1,line2);
            } else if ((checkOddA() && checkOddB()) || (checkOddB() && checkOddC()) || (checkOddA() && checkOddC())) {
                //1D
                line1 = digitNumShift(date,1);
                line2 = text;
                result = strcat(line1,line2); 
            } else if (checkOddA()){
                //1A
                line1 = strcat(invertOrder(text),text);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddB()){
                //1B
                line1 = text;
                line2 = excise(date,nums1345);
                result = strcat(line1,line2);
            } else if (checkOddC()){
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
        } else if (checkOdd2()){
            if (checkOddA() && checkOddB() && checkOddC()){
                //2E
                line1 = strcat(invertNumToLet(date),date);
                line2 = text;
                result = strcat(line1,line2);
            } else if ((checkOddA() && checkOddB()) || (checkOddB() && checkOddC()) || (checkOddA() && checkOddC())) {
                //2D
                line1 = deleteDig(invertOrder(text),-3);
                line2 = digitNumShift(date,2);
                result = strcat(line1,line2);
            } else if (checkOddA()){
                //2A
                line1 = digitNumShift(date,3);
                line2 = digitLetShift(text,-2);
                result = strcat(line1,line2);
            } else if (checkOddB()){
                //2B
                line1 = invertOrder(text);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddC()){
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
        } else if (checkOdd3()){
            if (checkOddA() && checkOddB() && checkOddC()){
                //3E
                line1 = date;
                line2 = text;
                result = strcat(line1,line2);
            } else if ((checkOddA() && checkOddB()) || (checkOddB() && checkOddC()) || (checkOddA() && checkOddC())) {
                //3D
                line1 = text;
                line2 = excise(date,primeNums);
                result = strcat(line1,line2);
            } else if (checkOddA()){
                //3A
                line1 = deleteDig(text,-3);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkOddB()){
                //3B
                line1 = text;
                line2 = strcat(invertOrder(date),excise(date,evenNums));
                result = strcat(line1,line2);
            } else if (checkOddC()){
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
            if (checkOddA() && checkOddB() && checkOddC()){
                //5E
                line1 = deleteDig(date,-3);
                line2 = invertOrder(digitLetShift(text,3));
                result = strcat(line1,line2);
            } else if ((checkOddA() && checkOddB()) || (checkOddB() && checkOddC()) || (checkOddA() && checkOddC())) {
                //5D
                line1 = invertNumToLet(date);
                line2 = invertLetToNum(excise(text,vowels));
                result = strcat(line1,line2);
            } else if (checkOddA()){
                //5A
                line1 = invertLetToNum(strcat(text,invertNumToLet(date)));
                line2 = text;
                result = strcat(line1,line2);
            } else if (checkOddB()){
                //5B
                line1 = excise(date,nums7890);
                line2 = excise(text,letsAEIJLOU);
                result = strcat(line1,line2);
            } else if (checkOddC()){
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
        if ((checkEven1() && checkEven2()) || (checkEven2() && checkEven3()) || (checkEven1() && checkEven3())){
            if (checkEvenA() && checkEvenB() && checkEvenC()){
                //4E
                line1 = excise(text,invertNumToLet(date));
                line2 = digitNumShift(date,-4);
                result = strcat(line1,line2);
            } else if ((checkEvenA() && checkEvenB()) || (checkEvenB() && checkEvenC()) || (checkEvenA() && checkEvenC())) {
                //4D
                line1 = excise(date,nums0128);
                line2 = digitLetShift(text,4);
                result = strcat(line1,line2);
            } else if (checkEvenA()){
                //4A
                line1 = strcat(excise(text,vowels),text);
                line2 = invertOrder(date);
                result = strcat(line1,line2);
            } else if (checkEvenB()){
                //4B
                line1 = deleteDig(text,3);
                line2 = invertOrder(date);
                result = strcat(line1,line2);
            } else if (checkEvenC()){
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
        } else if (checkEven1()){
            if (checkEvenA() && checkEvenB() && checkEvenC()){
                //1E
                line1 = text;
                line2 = excise(date,nums014689);
                result = strcat(line1,line2);
            } else if ((checkEvenA() && checkEvenB()) || (checkEvenB() && checkEvenC()) || (checkEvenA() && checkEvenC())) {
                //1D
                line1 = excise(text,letsMNOP);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkEvenA()){
                //1A
                line1 = invertOrder(text);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkEvenB()){
                //1B
                line1 = digitNumShift(date,-3);
                line2 = digitLetShift(text,-3);
                result = strcat(line1,line2);
            } else if (checkEvenC()){
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
        } else if (checkEven2()){
            if (checkEvenA() && checkEvenB() && checkEvenC()){
                //2E
                line1 = digitNumShift(date,1);
                line2 = digitLetShift(text,-2);
                result = strcat(line1,line2);
            } else if ((checkEvenA() && checkEvenB()) || (checkEvenB() && checkEvenC()) || (checkEvenA() && checkEvenC())) {
                //2D
                line1 = strcat(invertOrder(text),text);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkEvenA()){
                //2A
                line1 = deleteDig(invertOrder(text),-3);
                line2 = digitNumShift(date,2);
                result = strcat(line1,line2);
            } else if (checkEvenB()){
                //2B
                line1 = excise(date,evenNums);
                line2 = digitLetShift(text,3);
                result = strcat(line1,line2);
            } else if (checkEvenC()){
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
        } else if (checkEven3()){
            if (checkEvenA() && checkEvenB() && checkEvenC()){
                //3E
                line1 = deleteDig(date,3);
                line2 = digitLetShift(text,-1);
                result = strcat(line1,line2);
            } else if ((checkEvenA() && checkEvenB()) || (checkEvenB() && checkEvenC()) || (checkEvenA() && checkEvenC())) {
                //3D
                line1 = excise(date,nums01694);
                line2 = digitLetShift(text,4);
                result = strcat(line1,line2);
            } else if (checkEvenA()){
                //3A
                line1 = excise(text,vowels);
                line2 = date;
                result = strcat(line1,line2);
            } else if (checkEvenB()){
                //3B
                line1 = text;
                line2 = excise(date,primeNums);
                result = strcat(line1,line2);
            } else if (checkEvenC()){
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
            if (checkEvenA() && checkEvenB() && checkEvenC()){
                //5E
                line1 = invertOrder(invertLetToNum(text));
                line2 = invertNumToLet(invertOrder(date));
                result = strcat(line1,line2);
            } else if ((checkEvenA() && checkEvenB()) || (checkEvenB() && checkEvenC()) || (checkEvenA() && checkEvenC())) {
                //5D
                line1 = deleteDig(date,2);
                line2 = digitLetShift(text,6);
                result = strcat(line1,line2);
            } else if (checkEvenA()){
                //5A
                line1 = excise(date,nums01234);
                line2 = digitLetShift(text,4);
                result = strcat(line1,line2);
            } else if (checkEvenB()){
                //5B
                line1 = strcat(invertOrder(text),text);
                line2 = strcat(date,invertOrder(date));
                result = strcat(line1,line2);
            } else if (checkEvenC()){
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