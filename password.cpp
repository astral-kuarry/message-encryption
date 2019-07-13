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
    cout << plaintext << endl << ciphertext << endl << m << endl << n << endl;
    cout << getOp1() << endl;
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
    if (getParity((long long) plaintextNum) == getParity((long long) ciphertextNum) && n > 3 && m > 3) {
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
    std::string targetKey;
    std::stringstream strstream;
    strstream << targetKeyNum;
    strstream >> targetKey;
    return targetKey;

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


