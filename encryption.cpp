//============================================================================
// Name        : message-encryption
// Author      : Dante Sanaei and Alec Leven
// Version     : pre-release
// Description : An algorithm to generate an encrypted username and password for a messaging service
//============================================================================

#include <iostream>
#include <stdio.h>
#include "username.h"
#include "stdlib.h"
using namespace std;


//functions
void intro();
void inputs(string *email, string *message, string *receivedKey, int *type);
void email(string email, string message, string receivedKey, int type);


int main() {
	string email;
	string message;
	string receivedKey;
	int type;
	inputs(&email, &message, &receivedKey, &type);
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
	cout << "Enter message: ";
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


