//============================================================================
// Name        : message-encryption
// Author      : Dante Sanaei and Alec Leven
// Version     : pre-release
// Description : An encryption algorithm that generates a private messaging medium service for two or more users
//============================================================================

#include <iostream>
#include <stdio.h>
#include "headers/username.h"
#include "headers/base64.h"
#include "headers/helpers.h"
#include "stdlib.h"
#include "headers/password.h"
#include "headers/monarch.h"
#include <string>
#include <array>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <math.h>
#include <sstream>
#include <unistd.h>
#include <iomanip>
using namespace std;


//functions
void intro();
void inputs(string *email, string *inputDate, string *message, string *receivedKey, int *type);
void email(string email, string message, string receivedKey, int type);
string getTextKey(string message);
//int stringRemoveNonAlphaNum(char *str);
string getDateKey();
long long int getFrac(long double input, int numDigits);
void test();
string deleteDig (string input, int numDigits);
helpers hlpMain = helpers(false);

int main() {
	//test();
	string email;
	string message;
	string receivedKey;
	string textKey;
	string dateKey;
	int type;
	string inputDate;
	inputs(&email, &inputDate, &message, &receivedKey, &type);
	cout << message << endl;
	if (type == 1){
        textKey = getTextKey(message);
        dateKey = getDateKey();
        username part2 = username(textKey, dateKey);
        password part3 = password(part2.plaintext, part2.ciphertext);
        monarch part4 = monarch(part3.targetKey);
        cout << "Date Key: " << dateKey << endl << "Username: " << part2.theusername << endl << "Password: " << part4.password << endl;
	}
	if (type == 2) {
        textKey = getTextKey(message);
        dateKey = inputDate;
        username part2 = username(textKey, dateKey);
        password part3 = password(part2.plaintext, part2.ciphertext);
        monarch part4 = monarch(part3.targetKey);
        cout << "Username: " << part2.theusername << endl << "Password: " << part4.password << endl;
	}
    return 0;
}

// Prompts the user for inputs
void inputs(string *email, string *inputDate, string *message, string *receivedKey, int *type) { //Return email, message, time, and recieved keyword if recipient
	system("cls");
	cout << "Welcome to AQ Encryption v1.0" << endl;
	cout << "Enter your status ([1] sender, [2] receiver): ";
	cin >> *type;
	if (cin.fail()) {
		*type = 0;
	}
	if (*type == 1){
	//cout << "Enter email of recipient: ";
	//cin >> *email;
	cout << "Enter message: ";
	cin >> *message;
	} else if (*type == 2){
    cout << "Enter message: ";
    cin >> *message;
	cout << "Enter date key: ";
	cin >> *inputDate;
	//cout << "Enter keyword: ";
	//cin >> *receivedKey;
	//cout << "Enter email of sender: ";
	//cin >> *email;
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
    string encoded = base64_encode(reinterpret_cast<const unsigned char*>(message.c_str()), message.length());
    //cout << "\n" << encoded << "\n";
    int i, j, k, l, m;
    char messageArry[encoded.size()+1];
    strcpy(messageArry, encoded.c_str());
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
    int loops = hlpMain.stringRemoveNonAlphaNum(finalArry);
    if (loops > 0){
        for (int t = 9-loops+1; t < 10; t++){
            finalArry[t] = 'X';
        }     
    }
    string finalString = string(finalArry);
    return finalString;
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

// gets frac
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

	 cout << "\nTest 1" << endl;
    username test1 = username("RXRCOHCSIJ", "234237847219");
    password test1pass = password(test1.plaintext, test1.ciphertext);
    monarch test1mon = monarch(test1pass.targetKey);
    cout << "Username: " << test1.theusername << endl << "Password: " << test1mon.password << endl;

    cout << "\nTest 2"<< endl;
    username test2 = username("BCRCOHCSIJ", "234237847219");
    password test2pass = password(test2.plaintext, test2.ciphertext);
    monarch test2mon = monarch(test2pass.targetKey);
    cout << "Username: " << test2.theusername << endl << "Password: " << test2mon.password << endl;

    cout << "\nTest 3"<< endl;
    username test3 = username("BFRFOHFSIJ", "234237847219");
    password test3pass = password(test3.plaintext, test3.ciphertext);
    monarch test3mon = monarch(test3pass.targetKey);
    cout << "Username: " << test3.theusername << endl << "Password: " << test3mon.password << endl;

    cout << "\nTest 4"<< endl;
    username test4 = username("UVRVOHVSIJ", "234237847219");
    password test4pass = password(test4.plaintext, test4.ciphertext);
    monarch test4mon = monarch(test4pass.targetKey);
    cout << "Username: " << test4.theusername << endl << "Password: " << test4mon.password << endl;

    cout << "\nTest 5"<< endl;
    username test5 = username("UVRVOHVSIJ", "284237847219");
    password test5pass = password(test5.plaintext, test5.ciphertext);
    monarch test5mon = monarch(test5pass.targetKey);
    cout << "Username: " << test5.theusername << endl << "Password: " << test5mon.password << endl;

    cout << "\nTest 6"<< endl;
    username test6 = username("UVRVOHVSIJ", "286869756844");
    password test6pass = password(test6.plaintext, test6.ciphertext);
    monarch test6mon = monarch(test6pass.targetKey);
    cout << "Username: " << test6.theusername << endl << "Password: " << test6mon.password << endl;

    cout << "\nTest 7"<< endl;
    username test7 = username("BCRCOHCSIJ", "286869756844");
    password test7pass = password(test7.plaintext, test7.ciphertext);
    monarch test7mon = monarch(test7pass.targetKey);
    cout << "Username: " << test7.theusername << endl << "Password: " << test7mon.password << endl;

    cout << "\nTest 8"<< endl;
    username test8 = username("BCRCOHCSIJ", "103723971119");
    password test8pass = password(test8.plaintext, test8.ciphertext);
    monarch test8mon = monarch(test8pass.targetKey);
    cout << "Username: " << test8.theusername << endl << "Password: " << test8mon.password << endl;








    exit(1);
}

