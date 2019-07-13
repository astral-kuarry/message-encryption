#include "password.h"
#include "helpers.h"
#include "username.h"
#include <iostream>
#include<stdlib.h>
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
username part2;
helpers console1;

password::password(string rawplaintext, string rawciphertext) {
    password::plaintext = part2.invertLetToNum(rawplaintext);
    password::ciphertext = part2.invertLetToNum(rawciphertext);
    password::m = password::plaintext.length();
    password::n = password::ciphertext.length();
    cout << plaintext << endl << ciphertext << endl << m << endl << n << endl;
    cout << checkInstruct2();
}

password::~password() {
    // TODO Auto-generated destructor stub
}

bool password::getParity(long long num){
    return num % 2;
}

bool password::checkInstruct2(){
    console1.log("Check Instruction 2");
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



