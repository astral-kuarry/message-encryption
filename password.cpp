#include "password.h"
#include "helpers.h"
#include "username.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <math.h>




using namespace std;
username part2;
helpers console1;

password::password(string rawplaintext, string rawciphertext) {
    password::plaintext = part2.invertLetToNum(rawplaintext);
    password::ciphertext = part2.invertLetToNum(rawciphertext);
    password::m = password::plaintext.length();
    password::n = password::ciphertext.length();
    cout << plaintext << endl << ciphertext << endl;

    cout <<  getOp2() << endl;

}

password::~password() {
    // TODO Auto-generated destructor stub
}

bool password::getParity(long long num){
    return num % 2;
}

bool password::checkInstruct1(){
    console1.log("Check Instruction 1");
    char plaintextArry[m+1];
    strcpy(plaintextArry, plaintext.c_str());
    char ciphertextArry[n+1];
    strcpy(ciphertextArry, ciphertext.c_str());
    int plaintextNum = plaintextArry[m - 3] - '0';
    int ciphertextNum = ciphertextArry[n - 3] - '0';
    //cout << plaintextNum << endl << ciphertextNum << endl;
    if (n > 3 && m > 3 && getParity((long long) plaintextNum) == getParity((long long) ciphertextNum)) {
        return true;
    }
    return false;
}

string password::getOp1(){
    int i, j, k;
    long double top = 0; //genius naming scheme
    long double bottom = 0;
    long double finalNum;
    long long targetKeyNum;
    for (i = 1; i < m; i++){
        top = top + (long double) (n * (long double) (i + m));
    }
    for (j = 1; j < n; j++){
        bottom = bottom + (long double) pow((long double) j + (long double) (1/m) - 1, (long double) log(n - 1));  // Convert everything just to be safe.
    }
    finalNum = top / bottom;
    targetKeyNum = getFrac(finalNum, 8);
    std::string target;
    std::stringstream strstream;
    strstream << targetKeyNum;
    strstream >> target;
    return target;

}
// gets frac
long long int password::getFrac(long double input, int numDigits) {
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

bool password::checkInstruct2(){
    char plaintextArry[m+1];
    strcpy(plaintextArry, plaintext.c_str());
    char ciphertextArry[n+1];
    strcpy(ciphertextArry, ciphertext.c_str());
    int i,j;
    for (i = 0; i < m; i++){
        if (part2.checkPrime(plaintextArry[i] - '0') && part2.checkPrime(plaintextArry[i+1] - '0') && part2.checkPrime(plaintextArry[i+2] - '0') && part2.checkPrime(plaintextArry[i+3] - '0')){
            //cout << "first" << " " << i << endl;
            return true;
        }
    }
    for (j = 0; j < n; j++){
        if (part2.checkPrime(ciphertextArry[j] - '0') && part2.checkPrime(ciphertextArry[j+1] - '0') && part2.checkPrime(ciphertextArry[j+2] - '0') && part2.checkPrime(ciphertextArry[j+3] - '0')){
            //cout << "second" << " " << j << endl;
            return true;
        }
    }
    return false;
}

string password::getOp2(){
    int number = m * pow(m+n, n/5);
    //number = 235212;
    int factors[100];
    int multiplicy[100];
    int index = 0;
    int mindex = 0;
    //cout << number << endl;
    while (number%2 == 0){
        //printf("%d ", 2);
        factors[index] = 2;
        index++;
        number = number/2;
    }
    for (int i = 3; i <= sqrt(number); i = i+2){
        // While i divides n, print i and divide n
        while (number%i == 0){
            //printf("%d ", i);
            factors[index] = i;
            index++;
            number = number/i;
        }
    }
    if (number > 2){
        //printf ("%d ", number);
        factors[index] = number;
        index++;
    }
    //console1.printIntArray(factors, index);
    int q, r, x;
    int tempQ;
    for (q = 0; q < index; q++){
        tempQ = 0;
        x = 1;
        for (r = q + 1; r < index; r++) {
            if (factors[q] == factors[r]){
                tempQ++;
                multiplicy[mindex] = ++x;
            }
        }
        if (tempQ){
            mindex++;
        } else{
            multiplicy[mindex++] = x;
        }
        q += tempQ;
        //cout << q << endl;
    }
    //console1.printIntArray(multiplicy, mindex);
    long long factorsNum = part2.intToNum(factors, index);
    long long multiplicityNum = part2.intToNum(multiplicy, mindex);
    long double finalNum = (long double) factorsNum/multiplicityNum;
    long long targetKeyNum = getFrac(finalNum, 8);
    std::string target;
    std::stringstream strstream;
    strstream << targetKeyNum;
    strstream >> target;
    return target;
}


