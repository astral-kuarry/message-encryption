//============================================================================
// Name        : message-encryption
// Author      : Dante Sanaei and Alec Leven
// Version     : pre-release
// Description : An algorithm to generate an encrypted username and password for a messaging service
//============================================================================

#include <iostream>
#include <stdio.h>
#include "username.h"
#include "base64.h"
#include "helpers.h"
#include "stdlib.h"
#include <string>
#include <array>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <math.h>
#include <sstream>
#include <iomanip>
using namespace std;


//functions
void intro();
void inputs(string *email, string *message, string *receivedKey, int *type);
void email(string email, string message, string receivedKey, int type);
string getTextKey(string message);
int stringRemoveNonAlphaNum(char *str);
string getDateKey();
long long int getFrac(long double input, int numDigits);
void test();


int main() {
	test();
	string email;
	string message;
	string receivedKey;
	string textKey;
	string dateKey;
	int type;
	username part2;
	inputs(&email, &message, &receivedKey, &type);
	textKey = getTextKey(message);
	dateKey = getDateKey();
    

	return 0;
}

// Prompts the user for inputs
void inputs(string *email, string *message, string *receivedKey, int *type) { //Return email, message, time, and recieved keyword if recipient
	system("clear");
	cout << "Welcome to AQ Encryption v1.0" << endl;
	cout << "Enter your status ([1] sender, [2] receiver): ";
	cin >> *type;
	if (cin.fail()) {
		*type = 0;
	}
	if (*type == 1){
	cout << "Enter email of recipient: ";
	cin >> *email;
	cout << "Enter message: ";
	cin >> *message;
	} else if (*type == 2){
	cout << "Enter date key: ";
	cin >> *message;
	cout << "Enter keyword: ";
	cin >> *receivedKey;
	cout << "Enter email of sender: ";
	cin >> *email;
	} else{
		cout << "Invalid Input\n";
		exit(1);
	}
}

// Emails proper data to receiver, or emails pass/fail status to sender
void email(string email, string message, string receivedKey, int type){
	if (type == 1) {
		
	}
}

//Get text from user and converts it to TextKey
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
    if (loops > 0){
        for (int t = 9-loops+1; t < 10; t++){
            finalArry[t] = 'X';
        }     
    }
    string finalString = string(finalArry);
    return finalString;
}

// Remove non-alphanumeric characters
int stringRemoveNonAlphaNum(char *str)
{
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
    }
    return loops;
}

// Get date key
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
        dateInt[i] = datestring[i] - '0';
    }
    for (int j = 0; j < 7; j++){
        firstSeven[j] = dateInt[j];
    }
    for (int k = 0; k < 7; k++){
        lastSeven[k] = dateInt[k + 7];
    }
    int firstSevenInt = 0;
    int lastSevenInt = 0;
    for (int j = 0; j < 7; j++) {
        firstSevenInt *= 10;
        firstSevenInt += firstSeven[j];
        lastSevenInt *= 10;
        lastSevenInt += lastSeven[j];
    }
    long double getFracInput = (long double) firstSevenInt / lastSevenInt;
    long long dateKeyInt = getFrac(getFracInput, 12);
    std::stringstream ss;
    ss << std::setw(12) << std::setfill('0') << dateKeyInt;
    std::string finalString = ss.str();
    return finalString;
}

// 
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

void test(){
	username part2;
	helpers help;
	int mark[5] = {19, 10, 8, 17, 9};
    help.sort(mark, 5);
    help.printArray(mark, 5);
    string s = "THIS IS A TEST";
    int test[] = {1,2,3,4,5,34,234,234,13,23,23,2};
    int size = sizeof(test)/sizeof(test[0]);
    cout << part2.intToString(test, size) << "\n";
    cout << getTextKey("People who have met their online friends, what made you instantly regret it?") << "\n";
    cout << getTextKey("What are some things you realised too late in life?") << "\n";
    cout << getTextKey("\"Bott!23as is the meat in a ferrari sandwitch ")<< "\n";
    cout << getTextKey("  test§¶•hªº–≠ test ")<< "\n";
    cout << getTextKey("Formula.1.2019x09.Austria.Race.SkyF1HD.Smcgill1969")<< "\n";
    cout << getTextKey("Men, what things do you enjoy that are typically considered “girly”?")<< "\n";
    cout << getTextKey("  123werwerwere")<< "\n";
    cout << getDateKey() << endl;
    cout << "True Prime: " << part2.checkPrime(997) << endl << "False Prime: " << part2.checkPrime(38) << endl;
    cout << "False Consonant: " << part2.checkConsonant('E') << endl;
    cout << part2.checkAscending("111111567811") << endl;
    //string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
    //cout << "\n" << encoded << "\n";
    int countArry1[100];
    int countArry3[200];
    int countArryChar[100];
    //int checkArry3[146] = {101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
    int checkArry1[5] = {1,2,3,4};
    char checkArry[5] = {'A','G','R','T'};
    part2.countInt("12787687278", 11, checkArry1, 4, countArry1, 1);
    //part2.countInt("12787687278", 11, checkArry3, 146, countArry3, 2);
    part2.countChar("AGGGGG", 7, checkArry, 4, countArryChar);
    help.printArray(countArry1, 4);
    //help.printArray(countArry3, 146);
    for (int i; i < 4; i++){
        cout << countArryChar[i];
    }
    cout << endl;
    //cout << part2.invertNumToLet("3332");
	printf("CCCB:   %s\n", part2.invertNumToLet("3332").c_str());
    string letters = "CURBATM";
    string letterscheck = part2.invertNumToLet("398472023");
    string check = part2.excise(letters,letterscheck);
    printf("ans: %s\n",check.c_str());
    string even1 = "111111111111";
    string even2 = "479582694388";
    cout << "False: " << part2.checkEven1(even1) << endl;
    cout << "True: " << part2.checkEven2(even2) << endl;

    
	exit(1);
}